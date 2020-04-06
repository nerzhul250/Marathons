#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> pr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)lp[i * pr[j]] = pr[j];
	}
    
    int n,k;
    cin >> n >> k;
    int curk=0;
    fore(i,2,N+1){
		if(lp[i]>n && lp[i]!=i){
			curk++;
			if(curk==k){
				cout << i << "\n";
				break;
			}
		}
	}   
    return 0;
}
