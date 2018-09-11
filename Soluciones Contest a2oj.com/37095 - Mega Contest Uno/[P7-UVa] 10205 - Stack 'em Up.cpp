#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;


#define CARTAS 52
#define N 102

char map_valores[][6] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
char map_pintas[][9] = {"Clubs","Diamonds","Hearts","Spades"};

int shuffles[N][CARTAS];

int main () {

    int casos;
    cin >> casos;

    int i,j;
    int contador = 1;
    
    while (casos--) {

        int total_s;
        int mazo_actual[CARTAS];

        for (i = 0; i < CARTAS; ++i) {
            mazo_actual[i] = i;
        }

        int mazo_barajado[CARTAS];
        cin >> total_s;

        for (i = 0; i < total_s; ++i) {
            for (j = 0; j < CARTAS; ++j) {
                cin >> shuffles[i][j];
            }
        }

        string linea;
        getchar();
        while(getline(cin,linea)) {

            if(linea.empty())
                break;

            int k = atoi(linea.c_str());

            for(i = 0;i < CARTAS ;++i)
                mazo_barajado[i] = mazo_actual[shuffles[k-1][i]-1];

            for(i = 0;i < CARTAS; ++i)
                mazo_actual[i] = mazo_barajado[i];
        }

        if (contador > 1) {
            cout << endl;
        }

        for(i = 0;i < CARTAS; ++i) {
            cout << map_valores[mazo_actual[i] % 13] << " of " << map_pintas[mazo_actual[i] / 13] << endl;
        }

        contador++;
    }

return 0;
}
