#include <stdio.h>
#include <math.h>

///feito por: Gabrielly Moura
///Engenharia da Computação

int main(){
    float a0, a1, a2, ai;
    int i;
    float soma, soma1, somatorio;
    float q, an, n;
    a0 = 0.125;
    a1 = -0.25;
    a2 = 0.5;
    q = a2/a1;
    soma1 = a0+a1+a2;
    printf("A razao e %f \n", q);
        for (i=3; i<11; i++){
            ai =(a1 * pow(q,i-1));
            soma = soma + ai;
        }
        somatorio = soma1 +soma;
        printf("o somatorio e %f", somatorio);
}


