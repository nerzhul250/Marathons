#include <iostream>

using namespace std;
int n,a,criminals[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a;
    for(int i=0;i<n;i++){
        cin >> criminals[i];
    }
    int l=a-1,r=a-1;
    int criminalsCatched=0;
    while(l>=0 || r<n){
        int sum=0;
        if(l>=0)sum+=criminals[l];
        if(r<n && l!=r)sum+=criminals[r];
        if(l==r){
            criminalsCatched+=sum;
        }else{
            if(!(l>=0 && r<n && sum==1))criminalsCatched+=sum;
        }
        l--;
        r++;
    }
    cout << criminalsCatched << "\n";
    return 0;
}
