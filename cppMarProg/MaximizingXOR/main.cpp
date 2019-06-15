#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r;
    cin >> l >> r;
    int maxVal=-1;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){
            if((i^j)>maxVal)maxVal=(i^j);
        }
    }
    cout << maxVal << endl;
    return 0;
}
