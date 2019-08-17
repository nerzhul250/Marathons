#include <iostream>
#include <algorithm>

using namespace std;

int n,s,baseCosts[100005],realCosts[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;

    for(int i=0;i<n;i++){
        cin >> baseCosts[i];
    }

    int init=1,fin=n;
    int maxNumber=0;
    int minimumCost=0;
    while(init<=fin){
        int k=(init+fin)/2;
        for(int i=0;i<n;i++){
            realCosts[i]=baseCosts[i]+(i+1)*k;
        }
        sort(realCosts,realCosts+n);
        int sum=0,index=0;
        while(sum<=s && index<k){
            sum+=realCosts[index];
            index++;
        }
        if(sum<=s){
            init=k+1;
            maxNumber=k;
            minimumCost=sum;
        }else{
            fin=k-1;
        }
    }

    cout << maxNumber << " "<<minimumCost<<"\n";

    return 0;
}
