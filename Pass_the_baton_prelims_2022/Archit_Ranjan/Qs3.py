n = int(input())
s = input()
c = 0
d = {'a':0,'e':0,'i':0,'o':0,'u':0}
for i in range(n):     
    if s[i] in d.keys():
        d[s[i]]+=(i+1)*(n-(i))
        #print(d)
print(sum(d.values()))
