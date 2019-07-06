#include <iostream>

using namespace std;
string word;
int i;

int slump(){
    if(!(word[i]=='D' || word[i]=='E'))return 0;
    i++;
    while(word[i]=='F')i++;
    if(word[i]=='G'){i++;return 1;}
    return slump();
}

int slimp(){
    if(word[i]!='A')return 0;
    i++;
    if(word[i]=='H'){i++;return 1;}
    if(word[i]=='B'){
        i++;
        return slimp() && word[i++]=='C';
    }
    return slump() && word[i++]=='C';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << "SLURPYS OUTPUT\n";
    while(n--){
        cin >> word;
        i=0;
        int p= slimp() && slump() && i==word.length();
        if(p){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
