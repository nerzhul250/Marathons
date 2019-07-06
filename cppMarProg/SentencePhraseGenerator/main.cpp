#include <iostream>

using namespace std;
string op;
int k;
string article(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        return "the";
    }else{
        return "a";
    }
}
string noun(){
    k++;
    int choice=(k%5)+1;
    if(choice==1){
        return "man";
    }else if(choice==2){
        return "dog";
    }else if(choice==3){
        return "fish";
    }else if(choice==4){
        return "computer";
    }else if(choice==5){
        return "waves";
    }
}
string adjective(){
    k++;
    int choice=(k%4)+1;
    if(choice==1){
        return "green";
    }else if(choice==2){
        return "small";
    }else if(choice==3){
        return "rabid";
    }else if(choice==4){
        return "quick";
    }
}
string adverb(){
    k++;
    int choice=(k%3)+1;
    if(choice==1){
        return "nearly";
    }else if(choice==2){
        return "suddenly";
    }else if(choice==3){
        return "restlessly";
    }
}
string modifier(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        return adjective();
    }else{
        string a1=adverb();
        string a2=adjective();
        return a1+" "+a2;
    }
}
string modifiedNoun(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        return noun();
    }else{
        string a1=modifier();
        string a2=noun();
        return a1+" "+a2;
    }
}
string nounPhrase(){
    string a1=article();
    string a2=modifiedNoun();
    return a1+" "+a2;
}
string transVerb(){
    k++;
    int choice=(k%4)+1;
    if(choice==1){
        return "struck";
    }else if(choice==2){
        return "saw";
    }else if(choice==3){
        return "bit";
    }else if(choice==4){
        return "took";
    }
}
string verbPhrase(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        return transVerb();
    }else{
        string a1=adverb();
        string a2=transVerb();
        return a1+" "+a2;
    }
}
string object(){
    return nounPhrase();
}
string preposition(){
    k++;
    int choice=(k%3)+1;
    if(choice==1){
        return "on";
    }else if(choice==2){
        return "over";
    }else if(choice==3){
        return "through";
    }
}
string prepPhrase(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        string a1=preposition();
        string a2=nounPhrase();
        return a1+" "+a2;
    }else{
        return "";
    }
}
string subject(){
    return nounPhrase();
}
string transSentence(){
    string a1=subject();
    string a2=verbPhrase();
    string a3=object();
    string a4=prepPhrase();
    if(a4.empty()){
        return a1+" "+a2+" "+a3;
    }else{
        return a1+" "+a2+" "+a3+" "+a4;
    }

}
string instransVerb(){
    k++;
    int choice=(k%4)+1;
    if(choice==1){
        return "slept";
    }else if(choice==2){
        return "jumped";
    }else if(choice==3){
        return "walked";
    }else if(choice==4){
        return "swam";
    }
}
string instransVerbPhrase(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        return instransVerb();
    }else{
        string a1=adverb();
        string a2=instransVerb();
        return a1+" "+a2;
    }
}
string intransSentence(){
    string a1=subject();
    string a2=instransVerbPhrase();
    string a3=prepPhrase();
    if(a3.empty()){
        return a1+" "+a2;
    }else{
        return a1+" "+a2+" "+a3;
    }
}
string sentence(){
    k++;
    int choice=(k%2)+1;
    if(choice==1){
        return transSentence();
    }else{
        return intransSentence();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> op){
        if(op=="sentence"){
            cout << sentence();
        }else if(op=="trans-sentence"){
            cout << transSentence();
        }else if(op=="intrans-sentence"){
            cout << intransSentence();
        }else if(op=="subject"){
            cout << subject();
        }else if(op=="object"){
            cout << object();
        }else if(op=="noun-phrase"){
            cout << nounPhrase();
        }else if(op=="modified-noun"){
            cout << modifiedNoun();
        }else if(op=="modifier"){
            cout << modifier();
        }else if(op=="verb-phrase"){
            cout << verbPhrase();
        }else if(op=="intrans-verb-phrase"){
            cout << instransVerbPhrase();
        }else if(op=="prep-phrase"){
            cout << prepPhrase();
        }else if(op=="noun"){
            cout << noun();
        }else if(op=="trans-verb"){
            cout << transVerb();
        }else if(op=="intrans-verb"){
            cout << instransVerb();
        }else if(op=="article"){
            cout << article();
        }else if(op=="adjective"){
            cout << adjective();
        }else if(op=="adverb"){
            cout << adverb();
        }else if(op=="preposition"){
            cout << preposition();
        }else if(op=="empty"){
            cout << "";
        }
        cout << "\n";
    }
    return 0;
}
