#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

#define oper max
const int K=20;
int st[K][1<<K];int n;  // K such that 2^K>n
void st_init(vector<int> a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	if(s>=e)return 0;
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}


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
	string s;
	cin >> s;
	vector<int> z=z_function(s);
	n=s.size();
	st_init(z);
	int index=-1,maxLength=0;
	fore(i,0,n){
		if(z[i]+i==n && st_query(1,s.size()-z[i])>=z[i] && z[i]>maxLength){
			maxLength=z[i];
			index=i;
		}
	}
	if(index!=-1){
		cout << s.substr(index) << "\n";	
	}else{
		cout << "Just a legend\n";
	}
    return 0;
}

