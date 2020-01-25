    #include<bits/stdc++.h>
    #define inf 2e8
    #define FOR(i,a,b) for(int i=a;i<=b;i++)
    using namespace std;
     
    const int maxn = 500050;
    typedef long long ll;
     
    struct tree2{
        tree2 *lson,*rson;
        int len,x;
        ll sum,lazy;
    }dizhi[maxn<<1],*root=&dizhi[0];
     
    int t=1,n,m,a[maxn];
     
    void push_up(tree2 *tree){
        tree->len=tree->lson->len+tree->rson->len;
        tree->x=min(tree->lson->x,tree->rson->x);
        tree->sum=tree->lson->sum+tree->rson->sum;
    }
     
    void build(tree2 *tree,int l,int r){
        int mid=(l+r)>>1;
        tree->lazy=0;
        if(l==r){
            tree->len=1,tree->x=tree->sum=a[l];
            return ;
        }
        tree->lson=&dizhi[t++];
        tree->rson=&dizhi[t++];
        build(tree->lson,l,mid);
        build(tree->rson,mid+1,r);
        push_up(tree);
    }
     
    void push_down(tree2 *tree,int l,int r){
        if(!tree->lazy)return ;
        int mid=(l+r)>>1;
        tree->lson->sum-=1ll*tree->lson->len*tree->lazy;
        tree->lson->x-=tree->lazy;
        tree->lson->lazy+=tree->lazy;
        tree->rson->sum-=1ll*tree->rson->len*tree->lazy;
        tree->rson->x-=tree->lazy;
        tree->rson->lazy+=tree->lazy;
        tree->lazy=0;
    }
     
    void update(tree2 *tree,int l,int r,int x,int y,int d){
        int mid=(l+r)>>1;
        if(x<=l&&r<=y){
            if(l==r){
                if(d<tree->x){
                    tree->sum-=d;
                    tree->x-=d;
                }
                else {
                    tree->sum-=tree->x;
                    tree->x=inf;
                    tree->len=0;
                }
            }
            else{
                if(d<tree->x){
                    tree->x-=d;
                    tree->sum-=1ll*tree->len*d;
                    tree->lazy+=d;
                }
                else{
                    push_down(tree,l,r);
                    if(x<=mid&&tree->lson->len>0)update(tree->lson,l,mid,x,y,d);
                    if(y>mid&&tree->rson->len>0)update(tree->rson,mid+1,r,x,y,d);
                    push_up(tree);
                }
            }
            return ;
        }
        push_down(tree,l,r);
        if(x<=mid&&tree->lson->len>0)update(tree->lson,l,mid,x,y,d);
        if(y>mid&&tree->rson->len>0)update(tree->rson,mid+1,r,x,y,d);
        push_up(tree);
        return ;
    }
     
    ll query(tree2 *tree,int l,int r,int x,int y){
        if(x<=l&&r<=y)return tree->sum;
        push_down(tree,l,r);
        int mid=(l+r)>>1;
        ll t1=0,t2=0;
        if(x<=mid&&tree->lson->len>0)t1=query(tree->lson,l,mid,x,y);
        if(y>mid&&tree->rson->len>0)t2=query(tree->rson,mid+1,r,x,y);
        return t1+t2;
    }
     
    int main(){
        cin.sync_with_stdio(0);
    	cin.tie(0);	
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin >> a[i];
        build(root,1,n);
        for(int i=1;i<=m;i++){
            int op,l,r,val;
            cin >> op >> l>>r;
            if(op==1){
                if(l<=r)cout<<query(root,1,n,l,r)<<"\n";
                else cout <<query(root,1,n,l,n)+query(root,1,n,1,r)<<"\n";
            }
            else{
                cin >> val;
                if(l<=r&&root->len>0)update(root,1,n,l,r,val);
                else if(l>r){
                    if(root->len>0)update(root,1,n,l,n,val);
                    if(root->len>0)update(root,1,n,1,r,val);
                }
            }
        }
    }
