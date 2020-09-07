#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;
int b,w,x;
ll a,c;
int f(int eme){
	if(eme>=x){
		return eme-x;
	}else{
		return w-(x-eme);
	}	
}
//Cycle finding algorithm for iterative function f
//If the cycle length is lambda
// and the miu is the first index at which the cycle starts, then the algorithm will run in O(lambda+miu) time.
ii floydCycleFinding(int x0) { // function int f(int x) is defined earlier

    // 1st part: finding k*mu, hares speed is 2x tortoises
    int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }

    // 2nd part: finding mu, hare and tortoise move at the same speed
    int mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}

    // 3rd part: finding lambda, hare moves, tortoise stays
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); lambda++; }

    return ii(mu, lambda);
}
int rest[1000005];
int main(){FIN;	
	cin >> a >> b >> w >> x >> c;
	if(c<=a){
		cout << "0\n";
		return 0;
	}
	ii v=floydCycleFinding(b);
	int auxb=b;
	fore(i,0,v.ff+v.ss){
		if(auxb>=x){
			auxb=auxb-x;
		}else{
			rest[i]=-1;
			auxb=(w-(x-auxb));
		}
	}
	int cycleRest=0;
	fore(i,v.ff,v.ff+v.ss)cycleRest+=rest[i];
	ll time=0;
	auxb=b;
	fore(i,0,v.ff){
		time++;
		c--;
		a+=rest[i];
		if(c<=a){
			cout << time<<"\n";
			return 0;
		}
	}
	ll k=ceil((c-a+0.0)/(cycleRest+v.ss));
	c=c-k*v.ss;
	a=a+k*cycleRest;
	time+=k*v.ss;
	for(int i=v.ff+v.ss-1;i>=v.ff;i--){
		c++;
		a=a-rest[i];
		if(c>a){
			cout << time << "\n";
			return 0;
		}else{
			time--;
		}
	}
    return 0;
}
