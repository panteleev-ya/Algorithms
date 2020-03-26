fileIN = open("postfix.in", 'r')
fileOUT = open("postfix.out", 'w')

stack = []
arr = fileIN.readline().split()
for symbol in arr:
    if symbol == '+':
        buffer = stack[len(stack) - 2] + stack[len(stack) - 1]
        del stack[len(stack) - 2]
        del stack[len(stack) - 1]
        stack.append(buffer)
    elif symbol == '-':
        buffer = stack[len(stack) - 2] - stack[len(stack) - 1]
        del stack[len(stack) - 2]
        del stack[len(stack) - 1]
        stack.append(buffer)
    elif symbol == '*':
        buffer = stack[len(stack) - 2] * stack[len(stack) - 1]
        del stack[len(stack) - 2]
        del stack[len(stack) - 1]
        stack.append(buffer)
    elif symbol == '/':
        buffer = stack[len(stack) - 2] / stack[len(stack) - 1]
        del stack[len(stack) - 2]
        del stack[len(stack) - 1]
        stack.append(buffer)
    else:
        stack.append(int(symbol))
print(stack[0], file=fileOUT)
