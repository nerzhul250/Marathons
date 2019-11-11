#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;
int const MAXN=300005;
int As[MAXN],Bs[MAXN],preA[MAXN],preB[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    fore(i,0,n){
        if(s[i]=='A'){
            As[i]=1;
        }else{
            Bs[i]=1;
        }
    }

    preA[0]=As[0];
    preB[0]=Bs[0];
    fore(i,1,n){
        preA[i]=preA[i-1]+As[i];
        preB[i]=preB[i-1]+Bs[i];
    }
    ll ans=0;
    fore(i,0,n){
        if(s[i]=='A'){
            auto j=upper_bound(preA+i,preA+n,preA[i]);
            ans+=(j-(preA+i)-1);
        }else{
            auto j=upper_bound(preB+i,preB+n,preB[i]);
            ans+=(j-(preB+i)-1);
        }
    }
    preA[0]=As[n-1];
    preB[0]=Bs[n-1];
    fore(i,1,n){
        preA[i]=preA[i-1]+As[n-i-1];
        preB[i]=preB[i-1]+Bs[n-i-1];
    }

    fore(i,0,n){
        if(s[n-i-1]=='A'){
            auto j=upper_bound(preA+i,preA+n,preA[i]);
            ans+=(max(j-(preA+i)-2,0));
        }else{
            auto j=upper_bound(preB+i,preB+n,preB[i]);
            ans+=(max(j-(preB+i)-2,0));
        }
    }

    ll maximo=n;
    maximo=(maximo-1)*maximo/2;
    cout << maximo-ans<<endl;

}
