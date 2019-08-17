#include <iostream>
#include <string>

using namespace std;
string number;
int n;
int factors[10][4]={{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,0,0},{3,1,0,0},{3,1,1,0},{4,2,1,0},{4,2,1,1},{7,2,1,1},{7,4,1,1}};
int counter[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> number;
    for(int i=0;i<n;i++){
        int index=number[i]-'0';
        for(int j=0;j<4;j++){
            counter[j]+=factors[index][j];
        }
    }
    string ans="";
    for(int i=3;i>=0;i--){
        while(counter[i]>0){
            int index=2;
            string add="2";
            if(i!=0){
                index=i*2+1;
                add=to_string(index);
            }
            ans=ans+add;
            for(int j=0;j<4;j++){
                counter[j]=counter[j]-factors[index][j];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
