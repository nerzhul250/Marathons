#include <bits/stdc++.h>

#define fore(i,low,n) for(int i=low;i<n;i++)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;

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
			if (lines[mid].eval(x) < lines[mid + 1].eval(x)) l = mid + 1;
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
    int n;
    cin >> n;
    pair<ii,ll> rectangles[n+5];
    fore(i,0,n){
        ll x,y,a;
        cin >>x >>y>>a;
        rectangles[i]={{x,y},a};
    }
    sort(rectangles,rectangles+n);

    CHT cht;

    cht.addLine({ 0, 0 });

    ll maximo=0;
    fore(i,0,n){
        ll x=rectangles[i].ff.ff,y=rectangles[i].ff.ss,a=rectangles[i].ss;
        ll val=(i==0?0:cht.query(y))+x*y-a;
        maximo=max(maximo,val);
        cht.addLine({-x,val});
    }
    cout << maximo << endl;
    return 0;
}
