#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

struct point {
    ll x, y;
    point(ll a = 0, ll b = 0):
    	x(a), y(b) {}
};

int n;
vector <point> polygon;

ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);}

ll area(const vector<point>& fig) {
    ll res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return abs(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        ll xs,ys;
        cin >> xs >> ys;
        polygon.push_back(point(xs,ys));
    }

    ll countBorderPoints=0;
    for(int i=0;i<n;i++){
        ll xi=polygon[i].x;
        ll yi=polygon[i].y;
        ll xi1=polygon[(i+1)%n].x;
        ll yi1=polygon[(i+1)%n].y;
        countBorderPoints+=abs(gcd(xi1-xi,yi1-yi));
    }
    ll I=area(polygon)+2-countBorderPoints;
    cout << I/2 <<"\n";
    return 0;
}
