#include <iostream>

using namespace std;
string a,b;
int dp[1005][1005];
int possible(int ia,int ib){

    if(ia>=0 && ia<a.length() && ib>=0 && ib<b.length() && dp[ia][ib]!=-1)return dp[ia][ib];

    int res=0;

    if(ia==a.length() && ib==b.length()){
        res=1;
    }else if(ia==a.length()){
        res=0;
    }else if(ib==b.length()){
        if(a[ia]>='A' && a[ia]<='Z'){
            res=0;
        }else{
            res=possible(ia+1,ib);
        }
    }else if(a[ia]>='a' && a[ia]<='z'){
        if(toupper(a[ia])==b[ib]){
           res=possible(ia+1,ib+1) | possible(ia+1,ib);
        }else{
            res=possible(ia+1,ib);
        }
    }else{
        if(a[ia]==b[ib]){
            res=possible(ia+1,ib+1);
        }else{
            res=0;
        }
    }

    return dp[ia][ib]=res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        cin >> a >> b;
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                dp[i][j]=-1;
            }
        }
        int p=possible(0,0);
        if(p){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
