#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
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

    if(n%3==0){
        int k=n/3;
        if(k%3!=0){
            cout << k << " "<<k<<" "<<k<<"\n";
        }else{
            cout<<k-1<<" "<<k+2<<" "<<k-1<<"\n";
        }
    }else if(n%3==1){
        int k=n/3;
        if(k%3!=0){
            cout << "1"<<" "<<2*k<<" "<<k<<"\n";
        }else{
            cout <<"1"<<" "<<k+2<<" "<<(k-1)*2<<"\n";
        }
    }else{
        int k=n/3;
        if(k%3!=0){
            cout << "2 "<<2*k<<" "<<k<<"\n";
        }else{
            cout << "2 "<<k+2<<" "<<(k-1)*2<<"\n";
        }
    }
}
