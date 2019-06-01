#include <iostream>
#include <map>
#include <sstream>

using namespace std;
int N,ino[105],pre[105];
map<int,int> nodeToIndex;
void tree(int i,int j,int k,int l){
    if(i<=j && k<=l){
        tree(i,nodeToIndex[pre[k]]-1,k+1,l-(j-nodeToIndex[pre[k]]));
        tree(nodeToIndex[pre[k]]+1,j,k+1+(nodeToIndex[pre[k]]-i),l);
        cout <<pre[k]<<" ";
    }
}
int main()
{
    int N=0;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> ino[N])
    {
        nodeToIndex[ino[N]]=N;
        N++;
    }
    N=0;
    getline(cin, line);
    istringstream is(line);
    while(is >> pre[N]){
        N++;
    }
    tree(0,N-1,0,N-1);
    return 0;
    /*
            std::string line;
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            int a, b;
            if (!(iss >> a >> b)) { break; } // error

            // process pair (a,b)
        }
    */
}
