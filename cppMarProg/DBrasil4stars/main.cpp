#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int cont = 0;
    while(n--){
        int door;
        cin>>door;
        if (door != 1)
            cont++;
    }

    cout<<cont;

}
