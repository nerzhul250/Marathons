#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> conjunto;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        conjunto.insert(a);
    }
    if(conjunto.size()>3){
        cout << "NO\n";
    }else if(conjunto.size()==1 || conjunto.size()==2){
        cout << "YES\n";
    }else{
        set<int> :: iterator it=conjunto.begin();
        int a=*it;it++;
        int b=*it;it++;
        int c=*it;
        if(c-b==b-a){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
