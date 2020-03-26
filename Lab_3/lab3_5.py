fileIN = open("radixsort.in", 'r')
fileOUT = open("radixsort.out", 'w')
# n, m, k = map(int, input().split())
n, m, k = map(int, fileIN.readline().split())
arr = []
for i in range(n):
    arr.append(fileIN.readline().split('\n')[0])
for i in range(m-1, m-k-1, -1):
    arr = sorted(arr, key=lambda word: word[i])
for i in arr:
    fileOUT.write(str(i)+'\n')
