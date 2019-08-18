#include <iostream>

typedef long long int ll;

using namespace std;

int n,arrayA[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)cin >> arrayA[i];
    int zeroCounter=0,negativeCounter=0,positiveCounter=0;
    ll minimumCost=0;
    for(int i=0;i<n;i++){
        if(arrayA[i]<0){
            minimumCost+=(-1-arrayA[i]);
            negativeCounter++;
        }else if(arrayA[i]>0){
            minimumCost+=(-1+arrayA[i]);
            positiveCounter++;
        }else{
            zeroCounter++;
        }
    }
    int residium=negativeCounter%2;
    if(residium==1){
        if(zeroCounter>0){
            minimumCost+=zeroCounter;
        }else{
            minimumCost+=2;
        }
    }else{
        minimumCost+=zeroCounter;
    }

    cout << minimumCost << "\n";
    return 0;
}
