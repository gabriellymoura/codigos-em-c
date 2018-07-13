#include <stdio.h>
#include <stdlib.h>


typedef struct {
   int inicio;
   int fim;
   int *pElem;
}Fila;

void criarFila(Fila *p, int capacidade){
   p->inicio = 1;
   p->fim = 0;
   p->pElem = (int*) malloc (capacidade * sizeof(int));
}

void enfileirar (Fila *p, int v){
	p->pElem[++p->fim] = v;
	//printf("%d\n\n", p->pElem[p->fim]);
}

int desenfileirar (Fila *p){
   int valor = p->pElem[p->inicio];
   int i;
   for(i=0; i < p->fim; i++) {
     p->pElem[i] = p->pElem[i+1];
   }
   p->fim--;
   return valor;
}


typedef struct grafo {
  int numVertices;
  int **mat;
  int *visitado;
  int cont;
} Grafo;

void criaGrafo(Grafo* g, int n)  {
  g->mat = malloc (n * sizeof(int*));
  g->mat[0]=NULL;
  int i;
  for (i = 1; i < n; i++) {
    g->mat[i] = malloc (n * sizeof(int));
  }
  g->numVertices = n;
  int l,c;
  for(l=1;l<n;l++) {
      for(c=1;c<n;c++) {
        g->mat[l][c]=0;
      }
  }
  g->visitado = malloc (n * sizeof(int));
  for(i=0; i<n; i++) {
     g->visitado[i] = 0;
  }
  g->cont=1;
}

void insereAresta(Grafo *g, int v1, int v2) {
    g->mat[v1][v2] = 1;
}

void buscaLarg(Grafo *g, int orig){
    Fila f;
    criarFila(&f, g->numVertices);

    int indiceEntrada=0, indiceRetira=0;

    enfileirar(&f, orig);
    g->visitado[orig] = g->cont;
    indiceEntrada++;
    int proxVertSair;
    while(indiceRetira != indiceEntrada){
        indiceRetira = (indiceRetira + 1) % g->numVertices;

        proxVertSair = f.pElem[indiceRetira];
        int i;
        for(i=1; i<g->numVertices; i++){
            if((g->mat[proxVertSair][i]==1) && !g->visitado[i]){

                g->cont++;
                g->visitado[i] = g->cont;
                indiceEntrada++;
                enfileirar(&f, i);

            }
        }
    }
    //desenfileirar(&f);
}

int main(){
    Grafo g;
    criaGrafo(&g, 10);

    insereAresta(&g,1,4);
    insereAresta(&g,1,7);
    insereAresta(&g,1,8);
    insereAresta(&g,4,9);
    insereAresta(&g,9,6);
    insereAresta(&g,7,5);
    insereAresta(&g,7,3);
    insereAresta(&g,3,2);

    buscaLarg(&g, 1);

    int i;
    for(i=1; i < g.numVertices; i++)
        printf("%d -> %d\n",i,g.visitado[i]);
}
