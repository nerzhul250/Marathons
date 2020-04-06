#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef pair<int,char> ii;

int freq[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string in;
    cin >> in;
    int s=in.size();
    fore(i,0,s)freq[in[i]-'a']++;
    vector<ii> ans;
    fore(i,0,s){
		ans.pb(ii(-freq[in[i]-'a'],in[i]));
	}
	sort(ans.begin(),ans.end());
	for(ii c : ans){
		cout << c.ss;
	}
	cout << "\n";
    return 0;
}
