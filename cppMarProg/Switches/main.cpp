#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int N,M;
int state[1005];
int xs[1005][1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N>>M;
    int L;
    cin >> L;
    fore(i,0,L){
        int tmp;
        cin >> tmp;
        tmp--;
        state[tmp]++;
    }
    fore(i,0,N){
        int k;
        cin >> k;
        fore(j,0,k){
            int tmp;
            cin >> tmp;
            tmp--;
            xs[i][tmp]++;
        }
    }
    int steps=0;
    int sum=0;
    fore(i,0,N){
        sum=0;
        steps++;
        fore(j,0,M){
            state[j]^=xs[i][j];
            sum+=state[j];
        }
        if(sum==0){
            break;
        }
    }
    if(sum!=0){
        fore(i,0,N-1){
            sum=0;
            steps++;
            fore(j,0,M){
                state[j]^=xs[i][j];
                sum+=state[j];
            }
            if(sum==0){
                break;
            }
        }
    }
    if(sum==0){
        cout << steps<<"\n";
    }else{
        cout <<"-1\n";
    }
}
