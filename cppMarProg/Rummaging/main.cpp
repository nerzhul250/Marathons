#include <iostream>
#include <vector>
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
    int N;
    cin >> N;
    string T;
    cin >> T;
    string Tr;
    for(int i=N-1;i>=0;i--){
        Tr+=T[i];
    }
    int R,M;
    cin >> R >> M;
    int cnt=0;
    for(int i=0;i<R;i++){
        string pat;
        cin >> pat;
        string patr;
        for(int j=M-1;j>=0;j--){
            patr+=pat[j];
        }
        vector<int> myz1=z_function(pat+T);
        vector<int> myz2=z_function(patr+Tr);
        vector<int> myz[2];
        /*cout << pat+T << endl;
        cout << patr+Tr << endl;*/
        for(int j=0;j<N;j++){
            myz[0].push_back(myz1[j+M]);
            myz[1].push_back(myz2[N+M-j-1]);
        }
        for(int j=0;j<N-M+1;j++){
            if(myz[0][j]+myz[1][j+M-1]>=M-1){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
