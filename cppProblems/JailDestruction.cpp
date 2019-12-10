#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

int const N = 5e5;

ll sum[N],mx1[N],mx2[N],cnt[N],tag[N];

struct segment_tree
{
	int n;
	int ql, qr;

	  segment_tree(vector < ll >const &a)
	{
		n = a.size();
		build(1, 0, n-1, a);
	}
	
	void pushDown(int i, int l, int r){
		if(tag[i]>0){
			if (mx2[i] < tag[i] && tag[i] < mx1[i])
			{
				mx1[i]=mx1[i]-tag[i];
				mx2[i]=0;
				sum[i]=cnt[i]*mx1[i];
			}else{
				sum[i]=0;
				mx1[i]=0;
				mx2[i]=0;
				cnt[i]=r-l+1;
			}
			int m=(l+r)/2;
			if(l<=m)tag[i*2]+=tag[i];
			if(m+1<=r)tag[i*2+1]+=tag[i];
			tag[i]=0;
		}
	}

	inline void calc(int i)
	{
		int lf = 2 * i;
		int rg = lf + 1;
		
		cnt[i] = 0;
		sum[i] = sum[lf] + sum[rg];
		mx1[i] = max(mx1[lf], mx1[rg]);
		mx2[i] = max(mx2[lf], mx2[rg]);

		if (mx1[i] == mx1[lf])
			cnt[i] += cnt[lf];
		else
			mx2[i] = max(mx2[i], mx1[lf]);

		if (mx1[i] == mx1[rg])
			cnt[i] += cnt[rg];
		else
			mx2[i] = max(mx2[i], mx1[rg]);
	}

	void build(int i, int l, int r, vector < ll >const &a)
	{
		if (l == r)
		{
			cnt[i] = 1;
			mx2[i] =0;
			sum[i] = mx1[i] = a[l];
		}
		else
		{
			int m = (l + r) / 2;
			build(2 * i, l, m, a);
			build(2 * i + 1, m + 1, r, a);
			calc(i);
		}
	}

	void update(int i, int l, int r, ll x)
	{
	
		pushDown(i,l,r);
		
		if (r<ql||l>qr||sum[i]==0)
			return;
	
		if (ql <= l && r <= qr && mx2[i] < x && x < mx1[i])
		{
			mx1[i]=mx1[i]-x;
			mx2[i]=0;
			sum[i]=cnt[i]*mx1[i];
			int m=(l+r)/2;
			if(l<=m)tag[i*2]+=x;
			if(m+1<=r)tag[i*2+1]+=x;
		}else if(ql <= l && r <= qr && mx1[i]<=x){
			sum[i]=0;
			mx1[i]=0;
			mx2[i]=0;
			cnt[i]=r-l+1;
			int m=(l+r)/2;
			if(l<=m)tag[i*2]+=x;
			if(m+1<=r)tag[i*2+1]+=x;
		}else{
			int m = (l + r) / 2;
			update(i*2,l,m,x);
			update(i*2+1,m+1,r,x);
			calc(i);
		}
		return ;
	}

	void update(int l, int r, ll x)
	{
		ql = l;
		qr = r;
		update(1, 0, n-1, x);
	}


	ll query_sum(int i, int l, int r)
	{
		if (r<ql||l>qr)
			return 0;
		
		pushDown(i,l,r);
		
		if (ql <= l && r <= qr)
		{
			return sum[i];
		}
		else
		{
			int m = (l + r) / 2;
			ll x = 0;
			x += query_sum(2 * i, l, m);
			x += query_sum(2 * i + 1, m + 1, r);
			return x;
		}
	}

	ll query_sum(int l, int r)
	{
		ql = l;
		qr = r;
		return query_sum(1, 0, n-1);
	}
};


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);	
	int n,q;
	cin >> n>>q;
	vector<ll>heights;
	fore(i,0,n){
		ll h;
		cin >> h;
		heights.pb(h);
	}
	segment_tree st(heights);
	fore(i,0,q){
		int c,a,b;
		cin >> c >> a >> b;
		a--;
		b--;
		if(c==1){
			if(a<=b){
				cout << st.query_sum(a,b)<<"\n";
			}else{
				cout << st.query_sum(a,n-1)+st.query_sum(0,b)<<"\n";
			}
		}else{
			ll s;
			cin >> s;
			if(a<=b){
				st.update(a,b,s);
			}else{
				st.update(a,n-1,s);
				st.update(0,b,s);
			}
		}
	}
	return 0;
}
