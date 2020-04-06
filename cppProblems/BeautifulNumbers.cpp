#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
int positions[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
		int n;
		cin >> n;
		fore(i,0,n){
			int index;
			cin >> index;
			positions[index]=i;
		}
		int minimum=positions[1];
		int maximum=positions[1];
		fore(m,1,n+1){
			minimum=min(minimum,positions[m]);
			maximum=max(maximum,positions[m]);
			int len=maximum-minimum+1;
			if(len==m){
				cout << "1";
			}else{
				cout << "0";
			}
		}
		cout << "\n";
	}
    return 0;
}
