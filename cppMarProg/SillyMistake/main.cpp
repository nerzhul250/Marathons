#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;

ll arr[100005],freq[1000005];
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
    fore(i,0,n)cin >> arr[i];
    ll days=0;
    vector<ll> cuentas;
    ll cnt=0;
    ll totalSum=0;
    set<int> occu;
    fore(i,0,n){
        totalSum+=arr[i];
        cnt++;
        if(arr[i]<0){
            freq[-arr[i]]--;
            if(freq[-arr[i]]<0){
                days=-1;
                cuentas.clear();
                break;
            }
        }else{
            freq[arr[i]]++;
            if(freq[arr[i]]>1 || occu.find(arr[i])!=occu.end()){
                days=-1;
                cuentas.clear();
                break;
            }
            occu.insert(arr[i]);
        }
        if(totalSum==0){
            days++;
            occu.clear();
            cuentas.pb(cnt);
            cnt=0;
        }
    }
    if(totalSum!=0){
        days=-1;
        cuentas.clear();
    }
    cout << days<<endl;
    fore(i,0,cuentas.size()){
        if(i==cuentas.size()-1){
            cout <<cuentas[i]<<"\n";
        }else{
            cout <<cuentas[i]<<" ";
        }
    }
    return 0;
}
