#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

double computePerimeter(vector<pt>& a){
    double sum=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        sum+=hypot(a[i].x-a[(i+1)%n].x,a[i].y-a[(i+1)%n].y);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        double L;
        cin >> N >> L;
        vector<pt> a;
        for(int i=0;i<N;i++){
            double x,y;
            cin >> x >> y;
            pt punto=pt();
            punto.x=x;
            punto.y=y;
            a.push_back(punto);
        }
        convex_hull(a);
        double perimeter =computePerimeter(a);
        double radius=2*L*acos(-1);
        cout << fixed;
        cout << setprecision(6);
        cout << "Case "<<t<<": "<<perimeter+radius << "\n";
    }
}
