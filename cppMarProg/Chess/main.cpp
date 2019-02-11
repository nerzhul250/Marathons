#include <iostream>
#include <math.h>

using namespace std;
int m,n,t;
char c;
int main()
{
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> c >> m >> n;
        switch(c){
            case 'r':{
                printf("%d\n",min(n,m));
                break;
            }
            case 'k':{
                printf("%d\n",(int)(ceil(m/2.0)*(n/2)+ceil(m/2.0)*(n%2)+(n/2)*(m/2)));
                break;
            }
            case 'K':{
                printf("%d\n",(int)(ceil(m/2.0)*ceil(n/2.0)));
                break;
            }
            case 'Q':{
                printf("%d\n",min(n,m));
                break;
            }
        }
    }
    return 0;
}
