#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
int n,elements[1000005],counterOfCumulus[100005];
vector<int> globes;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int flag=0;
    for(int i=0;i<=60;i++){
         ll selector=((ll)1)<<i;
         int numberOfe=0;
         for(int i=0;i<n;i++){
            if((elements[i]&selector)!=0){
                numberOfe++;
                counter[i]++;
            }
         }
         if(numberOfe>1){
            globes.push_back(numberOfe)
         }else{
             for(int i=0;i<n;i++){
                if((elements[i]&selector)!=0){
                    counter[i]--;
                }
            }
         }
         if(numberOfe>=3){
            flag=1;
         }
    }
    if(flag){
        cout << "3\n";
    }else if(globes.size()<=2){
        cout << "-1\n";
    }else{
        flag=1;
        for(int i=0;i<n;i++){
            if(counter%2)
        }
    }
    return 0;
}
