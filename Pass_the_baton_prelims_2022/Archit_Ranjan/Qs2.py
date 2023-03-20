n = int(input())
c = 1
r = 10**9+7
b,a = (n+1)//2,(n//2)

c*=pow(4,a,r)
c*=pow(5,b,r)
print(c%r)
