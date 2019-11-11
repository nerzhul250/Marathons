#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;
typedef double ld;
const ll INF=1e16;


ll dp[1005][1005],G[1005],W[1005],X[1005],weights[1005],N,K;

struct Point {
	ld x, y;
};

struct Line {
	ll a, b;
	static Point intersect(const Line& l1, const Line& l2) {
		ld x, y;

		x = 1.0L * (l2.b - l1.b) / (l1.a - l2.a);
		y = l1.a * x + l1.b;

		return { x, y };
	}

	ll eval(ll x) {
		return a * x + b;
	}
};

struct CHT {
	vector<Line> lines;

	void addLine(const Line& l) {
		while (lines.size() >= 2 && Line::intersect(l, lines.end()[-1]).x > Line::intersect(l, lines.end()[-2]).x) {
			lines.pop_back();
		}
		lines.pb(l);
	}

	ll query(ll x) {
		int l = 0, r = lines.size() - 1;

		while (l != r) {
			int mid = (l + r) / 2;
			if (lines[mid].eval(x) > lines[mid + 1].eval(x)) l = mid + 1;
			else r = mid;
		}

		return lines[l].eval(x);
	}
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    while(cin >> N>>K){
        fore(i,0,N){
            ll pos,weight;
            cin >> pos>>weight;
            weights[i]=weight;
            X[i]=pos;
            if(i!=0){
                G[i]=G[i-1]+X[i]*weights[i];
                W[i]=W[i-1]+weights[i];
            }else{
                G[i]=X[i]*weights[i];
                W[i]=weights[i];
            }
        }

        dp[N][0]=0;
        fore(i,0,N)dp[i][0]=INF;
        fore(i,1,K+1)dp[N][i]=INF;

        fore(j,1,K+1){
            CHT cht;
            for(int i=N-1;i>=0;i--){
                cht.addLine({-X[i],X[i]*W[i]-G[i]+dp[i+1][j-1]});
                dp[i][j]=(i==0?0:G[i-1])+cht.query((i==0?0:W[i-1]));
            }
        }

        cout << dp[0][K]<<endl;

    }


    return 0;
}
