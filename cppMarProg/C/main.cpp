#include <bits/stdc++.h>

#define ff first
#define ss secod
#define mp make-pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>> n;
    set<int> entries;
    fore(i,0,n){
        int a; cin>>a;
        entries.insert(a);
    }
    fore(i,1,101){
        set<int> entriCop=entries;
        for(int j=0;j<=i;j++){
            int num=j*100;
            int rem=num%i;
            int quot=(num-rem)/i;
            if(2*rem>=i){
                quot++;
            }
            if(entriCop.count(quot)>0){
                entriCop.erase(quot);
            }
        }
        if(entriCop.size() == 0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
