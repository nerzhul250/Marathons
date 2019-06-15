#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> aes;
int found;
void f(int val, int j,int i){
    if(!found){
        if(j==0){
            val=val+aes[i];
        }else if(j==1){
            val=val-aes[i];
        }else{
            val=val*aes[i];
        }
        if(i==4){
            if(val==23)found=1;
        }else{
            for(int k=0;k<3;k++){
                f(val,k,i+1);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    aes.assign(5,0);
    cin >> aes[0];
    cin >> aes[1];
    cin >> aes[2];
    cin >> aes[3];
    cin >> aes[4];
    while(!(aes[0]==0 &&aes[1]==0 &&aes[2]==0 &&aes[3]==0 &&aes[4]==0)){
        sort(aes.begin(),aes.end());
        found=0;
        do{
            f(0,0,0);
            if(found){
                cout << "Possible" << endl;
                break;
            }
        }while(next_permutation(aes.begin(),aes.end()));
        if(!found)cout << "Impossible" << endl;
        cin >> aes[0];
        cin >> aes[1];
        cin >> aes[2];
        cin >> aes[3];
        cin >> aes[4];
    }
    return 0;
}
