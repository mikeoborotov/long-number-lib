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
        
        
def run_all_tests(
    file_name : str,
    ):
    os.system(f'g++ {file_name} -o test.out')
    os.system('./test.out')
    print('\n\n')
    
 
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
    write_to_file(filepath, func_name, line=7)
    os.system(f'g++ {filepath} -o test_func.out')
    
    result = int(sp.check_output('./test_func.out', stderr=sp.STDOUT, shell=True))
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
    fig.canvas.manager.set_window_title(f'Function {func_name} benchmark')
    
    ax = fig.add_subplot()
    ax.set_title(f'Function {func_name} benchmark')

    xticks = np.arange(0, len(times))
    ax.set_xticks(xticks)
    
    if (numbers.shape[1] == 1):
        ax.set_xticklabels([f'{func_name}({float(n):.1e})'.replace('[', '').replace(']', '') for n in numbers], fontsize=8)
    elif (numbers.shape[1] == 2):
        ax.set_xticklabels([f'{get_exp(int(n[0]))}{func_name}{get_exp(int(n[1]))}' for n in numbers], fontsize=8)
    else:
        print(f'Invalid shape of numbers for function {func_name}')
        return
    
    ax.grid(linestyle='--', linewidth=0.5)
    ax.set_xlabel('Numbers', labelpad=14.0)
    ax.set_ylabel('Time, ms')
                  
    ax.plot(times, color='tab:blue')
    plt.show()
    
def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "path_unit", metavar='PATH TO UNIT TESTS', type=str,
        help="Path to the cpp file with unit tests. " \
             "Basically it is source/testing.cpp.")
    parser.add_argument(
        "-path", metavar='PATH TO FILE FOR FUNC BENCHMARK', type=str,
        help="Path to the cpp file with function. " \
             "Basically it is source/test_func.cpp.")
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
        "--multi", action="store_true",
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
    
    filepath_all = ARGS.path_unit
    run_all_tests(filepath_all)
    
    
    if ARGS.path is not None:
        filepath = ARGS.path
        
        if ARGS.pow:
            num = np.asarray([[11e5, 10000], [11e10, 10000], [11e15, 10000]], dtype=int)
            run_func_evolution_test('pow', num)
            
        if ARGS.div:
            num = np.asarray([['11'*100, '21'*60], 
                              ['11'*150, '21'*60], 
                              ['11'*200, '21'*60], 
                              ['11'*250, '21'*60], 
                              ['11'*300, '21'*60]],
                             dtype=str)
            run_func_evolution_test('div', num)
            
        if ARGS.mod:
            num = np.asarray([[11e5, 200], [11e10, 200], [11e15, 200]], dtype=int)
            run_func_evolution_test('mod', num)

        if ARGS.gcd:
            num = np.asarray([[11e5, 200], [11e10, 200], [11e15, 200]], dtype=int)
            run_func_evolution_test('gcd', num)
            
        if ARGS.lcm:
            num = np.asarray([['14'*100, '27'*50], 
                              ['14'*300, '27'*50], 
                              ['14'*500, '27'*50], 
                              ['14'*700, '27'*50], 
                              ['14'*900, '27'*50]], 
                            dtype=str)
            run_func_evolution_test('lcm', num)
        
        if ARGS.factorial:
            num = np.asarray([[111], [1111], [11111]], dtype=int)
            run_func_evolution_test('factorial', num)
            
        if ARGS.multi:
            num = np.asarray([['11'*100, '11'*50], 
                              ['11'*300, '11'*50], 
                              ['11'*500, '11'*50], 
                              ['11'*700, '11'*50], 
                              ['11'*900, '11'*50]], 
                             dtype=str)
            run_func_evolution_test('*', num)
            
        if ARGS.divop:
            num = np.asarray([['99'*50, '99'*50], 
                              ['99'*100, '99'*50], 
                              ['99'*150, '99'*50], 
                              ['99'*200, '99'*50], 
                              ['99'*250, '99'*50]], 
                             dtype=str)
            run_func_evolution_test('/', num)
            
        if ARGS.modop:
            num = np.asarray([['99'*50, '99'*50], 
                              ['99'*100, '99'*50], 
                              ['99'*150, '99'*50], 
                              ['99'*200, '99'*50], 
                              ['99'*250, '99'*50]], 
                             dtype=str)
            run_func_evolution_test('%', num)
            


