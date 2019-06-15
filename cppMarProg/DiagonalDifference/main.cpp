#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            arr[i][j]=x;
        }
    }
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;i++){
        sum1+=arr[i][i];
        sum2+=arr[i][n-i-1];
    }
    cout << abs(sum1-sum2);
    return 0;
}
