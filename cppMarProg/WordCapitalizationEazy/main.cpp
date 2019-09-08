#include <iostream>

using namespace std;
string word;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin,word);
    for(int i=0;i<word.size();i++){
        if(i==0){
            cout << (char)toupper(word[i]);
        }else if(i==word.size()-1){
            cout << word[i]<<"\n";
        }else{
            cout << word[i];
        }
    }
    return 0;
}
