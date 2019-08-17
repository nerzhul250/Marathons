#include <iostream>

using namespace std;
int n,freq[60],freq1[60];
string pokemons;
int letToNum(char let){
    if(let>='a'){
        return let-'a';
    }else{
        return let-'A'+26;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> pokemons;
    for(int i=0;i<pokemons.size();i++){
        freq[letToNum(pokemons[i])]++;
        freq1[letToNum(pokemons[i])]++;
    }
    int i=0,j=n-1;
    while(freq[letToNum(pokemons[i])]!=1){
        freq[letToNum(pokemons[i])]--;
        i++;
    }
    int oneAns=j-i+1;
    i=0;j=n-1;
    while(freq1[letToNum(pokemons[j])]!=1){
        freq1[letToNum(pokemons[j])]--;
        j--;
    }
    int twoAns=j-i+1;
    cout << min(oneAns,twoAns) << "\n";
}
