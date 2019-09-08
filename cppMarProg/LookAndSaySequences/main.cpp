#include <iostream>
#include <string>
#include <vector>
using namespace std;

string effToString(int a){
    string ans="";
    if(a==0){
        ans+='0';
        return ans;
    }
    if(a<0){
        ans+='-';
        a*=-1;
    }
    while(a>0){
        ans+=(a%10)+'0';
        a/=10;
    }
    return ans;
}
string computeNewSequence(string seq){
    int counter=1;
    char let=seq[0];
    string ans="";
    for(int i=1;i<seq.size() && i<=1000;i++){
        if(seq[i]==let){
            counter++;
        }else{
            ans+=effToString(counter);
            ans+=let;
            counter=1;
            let=seq[i];
        }
    }
    ans+=effToString(counter);
    ans+=let;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << effToString(1356) << endl;
    int x,i,j;
    while(cin >>x){
        cin >> i >> j;
        if(x==0 && i==0 && j==0)break;
        j--;
        string currentSeq=to_string(x);
        for(int k=2;k<=i;k++){
            currentSeq=computeNewSequence(currentSeq);
        }
        cout << currentSeq[j] << "\n";
    }
    return 0;
}
