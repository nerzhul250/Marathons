#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;
    myfile.open ("sol.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        string lylipads;
        cin >> lylipads;
        int countBs=0;
        int N=lylipads.length();
        for(int i=0;i<lylipads.length();i++){
            if(lylipads[i]=='B')countBs++;
        }
        if((countBs>=N/2||countBs>=2) && countBs<N-1){
            myfile << "Case #"<<t<<": Y\n";
        }else{
            myfile << "Case #"<<t<<": N\n";
        }
    }
    myfile.close();
    return 0;
}
