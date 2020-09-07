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
const int MAXN=10000005;
int son[MAXN][2];
int cnt[MAXN];
int bits[35];
int sz;
int main(){FIN;	
	int Q;
	cin >> Q;
	sz++;
	int currNode=0;
	fore(i,0,31){
		son[currNode][0]=sz;
		cnt[sz]++;
		currNode=sz;
		sz++;
	}
	fore(q,0,Q){
		char op;
		int x;
		cin >> op >> x;
		fore(i,0,31){
			if(x%2==0){
				bits[i]=0;
				x/=2;
			}else{
				bits[i]=1;;
				x--;
				x/=2;
			}
		}
		reverse(begin(bits),begin(bits)+31);
		if(op=='+'){
			int currNode=0;
			fore(i,0,31){
				if(son[currNode][bits[i]]==0){
					son[currNode][bits[i]]=sz;
					cnt[sz]++;
					currNode=sz;
					sz++;
				}else{
					cnt[son[currNode][bits[i]]]++;
					currNode=son[currNode][bits[i]];
				}
			}
		}else if(op=='-'){
			int currNode=0;
			fore(i,0,31){
				cnt[son[currNode][bits[i]]]--;
				currNode=son[currNode][bits[i]];
			}
		}else{
			int currNode=0;
			int num=0;
			fore(i,0,31){
				num*=2;
				if(bits[i]==0){
					if(cnt[son[currNode][1]]>0){
						num++;
						currNode=son[currNode][1];
					}else{
						currNode=son[currNode][0];
					}
				}else{
					if(cnt[son[currNode][0]]>0){
						num++;
						currNode=son[currNode][0];
					}else{
						currNode=son[currNode][1];
					}
				}
			}
			cout << num << "\n";
		}
	}
    return 0;
}
