#include <iostream>

using namespace std;

int main()
{
    double H,U,D,F;
    while(scanf("%lf %lf %lf %lf",&H,&U,&D,&F), H){
        bool snailFailed=false;
        double fatigue=F*U/100.0;
        double cuH=0;
        int64_t day;
        for (day=1;!snailFailed;day++){
            cuH+=U;
            if(cuH>H)break;
            U-=fatigue;
            if(U<=0)U=0;
            cuH-=D;
            if(cuH<0)snailFailed=true;;
        }
        if(snailFailed){
            printf("failure on day %ld\n",(day-1));
        }else{
            printf("success on day %ld\n",day);
        }
    }
    return 0;
}
