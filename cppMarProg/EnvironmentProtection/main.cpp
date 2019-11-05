#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

double W,D,A;
int K;
double ys1[5][10],ys2[5][10];
const int N = 10000;

double Computey1(double x){
    double ans1=ys1[0][K],ans2=ys1[1][K];
    for(int i=K-1;i>=0;i--){
        ans1*=x;
        ans1+=ys1[0][i];
    }
    for(int i=K-1;i>=0;i--){
        ans2*=x;
        ans2+=ys1[1][i];
    }
    return ans1/ans2;
}
double Computey2(double x){
    double ans1=ys2[0][K],ans2=ys2[1][K];
    for(int i=K-1;i>=0;i--){
        ans1*=x;
        ans1+=ys2[0][i];
    }
    for(int i=K-1;i>=0;i--){
        ans2*=x;
        ans2+=ys2[1][i];
    }
    return ans1/ans2;
}
double f(double x,double d){
    return max(Computey1(x),d)-max(Computey2(x),d);
}

double simpson_integration(double a, double b,double d){
    double h = (b - a) / N;
    double s = f(a,d) + f(b,d); // a = x_0 and b = x_2n
    for (int i = 1; i <= N - 1; ++i) { // Refer to final Simpson's formula
        double x = a + h * i;
        s += f(x,d) * ((i & 1) ? 4 : 2);
    }
    s *= h / 3;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    while(cin>>W>>D>>A>>K){
        for(int i=0;i<K+1;i++){
            cin >> ys1[0][i];
        }
        for(int i=0;i<K+1;i++){
            cin >> ys1[1][i];
        }
        for(int i=0;i<K+1;i++){
            cin >> ys2[0][i];
        }
        for(int i=0;i<K+1;i++){
            cin >> ys2[1][i];
        }
        double d1=0,d2=-D;
        int it=100;
        double theArea=0;
        while(it--){
            double dmid=(d1+d2)/2;
            theArea=simpson_integration(0,W,dmid);
            if(theArea>A){
                d2=dmid;
            }else{
                d1=dmid;
            }
        }
        cout << fixed;
        cout <<setprecision(5)<< -(d1+d2)/2<<"\n";
    }
}
