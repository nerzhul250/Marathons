#include <iostream>

using namespace std;

int houses[2000005];
int n,m,counter,base;
int main()
{
    scanf("%d",&m);
    for (int t=0;t<m;t++){
        scanf("%d",&n);
        if(n==0){
            printf("0\n");
        }else{
            for (int i=0;i<n;i++){
                scanf("%d",&houses[i]);
            }
            counter=1; base=0;
            for (int i=1;i<n;i++){
                if(houses[i]-houses[base]>20){counter++;base=i;}
            }
            printf("%d\n",counter);
        }
    }
}
