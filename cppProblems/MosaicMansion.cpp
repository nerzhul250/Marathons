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
typedef pair<ll,ll> ii;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

ll const p1=31;
ll const p2=53;
ll const mod=1e9 + 9;
int n,m,c;
ii rowHashes[45];
vector<ii> goodHashes;
ii firstHalf[(1<<20)+5];
unordered_map<ii,int,hash_pair> mp;
ii addH(ii h1,ii h2){
	return {(h1.ff+h2.ff)%mod,(h1.ss+h2.ss)%mod};
}
ii subH(ii h1,ii h2){
	return {(h1.ff-h2.ff+mod)%mod,(h1.ss-h2.ss+mod)%mod};
}
int main(){FIN;
	cin >> n >> m >> c;
	fore(i,0,n){
		ii theHash={0,0};
		vector<int>freq(c,0);
		fore(j,0,m){
			int c;
			cin >> c;
			c--;
			freq[c]++;
		}
		fore(j,0,c){
			theHash.ff=(theHash.ff*p1+freq[j])%mod;
			theHash.ss=(theHash.ss*p2+freq[j])%mod;			
		}
		rowHashes[i]=theHash;
	}
	fore(mask,0,(1<<(n/2))){
		ii setMask={0,0};
		fore(i,0,n/2){
			if((mask&(1<<i))!=0){
				setMask=addH(setMask,rowHashes[i]);
			}
		}
		firstHalf[mask]=setMask;
	}
	fore(mask,0,(1<<(n-(n/2)))){
		ii setMask={0,0};
		fore(i,0,n-(n/2)){
			if((mask&(1<<i))!=0){
				setMask=addH(setMask,rowHashes[i+(n/2)]);
			}
		}
		mp[setMask]=mask;
	}
	
	fore(i,0,n+1){
		if(i*m%c==0){
			ii theGoodHash={0,0};
			fore(j,0,c){
				theGoodHash.ff=(theGoodHash.ff*p1+((i*m)/c))%mod;
				theGoodHash.ss=(theGoodHash.ss*p2+((i*m)/c))%mod;
			}
			goodHashes.pb(theGoodHash);
		}
	}
	int maximo=0;
	fore(mask,0,(1<<(n/2))){
		for(ii gh:goodHashes){
			ii toLook=subH(gh,firstHalf[mask]);
			if(mp.count(toLook)){
				maximo=max(maximo,__builtin_popcount(mask)+__builtin_popcount(mp[toLook]));
			}
		}
	}
	cout << maximo << "\n";
    return 0;
}
