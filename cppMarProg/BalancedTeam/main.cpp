
#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int n;
    cin >> n;
    vector<int> skills;
    for(int i=0;i<n;i++){
        int sk;
        cin >> sk;
        skills.push_back(sk);
    }
    sort(skills.begin(),skills.end());
    int i=0,j=0;
    int maxNumber=-1;
    while(j<n){
        if(skills[j]-skills[i]<=5){
            maxNumber=max(maxNumber,j-i+1);
            j++;
        }else{
            i++;
        }
    }
    cout << maxNumber << endl;
}
