#include <iostream>
#include <vector>

using namespace std;
int n, existence[20],prime[50];
void f(int index,vector<int>&numbers){
    for(int i=1;i<=n;i++){
        if(!existence[i]&&prime[numbers[index-1]+i]){
            if(index==n){
                if(prime[numbers[1]+i]){
                    numbers[index]=i;
                    for(int k=1;k<=n;k++){
                        if(k==n){
                            cout << numbers[k]<<endl;
                        }else{
                            cout << numbers[k]<<" ";
                        }
                    }
                }
            }else{
              existence[i]=1;
              numbers[index]=i;
              f(index+1,numbers);
              existence[i]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    existence[1]=1;
    prime[2]=1;
    prime[3]=1;
    prime[5]=1;
    prime[7]=1;
    prime[11]=1;
    prime[13]=1;
    prime[17]=1;
    prime[19]=1;
    prime[23]=1;
    prime[29]=1;
    prime[31]=1;
    prime[37]=1;
    vector<int> numbers;
    numbers.assign(20,1);
    int t=0;
    cin >> n;
    while(n){
        t++;
        cout << "Case " <<t <<":"<<endl;
        f(2,numbers);
        if(cin>>n){
            cout << endl;
        }else{
            break;
        }
    }
    return 0;
}
