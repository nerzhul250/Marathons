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

int n;
ll a[200005];
ll acum[200005];
int main(){FIN;	
	cin >> n;
	ll currentCost=0;
	fore(i,0,n){
		cin >> a[i];
		currentCost+=((i+1)*a[i]);
		acum[i]=a[i];
		if(i)acum[i]+=acum[i-1];
	}
	CHT cht;
	ll deltaCost=0;
	fore(j,1,n){
		cht.addLine({-(j-1),-(j-2<0?0:acum[j-2])});
		deltaCost=max(deltaCost,cht.query(-a[j])-a[j]*j+acum[j-1]);
	}
	CHT cht2;
	for(int i=n-2;i>=0;i--){
		cht2.addLine({i+1,-acum[i+1]});
		deltaCost=max(deltaCost,cht2.query(a[i])-a[i]*i+acum[i]);
	}
	cout << currentCost+deltaCost<<"\n";
	return 0;
}
