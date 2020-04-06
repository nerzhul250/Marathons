#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};

struct sensor{
	int x,y,s;
};

int M,N,K;
sensor sensors[1005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M>>N>>K;
	fore(i,0,K){
		int x,y,s;
		cin >> sensors[i].x >> sensors[i].y >> sensors[i].s;
	}
	
	UnionFind uf(K+4);
	
	fore(i,0,K){
		sensor s1=sensors[i];
		fore(j,i+1,K){
			sensor s2=sensors[j];
			if(hypot(s1.x-s2.x,s1.y-s2.y)<=s1.s+s2.s)uf.unionSet(i,j);
		}
		if(s1.x<=s1.s)uf.unionSet(i,K);
		if(s1.y+s1.s>=N)uf.unionSet(i,K+1);
		if(s1.x+s1.s>=M)uf.unionSet(i,K+2);
		if(s1.y<=s1.s)uf.unionSet(i,K+3);
	}
	if(uf.isSameSet(K+1,K+2)||uf.isSameSet(K+1,K+3)||
	uf.isSameSet(K,K+2)||uf.isSameSet(K,K+3)){
		cout << "N\n";
	}else{
		cout << "S\n";
	}
	
	
    return 0;
}
