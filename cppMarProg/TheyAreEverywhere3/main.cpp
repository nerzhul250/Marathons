#include <iostream>

using namespace std;
typedef long long int ll;
int n,freq[52];
string pokemons;
ll mask;

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
        ll add=((ll)1)<<letToNum(pokemons[i]);
        mask=mask|add;
    }

    ll currentMask=0;
    int smallestInterval=100000000;
    int i=0,j=0;
    while(j<n){
        if(currentMask==mask){
            if(j-i<smallestInterval)smallestInterval=j-i;
            if(freq[letToNum(pokemons[i])]==1)currentMask=(currentMask^(((ll)1)<<letToNum(pokemons[i])));
            freq[letToNum(pokemons[i])]--;
            i++;
        }else{
            freq[letToNum(pokemons[j])]++;
            currentMask=currentMask|(((ll)1)<<letToNum(pokemons[j]));
            j++;
        }
        if(j==n){
            while(currentMask==mask){
                if(j-i<smallestInterval)smallestInterval=j-i;
                if(freq[letToNum(pokemons[i])]==1)currentMask=(currentMask^(((ll)1)<<letToNum(pokemons[i])));
                freq[letToNum(pokemons[i])]--;
                i++;
            }
        }
    }
    cout << smallestInterval << "\n";
    return 0;
}
