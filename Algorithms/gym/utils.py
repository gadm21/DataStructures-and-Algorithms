




my_input = True 
input_file = 'input.txt'
index = 0

def init_input_file():
    global input_file 
    if my_input : 
        with open(input_file) as f:
            lines = f.readlines()
        input_file = [line.rstrip() for line in lines]
        
init_input_file()

def read():
    global index 
    if not my_input : return input() 
    else:
        if index >= len(input_file) : line = ''
        else: line = input_file[index]
        index += 1
        return line

def get_output():
    if my_input:
        for i in range(len(input_file)):
            if input_file[i] == 'output': return input_file[i+1:]
        return []
