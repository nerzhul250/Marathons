#include <iostream>

using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cin >> n;
    int counter=0;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(x+y+z>=2){
            counter++;
        }
    }
    cout << counter << "\n";
}
