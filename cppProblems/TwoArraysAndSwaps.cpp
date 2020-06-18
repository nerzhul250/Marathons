#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int arr[100],brr[100];
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		fore(i,0,n)cin >> arr[i];
		fore(i,0,n)cin >> brr[i];
		sort(begin(arr),begin(arr)+n);
		sort(begin(brr),begin(brr)+n);
		int i=0,j=n-1;
		while(k && arr[i]<brr[j]){
			swap(arr[i],brr[j]);
			i++;
			j--;
			k--;
		}
		int sum=0;
		fore(i,0,n)sum+=arr[i];
		cout << sum << "\n";
	}
    return 0;
}

