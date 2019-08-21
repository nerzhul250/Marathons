#include <iostream>
#include <string.h>
using namespace std;

string numerote;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> numerote;
    int counter=0;
    while(numerote.size()>1){
        int suma=0;
        for(int i=0;i<numerote.size();i++){
            suma+=(numerote[i]-'0');
        }
        numerote=to_string(suma);
        counter++;
    }
    cout << counter << "\n";
}
