#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for(auto it = l.begin(); it!= l.end(); it++)
#define fore(i,a,b) for(ll i=a, almo5t=b; i<almo5t; ++i)
#define SZ(x) ((int)x.size())
#define EPS 1e-9
#define PI cos(-1);
#define MOD 1000000007
#define FIN std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;

using namespace std;

int main(){ FIN;
#ifndef ONLINE_JUDGE
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif

int n;cin>>n;int a[n];
fore(i,0,n){
    cin>>a[i];
}
int ans = 0;
fore(i,1,101){
    bool yey = true;
    fore(j,0,n){
        int b = a[j];
        int xd = b*i;
        // cout<<xd<<"/";
        xd/=100;
        int xd1=round((double)xd*100/(double)i);
        int xd2=round((double)min(xd+1,100)*100/(double)i);
        if(b!=xd1 && b!=xd2){
            yey=false;
        }
    }
    if(yey){
        ans = i;break;
    }

}
    cout<<ans;

}
