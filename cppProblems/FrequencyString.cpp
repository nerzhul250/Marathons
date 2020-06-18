#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef pair<int,int> ii;

struct vertex {
	map<char,int> next,go;
	int p,link,leafLink;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1),leafLink(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, int id){
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
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int get_leafLink(int v){
	if(t[v].leafLink<0){
		if(!v||!t[v].p){
			t[v].leafLink=0;
		}else{
			if(t[get_link(v)].leaf.size()>0){
				t[v].leafLink=get_link(v);
			}else{
				t[v].leafLink=get_leafLink(get_link(v));
			}
		}
	}
	return t[v].leafLink;
}
int go(int v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}

int main(){FIN;
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<ii> queries;
	aho_init();
	fore(i,0,n){
		string m;
		int k;
		cin >> k >> m;
		queries.pb(ii(k,m.size()));
		add_string(m,i);
	}
	int curr=0;
	vector<int> positions[n+5];
	fore(i,0,s.size()){
		curr=go(curr,s[i]);
		int currLeaf=curr;
		while(currLeaf!=0){
			for(int id : t[currLeaf].leaf){
				positions[id].pb(i);
			}
			currLeaf=get_leafLink(currLeaf);
		}
	}
	fore(i,0,n){
		if(positions[i].size()>=queries[i].ff){
			int k=queries[i].ff;
			int minimum=1e9;
			fore(j,0,positions[i].size()-k+1){
				minimum=min(minimum,positions[i][j+k-1]-positions[i][j]);
			}
			cout << minimum+queries[i].ss<<"\n";
		}else{
			cout <<"-1\n";
		}
	}
    return 0;
}
