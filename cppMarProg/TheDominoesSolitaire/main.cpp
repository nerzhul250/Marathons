#include <iostream>

using namespace std;
typedef pair<int,int> ii;
ii dominoes[20];
bool existence[20],found;
int n,m;

void possible(int prev,int total){
    if(total==n && (dominoes[prev].second==dominoes[1].first))found=true;
    for(int i=2;i<m+2 && !found;i++){
        if(!existence[i] && (dominoes[i].first==dominoes[prev].second ||dominoes[i].second==dominoes[prev].second)){
            existence[i]=true;
            if(dominoes[i].second==dominoes[prev].second){
                dominoes[i]=ii(dominoes[i].second,dominoes[i].first);
            }
            possible(i,total+1);
            existence[i]=false;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n){
        cin >> m;
        int a,b;
        found=false;
        for(int i=0;i<m+2;i++){
            cin >> a >> b;
            dominoes[i]=ii(a,b);
            existence[i]=false;
        }
        possible(0,0);
        if(found){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        cin >> n;
    }
    return 0;
}
