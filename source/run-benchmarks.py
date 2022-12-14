# Copyright 2022 Mikhail Oborotov, Ivan Borisenkov, Elveg Khunshaev
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import subprocess as sp
import matplotlib.pyplot as plt
import numpy as np
import argparse


def write_to_file(
    file_name : str, 
    string : str, 
    line: int,
    ):
    
    with open(file_name, 'r') as file:
        data = file.readlines()
    
    if 'LNL::' in data[line-1]:  
        data[line-1] = '\t' + string + '\n'
    else:
        print('Wrong cpp file to run')
        exit()

    with open(file_name, 'w') as file:
        file.writelines(data)
    
 
def run_func_test(
    func_name: str, 
    values: np.ndarray,
    ):

    if func_name in avaliable_funcs:
        if(len(values) == 1):
            if isinstance(values[0], np.str_):
                func_name = f'LNL::{func_name}(LNL::LongInt("{values[0]}"));'
            else:
                func_name = f'LNL::{func_name}(LNL::LongInt({values[0]}));'
        elif (len(values) == 2):
            if isinstance(values[0], np.str_):
                func_name = f'LNL::{func_name}(LNL::LongInt("{values[0]}"), LNL::LongInt("{values[1]}"));'
            else:
                func_name = f'LNL::{func_name}(LNL::LongInt({values[0]}), LNL::LongInt({values[1]}));'
        else:
            print(f'Invalid number of arguments for function {func_name}')
            return
    elif func_name in avaliable_opers:
        if(len(values) == 2):
            func_name = f'LNL::LongInt result = LNL::LongInt("{values[0]}"){func_name}LNL::LongInt("{values[1]}");'
        else:
            print(f'Invalid number of arguments for operator {func_name}')
            return
        
    
    print(f'Testing function: {func_name}'.replace(';', ''))
    write_to_file(filepath, func_name, line=21)
    os.system(f'g++ {filepath} -o benchmark.out')
    
    result = int(sp.check_output('./benchmark.out', stderr=sp.STDOUT, shell=True))
    print(f'Time: {result} ms\n')
    return result
    

def run_func_evolution_test(
    func_name : str,
    numbers : np.ndarray,
    ):
    
    times = []
    for num in numbers:
        result = run_func_test(func_name, num)
        times.append(result)
        
    plot_time_evolution(func_name, numbers, np.array(times))
 
    
def get_exp(
    num : int
    ):
    snum = str(num)
    return f'{snum[0]}e+{len(snum)-1}'
        

def plot_time_evolution(
    func_name : str,
    numbers : np.ndarray,
    times : np.ndarray,
    ):
    
    fig = plt.figure(figsize=(8, 8))
    fig.subplots_adjust(bottom=0.25)
    fig.canvas.manager.set_window_title(f'Benchmark for function: {func_name}')
    
    ax = fig.add_subplot()
    ax.set_title(f'Benchmark for function: {func_name}')

    xticks = np.arange(0, len(times))
    ax.set_xticks(xticks)
    
    if (numbers.shape[1] == 1):
        ax.set_xticklabels([f'{func_name}({get_exp(int(n))})'.replace('[', '').replace(']', '') for n in numbers], fontsize=8)
    elif (numbers.shape[1] == 2):
        ax.set_xticklabels([f'{get_exp(int(n[0]))[0:1]}$\cdot$10{"$^{%s}$" % get_exp(int(n[0]))[3:]} {func_name} {get_exp(int(n[1]))[0:1]}$\cdot$10{"$^{%s}$" % get_exp(int(n[1]))[3:]}' for n in numbers], fontsize=8, rotation=45)
    else:
        print(f'Invalid shape of numbers for function {func_name}')
        return

    # Plotting labels only for 10 xticks (so there is no mess)
    tick_step = int(ax.get_xticks().size / 10)
    if (tick_step == 0):
        tick_step = 1
    ax.set_xticks(ax.get_xticks()[::tick_step])
    
    # Grid settings
    ax.grid(which='major', linestyle='-', linewidth=0.8)
    ax.grid(which='minor', linestyle='--', linewidth=0.5)
    ax.minorticks_on()

    ax.set_xlabel('Numbers (rounded up to orders of magnitude)', labelpad=14.0)
    ax.set_ylabel('Calculation time, ms')
                  
    ax.plot(times, linestyle='-', marker='.', linewidth=0.8, label='$time$')

    # Extra plots for comparing algorithm complexity
    if (func_name == '*'):
        karatsuba_complexity = np.power(times, 0.631)
        ax.plot(karatsuba_complexity, linestyle='--', marker='.', linewidth=0.8, label='$time^{log_32}$')
    sqrt_of_times = np.sqrt(times)
    ax.plot(sqrt_of_times, linestyle='--', marker='.', linewidth=0.8, label='$\sqrt{time}$')

    # Plot limits
    # ax.set_ylim(0, 50)

    ax.legend(loc='best')
    plt.show()
    
def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-path", metavar='PATH TO THE CPP BENCHMARK FILE', type=str,
        help="Path to the cpp file with a benchmark for a single function/operator. " \
             "Basically it is source/benchmark.cpp.")
    parser.add_argument(
        "--pow", action="store_true",
        help="Test LNL::pow function")
    parser.add_argument(
        "--div", action="store_true",
        help="Test LNL::div function")
    parser.add_argument(
        "--mod", action="store_true",
        help="Test LNL::mod function")
    parser.add_argument(
        "--gcd", action="store_true",
        help="Test LNL::gcd function")
    parser.add_argument(
        "--lcm", action="store_true",
        help="Test LNL::lcm function")
    parser.add_argument(
        "--factorial", action="store_true",
        help="Test LNL::factorial function")
    parser.add_argument(
        "--mult", action="store_true",
        help="Test LNL::operator *")
    parser.add_argument(
        "--divop", action="store_true",
        help="Test LNL::operator /")
    parser.add_argument(
        "--modop", action="store_true",
        help="Test LNL::operator %%")
    
    return parser.parse_known_args()


filepath = ''
avaliable_funcs = ['pow', 'div', 'mod', 'gcd', 'lcm', 'factorial']
avaliable_opers = ['*', '/', '%']


if __name__ == "__main__":
    
    ARGS, UNKNOWN = parse_args()
    
    if ARGS.path is not None:
        filepath = ARGS.path

        # Generating an array for benchmarks
        num = np.asarray([['9876543210'*i*10, '1234567890'*10] for i in range(1, 52)], dtype=str)
        
        if ARGS.pow:
            # Custom array for benchmarks
            num = np.asarray([[2, 1000*i] for i in range(1, 52)], dtype=int)
            run_func_evolution_test('pow', num)
            
        if ARGS.div:
            run_func_evolution_test('div', num)
            
        if ARGS.mod:
            run_func_evolution_test('mod', num)

        if ARGS.gcd:
            run_func_evolution_test('gcd', num)
            
        if ARGS.lcm:
            run_func_evolution_test('lcm', num)
        
        if ARGS.factorial:
            # Custom array for benchmarks
            num = np.asarray([[1000*i] for i in range(1, 12)], dtype=int)
            run_func_evolution_test('factorial', num)
            
        if ARGS.mult:
            # Custom array for benchmarks
            num = np.asarray([['9876543210'*i*10, '1234567890'*i*10] for i in range(1, 52)], dtype=str)
            run_func_evolution_test('*', num)
            
        if ARGS.divop:
            run_func_evolution_test('/', num)
            
        if ARGS.modop:
            run_func_evolution_test('%', num)
            
