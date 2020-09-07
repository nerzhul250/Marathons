#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;
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
int arr[200005],brr[200005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n)cin >> arr[i];
	fore(i,0,n)cin >> brr[i];
	string T;
	fore(i,0,n){
		T+=to_string(brr[i]);
	}
	fore(i,0,n){
		T+=to_string(arr[i]);
	}
	fore(i,0,n){
		T+=to_string(arr[i]);
	}
	vector<int> z=z_function(T);
	bool possible=false;
	fore(i,n,3*n){
		if(z[i]>=n){
			possible=true;
			break;
		}
	}
	if(possible){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
    return 0;
}
