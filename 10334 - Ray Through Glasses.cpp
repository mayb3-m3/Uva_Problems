import sys
arr = [1, 2, 3]
for i in range(998):
    arr.append(arr[-1]+arr[-2])
nums = sys.stdin.read().split()
for i in nums:
    print(arr[int(i)])
