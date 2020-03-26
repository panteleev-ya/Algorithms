fileIN = open("priorityqueue.in", 'r')
fileOUT = open("priorityqueue.out", 'w')

commands = []
queue = []

line = fileIN.readline()
while len(line):
    commands.append(line.split())
    line = fileIN.readline()
for c in commands:
    if c[0] == 'push':
        queue.append(int(c[1]))
    elif c[0] == 'extract-min':
        if len(queue):
            m = queue[0]
            ind = 0
            for e in range(len(queue)-1, -1, -1):
                if queue[e] < m:
                    m = queue[e]
                    ind = e
            print(m, file=fileOUT)
            del queue[ind]
        else:
            print('*', file=fileOUT)
    elif c[0] == 'decrease-key':
        el = int(commands[int(c[1]) - 1][1])
        commands[int(c[1]) - 1][1] = int(c[2])
        for i in range(len(queue)):
            if queue[i] == el:
                queue[i] = int(c[2])
                break
