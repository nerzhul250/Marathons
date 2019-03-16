#include <iostream>
#include <limits.h>

using namespace std;


int B;
int beans[25];
int T;
int farms[105];
int n,bean, total;
int main()
{
    total=0;
    scanf("%d",&B);
    for (int i=0;i<B;i++){scanf("%d",&beans[i]);total+=beans[i];}
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d",&n);
        int f=0;
        for (int j=0;j<n;j++){
            scanf("%d",&bean);
            f=f|(1<<(bean-1));
        }
        farms[i]=f;
    }
    int subsets=1<<B;
    int minimum=INT_MAX;
    int sum=0;
    bool out=false;
    int num=1;
    for (int bitmask=1;bitmask<subsets;bitmask++){
        for (int t=0;t<T;t++)if((farms[t]&bitmask)==0){out=true;break;}
        if(out){out=false; continue;}
        sum=0;
        num=1;
        if(((num)&bitmask)!=0){sum+=beans[0];}
        for(int i=1;i<B;i++){
            num=num<<1;
            if((num&bitmask)!=0){sum+=beans[i];}
        }
        if(sum<minimum)minimum=sum;
        out=false;
    }
    printf("%d\n",total-minimum);
    return 0;
}
