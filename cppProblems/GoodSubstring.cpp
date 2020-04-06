#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

struct state {
    int len, link;
    map<char, int> next;
};
const int MAXLEN = 1505;
state st[MAXLEN * 2];
int sz, last;
void sa_init() {
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
	last=cur;
}


int K;
int bad[30];
int dp[MAXLEN * 2][1505];

int go(int estado,int letrasMalas){
	if(dp[estado][letrasMalas]!=-1)return dp[estado][letrasMalas];
	if(letrasMalas>K)return -1;
	auto it=st[estado].next.begin();
	int theNam=0;
	while(it!=st[estado].next.end()){
		int let=(it->first)-'a';
		if(!bad[let]){
			theNam+=go(it->second,letrasMalas+1)+1;	
		}else{
			theNam+=go(it->second,letrasMalas)+1;
		}
		it++;
	}
	return dp[estado][letrasMalas]=theNam;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string bads;
    cin >> bads;
    cin >> K;
    sa_init();
    fore(i,0,s.size())sa_extend(s[i]);
	fore(i,0,bads.size())bad[i]=bads[i]-'0';
	memset(dp,-1,sizeof dp);
    cout << go(0,0)<<"\n";
    return 0;
}
