#include <iostream>
#define MOD 1000000007LL

using namespace std;

typedef long long ll;

int N,X,Y,F,le[100009],ri[100009],type[100009];
ll mem[100009][3][3];

ll w(int n, int io,int ro){
    if(n==0){return io==ro?1:0;}

    if(mem[n][io][ro]!=-1)return mem[n][io][ro];

    ll a =w(le[n],0,0);
    ll b =w(le[n],1,0);
    ll c =w(le[n],0,1);
    ll d =w(le[n],1,1);

    ll e =w(ri[n],0,0);
    ll f =w(ri[n],1,0);
    ll g =w(ri[n],0,1);
    ll h =w(ri[n],1,1);


    if(type[n]==-1){
        if(io==0 && ro==0)return mem[n][io][ro]=(d*h)%MOD;
        if(io==1 && ro==0)return mem[n][io][ro]=(c*g+c*h+d*g)%MOD;
        if(io==0 && ro==1)return mem[n][io][ro]=(b*f+b*h+d*f)%MOD;
        if(io==1 && ro==1)return mem[n][io][ro]=(a*(e+f+g+h)+c*(e+f)+b*(g+e)+d*e)%MOD;
    }

    if(type[n]==0){
        if(io==0 && ro==0)return mem[n][io][ro]=((b+d)*(f+h))%MOD;
        if(io==1 && ro==0)return mem[n][io][ro]=(a*(e+f+g+h)+b*(e+g)+c*(e+f+g+h)+d*(e+g))%MOD;
        if(io==0 && ro==1)return mem[n][io][ro]=0;
        if(io==1 && ro==1)return mem[n][io][ro]=0;
    }

    if(type[n]==1){
        if(io==0 && ro==0)return mem[n][io][ro]=0;
        if(io==1 && ro==0)return mem[n][io][ro]=0;
        if(io==0 && ro==1)return mem[n][io][ro]=((b+d)*(f+h))%MOD;
        if(io==1 && ro==1)return mem[n][io][ro]=(a*(e+f+g+h)+b*(e+g)+c*(e+f+g+h)+d*(e+g))%MOD;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> X >> Y >> F;
        le[i]=X;
        ri[i]=Y;
        type[i]=F;
    }
    for(int i=0;i<100009;i++){
        mem[i][0][0]=-1;
        mem[i][1][0]=-1;
        mem[i][2][0]=-1;
        mem[i][0][1]=-1;
        mem[i][1][1]=-1;
        mem[i][2][1]=-1;
        mem[i][0][2]=-1;
        mem[i][1][2]=-1;
        mem[i][2][2]=-1;
    }
    cout << (w(1,1,0)+w(1,0,1))%MOD<<endl;
}
