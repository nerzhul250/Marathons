#include <iostream>
using namespace std;
int dig[10]={1,1,2,6,4,2,2,4,2,8};

int lnd(int n){
    if(n<10)return dig[n];
    if(((n/10)%10)%2==0){
        return (6*lnd(n/5)*dig[n%10])%10;
    }else{
        return (4*lnd(n/5)*dig[n%10])%10;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tb[4][4]={{4,8,2,6},{8,6,4,2},{2,4,6,8},{6,2,8,4}};
    int n,m;
    while(cin >> n){
        cin >> m;
        if(m==0){
            cout << "1\n";
        }else if(m==n){
            cout << lnd(n)<<"\n";
        }else{
            int a=lnd(n);
            int b=lnd(n-m);
            b=(b/2)-1;
            for(int i=0;i<4;i++){
                if(tb[b][i]==a){
                    cout << (i+1)*2 << "\n";
                }
            }
        }
    }
    return 0;
}
