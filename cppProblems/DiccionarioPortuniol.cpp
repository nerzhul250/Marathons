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

struct vertex {
	map<char,int> next;
	int p;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch){}
};
void aho_init(vector<vertex> &t){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, int id,vector<vertex> &t){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
vector<vertex> pref;
vector<vertex> suff;
void countEndings(vertex v,vector<ll> &endings,vector<vertex> &t){
	for(auto it=v.next.begin();it!=v.next.end();it++){
		endings[it->ff-'a']++;
		countEndings(t[it->ss],endings,t);
	}
}

int main(){FIN;
	int P,S;	
	while(cin >> P >> S){
		if(P==0 && S==0)break;
		aho_init(pref);
		aho_init(suff);
		fore(i,0,P){
			string s;
			cin >> s;
			add_string(s,i,pref);
		}
		fore(i,0,S){
			string s;
			cin >> s;
			reverse(ALL(s));
			add_string(s,i,suff);
		}
		vector<ll> prefEnd(30,0),suffEnd(30,0);
		for(auto it=pref[0].next.begin();it!=pref[0].next.end();it++){
			countEndings(pref[it->ss],prefEnd,pref);
		}
		for(auto it=suff[0].next.begin();it!=suff[0].next.end();it++){
			countEndings(suff[it->ss],suffEnd,suff);
		}
		ll total=1;
		total*=(suff.size()-1);
		total*=(pref.size()-1);
		ll toSubstract=0;
		fore(i,0,26)toSubstract+=(prefEnd[i]*suffEnd[i]);
		cout << total-toSubstract<<"\n";
	}
    return 0;
}
