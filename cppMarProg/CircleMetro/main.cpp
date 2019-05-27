#include <iostream>

using namespace std;

int main()
{
    int n,a,x,b,y;
    cin >> n >> a >> x >> b >> y;
    int meet=0;
    while(!meet){
        if(a==b)meet=1;
        if(a==x || b==y)break;
        if(a<n){a++;}else{a=1;}
        if(b>1){b--;}else{b=n;}
    }
    if(meet){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
