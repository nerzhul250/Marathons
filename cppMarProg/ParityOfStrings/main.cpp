#include <iostream>

using namespace std;
int counting[30];
string word;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> word;
    for(int i=0;i<word.size();i++){
        counting[word[i]-'a']++;
    }
    int decide=counting[word[0]-'a'];
    if(decide%2==0){
        decide=1;
        for(int i=0;i<26;i++){
            if(counting[i]!=0&&counting[i]%2!=0){
                decide=0;
                break;
            }
        }
        if(decide){
            cout << "0\n";
        }else{
            cout <<"2\n";
        }
    }else{
        decide=1;
        for(int i=0;i<26;i++){
            if(counting[i]!=0&&counting[i]%2!=1){
                decide=0;
                break;
            }
        }
        if(decide){
            cout << "1\n";
        }else{
            cout <<"2\n";
        }
    }
    return 0;
}
