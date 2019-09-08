#include <iostream>

using namespace std;
int adjMatrix[26][26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        int p;
        cin >> n;
        cin >> p;

        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                adjMatrix[i][j]=0;
            }
        }

        if(n%2==0){
            for(int i=0;i<n;i+=2){
                adjMatrix[i+1][((i+2)%n)+1]=1;
                adjMatrix[((i+2)%n)+1][i+1]=1;
                cout << i+1 << " " << ((i+2)%n)+1 << "\n";
            }
            for(int i=1;i<n;i+=2){
                adjMatrix[((i+2)%n)+1][i+1]=1;
                adjMatrix[i+1][((i+2)%n)+1]=1;
                cout << i+1 << " " << ((i+2)%n)+1 << "\n";
            }
            for(int i=0;i<n;i++){
                adjMatrix[i+1][((i+1)%n)+1]=1;
                adjMatrix[((i+1)%n)+1][i+1]=1;
                cout << i+1 << " " << ((i+1)%n)+1 << "\n";
            }
        }else{
            for(int i=0;i<n*2;i+=2){
                adjMatrix[((i)%n)+1][((i+2)%n)+1]=1;
                adjMatrix[((i+2)%n)+1][((i)%n)+1]=1;
                cout << ((i)%n)+1 << " " << ((i+2)%n)+1 << "\n";
            }
            for(int i=0;i<n;i++){
                adjMatrix[i+1][((i+1)%n)+1]=1;
                adjMatrix[((i+1)%n)+1][i+1]=1;
                cout << i+1 << " " << ((i+1)%n)+1 << "\n";
            }
        }
        int sum=0;
        for(int i=1;i<n && sum<p;i++){
            for(int j=i+1;j<=n && sum<p;j++){
                if(adjMatrix[i][j]==0){
                    cout << i << " " << j << "\n";
                    sum++;
                }
            }
        }
    }
    return 0;
}
