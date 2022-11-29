import os


def write_to_file(file_name : str, string : str, line: int):
    with open(file_name, 'r') as file:
        data = file.readlines()

    print(data)
    data[line-1] = '\t' + string + '\n'

    with open(file_name, 'w') as file:
        file.writelines(data)


def run_all_tests():
    os.system('g++ testing.cpp -o test.out')
    os.system('./test.out')
    print('\n\n')
    
    
def run_func_test(func_name: str, value: int):
    print(f'Testing function: {func_name}')
    write_to_file('test_func.cpp', f'LNL::{func_name}({value}, 5);', 5)
    os.system("g++ test_func.cpp -o test_func.out")
    os.system("time ./test_func.out")
    print('\n\n')
    

if __name__ == "__main__":
    run_all_tests()
    run_func_test("pow", 3)