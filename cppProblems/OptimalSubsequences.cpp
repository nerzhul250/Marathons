#include <bits/stdc++.h>
#include <ext/rope>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
using namespace __gnu_cxx;
struct query{
	int k,pos,q;
	bool operator<(const query &q2){
		return k<q2.k;
	}
};
bool cmp(const int &v1,const int &v2){
	return v1>v2;
}
map<int,rope<int>> e2i;
int n,m,org[200005];
int main(){FIN;
	cin >> n;
	vector<int> seq(n);
	fore(i,0,n){
		cin >> seq[i];
		e2i[seq[i]].pb(i);
		org[i]=seq[i];
	}
	sort(ALL(seq));
	reverse(ALL(seq));
	cin >> m;
	vector<query> queries(m);
	fore(i,0,m){
		query q;
		cin >> q.k >> q.pos;
		q.k--;
		q.pos--;
		q.q=i;
		queries[i]=q;
	}
	sort(ALL(queries));
	int ans[m];
	rope<int>currSeq;
	int currk=-1;
	fore(q,0,queries.size()){
		int k=queries[q].k;
		int pos=queries[q].pos;
		while(currk<k){
			currk++;
			rope<int> &r=e2i[seq[currk]];
			auto it=upper_bound(ALL(currSeq),r[0]);
			if(it==currSeq.end()){
				currSeq.pb(r[r.size()-1]);
				r.erase(r.size()-1,1);
			}else{
				int e=*it;
				auto it2=upper_bound(r.rbegin(),r.rend(),e,cmp);
				currSeq.insert(it-currSeq.begin(),*it2);
				r.erase(next(it2).base()-r.begin(),1);
			}
		}
		ans[queries[q].q]=org[currSeq[pos]];
	}
	fore(i,0,m){
		cout << ans[i]<<"\n";
	}
    return 0;
}
