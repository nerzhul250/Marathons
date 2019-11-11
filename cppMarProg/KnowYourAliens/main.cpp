#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    string aliens;
    cin >> aliens;
    vector<vector<ll>>polinomials;
    fore(i,1,aliens.size()){
        if(aliens[i]!=aliens[i-1]){
            ll root=i*2+1;
            vector<ll> po;
            po.pb(1);
            po.pb(-root);
            polinomials.pb(po);
        }
    }

    int D=polinomials.size();
    cout << D<<endl;

    if(D==0){
        if(aliens[0]=='A'){
            cout << "-1\n";
        }else{
            cout << "1\n";
        }
        return 0;
    }


    fore(i,1,polinomials.size()){
        polinomials[0].pb(0);
        for(int j=polinomials[0].size()-1;j>0;j--){
            polinomials[0][j]+=polinomials[0][j-1]*polinomials[i][1];
        }
    }

    int multiply=1;

    if(D%2==0){
        if(aliens[0]=='A'){
            multiply=-1;
        }
    }else{
        if(aliens[0]=='H'){
            multiply=-1;
        }
    }

    fore(i,0,polinomials[0].size()){
        if(i==polinomials[0].size()-1){
            cout << multiply*polinomials[0][i] << endl;
        }else{
            cout << multiply*polinomials[0][i] << " ";
        }
    }
    return 0;
}
