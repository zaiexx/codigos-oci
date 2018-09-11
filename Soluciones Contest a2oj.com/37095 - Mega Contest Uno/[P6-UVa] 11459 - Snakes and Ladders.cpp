#include <iostream>
#include <map>

using namespace std;

#define MAXT 101

int tablero[MAXT];

void init() {
  
    for (int i = 0; i < MAXT; i++) {      
        tablero[i] = i;
    }
  
}

int main () {

    int casos;  
    cin >> casos;
  
    while(casos--) {
      
        int player,snladders,die;
        int infin1,infin2;
        init();

      
        cin >> player >> snladders >> die;

        for (int i = 0; i < snladders; i++) {
            cin >> infin1 >> infin2;
            tablero[infin1] = infin2;
        }

        int posiciones[player+1];

        for (int i = 0; i < player+1; i++)
            posiciones[i] = 1;

        int valor;
        int ganador = 0;
        int ciclo = 1;

        for (int i = 0; i < die; i++) {
            cin >> valor;
            if (!ganador) {
                
                int movimiento = posiciones[ciclo] + valor;
                
                if (movimiento >= 100) {
                    movimiento = 100;
                }
                
                posiciones[ciclo] = tablero[movimiento];
                
                if (posiciones[ciclo] == 100) {
                    ganador = 1;
                }

                ciclo++;
                if (ciclo > player) {
                    ciclo = 1;
                }
            }
        }

        for (int i = 1; i < player+1; i++) {
            cout << "Position of player " << i << " is " << posiciones[i] << "." << endl;
        }

    }
return 0;
}
