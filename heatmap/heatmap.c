#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct map{
    unsigned dim;
    char** head;
};

struct heatmap
{    
    unsigned dim;
    int** head;
};


struct piece{
    unsigned row;
    unsigned col;
    char** head;
};

typedef struct map map;
typedef struct heatmap heatmap;
typedef struct piece piece;

map createMap(unsigned);    
void showMap(map);
int encercle(heatmap, map);
heatmap makeheatmap(map);




int max = 0;

map createMap(unsigned size){
    map M = {size, (char**)malloc(sizeof(char*)*size)};
    for(int i = 0; i < size; i++) M.head[i] = (char*)malloc(sizeof(char)*size);
    for(int j = 0; j < size; j++){
        for(int e = 0; e < size; e++){
            M.head[j][e] = '.';
        } 
    }
    return M;
}

heatmap createHeatMap(unsigned size){
    heatmap M = {size, (int**)malloc(sizeof(int*)*size)};
    for(int i = 0; i < size; i++) M.head[i] = (int*)malloc(sizeof(int)*size);
    for(int j = 0; j < size; j++){
        for(int e = 0; e < size; e++){
            M.head[j][e] = '.';
        } 
    }
    return M;
}

void showMap(map M){
    for(int i = 0; i < M.dim; i++){
        printf("||");
        for(int j = 0; j < M.dim; j++) printf("%c ", M.head[i][j]);
        printf("||\n");        
    }
    printf("\n");
}

void showHeatMap(heatmap M){
    if(max > 9){
        for(int i = 0; i < M.dim; i++){
            printf("||");
            for(int j = 0; j < M.dim; j++){
                if(M.head[i][j] == 'A' || M.head[i][j] == 'B' || M.head[i][j] == '.') printf(" %c ", M.head[i][j]);
                else{
                    if(M.head[i][j] > 9) printf("%d ", M.head[i][j]);
                    else printf(" %d ", M.head[i][j]);
                }
            }
            printf("||\n");        
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < M.dim; i++){
            printf("||");
            for(int j = 0; j < M.dim; j++){
                if(M.head[i][j] == 'A' || M.head[i][j] == 'B' || M.head[i][j] == '.') printf("%c ", M.head[i][j]);
                else printf("%d ", M.head[i][j]);
            }
            printf("||\n");        
        }
        printf("\n");
    }
}

int encercle(heatmap T, map M){
    int changes = 0;
    for(int i = 0; i < M.dim; i++){
        for(int j = 0; j < M.dim; j++){
            if(M.head[i][j] == 'B') T.head[i][j] = M.head[i][j];
            else{
                if(M.head[i][j] == 'A'){
                    if(i > 0){
                        if(M.head[i-1][j] != 'A' && M.head[i-1][j] != 'B' && T.head[i-1][j] != 0){
                            T.head[i-1][j] = 0;
                            changes++;
                        }
                        if(j < T.dim-1){
                            if(M.head[i-1][j+1] != 'A' && M.head[i-1][j+1] != 'B' && T.head[i-1][j+1] != 0){
                                T.head[i-1][j+1] = 0;
                                changes++;
                            }
                            if(M.head[i][j+1] != 'A' && M.head[i][j+1] != 'B' && T.head[i][j+1] != 0){
                                T.head[i][j+1] = 0;
                                changes++;
                            }
                        }                        
                        if(j > 0){
                            if(M.head[i-1][j-1] != 'A' && M.head[i-1][j-1] != 'B' && T.head[i-1][j-1] != 0){
                                T.head[i-1][j-1] = 0;
                                changes++;
                            }
                            if(M.head[i][j-1] != 'A' && M.head[i][j-1] != 'B' && T.head[i][j-1] != 0){
                                T.head[i][j-1] = 0;
                                changes++;
                            }
                        }
                    }
                    if(i < T.dim-1){
                        if(M.head[i+1][j] != 'A' && M.head[i+1][j] != 'B' && T.head[i+1][j] != 0){
                            T.head[i+1][j] = 0;
                            changes++;
                        }
                        if(j < T.dim){
                            if(M.head[i+1][j+1] != 'A' && M.head[i+1][j+1] != 'B' && T.head[i+1][j+1] != 0){
                                T.head[i+1][j+1] = 0;   
                                changes++;
                            }
                        }
                        if(j > 0){
                            if(M.head[i+1][j-1] != 'A' && M.head[i+1][j-1] != 'B' && T.head[i+1][j-1] != 0){
                                T.head[i+1][j-1] = 0;  
                                changes++;
                            }
                        }
                    }
                    T.head[i][j] = M.head[i][j];
                }
                else{
                    if(T.head[i][j] != '.'){
                        int next = T.head[i][j];
                        if(max < next+1) max = next+1;
                        if(i > 0){
                            if(M.head[i-1][j] != 'A' && M.head[i-1][j] != 'B' && next+1 < T.head[i-1][j]){
                                T.head[i-1][j] = next+1;
                                changes++;
                            }
                            if(j < T.dim-1){
                                if(M.head[i-1][j+1] != 'A' && M.head[i-1][j+1] != 'B' && next+1 < T.head[i-1][j+1]){
                                    T.head[i-1][j+1] = next+1;
                                    changes++;
                                }
                                if(M.head[i][j+1] != 'A' && M.head[i][j+1] != 'B' && next+1 < T.head[i][j+1]){
                                    T.head[i][j+1] = next+1;
                                    changes++;
                                }
                            }
                            if(j > 0){
                                if(M.head[i-1][j-1] != 'A' && M.head[i-1][j-1] != 'B' && next+1 < T.head[i-1][j-1]){
                                    T.head[i-1][j-1] = next+1; 
                                    changes++;
                                }
                                if(M.head[i][j-1] != 'A' && M.head[i][j-1] != 'B' && next+1 < T.head[i][j-1]){
                                    T.head[i][j-1] = next+1;  
                                    changes++;
                                }
                            }
                        }
                        if(i < T.dim-1){
                            if(M.head[i+1][j] != 'A' && M.head[i+1][j] != 'B' && next+1 < T.head[i+1][j]){
                                T.head[i+1][j] = next+1;
                                changes++;
                            }
                            if(j < T.dim-1){
                                if(M.head[i+1][j+1] != 'A' && M.head[i+1][j+1] != 'B' && next+1 < T.head[i+1][j+1]){
                                    T.head[i+1][j+1] = next+1;
                                    changes++;
                                }
                            }                        
                            if(j > 0){
                                if(M.head[i+1][j-1] != 'A' && M.head[i+1][j-1] != 'B' && next+1 < T.head[i+1][j-1]){
                                    T.head[i+1][j-1] = next+1;
                                    changes++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return changes;
}

heatmap makeheatmap(map M){
    heatmap final = createHeatMap(M.dim);
    while(encercle(final, M) != 0);
    return final;
}
