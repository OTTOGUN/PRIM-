#define INF 23767
#define OK 1
#define ERROR 0
#define MAXVERTEX 20
#include<stdio.h>
#include<stdlib.h>

typedef struct _AMGraph{
    int edge,vertex;
    char name[MAXVERTEX];
    int Edges[MAXVERTEX][MAXVERTEX];
}AMGraph;

void Prim(AMGraph* G,int v){
    int closet[MAXVERTEX];
    int lowcost[MAXVERTEX];
    int min = INF;
    int i,j,k;

    for(int i = 0;i < G -> vertex;i++){
        closet[i] = v;
        lowcost[i] = G -> Edges[v][i];
    }
    lowcost[v] = 0;

    for(i = 0;i < G -> vertex - 1;i++){
        for(j = 0;j < G -> vertex;j++){
            if(lowcost[i] < min){
                min = lowcost[i];
                k = j;
            }
        }
        lowcost[k] = 0;
        printf("%c ¡·¡·¡· %c\n",G -> name[closet[k]],G -> name[k]);

        for(i = 0;i < G -> vertex;i++){
            if(G -> Edges[k][i] < lowcost[i]){
                lowcost[i] = G -> Edges[k][i];
                closet[i] = k;
            }
        }
    }
}