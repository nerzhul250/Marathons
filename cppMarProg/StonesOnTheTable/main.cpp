#include <iostream>

using namespace std;
string cad;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >>n ;
    cin >> cad;
    int counter=1;
    char let=cad[0];
    int sum=0;
    for(int i=1;i<n;i++){
        if(cad[i]==let){
            counter++;
        }else{
            sum+=counter-1;
            counter=1;
            let=cad[i];
        }
    }
    sum+=counter-1;
    cout << sum << "\n";
    return 0;
}
