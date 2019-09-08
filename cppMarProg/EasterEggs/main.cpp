#include <iostream>

using namespace std;
int n;
string let[]={"R","O","Y","G","B","I","V"};
string ans[]={"","G","YG","OYG","ROYG","ROYGB","ROYGBI"};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int q=n/7;
    int r=n%7;
    for(int i=0;i<7*q;i++){
        cout << let[i%7];
    }
    cout << ans[r] << "\n";
    return 0;
}
