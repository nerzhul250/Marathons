#include <iostream>
#include <vector>
using namespace std;

typedef pair<string,int> ii;
vector<string> attendes;
vector<int> teams;

int countOnes(int t,int m){
    int index=0;
    int counter=0;
    int power=(1<<index);
    while(index<m){
        if(power&t){
            counter++;
        }
        index++;
        power=power<<1;
    }
    return counter;
}
int BStoINT(string b){
    int power=1;
    int sum=0;
    for(int i=b.size()-1;i>=0;i--){
        if(b[i]=='1'){
            sum+=power;
        }
        power=power<<1;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string att;
        cin >> att;
        attendes.push_back(att);
    }
    int maxCount=-1;
    for(int i=0;i<attendes.size()-1;i++){
        for(int j=i+1;j<attendes.size();j++){
            int numberOfOnes=0;
            for(int k=0;k<m;k++){
                if(attendes[i][k]=='1'||attendes[j][k]=='1')numberOfOnes++;
            }
            teams.push_back(numberOfOnes);
            if(numberOfOnes>maxCount)maxCount=numberOfOnes;
        }
    }
    int counterTeams=0;
    for(int i=0;i<teams.size();i++){
        if(teams[i]==maxCount)counterTeams++;
    }


    cout << maxCount << endl;
    cout << counterTeams << endl;

    return 0;
}
