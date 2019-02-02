#include <cstdio>
#include <cstring>
#include <iostream>
#include <float.h>
using namespace std;

int main()
{
    string bestName,auxName,trash;
    int n,p,bestReq=-1,cas=1,req;
    double bestPrice=DBL_MAX,price;
    while(scanf("%d %d",&n,&p),n){
        for (int i=0;i<n;i++){cin.ignore();getline(cin,trash);}
        for (int i=0;i<p;i++){
            getline(cin,auxName);
            scanf("%lf %d",&price,&req);
            if(req>bestReq){
                bestName=auxName;
                bestReq=req;
                bestPrice=price;
            }else if(req==bestReq && price<bestPrice){
                bestName=auxName;
                bestReq=req;
                bestPrice=price;
            }
            for (int j=0;j<req;j++){cin.ignore();getline(cin,trash);}
        }
        if(cas>1)printf("\n");
        printf("RFP #%d\n%s\n",cas++,bestName.c_str());
        bestReq=-1,bestPrice=DBL_MAX;
    }
    return 0;
}
