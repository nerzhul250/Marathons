#include <iostream>
#include <vector>
#include <utility>
#include <fstream>


using namespace std;

typedef long long ll;
const ll INF=1e15;

ll AdjMat[55][55];
vector<pair<ll,pair<int,int> > > someList;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream myfile;
    myfile.open ("sol.txt");
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N,M;
        cin >> N >> M;
        someList.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                AdjMat[i][j]=INF;
            }
        }
        for(int i=0;i<M;i++){
            int a,b,w;
            cin >> a >> b >> w;
            a--;
            b--;
            AdjMat[a][b]=w;
            AdjMat[b][a]=w;
            someList.push_back(make_pair(w,make_pair(a,b)));
        }

        for (int k = 0; k < N; k++) // remember that loop order is k->i->j
          for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
              AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        bool possible=true;
        for(int i=0;i<M && possible;i++){
            int u=someList[i].second.first;
            int v=someList[i].second.second;
            ll weight=someList[i].first;
            if(AdjMat[u][v]!=weight){
                possible=false;
            }
        }
         myfile << "Case #"<<t<<": ";
        if(possible){
             myfile << M << "\n";
            for(int i=0;i<M;i++){
                int u=someList[i].second.first;
                int v=someList[i].second.second;
                ll weight=someList[i].first;
                 myfile << u+1 << " " << v+1 << " " << weight << "\n";
            }
        }else{
             myfile << "Impossible\n";
        }
    }
    myfile.close();
    return 0;
}
