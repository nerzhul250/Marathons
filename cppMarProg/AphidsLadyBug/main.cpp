#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
ll ini=0;
ll fin=((1LL)<<60);
vector<ll> esq,dir,val;
ll it;

void update(ll pos,ll left,ll right,ll x,ll delta){
	val[pos] += delta;
	if(left == right) return;
	ll mid = (left+right)/2;
	if(x <= mid){
		if(esq[pos] == -1){
			esq[pos] = ++it;
			esq.push_back(-1);
			dir.push_back(-1);
			val.push_back(0);
		}
		update(esq[pos],left,mid,x,delta);
	}
	else{
		if(dir[pos] == -1){
			dir[pos] = ++it;
			esq.push_back(-1);
			dir.push_back(-1);
			val.push_back(0);
		}
		update(dir[pos],mid+1,right,x,delta);
	}
}
ll query(ll pos,ll left,ll right,ll i,ll j){
	if(left > right || left > j || right < i) return 0;
	if(left >= i && right <= j){
		return val[pos];
	}
	ll mid = (left+right)/2;
	ll sinistra = (esq[pos] == -1) ? 0 : query(esq[pos],left,mid,i,j);
	ll destra = (dir[pos] == -1) ? 0 : query(dir[pos],mid+1,right,i,j);
	return sinistra + destra;
}

int Q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> Q;
    ll A,V,L=0;
    esq.push_back(-1);
	dir.push_back(-1);
	val.push_back(0);
    fore(i,0,Q){
        cin >> A>>V;
        ll firstInteger=A^L;
        ll randomNumber=V^L;
        update(0,ini,fin,firstInteger,randomNumber);
        ll secondInteger=query(0,ini,fin,0,firstInteger);
        cout << firstInteger << " "<<secondInteger<<"\n";
        L=secondInteger;
    }
    return 0;
}