#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <math.h>


using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
const int INF=10000000;

vector<pair<int,ii> > AdjList [105];
int father[105],realFather[105];
int N,E,S,T,X,Y;
double R,D;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> N){
        cin >> E;
        cin >> S >> T;
        S--;
        T--;
        int maxTemp=-1000000;
        int minTemp=1000000;
        for(int k=0;k<N;k++){AdjList[k].clear();}
        for(int i=0;i<E;i++){
            cin >> X >> Y >> R >> D;
            X--;
            Y--;
            int tempC=round(R*10.0);
            int length=round(D*10.0);
            if(tempC>maxTemp)maxTemp=tempC;
            if(tempC<minTemp)minTemp=tempC;
            AdjList[X].push_back(make_pair(Y,ii(length,tempC)));
            AdjList[Y].push_back(make_pair(X,ii(length,tempC)));
        }
        int i=minTemp;
        int j=maxTemp;
        int distance=0,temperature=0;

        while(i<=j){
            int midTemp=(i+j)/2;

            vi dist(N, INF); dist[S] = 0; // INF = 1B to avoid overflow
            priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,S));
            while (!pq.empty()) { // main loop
            ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d > dist[u]) continue; // this is a ve ry important check
            for (int k = 0; k < (int)AdjList[u].size(); k++) {
            pair<int,ii> v = AdjList[u][k]; // all outgoing edges from u
            if ((v.second.second<=midTemp) && (dist[u] + v.second.first < dist[v.first])) {
            dist[v.first] = dist[u] + v.second.first; // relax operation
            pq.push(ii(dist[v.first], v.first));
            father[v.first]=u;
            }}} // this variant can cause duplicate items in the priority queue

            if(dist[T]==INF){
                i=midTemp+1;
            }else{
                temperature=midTemp;
                distance=dist[T];
                for(int k=0;k<N;k++){realFather[k]=father[k];}
                j=midTemp-1;
            }
        }

        vi pila;
        int currentNode=T;
        while(currentNode!=S){
            pila.push_back(currentNode);
            if(currentNode==realFather[currentNode])break;
            currentNode=realFather[currentNode];
        }
        pila.push_back(currentNode);

        for(int m=pila.size()-1;m>=0;m--){
            if(m==0){
                cout << pila[m]+1 << "\n";
            }else{
                cout << pila[m]+1 << " ";
            }
        }

       cout << (distance/10)<<"."<<distance-(distance/10)*10<<" "<<(temperature/10)<<"."<<temperature-(temperature/10)*10<<"\n";

    }
    return 0;
}
