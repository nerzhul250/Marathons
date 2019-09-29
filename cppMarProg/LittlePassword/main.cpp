#include <iostream>
#include <map>
#include <string.h>
#include <string>
using namespace std;

struct state {
    int len, link;
    map<char, int> next;
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

void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].next.count(c)) {
        st[p].next[c] = cur;
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
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
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
    if(st[v].next.size()!=st[0].next.size())return dp[v]= 1;
    int minimum=1e9;
    for(map<char,int> :: iterator it=st[v].next.begin();it!=st[v].next.end();it++){
        minimum=min(minimum,d(it->second));
    }
    return dp[v]=minimum+1;
}


void getAns(int v,char c){
    if(c!='.')cout << c;
    if(dp[v]==1){
        for(map<char,int> :: iterator it=st[0].next.begin();it!=st[0].next.end();it++){
             if(st[v].next.find(it->first)==st[v].next.end()){
                cout << it->first;
                return ;
            }
        }
    }
    for(map<char,int> :: iterator it=st[v].next.begin();it!=st[v].next.end();it++){
        if(dp[it->second]==dp[v]-1){
            getAns(it->second,it->first);
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
            sa_extend(S[i]);
        }
        cout << d(0) << " ";
        getAns(0,'.');
        cout << "\n";
    }
    return 0;
}
