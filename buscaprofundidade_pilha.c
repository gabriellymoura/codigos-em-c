#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int topo;
   int *pElem;
}Pilha;

void criarpilha(Pilha *p, int capacidade){
   p->topo = 0;
   p->pElem = (int*) malloc (capacidade * sizeof(int));
}

void empilhar (Pilha *p, int v){
	p->topo++;
	p->pElem [p->topo] = v;
}

int desempilhar (Pilha *p){
   return p->pElem [p->topo--];;
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
void buscaProf(Grafo *g, int orig){
    Pilha p;
    criarpilha(&p, g->numVertices);
    int ent=0, ret=0;

    empilhar(&p, orig);
    g->visitado[orig] = g->cont;
    ent++;
    int aux;
    while(ent != ret){
        ret++;
        aux = p.pElem[p.topo];
        int i, j;
        for(j=1; j<g->numVertices; j++){
            for(i=1; i<g->numVertices; i++){
                if( (g->mat[aux][i]==1) && !g->visitado[i]) {
                    empilhar(&p,i);
                    aux = p.pElem[p.topo];

                    g->cont++;

                    g->visitado[aux] = g->cont;

                    ent++;
                }
            }

        }
        desempilhar(&p);

    }

}



int main(){

  int tam=10;
  Grafo g;
  int visitado[10];

  criaGrafo(&g,tam);

  insereAresta(&g,1,4);
  insereAresta(&g,1,7);
  insereAresta(&g,1,8);
  insereAresta(&g,4,9);
  insereAresta(&g,9,6);
  insereAresta(&g,7,5);
  insereAresta(&g,7,3);
  insereAresta(&g,3,2);

  buscaProf(&g, 1);

  int i;
  for(i=1;i<tam;i++){
    printf("\n>> %d -> %d ",i,g.visitado[i]);
  }
}
