#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
vector<int> real;
ii adj[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n!=0){
        for(int i=0;i<n;i++){
            string val;
            int go;
            int binary;
            cin >> go >> val;
            go--;
            if(val=="false"){
                binary=0;
            }else{
                binary=1;
            }
            adj[i]=ii(go,binary);
        }
        int isParadox=0;
        for(int i=0;i<n && !isParadox;i++){
            real.assign(105,-1);
            real[i]=1;
            int currentNode=i;
            while(real[adj[currentNode].first]==-1){
                real[adj[currentNode].first]=(real[currentNode]^adj[currentNode].second)?0:1;
                currentNode=adj[currentNode].first;
            }
            int inferred=(real[currentNode]^adj[currentNode].second)?0:1;
            int originalValue=real[adj[currentNode].first];
            if(originalValue!=inferred){
                cout << "PARADOX" << endl;
                isParadox=1;
            }
        }
        if(!isParadox)cout << "NOT PARADOX" << endl;
        cin >> n;
    }
    return 0;
}
