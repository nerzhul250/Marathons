#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
using namespace __gnu_pbds;


typedef long long int ll;

struct point{
	//*,0-1,0-1,left-right,open-close
	int cor,dir,mark,id;
	int left,right;
	
	bool operator<(const point& p2){
		if(cor==p2.cor){
			if(id==p2.id){
				return mark<p2.mark;
			}else{
				return mark>p2.mark;
			}
		}else{
			return cor<p2.cor;
		}
	}
};

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
set_t;


int X,Y,H,V;
point pointsH[300000],pointsV[300000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> Y;
    cin >> H >> V;
    fore(i,0,H){
		int y1,y2;
		cin >> y1>>y2;
		point p,p1;
		p.cor=y1,p.dir=0,p.id=i,p.left=y1,p.right=y2;
		p1.cor=y2,p1.dir=1,p1.id=i,p1.left=y1,p1.right=y2;
		if(y1<y2){
			p.mark=0,p1.mark=1;	
		}else{
			p.mark=1,p1.mark=0;
		}
		pointsH[i*2]=p;
		pointsH[i*2+1]=p1;
	}
	
	fore(i,0,V){
		int x1,x2;
		cin >> x1>>x2;
		point p,p1;
		p.cor=x1,p.dir=0,p.id=i,p.left=x1,p.right=x2;
		p1.cor=x2,p1.dir=1,p1.id=i,p1.left=x1,p1.right=x2;
		if(x1<x2){
			p.mark=0,p1.mark=1;	
		}else{
			p.mark=1,p1.mark=0;
		}
		pointsV[i*2]=p;
		pointsV[i*2+1]=p1;
	}
	sort(begin(pointsV),begin(pointsV)+V*2);
	sort(begin(pointsH),begin(pointsH)+H*2);
	
	
	set_t countLeft,countRight;
	ll numRegions=1;
	fore(i,0,2*H){
		if(pointsH[i].mark==0){
			if(pointsH[i].dir==0){
				countLeft.insert(pointsH[i].cor);
			}else{
				countRight.insert(pointsH[i].cor);
			}	
		}else{
			if(pointsH[i].dir==0){
				numRegions+=(countLeft.size()+countRight.order_of_key(pointsH[i].right)+1);
				countRight.erase(pointsH[i].right);
			}else{
				numRegions+=(countRight.size()+countLeft.order_of_key(pointsH[i].left)+1);
				countLeft.erase(pointsH[i].left);
			}
		}
		
	}
	
	fore(i,0,2*V){
		if(pointsV[i].mark==0){
			if(pointsV[i].dir==0){
				countLeft.insert(pointsV[i].cor);
			}else{
				countRight.insert(pointsV[i].cor);
			}	
		}else{
			if(pointsV[i].dir==0){
				numRegions+=(countLeft.size()+countRight.order_of_key(pointsV[i].right)+H+1);
				countRight.erase(pointsV[i].right);
			}else{
				numRegions+=(countRight.size()+countLeft.order_of_key(pointsV[i].left)+H+1);
				countLeft.erase(pointsV[i].left);
			}
		}
	}
	
    cout << numRegions << "\n";
    
    return 0;
}
