#include <iostream>

using namespace std;
const int MAXB=20,MAXF=20;
int B,F,indexBand,auxIndex;
double szBands[MAXB],prcBands[MAXB],finalTax,earns[MAXF],gifts[MAXF],firstBand,total,canGet;

int main()
{

    scanf("%d",&B);
    for (int i=0;i<B;i++)scanf("%lf %lf",&szBands[i],&prcBands[i]);
    scanf("%lf",&finalTax);
    scanf("%d",&F);
    for (int i=0;i<F;i++)scanf("%lf %lf",&earns[i],&gifts[i]);
    for (int i=0;i<F;i++){
        total=0;
        auxIndex=0;
        firstBand=szBands[0];
        indexBand=0;

        while(earns[i]!=0){
            if(indexBand<B && earns[i]<szBands[indexBand]){
                firstBand=szBands[indexBand];
                auxIndex=indexBand;
                szBands[indexBand]-=earns[i];
                earns[i]=0;
            }else if(indexBand<B){
                earns[i]-=szBands[indexBand];
                indexBand++;
            }else{
                earns[i]=0;
            }
        }

        while(indexBand<B && gifts[i]!=0){
            if(prcBands[indexBand]!=100){
                if(prcBands[indexBand]==0){
                    canGet=szBands[indexBand];
                }else{
                    canGet=szBands[indexBand]/100*(100-prcBands[indexBand]);
                }
                if(canGet>=gifts[i] && prcBands[indexBand]==0){
                    total+=gifts[i];
                    gifts[i]=0;
                }else if(canGet>=gifts[i]){
                    total+=gifts[i]/(100-prcBands[indexBand])*100;
                    gifts[i]=0;
                }else{
                    total+=szBands[indexBand];
                    gifts[i]-=canGet;
                }
            }else{
                total+=szBands[indexBand];
            }
            indexBand++;
        }
        if(gifts[i]!=0){
            if(finalTax==0){
                total+=gifts[i];
            }else{
                total+=gifts[i]/(100-finalTax)*100;
            }
        }
        printf("%.6f\n",total);
        szBands[auxIndex]=firstBand;
    }
    return 0;
}
