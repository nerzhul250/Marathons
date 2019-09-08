#include <iostream>

using namespace std;
string str;
bool inGroup(int index){
    return index-1>=0 && str[index-1]=='.' && index+1<str.size() && str[index+1]=='.';
}
bool alone(int index){
    return (index-1>=0?str[index-1]!='.':true) && (index+1<str.size()?str[index+1]!='.':true);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    cin >> str;
    int counter=(str[0]=='.'?1:0);
    int sum=0;
    for(int i=1;i<n;i++){
        if(str[i]=='.'){
            counter++;
        }else{
            if(counter!=0)sum+=(counter-1);
            counter=0;
        }
    }
    if(counter!=0)sum+=(counter-1);

    for(int i=0;i<m;i++){
        int index;
        string let;
        cin >> index >> let;
        index--;
        if(let[0]=='.' && str[index]!='.'){
            if(inGroup(index)){
                sum+=2;
            }else if(!alone(index)){
                sum+=1;
            }
        }else if(let[0]!='.' && str[index]=='.'){
            if(inGroup(index)){
                sum-=2;
            }else if(!alone(index)){
                sum-=1;
            }
        }
        cout << sum << "\n";
        str[index]=let[0];
    }
    return 0;
}
