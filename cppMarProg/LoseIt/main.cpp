#include <iostream>

using namespace std;
int buff[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,num;
    cin >> n;
    num=n;
    while(n--){
        int x;
        cin >> x;
        if(x==4){
            buff[1]++;
        }else if(x==8){
            if(buff[1]>0){
                buff[1]--;
                buff[2]++;
            }
        }else if(x==15){
            if(buff[2]>0){
                buff[2]--;
                buff[3]++;
            }
        }else if(x==16){
            if(buff[3]>0){
                buff[3]--;
                buff[4]++;
            }
        }else if(x==23){
            if(buff[4]>0){
                buff[4]--;
                buff[5]++;
            }
        }else if(x==42){
            if(buff[5]>0){
                buff[5]--;
                buff[6]++;
            }
        }
    }
    cout << num-6*buff[6]<< endl;
    return 0;
}
