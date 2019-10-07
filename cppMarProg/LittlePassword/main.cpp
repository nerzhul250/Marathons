#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

struct state {
    int len, link, numOfTransitions=0;
    int next[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
};

const int MAXLEN = 100000;
state st[MAXLEN * 2];
int dp[MAXLEN * 2+5];
int sz, last;

void sa_init() {
    for(int i=0;i<MAXLEN*2;i++){
        st[i]=state();
        dp[i]=0;
    }
    sz=0;

    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void sa_extend(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && st[p].next[c]==-1) {
        st[p].next[c] = cur;
        st[p].numOfTransitions++;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            copy(begin(st[q].next), end(st[q].next),begin(st[clone].next));
            st[clone].link = st[q].link;
            st[clone].numOfTransitions=st[q].numOfTransitions;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int d(int v){
    if(dp[v]!=0)return dp[v];
    if(st[v].numOfTransitions!=st[0].numOfTransitions)return dp[v]= 1;
    int minimum=1e9;
    for(int i=0;i<=9;i++){
        if(st[v].next[i]!=-1)minimum=min(minimum,d(st[v].next[i]));
    }
    return dp[v]=minimum+1;
}


void getAns(int v,int c){
    if(c!=-1)cout << c;
    if(dp[v]==1){
        for(int i=0;i<=9;i++){
             if(st[0].next[i]!=-1 &&st[v].next[i]==-1){
                cout << i;
                return ;
            }
        }
    }
    for(int i=0;i<=9;i++){
        if(st[v].next[i]!=-1 && dp[st[v].next[i]]==dp[v]-1){
            getAns(st[v].next[i],i);
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        string S;
        cin >> S;
        sa_init();
        for(int i=0;i<N;i++){
            sa_extend(S[i]-'0');
        }
        cout << d(0) << " ";
        getAns(0,-1);
        cout << "\n";
    }
    return 0;
}
