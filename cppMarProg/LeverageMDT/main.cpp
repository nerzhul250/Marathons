#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int N,M,acumulado[1005][1005];
char theKingdom[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    cin >> N>>M;
    fore(i,0,N){
        fore(j,0,M){
            char c;
            cin >> c;
            theKingdom[i][j]=c;
        }
    }

    fore(i,0,N){
        int init=0;
        fore(j,1,M+1){
            if(j==M ||theKingdom[i][j-1]!=theKingdom[i][j]){
                fore(m,init,j){
                    acumulado[i][m]=j-m;
                }
                init=j;
            }
        }
    }

    int theMaximum=1;
    int left=1,right=min(N,M);
    while(left<=right){
        int mid=(left+right)/2;
        int maximo=0;
        fore(i,0,M){
            int cnt=0;
            fore(j,0,N){
                if(acumulado[j][i]>=mid){
                    cnt++;
                    maximo=max(cnt,maximo);
                }else{
                    cnt=0;
                }
            }
        }

        if(maximo>=mid){
            left=mid+1;
            theMaximum=mid;
        }else{
            right=mid-1;
        }
    }

    cout << theMaximum*theMaximum << endl;

    return 0;
}
