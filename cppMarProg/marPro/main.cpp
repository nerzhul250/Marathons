#include <iostream>
#include <math.h>       /* ceil */
#include <stdio.h>
#include<float.h> // for float,double macros
#include<limits.h> // for int,char macros

using namespace std;

int64_t gcd (int64_t n1,int64_t n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}
int main()
{
    int L,n,d;
    while (scanf("%d %d %d", &L, &n, &d) == 3 && L) {
        int minb;
        double ans=DBL_MAX;
        for (int b=1;b<=n;b++){
            double num=ceil(b*(d/(double)L));
            double den=L/(double)b;
            double val=num*den;
            if(val<ans){ans=val;minb=b;}
        }
        int64_t grcd=gcd(ceil(minb*(d/(double)L))*(int64_t)L,minb);
		printf("%lld/%lld\n",((int64_t)ceil(minb*(d/(double)L))*(int64_t)L)/grcd,minb/(int64_t)grcd);
	}
    return 0;
}
