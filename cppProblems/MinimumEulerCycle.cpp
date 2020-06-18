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

int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		ll n,l,r;
		cin >> n >> l >> r;
		string ans="";
		ll left=1;
		fore(i,1,n){
			ll x=i;
			ll right=left+2*(n-x)-1;
			ll size=2*(n-x);
			if(l>=left && l<=right){
				while(l<=min(r,right)){					
					ll norm=l-left;
					if(norm%2==0){
						ans+=to_string(i);
						ans+=" ";
					}else{
						norm=(norm-1)/2;
						ans+=to_string(norm+i+1);
						ans+=" ";
					}
					l++;
				}
			}
			left+=size;
		}
		if(left==r)ans+="1 ";
		ans[ans.size()-1]='\n';
		cout << ans;
	}
    return 0;
}
