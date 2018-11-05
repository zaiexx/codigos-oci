#include <iostream>

using namespace std;

#define MAXR 100
#define MAXC 100

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

int gold = 0;

char grilla[MAXR][MAXC];

void dfs (int r, int c, char c1, char c2) {

    if (r < 0 || r >= MAXR || c < 0 || c >= MAXC) {
        return;
    }

    if (grilla[r][c] != c1 && grilla[r][c] != 'G') {
        return ;
    }

    if (grilla[r][c] == 'G') {
        gold++;
    }

    grilla[r][c] = c2;

    for (int i = 0; i < 4; i++) {
        if (grilla[dr[i]+r][dc[i]+c] == 'T') {
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        dfs(dr[i] + r, dc[i] + c, c1, c2);
    }
}

int main () {

    int row, col;
    int coorx, coory;

    while (cin >> col >> row) {

        getchar();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) {
                cin >> grilla[i][j];
                if (grilla[i][j] == 'P') {
                    coorx = i;
                    coory = j;
                }
            }
            getchar();
        }

        grilla[coorx][coory] = '.';
        //usamos el signo peso para marca visitado
        dfs(coorx,coory,'.','$');
        cout << gold << endl;
        gold = 0;
    }

return 0;
}
