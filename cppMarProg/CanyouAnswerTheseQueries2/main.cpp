#include <iostream>

using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll>> pl;

ll const INF=1e15;
ll arr[50005], mint[200005], maxt[200005], best[200005];
void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        mint[v]=(tl==0?0:a[tl-1]);
        maxt[v]=a[tl];
        best[v]=(tl==0?a[tl]:a[tl]-a[tl-1]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        mint[v]=min(mint[v*2],mint[v*2+1]);
        maxt[v]=max(maxt[v*2],maxt[v*2+1]);
        best[v]=max(max(best[v*2],best[v*2+1]),maxt[v*2+1]-mint[v*2]);
    }
}
pl get(int v, int tl, int tr, int x,int y) {
    if(tl>y || tr<x)return {-INF,{INF,-INF}};
    if(tl>=x && tr<=y){
        return {best[v],{mint[v],maxt[v]}};
    }else{
        int tm=(tl+tr)/2;
        pl left = get(v*2,tl,tm,x,y);
        pl right = get(v*2+1,tm+1,tr,x,y);
        return {max(max(left.first,right.first),right.second.second-left.second.first),
        {min(left.second.first,right.second.first),max(left.second.second,right.second.second)}};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,n;
    cin >> n;
    for(int i=0;i<n;i++)cin >> arr[i];
    for(int i=1;i<n;i++)arr[i]+=arr[i-1];
    build(arr,1,0,n-1);
    cin >> M;
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        cout << get(1,0,n-1,x,y).first << "\n";
    }
    return 0;
}
