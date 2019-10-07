#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vi match, vis; // global variables
vi AdjList [205];
//NORMAL AUGMENTING PATH ALGORITHM V*E
int Aug(int l) { // return 1 if an augmenting path is found
if (vis[l]) return 0; // return 0 otherwise
vis[l] = 1;
for (int j = 0; j < (int)AdjList[l].size(); j++) {
int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList
if (match[r] == -1 || Aug(match[r])) {
match[r] = l; match[l]=r; return 1; // found 1 matching
} }
return 0; // no matching
}


int main()
{
     ofstream myfile;
     ifstream myfile2;
     myfile.open ("example.txt");
     myfile2.open("openthis.in");
    int T;
    int orr;
    myfile2 >> T;
    cout << T << endl;
    orr=T;
    while(T--){
        int n,k;
        myfile2 >> n >> k;
        cout << "HERE "<< n << " "<<k<<"\n";
        int info[n+5][k+5];
        for(int i=0;i<n;i++){
            AdjList[i].clear();
            for(int j=0;j<k;j++){
                myfile2 >> info[i][j];
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                bool isBigger=true;
                for(int l=0;l<k && isBigger;l++){
                    if(info[i][l]<=info[j][l])isBigger=false;
                }
                bool isSmaller=true;
                for(int l=0;l<k && isSmaller;l++){
                    if(info[i][l]>=info[j][l])isSmaller=false;
                }
                if(isBigger){
                    AdjList[i].push_back(j+n);
                    AdjList[j+n].push_back(i);
                }else if(isSmaller){
                    AdjList[j].push_back(i+n);
                    AdjList[i+n].push_back(j);
                }
            }
        }
        match.assign(n*2,-1);
        for(int i=0;i<n;i++){
            vis.assign(n*2,0);
            Aug(i);
        }
        int countPaths=0;
        for(int i=0;i<n;i++){
            if(match[i]==-1){
                countPaths++;
            }
        }
        myfile << "Case #"<<orr-T<<": "<<countPaths <<"\n";
    }
     myfile.close();
     myfile2.close();
    return 0;
}
