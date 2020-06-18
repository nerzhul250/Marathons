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
typedef pair<ll,ll> l2;
typedef pair<ll,l2> l3;

int n,x,y,z;
int init;
ll dp[3][105],arr[300005],period;
ll getGrundy(int p,int s){
	if(s==0)return dp[p][s]=0;
	if(dp[p][s]!=-1)return dp[p][s];
	set<ll> st;
	st.insert(-1);
	if(p==0){
		st.insert(getGrundy(0,max(0,s-x)));
		st.insert(getGrundy(1,max(0,s-y)));
		st.insert(getGrundy(2,max(0,s-z)));
	}else if(p==1){
		st.insert(getGrundy(0,max(0,s-x)));
		st.insert(getGrundy(2,max(0,s-z)));
	}else if(p==2){
		st.insert(getGrundy(0,max(0,s-x)));
		st.insert(getGrundy(1,max(0,s-y)));
	}
	vector<ll> ans;
	for(ll e:st)ans.pb(e);
	fore(i,0,ans.size())if(i==ans.size()-1||ans[i]+1!=ans[i+1])return dp[p][s]=ans[i]+1;
}
ll gg(int p,ll s){
	if(s<100)return dp[p][(int)s];
	ll k=(s-100)/period;
	k++;
	int news=s-k*period;
	assert(news>=init);
	return dp[p][news];
}
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> x >> y >> z;
		memset(dp,-1,sizeof dp);
		fore(i,0,100)getGrundy(0,i),getGrundy(1,i),getGrundy(2,i);
		vector<l3> base;
		fore(l,0,5){
			l3 tuple=l3(getGrundy(0,l),l2(getGrundy(1,l),getGrundy(2,l)));
			base.pb(tuple);
		}
		map<vector<l3>,int> mp;
		mp[base]=4;
		int index=-1e8;
		fore(l,5,100){
			l3 tuple=l3(getGrundy(0,l),l2(getGrundy(1,l),getGrundy(2,l)));
			vector<l3> nwbase=base;
			nwbase.erase(nwbase.begin());
			nwbase.pb(tuple);
			if(mp.count(nwbase)!=0){
				index=l;
				base=nwbase;
				break;
			}else{						
				mp[nwbase]=l;
				base=nwbase;
			}
		}
		period=index-mp[base];
		init=mp[base]-4;
		ll xorsum=0;
		fore(i,0,n)cin >> arr[i],xorsum^=gg(0,arr[i]);
		int cnt=0;
		ll attack[3];
		attack[0]=x,attack[1]=y,attack[2]=z;
		fore(i,0,n){
			fore(j,0,3){
				ll newval=max((ll)0,arr[i]-attack[j]);
				if((gg(j,newval)^gg(0,arr[i])^xorsum)==0)cnt++;
			}
		}
		cout << cnt<<"\n";
	}
    return 0;
}
