#include <iostream>
#include <math.h>

using namespace std;

float altura=0;
float delta=0.01;

double alturareal=0;
double delta2=0.01;
int count=0;
float AlturaMax=300000;
int main(){
    while ((altura < AlturaMax) & (altura < altura + delta) ){
        altura= altura + delta; // Se determina el tiempo transcurrido
        alturareal=alturareal+delta2;
        count=count+1; // Contador de incrementos0==0
        if(fabs(alturareal-altura)>1){
            cout << count << endl;
            break;
        }
    }
    cout <<count << endl;
    cout << "SEPARACION DE EMERGENCIA"; // Separación de emergencia
}
