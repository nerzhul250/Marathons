#include <iostream>

using namespace std;
int AdjMat[105][105];
const int INF=1000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,B;
    cin >> N >> B;
    while(!(N==0 && B==0)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j)AdjMat[i][j]=0;
                if(i!=j)AdjMat[i][j]=INF;
            }
        }
        for(int i=0;i<B;i++){
            int a,b,c;
            cin >> a >> b >> c;
            a--;
            b--;
            AdjMat[a][b]=c;
            AdjMat[b][a]=-c;
        }
        for (int k = 0; k < N; k++) // remember that loop order is k->i->j
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
        int found=0;
        for(int i=0;i<N;i++){
            if(AdjMat[i][i]<0){
                found=1;
                cout << "Y" << endl;
                break;
            }
        }
        if(!found)cout << "N" << endl;
        cin >> N >> B;
    }
    return 0;
}
