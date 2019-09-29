#include <iostream>
#include <vector>

using namespace std;
string answers[29]={"0",
                  "1","2","2","2","6","8","10",
                  "18","20","20","28","68","88","108",
                  "188","200","208","288","688","888","1088",
                  "1888","2008","2088","2888","6888","8888","10888"};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    vector<string> theAnswers;
    for(int i=0;i<29;i++){
        theAnswers.push_back(answers[i]);
    }
    for(int j=29;j<=128;j++){
        theAnswers.push_back(theAnswers[j-7]+"8");
    }
    while(T--){
        int n;
        cin >> n;
        cout << theAnswers[n] << "\n";
    }
    return 0;
}
