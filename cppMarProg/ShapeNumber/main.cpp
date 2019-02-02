#include <iostream>

using namespace std;

struct Node {
   int originalIndex;
   int index;
   Node *next;
};
struct Node* head = NULL;
void insert(int originalIndex) {
   Node* new_node =new Node;
   new_node->originalIndex =originalIndex;
   new_node->index =originalIndex;
   new_node->next=head;
   head = new_node;
}
const int MAXN=300000;
char code[MAXN],aux[MAXN];
int main()
{
    int i=0;
    char c,lowest;
    Node *previous=new Node,*current=new Node;
    while(scanf("%c",&c)){
        aux[i]=c;
        for(i=1;c!='\n';i++){scanf("%c",&c);aux[i]=c;}
        i--;
        for (int n=0;n<i;n++){
            int val=aux[(n+1)%i]-aux[n];
            if(val<0)val+=8;
            code[n]='0'+val;
        }
        for (int j=i-1;j>=0;j--)insert(j);
        for (int j=0;j<i;j++){
            lowest='8';
            previous=NULL;
            current=head;
            while(current!=NULL){
                if(code[current->index]<lowest)lowest=code[current->index];
                current=current->next;
            }
            current=head;
            while(current!=NULL){
                if(code[current->index]>lowest){
                    if(previous==NULL){
                        head=head->next;
                        delete current;
                        current=head;
                    }else{
                        previous->next= current->next;
                        delete current;
                        current=previous->next;
                    }
                }else{
                    current->index=((current->index)+1)%i;
                    previous=current;
                    current=current->next;
                }
            }
        }
        for (int j=0;j<i;j++){
            printf("%c",code[((head->originalIndex)+j)%i]);
        }
        current=NULL;
        while(head!=NULL){
            current=head;
            head=head->next;
            delete current;
        }
        printf("\n");
        i=0;
    }
    return 0;
}
