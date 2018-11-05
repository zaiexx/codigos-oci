#include <iostream>

using namespace std;

#define MAXR 128
#define MAXC 128

char tablero[MAXR][MAXC];

//S,SE,E,NE,N,NW,W,SW
int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};


int dfs (int r, int c, char c1, char c2) {

    if (r < 0 || r >= MAXR || c < 0 || c >= MAXC) {
        return 0;
    }

    if (tablero[r][c] != c1) {
        return 0;
    }

    int ans = 1;
    tablero[r][c] = c2;

    for (int i = 0; i < 8; i++) {
        ans+= dfs(dr[i]+r,dc[i]+c,c1,c2);
    }

return ans;
}

int main () {

    int row, col;
    int cc;
    int total = 0;

    while (cin >> row >> col) {
        getchar();

        if (row == 0 && col == 0) {
            return 0;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> tablero[i][j];
            }
            getchar();
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                //usamos el signo $ como no visitado
                cc = dfs(i,j,'*','$');
                if (cc == 1) {
                    total++;
                }
            }
        }

        cout << total << endl;
        total = 0;
    }

return 0;

}
