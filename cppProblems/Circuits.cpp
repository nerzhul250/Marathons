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

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

struct Rectangle{
	int y1,y2,id;
	Rectangle(int y1,int y2,int id):y1(y1),y2(y2),id(id){}
	Rectangle(){}
};
Rectangle rectangles[100005];
int arr[200005];
int main(){FIN;
	int n;
	cin >> n;
	vector<iii> line;
	fore(i,0,n){
		int x1,y1,x2,y2;
		cin >> x2 >> y2 >> x1 >> y1;
		Rectangle re(y1,y2,i);
		rectangles[i]=re;
		line.pb(iii(y1,ii(0,i)));
		line.pb(iii(y2+1,ii(1,i)));
	}
	sort(ALL(line));
	int interRec=0;
	int index=0;
	map<int,int> coorToIndex;
	fore(i,0,line.size()){
		if(i!=0 && line[i-1].ff!=line[i].ff){
			arr[index]=interRec;
			index++;
		}
		if(line[i].ss.ff==0){
			interRec++;
		}else if(line[i].ss.ff==1){
			interRec--;
		}
		coorToIndex[line[i].ff]=index;
	}
	arr[index]=interRec;
	index++;
	
	n=index;
	STree rmq(index);
	rmq.init(arr);
	
	int maximo=0;
	index=0;
	fore(i,0,line.size()){
		if(i!=0 && line[i-1].ff!=line[i].ff){
			maximo=max(maximo,arr[index]+rmq.query(0,n));
			index++;
		}
		int id=line[i].ss.ss;		
		int left=coorToIndex[rectangles[id].y1];
		int right=coorToIndex[rectangles[id].y2+1];
		if(line[i].ss.ff==0){
			rmq.upd(left,right,-1);
		}else if(line[i].ss.ff==1){
			rmq.upd(left,right,1);
		}
	}
	maximo=max(maximo,arr[index]+rmq.query(0,n));
	cout << maximo << "\n";
    return 0;
}
