#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

struct STree { // segment tree for min over integers
	vector<vector<int>> st;int n;
	STree(int n): st(4*n+5,vector<int>(26,0)), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){
			fore(i,0,26)st[k][i]=0;
			st[k][v]=1;
			return;
		}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		fore(i,0,26)st[k][i]=st[2*k][i]+st[2*k+1][i];
	}
	vector<int> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return vector<int> (26,0);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		vector<int> ans(26,0),ql=query(2*k,s,m,a,b),qr=query(2*k+1,m,e,a,b);
		fore(i,0,26)ans[i]=ql[i]+qr[i];
		return ans;
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){
		vector<int> ans=query(1,0,n,a,b);
		int diff=0;
		fore(i,0,26)if(ans[i]>0)diff++;
		return diff;
	}
	void init(string s){
		fore(i,0,s.size()){
			upd(i,s[i]-'a');
		}
		return ;
	}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){FIN;
	string s;
	cin >> s;
	STree st(s.size());
	st.init(s);
	int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type==1){
			int pos;
			char c;
			cin >> pos >> c;
			st.upd(pos-1,c-'a');
		}else if(type==2){
			int l,r;
			cin >> l >> r;
			l--;
			cout << st.query(l,r)<<"\n";
		}
	}
    return 0;
}
