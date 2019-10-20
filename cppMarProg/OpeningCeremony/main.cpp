#include <iostream>
#include <unordered_map>

#define forn(n,x) for(int i=x;i<n;i++)

using namespace std;

int heightAcum[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    forn(N,0){
        int h;
        cin >> h;
        heightAcum[h]++;
    }
    int minimo=2e6;
    for(int i=0;i<=1e6;i++){
        heightAcum[i+1]+=heightAcum[i];
        minimo=min(minimo,i+N-heightAcum[i]);
    }
    cout << minimo << "\n";
    return 0;
}
