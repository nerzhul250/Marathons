#include <iostream>
#include <algorithm>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin >> t;
   while(t--){
       string let;
       cin >> let;
       if(next_permutation(let.begin(),let.end())){
            cout << let<<endl;
       }else{
           cout << "no answer" << endl;
       }
    }
  return 0;
}
