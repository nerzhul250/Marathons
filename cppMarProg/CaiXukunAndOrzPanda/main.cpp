#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double x0,y0,x1,y1,vmax;
double g=-9.80665;
double vmagnitude(double t){
    double res=(x1-x0)*(x1-x0)/(t*t);
    res+=(g*t/2.0)*(g*t/2.0);
    res+=g*(y1-y0);
    res+=((y1-y0)/t)*((y1-y0)/t);
    return res;
}
double v0x(double t){
    return (x1-x0)/t;
}
double v0y(double t){
    return g*t/2.0 + (y1-y0)/t;
}
double q1(double t){
    return x0+v0x(t)*t;
}
double q2(double t){
    return y0+v0y(t)-g*t*t/2.0;
}
double magnitude(double x,double y){
    return hypot(x,y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> x0){
        cin >> y0 >> x1 >> y1 >> vmax;
        double a=g/2.0;
        a=a*a;
        double b=g*(y1-y0)-vmax*vmax;
        double c=(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0);
        double z1=-b/(2.0*a);
        z1+=((sqrt(b*b-4*a*c))/(2.0*a));
        double z2=-b/(2.0*a);
        z2-=((sqrt(b*b-4*a*c))/(2.0*a));
        if(z2<z1)swap(z1,z2);
        double t;
        if(z1<0 || z1==z2){
            t=sqrt(z2);
        }else{
            double t1,t2;
            t1=sqrt(z1);
            t2=sqrt(z2);
            cout << t1 << " " << t2 << endl;
            if(vmagnitude(t1)-vmax*vmax<1e-6 && magnitude(q1(t1)-x1,q2(t1)-y1)<=1e-6){
                t=t2;
            }else{
                t=t1;
            }
        }
        cout << v0x(t) << " " << v0y(t) << " " << t << "\n";
    }
    return 0;
}
