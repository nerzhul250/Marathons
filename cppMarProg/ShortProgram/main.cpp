#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
int theOps[15];
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

    for(int j=0;j<15;j++)theOps[j]=2;
    for(int i=0;i<n;i++){
        char op;
        int x;
        cin >> op;
        cin >> x;
        if(op=='|'){
            for(int j=0;j<10;j++){
                if((x>>j)%2==1){
                    theOps[j]=1;
                }
            }
        }else if(op=='^'){
            for(int j=0;j<10;j++){
                if((x>>j)%2==1){
                    if(theOps[j]==0){
                        theOps[j]=1;
                    }else if(theOps[j]==1){
                        theOps[j]=0;
                    }else if(theOps[j]==2){
                        theOps[j]=-2;
                    }else if(theOps[j]==-2){
                        theOps[j]=2;
                    }
                }
            }
        }else if(op=='&'){
            for(int j=0;j<10;j++){
                if((x>>j)%2==0){
                    theOps[j]=0;
                }
            }
        }
    }
    int guay=(1<<10)-1;
    int ors=0;
    int xors=0;
    for(int j=0;j<10;j++){
        if(theOps[j]==1){
            ors=ors|(1<<j);
        }else if(theOps[j]==0){
            guay=guay^(1<<j);
        }else if(theOps[j]==-2){
            xors=xors|(1<<j);
        }
    }
    int cnt=(ors!=0)+(guay!=(1<<10)-1)+(xors!=0);
    cout << cnt<<"\n";
    if(ors!=0)cout << "| "<<ors<<"\n";
    if(guay!=((1<<10)-1))cout << "& "<<guay<<"\n";
    if(xors!=0)cout << "^ "<<xors <<"\n";
    return 0;
}
