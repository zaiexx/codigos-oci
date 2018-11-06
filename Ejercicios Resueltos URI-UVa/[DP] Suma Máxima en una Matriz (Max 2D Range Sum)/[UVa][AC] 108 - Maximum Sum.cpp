#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_T 101

int n, Matriz[MAX_T][MAX_T], maxSubRect, subRect;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Matriz[i][j];
            if (j > 0) {
                Matriz[i][j]+= Matriz[i][j-1];
            }
        }
    }

    //MENOR SUMA POSIBLE PARA EL PROBLEMA
    maxSubRect = -127*100*100;    // Cambiar dependiendo el ejercicio!


    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            subRect = 0;
            for (int row = 0; row < n; row++) {
                if (l > 0) {
                    subRect += Matriz[row][r] - Matriz[row][l - 1];
                } else {
                    subRect += Matriz[row][r];
                }

            if (subRect < 0) {
                subRect = 0;
            }

            maxSubRect = max(maxSubRect, subRect);
            }
         }
    }

    cout << maxSubRect << endl;

return 0;
}

