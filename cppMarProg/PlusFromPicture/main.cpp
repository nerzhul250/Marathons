#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> ii;

int visited[505][505];
int shape[505][505];
int ies[505];
int jies[505];
int h,w;
vector<vector<ii> > components;
void addComponent(vector<ii> &component,int i, int j){
    if(i>=0 && i<h && j>=0 && j<w && shape[i][j] && !visited[i][j]){
        visited[i][j]=1;
        component.push_back(ii(i,j));
        addComponent(component,i+1,j);
        addComponent(component,i,j+1);
        addComponent(component,i-1,j);
        addComponent(component,i,j-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        string line;
        cin >> line;
        for(int j=0;j<w;j++){
            if(line[j]=='.'){
                shape[i][j]=0;
            }else{
                shape[i][j]=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!visited[i][j] && shape[i][j]){
                vector<ii>component;
                addComponent(component,i,j);
                components.push_back(component);
            }
        }
    }
    if(components.size()==1 && components[0].size()>=5){
        for(int i=0;i<components[0].size();i++){
            ies[components[0][i].first]++;
            jies[components[0][i].second]++;
        }
        int maxh=0;
        int I=0;
        int J=0;
        for(int i=0;i<h;i++){
            if(ies[i]>maxh){
                maxh=ies[i];
                I=i;
            }
        }
        int maxw=0;
        for(int i=0;i<w;i++){
            if(jies[i]>maxw){
                maxw=jies[i];
                J=i;
            }
        }
        if(maxw-1+maxh==components[0].size()){
            int i=I-1;
            int j=J;
            int possible=0;
            if(i>=0 && i<h && j>=0 && j<w && shape[i][j]){
                i=I+1;
                j=J;
                if(i>=0 && i<h && j>=0 && j<w && shape[i][j]){
                    i=I;
                    j=J+1;
                    if(i>=0 && i<h && j>=0 && j<w && shape[i][j]){
                        i=I;
                        j=J-1;
                        if(i>=0 && i<h && j>=0 && j<w && shape[i][j]){
                            i=I+1;
                            j=J;
                            possible=1;
                        }
                    }
                }
            }
            if(possible){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
