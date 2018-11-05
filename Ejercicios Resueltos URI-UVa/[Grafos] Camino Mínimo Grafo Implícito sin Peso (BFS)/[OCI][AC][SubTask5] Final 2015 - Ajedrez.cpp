// Solucion problema FINAL NACIONAL OCI 2015
// Subtarea para el caballo!
// Dada la posicion del caballo en un tablero de ajedrez
// Determinar el minimo camino posible para llegar a
// Una posicion cualquier dal tablero

#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

#define MAX_F 110
#define MAX_C 110
#define INF 100000000

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int tablero [MAX_F][MAX_C];


//arreglo de movimientos para un caballo en un tablero de ajedrez
/*
	Posibles movimientos:
    ..1.2..
    .8...3.
    ...C...
    .7...4.
    ..6.5..
    .......
*/

//            1   2   3   4   5   6   7   8
int df[] = { -2, -2, -1,  1,  2,  2,  1, -1};
int dc[] = { -1,  1,  2,  2,  1, -1, -2, -2};


bool limites (int x, int y) {
	// Validamos que nos estamos moviendo dentro de los limites del tablero
	// Mas claro hacerlo con una funcion
	return (x >= 0 && x < MAX_F && y >= 0 && y < MAX_C);
}

void init() {
	//Inicializar todo el tablero como No visitado
	//Como BFS calcula distancia minima, marcamos como que la distancia
	//A cualquier punto del tablero es un numero MUY grande

	for (int i = 0; i < MAX_F; i++) {
		for (int j = 0; j < MAX_C; j++) {
			tablero[i][j] = INF;
		}
	}
}

int main () {


    int P;

    cin >> P;

    //subtarea 5
    if (P == 5) {

        // par de coordenadas para el punto de partida y para el punto de destino
        // usaremos pares por comodidad al momento de representar las coordenadas
        ii partida;
        ii destino;


        // inicializamos la matriz con distancias infinitas
        init();

        // leemos datos de partida y de destino (son coordenadas x,y)
        cin >> partida.first >> partida.second;
        cin >> destino.first >> destino.second;

        // BFS
        // usamos cola de pares para representar coordenadas a procesar
        // recordar que ahora cada nodo es un par (x,y) en el tablero

        queue <ii> q;
        q.push(partida);

        //la distancia del tablero en su punto de partida es 0
        tablero[partida.first][partida.second] = 0;

        bool encontrado = false;
        int distancia = 0;

        // Si el destino es igual a la partida, distancia es 0
        // Comparamos pares directamente
        if (partida == destino) {
            cout << 0 << endl; // Mismo punto
        }else {

            // Mientras podamos procesar nodos
            while (!q.empty()) {

                // recuperamos la coordenada actual
                ii nodoActual = q.front();

                // quitamos el nodo de la cola
                q.pop();

                // Los vecinos de la coordenadas seran todos los movimientos
                // validos desde ese punto
                for (int i = 0; i < 8; i++) {
                    int nx, ny;
                    //nuevo movimiento para la coordenada x e y
                    nx = nodoActual.first + df[i];  // coordenada x vecino i
                    ny = nodoActual.second + dc[i]; // coordenda y vecino i

                    // Si no hemos visitado esa parte del tablero y estamos dentro de
                    // los limites
                    if (limites(nx, ny) && tablero[nx][ny] == INF) {
                        ii nodoSiguiente = ii(nx, ny);
                        // Calculamos la distancia al vecino como la distancia actual+1
                        // Si la distancia entre nodos NO es 1, NO SIRVE BFS
                        // En ese caso usar Dijkstra

                        tablero[nx][ny] = tablero[nodoActual.first][nodoActual.second] + 1;

                        //si llegamos al destino, terminamos y recuperamos la distancia
                        if (nodoSiguiente == destino) {
                            encontrado = true;
                            distancia = tablero[nx][ny];
                            break;
                        }

                        // encolamos la siguiente coordenada
                        q.push(nodoSiguiente);
                    }
                }
            }

            // Si pudimos llegar al destino
            if (encontrado) {
                cout << distancia << endl;
            }else {
                cout << -1 << endl;
            }
        }
    }

	return 0;
}
