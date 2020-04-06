#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int a[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    double r;
    cin >> r;
    fore(i,0,n){
        cin >> a[i];
    }
    sort(begin(a),begin(a)+n);
    double baseArea=r*r*acos(-1);
    if(n==1){
        cout<<fixed<<setprecision(10) << baseArea<<"\n";
    }else{
        double acum=0;
        double intersectionArea=0;
        fore(i,0,n-1){
            double a1=a[i];
            double a2=a[i+1];
            double d = a2-a1;
            if(d<2*r){
                double part1 = r*r*acos((d*d)/(2*d*r));
                double part2 = 0.5*sqrt((-d+r+r)*(d)*(d)*(d+r+r));
                intersectionArea = 2*part1 - part2;
                acum+=(baseArea-intersectionArea);
            }else{
                acum+=(baseArea);
            }
        }
        acum+=baseArea;
        cout <<fixed<<setprecision(10)<< acum <<"\n";
    }
    return 0;
}
