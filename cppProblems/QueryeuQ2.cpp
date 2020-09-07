#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;

struct palindromic_tree{
    static const int SIGMA=26;
    struct Node{
        int len, link, to[SIGMA];
        ll palindromes;
        ll cnt;
        Node(int len, int link=0, ll cnt=1, ll palindromes=0):len(len),link(link),cnt(cnt),palindromes(palindromes){
            memset(to,0,sizeof(to));
        }
    };
    vector<Node> ns;
    vector<int> last;
    ll totalPalindromes;
    palindromic_tree():totalPalindromes(0){ns.pb(Node(-1));ns.pb(Node(0));last.pb(0);}
    void add(int i, string &s){
        int p=last.back(), c=s[i]-'a';
        while(s[i-ns[p].len-1]!=s[i])p=ns[p].link;
        if(ns[p].to[c]){
            last.pb(ns[p].to[c]);
            ns[last.back()].cnt++;
            totalPalindromes+=ns[last.back()].palindromes;
        }else{
            int q=ns[p].link;
            while(s[i-ns[q].len-1]!=s[i])q=ns[q].link;
            q=max(1,ns[q].to[c]);
            ns[p].to[c]=SZ(ns);
            last.pb(ns[p].to[c]);
            ns.pb(Node(ns[p].len+2,q,1,1+ns[q].palindromes));
            totalPalindromes+=ns[last.back()].palindromes;
        }
    }
    void rem(){
		totalPalindromes-=ns[last.back()].palindromes;
		last.pop_back();
		return ;
	}
};


int main(){FIN;	
	int Q;
	cin >> Q;
	string T="";
	string S;
	cin >> S;
	palindromic_tree pt;
	fore(q,0,Q){
		if(S[q]=='-'){
			pt.rem();
			T.pop_back();
			cout << pt.totalPalindromes<<" ";
		}else{
			T+=S[q];
			pt.add(T.size()-1,T);
			cout << pt.totalPalindromes<<" ";
		}
	}
	cout << "\n";
    return 0;
}
