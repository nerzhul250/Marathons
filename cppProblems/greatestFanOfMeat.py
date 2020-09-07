import math
t=int(input())
while(t>0):
	a,b = map(int,input().split())
	g = math.gcd(a,b)
	a //= g
	b //= g
	ans=[]
	for k in range(math.ceil((2*a/b)-2),math.floor(2*a/b)+1):
		if (k>1 and (a*(k-1))%b==0):
			n=(k*(k+1))//2-((a*(k-1))//b)
			if(k>=n and n>=1):
				ans.append([k,n])
	print(len(ans))
	for p in ans:
		print(p[0],p[1])
	t-=1
    
