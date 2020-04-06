#include <bits/stdc++.h>
#include <stdio.h>

#define fore(i,low,n) for(int i=low;i<n;i++)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

const int INF=1e9;

int n,canoas;
int costUnf[4005][4005];
int cost(int i, int j){
	int sum=costUnf[j][j]-(i==0?0:costUnf[j][i-1])-(i==0?0:costUnf[i-1][j])+(i==0?0:costUnf[i-1][i-1]);
	return sum/2;
}

vector<int> dp_before(4005),dp_cur(4005);
// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<int, int> best = {INF, -1};

    for (int k = max(mid,optl); k<=optr; k++) {
        best = min(best, {dp_before[k+1] + cost(mid,k), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

int main()
{
	scanf("%d%d\n",&n,&canoas);
	char buffer[10000];
	for(int i=1; i<=n; i++) {
	  gets(buffer);
	  for(int j=1; j<=n; j++)
		costUnf[i-1][j-1] = buffer[2 * (j - 1)] - '0';
	}
	
	fore(i,1,n){
		fore(j,0,n){
			costUnf[i][j]+=costUnf[i-1][j];
		}
	}
	
	fore(i,0,n){
		fore(j,1,n){
			costUnf[i][j]+=costUnf[i][j-1];
		}
	}
	
	
	
	fore(i,0,n){
		dp_before[i]=cost(i,n-1);
	}
	
	dp_cur=dp_before;
	
	fore(k,2,canoas+1){
		compute(0,n-1,0,n-1);
		dp_before=dp_cur;
	}
	
	cout << dp_cur[0]<<"\n";
	
    return 0;
}
