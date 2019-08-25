#include <iostream>

using namespace std;
int n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >>m ;
    int x=0,y=m;
    cout << min(n,m)+1 << "\n";
    for(int i=0;i<min(n,m)+1;i++){
        cout << x << " " << y << "\n";
        x++;
        y--;
    }
}
