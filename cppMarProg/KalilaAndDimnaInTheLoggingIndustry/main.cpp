#include <bits/stdc++.h>

#define fore(i,low,n) for(int i=low;i<n;i++)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef double ld;

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
		while (lines.size() >= 2 && Line::intersect(l, lines.end()[-2]).x > Line::intersect(l, lines.end()[-1]).x) {
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
    int n;
    cin >> n;
    ll as[n+5],bs[n+5];
    fore(i,0,n)cin >> as[i];
    fore(i,0,n)cin >> bs[i];
    CHT cht;
    cht.addLine({bs[0],0});
    ll minimum=0;
    fore(i,1,n){
        ll val=cht.query(as[i]);
        cht.addLine({bs[i],val});
        if(i==n-1)minimum=val;
    }
    cout << minimum<<endl;
    return 0;
}
