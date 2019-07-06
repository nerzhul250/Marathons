#include <iostream>
#include <fstream>

using namespace std;
string e;
int i;
int x;
int exp(){
    if(e[i]=='x'){
        i++;
        return x;
    }
    if(e[i]=='X'){
        i++;
        return x^1;
    }
    if(e[i]=='0'){
        i++;
        return 0;
    }
    if(e[i]=='1'){
        i++;
        return 1;
    }
    if(e[i]=='('){
        i++;
        int val1=exp();
        if(e[i]=='|'){
            i++;
            int val2=exp();
            if(e[i]==')'){
                i++;
                return val1 | val2;
            }
        }else if(e[i]=='^'){
            i++;
            int val2=exp();
            if(e[i]==')'){
                i++;
                return val1 ^ val2;
            }
        }else if(e[i]=='&'){
            i++;
            int val2=exp();
            if(e[i]==')'){
                i++;
                return val1 & val2;
            }
        }
    }
    return -1;
}
int eval(int val){
    x=val;
    return exp();
}
int main()
{
    ofstream myfile;
    myfile.open ("sol.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        cin >> e;
        i=0;
        int val1=eval(1);
        i=0;
        int val2=eval(0);
        if(val1==val2){
            myfile << "Case #"<<t<<": 0\n";
        }else{
            myfile << "Case #"<<t<<": 1\n";
        }
    }
    myfile.close();
    return 0;
}
