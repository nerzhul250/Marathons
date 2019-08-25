#include <iostream>
#include <algorithm>

using namespace std;
string weighting;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int selector=0;
    for(int i=0;i<3;i++){
        cin >> weighting;
        int a,b,c;
        a=weighting[0]-'A';
        b=weighting[1]=='<'?0:1;
        c=weighting[2]-'A';
        if(a>c){
            b=1-b;
            swap(a,c);
        }
        if(a==0 && c==1){
            selector+=(b*(1<<2));
        }else if(a==0 && c==2){
            selector+=(b*(1<<1));
        }else{
            selector+=(b*(1<<0));
        }
    }
    switch(selector){
        case 0:
            cout << "ABC\n";
            break;
        case 1:
            cout << "ACB\n";
            break;
        case 2:
            cout << "Impossible\n";
            break;
        case 3:
            cout << "CAB";
            break;
        case 4:
            cout << "BAC\n";
            break;
        case 5:
            cout << "Impossible\n";
            break;
        case 6:
            cout << "BCA";
            break;
        case 7:
            cout << "CBA\n";
            break;
    }
}
