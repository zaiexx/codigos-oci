#include <iostream>

using namespace std;

int sobran, peso_total;


//Geeksforgeeks (Reconstruye parte de la solucion)
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

    int res = K[n][W];
    w = W;

    for (int i = n; i > 0 && res > 0; i--) {

        if (res == K[i - 1][w]) {
            continue;
        }else {
            peso_total+= wt[i - 1];
            sobran++;
            res = res - val[i - 1];
            w = w - wt[i - 1];
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

        sobran  = 0;
        peso_total = 0;

        cin >> N;

        int valores[N];
        int pesos[N];

        for (int i = 0; i < N; i++) {
            cin >> valores[i] >> pesos[i];
        }

        int sol = knapSack(50, pesos, valores, N);

        cout << sol << " brinquedos" <<endl;
        cout << "Peso: " << peso_total << " kg" << endl;
        cout << "sobra(m) " << N - sobran << " pacote(s)" << endl;
        cout << endl;
    }

return 0;
}
