#include <iostream>
#include <math.h>

using namespace std;

typedef long long int ll;

ll n,k;
int computePowerOfTwo(){
    int counter=0;
    ll current=k;
    while(current%2==0){
        counter++;
        current/=2;
    }
    return counter;
}
string getLetter(int x){
    return (x==0?"A":(x==1?"B":"C"));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >>n){
        cin >> k;
        if(log2(k)>=n){
            cout << "Orz\n";
        }else{
            int p=computePowerOfTwo();
            ll level=n-p;
            int a=0,b=1,c=2;
            if(level%2==0){
                swap(b,c);
            }
            ll current=k;
            while(current%2==0){
                current/=2;
            }
            current-=1;
            current/=2;
            if(current%3==0){
            }else if(current%3==1){
                int tempa=a;
                a=b;
                b=c;
                c=tempa;
            }else{
                int tempa=a;
                a=c;
                c=b;
                b=tempa;
            }
            cout << "move " <<p+1 << " from " << getLetter(a) << " to " << getLetter(b)<<"\n";
        }
    }
    return 0;
}
