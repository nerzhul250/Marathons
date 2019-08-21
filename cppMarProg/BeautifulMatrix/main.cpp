#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int flag=1;
    for(int i=0;i<5 && flag;i++){
        for(int j=0;j<5 && flag;j++){
            int num;
            cin >> num;
            if(num==1){
                cout << abs(2-i)+abs(2-j) << "\n";
                flag=0;
            }
        }
    }
}
