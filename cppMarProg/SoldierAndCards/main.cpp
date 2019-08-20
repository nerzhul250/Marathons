#include <iostream>
#include <unordered_set>
#include <string.h>
#include <vector>

using namespace std;

int n,k1,k2;
vector<int> deck1,deck2;
unordered_set<string> states;

string stateToString(){
    string encoded="";
    for(int i=0;i<deck1.size();i++){
        encoded=encoded+","+to_string(deck1[i]);
    }
    encoded=encoded+"|";
    for(int i=0;i<deck2.size();i++){
        encoded=encoded+","+to_string(deck2[i]);
    }
    return encoded;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> k1;
    for(int i=0;i<k1;i++){
        int nam;
        cin >> nam;
        deck1.push_back(nam);
    }
    cin >> k2;
    for(int i=0;i<k2;i++){
        int nam;
        cin >> nam;
        deck2.push_back(nam);
    }
    int flag=1;
    int gameCounter=0;
    while(flag){
        gameCounter++;
        if(deck1[0]>deck2[0]){
            deck1.push_back(deck2[0]);
            deck2.erase(deck2.begin());
            deck1.push_back(deck1[0]);
            deck1.erase(deck1.begin());
        }else{
            deck2.push_back(deck1[0]);
            deck1.erase(deck1.begin());
            deck2.push_back(deck2[0]);
            deck2.erase(deck2.begin());
        }
        string encodedState=stateToString();
        if(states.find(encodedState)!=states.end()){
            cout << "-1\n";
            flag=0;
        }else{
            states.insert(encodedState);
            if(deck1.size()==0){
                cout << gameCounter << " 2\n";
                flag=0;
            }else if(deck2.size()==0){
                cout << gameCounter << " 1\n";
                flag=0;
            }
        }
    }
}
