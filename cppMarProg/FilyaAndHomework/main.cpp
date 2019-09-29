#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> ints;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        ints.insert(a);
    }
    if(ints.size()>3){
        cout <<"NO\n";
    }else if(ints.size()==1){
        cout << "YES\n";
    }else{
        int num=ints.size();
        set<int> :: iterator it =ints.begin();
        if(num==2){
            int a=*it;
            it++;
            int b=*it;
            if(2*a==b || a==0){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else if(num==3){
            int a=*it;
            it++;
            int b=*it;
            it++;
            int c=*it;

            if((a*2==b && c-a==b) || (a==0 && b*2==c) || () ){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
