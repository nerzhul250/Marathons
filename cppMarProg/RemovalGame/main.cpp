#include <bits/stdc++.h>

#define push_back pb
#define make_pair mp
#define first ff
#define second ss
#define forn(i,n) for(i=0;i<n;i++)

using namespace std;
int N,arr[105],dp[105][105];
int gcd(int a,int b){return a==0?b:gcd(b%a,a);}

int minRemoval(int a,int b){
    if((a+1)%N==b)return 0;
    if((a+2)%N==b){
        return gcd(arr[a],arr[b]);
    }
    int &r=dp[a][b];
    if(r!=-1)return r;
    int i=(a+1)%N;
    int minimum=1e6;
    while(i!=b){
        minimum=min(minimum,gcd(arr[a],arr[b])+minRemoval(a,i)+minRemoval(i,b));
        i=(i+1)%N;
    }
    return r=minimum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
        freopen("input.txt","r",stdin);
    #else
        #define endl '\n'
    #endif

    while(cin >> N){
        if(N==0)break;
        int i,j;
        forn(i,N)cin >> arr[i];
        forn(i,N){
            forn(j,N){
                dp[i][j]=-1;
            }
        }
        int minimum=1e6;
        forn(i,N){
            forn(j,N){
                if(i<j){
                    minimum=min(minimum,gcd(arr[i],arr[j])+minRemoval(i,j)+minRemoval(j,i));
                }
            }
        }
        cout << minimum << endl;
    }
    return 0;
}
