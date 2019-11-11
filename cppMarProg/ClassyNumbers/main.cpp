#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;

int comb[50][50];

int getComb(int n, int k){
    if(n<0 || k<0 ||k>n)return 0;
    if(n==k){
        return 1;
    }else if(k==0){
        return 1;
    }
    if(comb[n][k]!=0)return comb[n][k];
    return comb[n][k]=getComb(n-1,k-1)+getComb(n-1,k);
}

int compute(ll N){
    string theNum=to_string(N);
    int k=0;
    int ans=0;
    for(int d=0;d<theNum.size();d++){
        int D=theNum[d]-'0';
        int x=theNum.size()-d-1;
        if(D!=0){
            for(int i=0;i<=3-k;i++){
                ans+=getComb(x,i)*pow(9,i);
            }
            for(int i=0;i<=2-k;i++){
                ans+=getComb(x,i)*pow(9,i)*(D-1);
            }
        }
        if(D!=0)k++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int T;
    cin >> T;
    while(T--){
        ll L,R;
        cin >>L>>R;
        cout << compute(R+1)-compute(L)<<endl;
    }
}
