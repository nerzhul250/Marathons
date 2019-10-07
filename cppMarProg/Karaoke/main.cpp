#include <iostream>
#include <set>

using namespace std;

struct point{
    int p,s,e;
    char t;

    point(int p,int s, int e, char t) : p(p),s(s),e(e),t(t){}
};
struct cmp{
    bool operator()(const point& p1, const point& p2) const{
        if(p1.p<p2.p)return true;
        if(p1.p>p2.p)return false;
        if(p1.p==p1.s && p2.p==p2.e)return true;
        if(p1.p==p1.e && p2.p==p2.s)return false;
        if(p1.t=='J' && p2.t=='D')return true;
        if(p1.t=='D' && p2.t=='J')return false;
        if(p1.s<p2.s)return true;
        if(p1.s>p2.s)return false;
        return p1.e<p2.e;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    set<point,cmp> pointsOrdered;
    for(int i=0;i<N;i++){
        int a,b;
        char c;
        cin >> c;
        cin >> a >> b;
        point p1=point(a,a,b,c);
        point p2=point(b,a,b,c);
        pointsOrdered.insert(p1);
        pointsOrdered.insert(p2);
    }
    set<point,cmp> :: iterator it=pointsOrdered.begin();

    set<point,cmp> Ds;
    set<point,cmp> Js;

    int maximumLength=0;

    while(it!=pointsOrdered.end()){
        //cout << it->p << " " << it->s << " " << it-> e << " " << it->t<<endl;
        if(it->p==it->s){
            if(it->t=='D'){
                Ds.insert(*it);
            }else if(it->t=='J'){
                Js.insert(*it);
            }
        }else if(it->p==it->e){
            if(it->t=='D'){
                Ds.erase(point(it->s,it->s,it->e,it->t));
                if(Js.size()!=0){
                    int s=Js.begin()->s;
                    maximumLength=max(maximumLength,(it->e)-max(s,it->s));
                }
            }else if(it->t=='J'){
                Js.erase(point(it->s,it->s,it->e,it->t));
                if(Ds.size()!=0){
                    int s=Ds.begin()->s;
                    maximumLength=max(maximumLength,(it->e)-max(s,it->s));
                }
            }
        }
        it++;
    }

    cout << maximumLength << "\n";

    return 0;
}
