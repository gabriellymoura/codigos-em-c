#include <stdio.h>

///Feito por: Gabrielly Moura
///Engenharia da Computação - UEMA

int main(){
    char x, y, z;
    int a, b, c;
    int cont=0;


    for (x = 'a'; y<='z'; x++){
        for (y = 'a'; y<='z'; y++){
            for (z = 'a'; z<='z';z++){
                for (a = 0; a<=9; a++){
                    for (b = 0; b<=9; b++){
                        for (c = 0; c<=9; c++){
                            cont = cont + 1;
                            //if (cont == 1000){
                                printf ("%c%c%c%d%d%d", x, y, z, a, b ,c);
                                //break;

                            }
                        }
                    }
                }
            }
        }
    }





//}
