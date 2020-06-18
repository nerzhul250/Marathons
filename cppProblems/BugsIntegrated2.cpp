#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
const int maxn=156,maxm=16,inf=6e4;
const int power[]={1,3,9,27,81,243,729,2187,6561,19683,59049};
template<typename T>inline void read(T &x)
{
	x=0;
	T f=1, ch=getchar();
	while (!isdigit(ch) && ch^'-') ch=getchar();
	if (ch=='-') f=-1, ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x*=f;
}
int n,m,k;
inline int Th2De(int *a)
{
	int ans=0;
	for (int i=0; i<m; ++i)
		ans+=a[i]*power[i];
	return ans;
}

inline void De2Th(int x,int *a)
{
	for (int i=0; i<m; ++i)
	{
		a[i]=x%3;
		x/=3;
	}
}

int pre[maxm],ver[maxm],f[2][inf];
bool bad[maxn][maxm];
inline void dfs(int now,int j,int last,int state)
{
	f[now][state]=max(f[now][state],last);
	if (j>=m) return ;
	if (j<m-1 && !pre[j] && !pre[j+1] && !ver[j] && !ver[j+1])
	{
		ver[j]=ver[j+1]=2;
		dfs(now,j+2,last+1,Th2De(ver));
		ver[j]=ver[j+1]=0;
	}
	if (j<m-2 && !ver[j] && !ver[j+1] && !ver[j+2])
	{
		ver[j]=ver[j+1]=ver[j+2]=2;
		dfs(now,j+3,last+1,Th2De(ver));
		ver[j]=ver[j+1]=ver[j+2]=0;
	}
	dfs(now,j+1,last,state);
}

int main()
{
	int t;read(t);
	while (t--)
	{
		read(n);read(m);read(k);
		memset(bad,0,sizeof(bad));
		while (k--)
		{
			int x,y;
			read(x);read(y);
			bad[x][y-1]=1;
		}
		memset(f[0],-1,sizeof(f[0]));
		for (int i=0; i<m; ++i)
			pre[i]=bad[1][i]?2:1;
		int now=0,tmp=Th2De(pre);
		f[now][tmp]=0;
		for (int i=2; i<=n; ++i)
		{
			now^=1;
			memset(f[now],-1,sizeof(f[now]));
			for (int j=0; j<power[m]; ++j)
			{
				if (f[now^1][j]==-1) continue;
				De2Th(j,pre);
				for (int k=0; k<m; ++k)
					if (bad[i][k]) ver[k]=2;
					else ver[k]=pre[k]?pre[k]-1:0;
				tmp=Th2De(ver);
				dfs(now,0,f[now^1][j],tmp);
			}
		}
		int ans=0;
		for (int i=0; i<power[m]; ++i)
			ans=max(ans,f[now][i]);
		printf("%d\n",ans);
	}
	return 0;
}
