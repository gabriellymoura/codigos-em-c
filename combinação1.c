#include <stdio.h>

/// Feito por: Gabrielly Moura
/// Engenharia da Computação - UEMA



int main(){

    char i, m, a;
    int j, n, b;
    char k, o, p, c, d, e;
    int cont, cont1=0, cont2=0, cont3=0;


    for(i=1; i<=26; i++){
        for(j=0; j<=9; j++){
            for(k=1; k<=36; k++){
                cont1 = cont1 + 1;

            }
        }
    }

     for(m=1; m<=26; m++){
        for(n=0; n<=9; n++){
            for(o=1; o<=36; o++){
               for(p=1; p<=36; p++){
                  cont2 = cont2+1;
               }
            }
        }
     }

     for(a=1; a<=26; a++){
        for(b=0; b<=9; b++){
            for(c=1; c<=36; c++){
               for(d=1; d<=36; d++){
                    for(e=1; e<=36; e++){
                        cont3 = cont3 + 1;
                    }
               }
            }
        }
     }

    cont = cont1+cont2+cont3;
    printf("%d",cont);


}
