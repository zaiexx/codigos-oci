#include <iostream>

using namespace std;

//CODIGO DE GEEKFORGEEKS
int knapSack(int W, int wt[], int val[], int n) {

    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i==0 || w==0) {

               K[i][w] = 0;
            }else if (wt[i-1] <= w) {

                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            }else {
                 K[i][w] = K[i-1][w];
            }
       }
   }

   return K[n][W];
}

int main() {


    int TC;
    int N;
    int capacidad;
    int resistencia;

    cin >> TC;

    while (TC--) {

        cin >> N;

        int valores[N];
        int pesos[N];

        for (int i = 0; i < N; i++) {
            cin >> valores[i] >> pesos[i];
        }

        cin >> capacidad;
        cin >> resistencia;

        int sol = knapSack(capacidad, pesos, valores, N);

        if (sol < resistencia) {
            cout << "Falha na missao" << endl;
        }else {

            cout << "Missao completada com sucesso" << endl;
        }


    }

return 0;
}
