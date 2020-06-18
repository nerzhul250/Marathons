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
const int MAXN=200005;
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
ll arr[MAXN];
ll freq[1000005];
ll currAns=0;
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void add(int index){
	currAns-=freq[arr[index]]*freq[arr[index]]*arr[index];
	freq[arr[index]]++;
	currAns+=freq[arr[index]]*freq[arr[index]]*arr[index];
}
void remove(int index){
	currAns-=freq[arr[index]]*freq[arr[index]]*arr[index];
	freq[arr[index]]--;
	currAns+=freq[arr[index]]*freq[arr[index]]*arr[index];
}
ll get_ans(){
	return currAns;
}
void mos(){
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}

int main(){FIN;
	cin >> n >> nq;
	fore(i,0,n)cin >> arr[i]; 
	fore(i,0,nq){
		int l,r;
		cin >> l >> r;
		l--;
		qs[i].id=i;
		qs[i].l=l;
		qs[i].r=r;
	}
	mos();
	fore(i,0,nq){
		cout << ans[i]<<"\n";
	}
    return 0;
}
