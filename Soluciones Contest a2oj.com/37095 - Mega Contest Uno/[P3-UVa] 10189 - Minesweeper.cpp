#include <iostream>
#include <cstring>

using namespace std;

#define MAX_R 110
#define MAX_C 110


int mines[MAX_R][MAX_C];
char grid[MAX_R][MAX_C];

int dr[] =  {-1, -1, 0, 1, 1, 1 ,0, -1};
int dc[] =  {0, 1, 1, 1, 0, -1, -1, -1};

int nR, nC;

bool bound(int r, int c) {
    return r >= 0 && r < nR &&  c >= 0 && c < nC;
}


void process (int r, int c) {

    if (grid[r][c] == '*') {

        int nr, nc;
        mines[r][c] = -1;

        for (int i = 0; i < 8; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if (mines[nr][nc]!=-1)
                mines[nr][nc]+=1;
        }
    }
}


int main () {

    int linea = 0;

    int k = 0;
    while (cin >> nR >> nC) {

        if (nR == 0 || nC == 0)
            return 0;

        if (linea)
            cout << endl;

        memset(mines, 0, sizeof mines);

        for (int i = 0; i < nR; i++) {
            for (int j = 0; j < nC; j++) {
                cin >> grid[i][j];
            }
        }


        for (int i = 0; i < nR; i++) {
            for (int j = 0; j < nC; j++) {
                if (grid[i][j] == '*')
                    process(i,j);
            }
        }

        cout << "Field #" << ++k << endl;

        for (int i = 0; i < nR; i++) {
            for (int j = 0; j < nC; j++) {
                if (mines[i][j] == -1)
                    cout << "*";
                else
                    cout << mines[i][j];
            }
            cout << endl;
        }


        linea = 1;

    }

return 0;
}
