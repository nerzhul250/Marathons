#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string enc; cin>> enc;
    string crib; cin>>crib;
    vector<bool> pickedPos(enc.size());

    map<char,vector<int>> cribPos;
    fore(i,0,crib.size()){
        cribPos[crib[i]].pb(i);
    }
    fore(i,0,enc.size()){
        if(cribPos.find(enc[i]) != cribPos.end()){
            vector<int> p = cribPos[enc[i]];
            for(int n : p){
                if(i - n>= 0){
                   // cout<<i<<" "<<i-n <<" "<<n<<endl;
                    pickedPos[i -n] = true;
                }
            }

        }
    }
    int cant = 0;
    fore(i,0,enc.size()){
        if(crib.size()+ i > enc.size()) break;
          //cout<<i<<" "<<pickedPos[i]<<endl;
        if(!pickedPos[i]){
          cant++;
        }
    }
    cout<<cant<<endl;

}
