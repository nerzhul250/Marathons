#include <iostream>
#include <string>
using namespace std;

int digToStick[10]={6,2,5,5,4,5,6,4,7,6};

int getSticks(int n){
    string s=to_string(n);
    int nam=0;
    for(int i=0;i<s.size();i++){
        nam+=digToStick[s[i]-'0'];
    }
    return nam;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int n=1;n<=100;n++){
        for(int i=1;true;i++){
            int countSticks=getSticks(i);
            if(countSticks>n){
                cout << n << " " << i << " " << countSticks << endl;
                break;
            }
        }
    }
    return 0;
}
