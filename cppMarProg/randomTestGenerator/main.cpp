#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    ofstream myFile;
    myFile.open("tests.txt");
    myFile << 1040;
    myFile << " ";
    myFile << 2073;
    myFile << "\n";
    for (int i=1;i<=1040;i++){
        int d;
        d=(i%1040)+1;
        myFile << d;
        if(i!=1040)myFile << " ";
    }
    myFile << "\n";
}
