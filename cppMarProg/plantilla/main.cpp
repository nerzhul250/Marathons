#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int divers[10005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,R;
    cin >> N >> R;
    fore(i,0,R){
        int a;
        cin >> a;
        divers[a]=1;
    }
    if(N==R){
        cout << "*\n";
    }else{
        fore(i,1,N+1){
            if(!divers[i]){
                if(i==N){
                    cout << i<<"\n";
                }else{
                    cout << i<<" ";
                }
            }
        }
    }
}
