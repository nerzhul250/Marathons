#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

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

int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		string s;
		cin >> s;
		vector<int> z=z_function(s);
		int n=z.size();
		bool found=false;
		int nam=n;
		for(int i=z.size()-1;i>0 && !found;i--){
			if(z[i]==n-i){
				int j=i;
				while(j!=0 && z[j]==n-j)j-=z[i];
				if(j==0){
					found=true;
					nam=z[i];
				}
			}
		}
		cout << nam << "\n";
		if(t!=0)cout << "\n";
	}
    return 0;
}
