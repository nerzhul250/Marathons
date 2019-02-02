#include <iostream>
#include <map>

using namespace std;

const int SUITS=4;

int main()
{
    char ntol[4]={'S','H','D','C'};
    map<char, int> lton;
    lton['S'] = 0;
    lton['H'] = 1;
    lton['D'] = 2;
    lton['C'] = 3;
    bool ace[SUITS],king[SUITS],queen[SUITS],jack[SUITS];
    int number[SUITS];
    char temp[3];
    while(scanf("%s",temp)==1){
        bool stopped=true;
        int score=0,score2=0;
        for (int i = 0; i < SUITS;i++)
        {
            ace[i] = king[i] = queen[i] = jack[i] = false;
            number[i] = 0;
        }
        for (int i=0;i<13;i++){
            if(i!=0)scanf("%s",temp);
            switch(temp[0]){
            case 'A':
                ace[lton[temp[1]]]=true;
                break;
            case 'K':
                king[lton[temp[1]]]=true;
                break;
            case 'Q':
                queen[lton[temp[1]]]=true;
                break;
            case 'J':
                jack[lton[temp[1]]]=true;
                break;
            }
            number[lton[temp[1]]]++;
        }
        for (int i=0;i<SUITS;i++){
            score+=4*ace[i];
            score+=3*king[i];
            score+=2*queen[i];
            score+=jack[i];
            if(king[i] && number[i]==1){
                score-=1;
            }
            if(queen[i] && number[i]<=2){
                score-=1;
            }
            if(jack[i] && number[i]<=3){
                score-=1;
            }
            stopped&=ace[i] || (king[i] && number[i]>=2) || (queen[i] && number[i]>=3);
            if(number[i]==2)score2+=1;
            if(number[i]==1)score2+=2;
            if(number[i]==0)score2+=2;
        }
        if(score>=16 && stopped){
            printf("BID NO-TRUMP\n");
        }else if((score+score2)>=14){
            int index=0;
            int bestQuantity=-1;
            for (int i=0;i<SUITS;i++){
                if(number[i]>bestQuantity){index=i;bestQuantity=number[i];}
            }
            printf("BID %c\n",ntol[index]);
        }else{
            printf("PASS\n");
        }
    }
    return 0;
}
