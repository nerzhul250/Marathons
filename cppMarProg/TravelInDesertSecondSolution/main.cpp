#include <bits/stdc++.h>
#include <math.h>

using namespace std;


const long long inf = 1e12;

struct edge {
  int to;
  int temp,len;
  bool operator < (const edge & o) const {
    if (temp == o.temp)
      return len > o.len;
    return temp > o.temp;
  }
};


int my_cmp(const edge &a, const edge &b) {
  if (a < b) return 1; // greater
  if (b < a) return -1;
  return 0;
}

void printPath(int node, vector<edge> &best,int &dis,int &temp){
    if(node!=1)printPath(realFather[node]);
    if(node==1){
        cout << 1;
    }else{
        cout << " " << node;
    }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, E;
  while(cin >> N){
    cin >> E;
    int S,T;
    cin >> S >> T;
    S--;
    T--;
    int X,Y;
    double R,D;
    vector<vector<edge>> g(N);
    for(int i=0;i<E;i++){
        cin >> X >> Y >> R >> D;
        X--;
        Y--;
        int tempC=round(R*10.0);
        int length=round(D*10.0);
        g[X].push_back({Y, tempC, length});
        g[Y].push_back({X, tempC, length});
    }

      priority_queue<edge> q;
      q.push({0, 0, 0});

      vector<edge> best(n, {0, inf, inf});
      best[0] = {0, 0, 0};

      while (!q.empty()) {
        auto s = q.top();
        q.pop();

        int node = s.to;

        if (my_cmp(s, best[node]) == 1) continue;

        for (auto e : g[node]) {
          int to = e.to;
          edge extra = {to,e.temp,s.len+e.len};
          edge extra2 = {node,e.temp,s.len+e.len};
          if (my_cmp(extra, best[to]) == -1) {
            best[to] = extra2;
            q.push(extra);
          }
        }
      }

      int distance=0,temp=-1;

      printPath(T,best,distance,temp);

      cout <<"\n";
      cout << (distance/10)<<"."<<distance-(distance/10)*10<<" "<<(temperature/10)<<"."<<temperature-(temperature/10)*10<<"\n";
  }

  return 0;
}
