#include<stdio.h>
#include<stdlib.h>

/*****structs*****/
struct map
{
    unsigned row;
    unsigned column;
    int ** head;
};
typedef struct map map;

struct piece
{
    unsigned row;
    unsigned column;
    int ** head;
};
typedef struct piece piece;

/*****Prototypes*****/
map createMap(unsigned);
piece createPiece(unsigned,unsigned);
void libererMap(map);
void libererPiece(piece);
void copyMap(map, map*);
void scanPiece(piece*);
void printMap(map);
void printPiece(piece);
piece fullPiece(int, int);
/********************/

map createMap(unsigned n)
{
    map M={0,0,NULL};
    M.row=n;
    M.column=n;
    M.head=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        M.head[i][j] = 0; 
    }
    return M;
}

piece createPiece(unsigned r,unsigned c)
{
    piece M={0,0,NULL};
    M.row=r;
    M.column=c;
    M.head=(int **)malloc(r*sizeof(int *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(int *)malloc(c*sizeof(int));
    return M;
}

void libererMap(map M)
{
    if(M.head!=NULL)
    {
        for(int i=0;i<M.row;i++)
        {
            if(M.head[i]!=NULL)
                free(M.head[i]);
        }
        free(M.head);
    }
    return;
}

void libererPiece(piece M)
{
    if(M.head!=NULL)
    {
        for(int i=0;i<M.row;i++)
        {
            if(M.head[i]!=NULL)
                free(M.head[i]);
        }
        free(M.head);
    }
    return;
}

void scanPiece(piece * M)
{
    printf("---------------\n");
    if(M->head==NULL)
        return;
    for(int i=0;i<M->row;i++)
    {
        for(int j=0;j<M->column;j++)
            scanf("%d",M->head[i]+j);
    }
    return;
}
void printMap(map M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    for(int i=0;i<M.row;i++)
    {
        printf("| ");
        for(int j=0;j<M.column-1;j++)
            printf("%d ",M.head[i][j]);
        printf("%d |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}
void printPiece(piece M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    for(int i=0;i<M.row;i++)
    {
        printf("| ");
        for(int j=0;j<M.column-1;j++)
            printf("%d ",M.head[i][j]);
        printf("%d |\n\n",M.head[i][M.column-1]);
    }
    printf("\n");
    return;
}

piece fullPiece(int n, int m){
    piece P = createPiece(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            P.head[i][j] = 1;
        }
    }
    return P;
}

void copyMap(map M, map * N){
    int n = M.column;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            N->head[i][j] = M.head[i][j];
    }
    return;
}
