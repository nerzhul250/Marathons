#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef long long int ll;

const int MAX_N=1045;
int N,permutation[MAX_N],matrix[MAX_N][MAX_N];
ll R;
void fillMatrix(){
    int j=1;
    for (int i=1;i<=N;i++){
        j=0;
        do{
            j++;
            matrix[i][j]=permutation[matrix[i][j-1]];
        }while(matrix[i][j]!=matrix[i][0]);
        matrix[i][MAX_N-1]=j;
    }
}
int main()
{
    //ifstream inFile;
    //inFile.open("tests.txt");
    //scanf("%d %lld",&N,&R) scanf("%d",&permutation[i]);
    while(cin >> N >> R){
        for (int i=1;i<=N;i++){
            cin >> permutation[i];
            matrix[i][0]=i;
        }
        fillMatrix();
        string s;
        for (int i=1;i<=N;i++){
            ll t=matrix[i][MAX_N-1];
            ll m=(R%t);
            if(i!=N){
                s+=to_string(matrix[i][m])+" ";
            }else{
                s+=to_string(matrix[i][m]);
            }
        }
        cout << s << endl;
    }
    return 0;
}
