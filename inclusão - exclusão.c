#include <stdio.h>
#include <math.h>

/// Feito por: Gabrielly Moura
/// Engenharia da computação

int main(){

    int i, j, k;
    int x, y;
    x=1;
    y=0;

    int cont=0, cont1=0, cont2=0;

    for(i=0; i<=1; i++){
        for(j=0; j<=1; j++){
            for (k=0; k<=1; k++){
                printf("%d%d%d%d", x,i,j,k);
                printf("\n");
                cont1++;
            }

        }
    }
    for(i=0; i<=1; i++){
        for(j=0; j<=1; j++){
            for (k=0; k<=1; k++){
                    if (i==0){
                        printf("%d%d%d%d",i,j,k,y);
                        printf("\n");
                        cont2++;
                    }
                }
            }

        }
    cont = cont1+cont2;
    printf("\n%d possibilidades", cont);
    }


