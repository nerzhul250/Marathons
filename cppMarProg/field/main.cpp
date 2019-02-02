#include <iostream>
#include <math.h>       /* ceil */
#include <stdio.h>
#include<float.h> // for float,double macros
#include<limits.h> // for int,char macros
#include <unordered_set>
#include <cstring>

using namespace std;
int main()
{
    int N=0,val=0,sum=0;
    scanf("%d",&N);
    int trees[N+1];
    memset(trees,0,N+1);
    unordered_set<int> theSet;
    theSet.insert(0);
    for (int n=1;n<=N;n++){
        scanf("%d",&val);
        sum+=val;
        theSet.insert(sum);
        trees[n]=trees[n-1]+val;
    }
    if(sum%2!=0){
        printf("%c\n",'N');
    }else{
        sum=sum/2;
        int pairs=0;
        for (int i=0;trees[i]<sum && pairs!=2;i++){
            if(theSet.count(trees[i]+sum)){
                pairs++;
            }
        }
        if(pairs==2){
            printf("%c\n",'Y');
        }else{
            printf("%c\n",'N');
        }
    }
    return 0;
}
