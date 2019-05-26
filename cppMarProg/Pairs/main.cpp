#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n,m,x1,x2,y1[2],y2[2];
	cin>>n>>m;
	vector<int> a,b;
	for(int i=0;i<m;++i) {
		cin>>x1>>x2;
		a.push_back(x1);
		b.push_back(x2);
	}
	x1=a[0];
	x2=b[0];
	for(int i=0;i<m;++i) {
		if(a[i]!=x1&&b[i]!=x1) {
			y1[0]=a[i];
			y1[1]=b[i];
		}
		if(a[i]!=x2&&b[i]!=x2) {
			y2[0]=a[i];
			y2[1]=b[i];
		}
	}
	bool g10=true,g11=true,g20=true,g21=true;
	for(int i=0;i<m;++i) {
		if(a[i]!=x1&&b[i]!=x1&&a[i]!=y1[0]&&b[i]!=y1[0]) g10=false;
		if(a[i]!=x1&&b[i]!=x1&&a[i]!=y1[1]&&b[i]!=y1[1]) g11=false;
		if(a[i]!=x2&&b[i]!=x2&&a[i]!=y2[0]&&b[i]!=y2[0]) g20=false;
		if(a[i]!=x2&&b[i]!=x2&&a[i]!=y2[1]&&b[i]!=y2[1]) g21=false;
	}
	if(g10||g11||g20||g21) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
