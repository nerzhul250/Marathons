#include <iostream>

using namespace std;
string word;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> word;
    for(int i=0;i<word.size();i++){
        cout << word[i];
    }
    for(int i=word.size()-1;i>=0;i--){
        cout << word[i];
    }
    cout << "\n";

    return 0;
}
