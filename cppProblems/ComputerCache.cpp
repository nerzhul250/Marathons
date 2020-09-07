#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
struct LPSTree{
	vector<bool> hasflag; // if node has a flag (sometimes, you can omit this)
	vector<int> flag;     // the actual value of the flag
	vector<int> st,l,r;
	vector<int> treeVersion;
	int n;
	int newparent(int lson,int rson){
		int p=st.size();
		l.pb(lson);
		r.pb(rson);
		flag.pb(0);
		hasflag.pb(false);
		st.pb((st[lson]+st[rson])%256);
		return p;
	}
	int new_node(int v){
		int p=st.size();
		l.pb(-1);
		r.pb(-1);
		flag.pb(0);
		hasflag.pb(false);
		st.pb(v);
		return p;
	}
	int init(int L, int R, vector<int> &a){
		if(L==R)return new_node(a[L]);
		int M=(L+R)/2,lson=init(L,M,a),rson=init(M+1,R,a);
		return newparent(lson,rson);
	}
	LPSTree(vector<int> &a){
		n=a.size();
		int root=init(0,n-1,a);
		treeVersion.pb(root);
	}
	// returns a new node with a lazy flag
	int newlazykid(int node, int delta, int L, int R) {
		int p = st.size();
		l.pb(l[node]);
		r.pb(r[node]);
		flag.pb(flag[node]); // need this since lazy kid might be lazy before
		hasflag.pb(true);
		/* range increase */
		flag[p] += delta;
		st.pb((st[node] + (R - L + 1) * delta)%256);
		return p;
	}
	void propagate(int p, int L, int R) {
		if (hasflag[p]) {
			if (L != R) { // spread the laziness
				int M=(L+R)/2;
				int newval=newlazykid(l[p], flag[p], L, M);
				l[p]=newval;
				newval=newlazykid(r[p], flag[p], M + 1, R);
				r[p] =newval;
			}
			// reset flag
			hasflag[p] = false;
			flag[p]=0;
		}
		return ;
	}
	// range update on [a:b] with value x, on the tree rooted at p
	int update(int a, int b, int x, int p, int L, int R) {
		if (b < L || R < a) return p;
		if (a <= L && R <= b)return newlazykid(p, x, L, R);
		propagate(p, L, R); // always do this before going down
		int M=(L+R)/2;
		int np=newparent(update(a, b, x, l[p] , L, M),
						 update(a, b, x, r[p] , M + 1, R));
		return np;
	}
	// range query on [a:b], on the tree rooted at p
	int query(int a, int b, int p, int L, int R) {
		if (b < L || R < a)   return 0;
		if (a <= L && R <= b) return st[p];
		propagate(p, L, R); // always do this before going down
		int M=(L+R)/2;
		return (query(a, b, l[p], L, M) + query(a, b, r[p], M + 1, R))%256;
	}
	int update(int a,int b,int x,int version){
		int newRoot=update(a,b,x,treeVersion[version],0,n-1);
		treeVersion.pb(newRoot);
		return newRoot;
	}
	int query(int a,int b, int version){
		return query(a,b,treeVersion[version],0,n-1);
	}
};
struct STree { // example: range sum with range addition
	vector<iii> st,lazy;
	int n;
	STree(int n): st(4*n+5,{-1,{-1,-1}}), lazy(4*n+5,{-1,{-1,-1}}), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k].ff==-1)return; // if neutral, nothing to do
		st[k]=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k].ff=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, iii v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		if(st[2*k]==st[2*k+1]){
			st[k]=st[2*k];
		}else{
			st[k].ff=-1;
		}
	}
	iii query(int k,int s,int e,int p){
		if(p<s || p>=e)return {-1,{-1,-1}}; // operation neutral
		push(k,s,e);
		if(s+1==e)return st[k];
		int m=(s+e)/2;
		iii left=query(2*k,s,m,p),right=query(2*k+1,m,e,p);
		if(left.ff==-1){
			return right;
		}else{
			return left;
		}
	}
	void upd(int a, int b, iii v){upd(1,0,n,a,b,v);}
	iii query(int p){return query(1,0,n,p);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int n,m,Q;
int S[500005],treeStart[500005];
int main(){FIN;
	cin >> n >> m >> Q;
	STree cache(n);
	vector<int> a;
	fore(i,0,m){
		cin >> S[i];
		if(i)treeStart[i]=treeStart[i-1]+S[i-1];
		fore(j,0,S[i]){
			int nam;
			cin >> nam;
			a.pb(nam);
		}
	}
	LPSTree dataTree(a);
	fore(q,0,Q){
		int type;
		cin >> type;
		if(type==1){
			int data,pos;
			cin >> data >> pos;
			data--;
			pos--;
			iii v={data,{pos,dataTree.treeVersion.size()-1}};
			cache.upd(pos,pos+S[data],v);
		}else if(type==2){
			int pos;
			cin >> pos;
			pos--;
			iii v=cache.query(pos);
			if(v.ff==-1){
				cout << "0\n";
			}else{
				int relativeDataPos=pos-v.ss.ff;
				int byteTreePos=relativeDataPos+treeStart[v.ff];
				cout << dataTree.query(byteTreePos,byteTreePos,v.ss.ss)<<"\n";
			}
		}else if(type==3){
			int data,l,r;
			cin >> data >> l >> r;
			data--;
			l--;
			r--;
			int ltree=l+treeStart[data];
			int rtree=r+treeStart[data];
			dataTree.update(ltree,rtree,1,dataTree.treeVersion.size()-1);
		}
	}
    return 0;
}
