import math
n = int(input())
while(n > 0):
    a, t, b = input().split()
    a = int(a)
    b = int(b)
    g = math.gcd(a,b)
    a //= g
    b //= g
    print(a,"/",b)
    n -= 1
