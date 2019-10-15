#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> firstClock,secondClock;
    for(int i=0;i<n;i++){
        int deg;
        cin >> deg;
        firstClock.push_back(deg);
    }
    for(int i=0;i<n;i++){
        int deg;
        cin >> deg;
        secondClock.push_back(deg);
    }
    sort(firstClock.begin(),firstClock.end());
    sort(secondClock.begin(),secondClock.end());
    string s1="$",s2="$";
    for(int i=0;i<n-1;i++){
        s1+=to_string(firstClock[i+1]-firstClock[i]);
        s1+="$";
    }
    s1+=to_string(firstClock[0]+360000-firstClock[n-1]);

    for(int i=0;i<n-1;i++){
        s2+=to_string(secondClock[i+1]-secondClock[i]);
        s2+="$";
    }
    s2+=to_string(secondClock[0]+360000-secondClock[n-1]);

    /*cout << s1 << endl;
    cout << s2 << endl;*/

    string rot=s2+s1+s1;

    //cout << rot << endl;

    int possible=0;

    vector <int> myz=z_function(rot);

    for(int i=n;i<myz.size() && !possible;i++){
        if(myz[i]>=s2.size()){
            possible=1;
        }
    }

    if(possible){
        cout << "possible\n";
    }else{
        cout << "impossible\n";
    }

    return 0;
}
