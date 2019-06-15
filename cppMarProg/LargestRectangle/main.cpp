#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

const int MAXN=100005,K=log2(MAXN);
int arr[MAXN], st[MAXN][K], logs[MAXN+1],N;

ll maxArea(int i,int j){
    if(i==j)return arr[i];
    if(i<0 || j<0 || j>=N || i>=N || i>j)return -1;
    int L=i;
    int R=j;
    int k = logs[R - L + 1];
    ll minHeight = min(st[L][k], st[R - (1 << k) + 1][k]);
    int index=0;
    for(int l=i;l<=j;l++){
        if(arr[l]==minHeight){
            index=l;
            break;
        }
    }
    return max(maxArea(i,index-1),max(maxArea(index+1,j),(j-i+1)*minHeight));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    logs[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        logs[i] = logs[i/2] + 1;


    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    cout << maxArea(0,N-1)<<"\n";


    return 0;
}
