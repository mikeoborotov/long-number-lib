import os
import subprocess as sp
import matplotlib.pyplot as plt
import numpy as np


def write_to_file(
    file_name : str, 
    string : str, 
    line: int,
    ):
    with open(file_name, 'r') as file:
        data = file.readlines()
        
    data[line-1] = '\t' + string + '\n'

    with open(file_name, 'w') as file:
        file.writelines(data)
        
        
def run_all_tests():
    os.system('g++ testing.cpp -o test.out')
    os.system('./test.out')
    print('\n\n')
    
    
def run_func_test(
    func_name: str, 
    values: np.ndarray,
    ):

    print(values[0])
    print(values[1])
    if(len(values) == 1):
        func_name = f'LNL::{func_name}(LNL::LongInt({values[0]}));'
    elif (len(values) == 2):
        func_name = f'LNL::{func_name}(LNL::LongInt({values[0]}), LNL::LongInt({values[1]}));'
    else:
        print(f'Invalid number of arguments for function {func_name}')
        return
    
    print(f'Testing function: {func_name}'.replace(';', ''))
    write_to_file('test_func.cpp', func_name, line=7)
    os.system('g++ test_func.cpp -o test_func.out')
    
    result = int(sp.check_output('./test_func.out', stderr=sp.STDOUT, shell=True))
    print(result)
    print('\n\n')
    return result
    

def run_func_evolution_test(
    func_name : str,
    numbers : np.ndarray,
    ):
    
    times = []
    for num in numbers:
        print('Num: ' + str(num))
        result = run_func_test(func_name, num)
        times.append(result)
        
    plot_time_evolution(func_name, numbers, np.array(times))
        

def plot_time_evolution(
    func_name : str,
    numbers : np.ndarray,
    times : np.ndarray,
    ):
    
    print(numbers.shape)
    
    # fig = plt.figure(figsize=(8, 8))
    # ax = fig.add_subplot()
    # ax.set_title(f'Function {func_name} benchmark')
    
    # xticks = np.arange(0, len(areas))
    # xt = np.linspace(0, len(matrix.time)-1, len(areas), dtype=int)
    # ax_areas.set_xticks(xticks)
    # ax_areas.set_xticklabels(
    #     np.take(matrix.time, xt), fontsize=8, rotation=45)
    # ax_areas.tick_params(axis='y', labelcolor='tab:blue')
    # ax_areas.set(
    #     xlabel=_tr('Time', 'hh:mm:ss'),
    #     ylabel=_tr('Area', 'km * m/s'),
    # )
    
    # ax.plot(numbers, times)
    

if __name__ == "__main__":
    run_all_tests()
    # run_func_test("pow", 12121212121, 100)
    print(11e10)
    num = np.asarray([[int(11e10), 10], [int(11e15), 10]])
    run_func_evolution_test('pow', num)