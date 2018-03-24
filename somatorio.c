#include <stdio.h>

///feito por: Gabrielly Moura
///Engenharia da Computação


int f(int x){
    int rf;
    rf = x + 1;
    return (rf);

}

int g(int x){
    int rg;
    rg = (2*x) - 2;
    return (rg);
}

int fog (int rg){
    int rfog;
    rfog = rg + 1;
    return (rfog);
}

int main(){
    int s[3]= {1,2,3}, resultado, i;

    int rf, rg, rfog;
    int somaf=0, somag = 0, somafog = 0, soma;

    for (i=0; i<3; i++){
        rf = f(s[i]);

        somaf = somaf + rf;
    }
    for (i=0; i<3; i++){

        rg = g(s[i]);
        somag = somag + rg;
    }
    for (i=0; i<3; i++){

        rfog = fog(s[i]);
        somafog = somafog + rfog;
    }
    printf("a soma da funcao f e %d \n", somaf);
    printf("a soma da funcao g e %d\n", somag);
    printf("a soma da funcao fog e %d\n", somafog);
    soma = somaf * somag * somafog;
    printf("O somatorio e %d", soma);

}
