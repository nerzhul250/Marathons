#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    int q = 0;
    cin >> n;
    cin >> q;

    int theArray [n];
    for (int i = 0; i < n; i++){
        cin >> theArray[i];
    }

    sort(theArray, theArray + n);

    for (int i = 0; i < q; i++){
        int actQ = 0;
        cin >> actQ;
        ll totSubs = 0;
        int li = 0;
        int ri = n-1;
        for(int j=ri;j>0;j--){
            while(li<j && theArray[li]+theArray[j]<=actQ){
                li++;
            }
            totSubs+=min(li,j);
        }
        cout << totSubs << "\n";
    }

    return 0;
}
