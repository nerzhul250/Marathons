#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef long long int ll;

ll bag[70],box[70];
ll n,m;
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		memset(bag,0,sizeof bag);
		memset(box,0,sizeof box);
		fore(i,0,64){
			if((n&(1<<i))!=0){
				bag[i]++;
			}
		}
		ll sum=0;
		fore(i,0,m){
			int a;
			cin >> a;
			sum+=a;
			box[31-__builtin_clz(a)]++;
		}	
		if(sum<n){
			cout << "-1\n";
		}else{
			ll current=0;
			ll divisions=0;
			fore(i,0,64){
				current+=box[i];
				if(bag[i]<=current){
					current-=bag[i];
				}else{
					fore(j,i+1,64){
						if(box[j]>0){
							divisions+=(j-i);
							fore(k,i+1,j){
								box[k]=1;
							}
							box[j]--;
							current+=2;
							break;
						}
					}
					current-=bag[i];
				}
				current/=2;
			}
			cout << divisions << "\n";
		}
	}
    return 0;
}
