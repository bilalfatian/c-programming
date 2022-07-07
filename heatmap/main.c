#include "heatmap.c"

int main(){
    map M = createMap(20);
    M.head[12][9] = 'A';
    M.head[12][10] = 'A';
    M.head[13][9] = 'A';
    M.head[14][9] = 'A';
    M.head[12][11] = 'A';
    M.head[13][10] = 'A';
    M.head[6][3] = 'B';
    M.head[7][4] = 'B';
    M.head[8][4] = 'B';
    M.head[6][5] = 'B';
    M.head[7][3] = 'B';
    M.head[8][5] = 'B';
    M.head[9][6] = 'B';
    showMap(M);
    heatmap T = makeheatmap(M); 
    showHeatMap(T);
    return 0;
}
