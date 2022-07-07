#include "tetris.h"
#include<unistd.h>
#include"liste.h"

int placePiece(piece P, map *M, int x, int y){ //x moves up and down, y moves right and left
    start: ;
    if(x>M->column - P.row || y>M->column-P.column){
        printf("out of bounds.\n");
        return 0;
    }
    map backup = createMap(M->column);
    copyMap(*M,&backup);
    for(int i=0;i<P.row;i++){
        for(int j=0;j<P.column;j++){
            if(M->head[x+i][y+j] == 0 || (M->head[x+i][y+j] != 0 && P.head[i][j] == 0))
                M->head[x+i][y+j] += P.head[i][j];
            else{
                copyMap(backup,M);
                return 0;
            }
        }
    }
    libererMap(backup); //freeing memory
    return 1;
}

int id(int x, int y){ //return 2^x * 3^y
    int res=1;
    for(int i=0;i<x;i++) res = res*2;
    for(int i=0;i<y;i++) res = res *3;
    return res;
}
void placePieceSmart(piece* P,map *M,int n){
    int X, Y;
    int x = 0, y = 0, count = 0, k=1;
    //creating backup and solutions arrays.
    map* backup = (map*)malloc(n*sizeof(map)); //backs up the state of the map
    for(int i=0;i<n;i++) backup[i] = createMap(M->column);
    liste* solutions = (liste*)malloc(n*sizeof(liste));
    for(int i=0;i<n;i++) solutions[i] = NULL;
    for(int i=0;i<n;i++){
        X = M->column - P[i].row; Y = M->column - P[i].column;
        copyMap(*M,&backup[i]);
        if( recherche(id(x,y),solutions[i])==NULL && placePiece(P[i],M,x,y)  == 1 ){
            ajoutDebut(id(x,y),&solutions[i]); //we memorize the solution used for this state.
            x = 0; y = 0; //resetting x and y
        }
        else{
            if(x<X) x++;
            else{if(x==X){ x=0;y++; }}
            if(y>Y){ //all possible combinations failed, we go back to a previous state and retry.
                count++;
                if(count == (X+1)*(Y+1)) {
                    k++; count=0;
                }
                x=0; y=0;
                copyMap(backup[i-k],M);
                i=i-k;
                if(i<0){printf("Impossible to solve!! \n"); exit(EXIT_FAILURE);}
            }
            i--; //since we've entered this branch it means we have to stay in place and try again
        }
        /*sleep(0.5);
        printf("piece no. %d, with (x,y)=(%d<%d,%d<%d)\n",i+1,x,X,y,Y);
        printMap(*M);*/
    }
    //freeing memory.
    for(int i=0;i<n;i++) libererMap(backup[i]);
    free(backup);
    for(int i=0;i<n;i++) liberer(&solutions[i]);
    free(solutions);
    return;
}


int main(){
    map M = createMap(3);
    int n = 3;
    piece* L = (piece*)malloc(n*sizeof(piece));
    for(int i=0;i<n;i++){
        L[i] = createPiece(2,2);
        printf("Enter your piece\n");
        scanPiece(&L[i]);
        printPiece(L[i]);
    }
    /*placePiece(L[0],&M,0,0);
    placePiece(L[1],&M,1,1);
    placePiece(L[2],&M,1,0);*/
    placePieceSmart(L,&M,n);
    printMap(M);
    //freeing memory.
    for(int i=0;i<n;i++) libererPiece(L[i]);
    free(L);
    libererMap(M);
    return 0;
}
