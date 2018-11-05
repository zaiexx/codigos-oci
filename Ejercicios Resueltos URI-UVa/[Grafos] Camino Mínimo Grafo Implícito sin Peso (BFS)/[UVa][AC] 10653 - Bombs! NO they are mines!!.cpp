#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef unsigned long long ll;

#define MAX_TAM 1000
#define NO_VISITADO -1


//Declaramos todo global, mas facil de trabajar
int F, C, NB, r, nbr, c;
int dist[1000][1000];
int tablero[MAX_TAM][MAX_TAM];

ii inicio, destino;

//movimientos validos
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};


bool limites(int x, int y) {
    return x >= 0 && x < F && y >= 0 && y < C;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> F >> C) {

        if (F == 0 && C == 0) {
            return 0;
        }
        cin >> NB;

        //inicializamos la matriz a 0, mejor que hacer 2 for
        //memset es de la libreria cstring
        memset(tablero, 0, sizeof tablero);

        while (NB--) {

            cin >> r >> nbr;
            while (nbr--) {
                cin >> c;
                //hay bomba
                tablero[r][c] = 1;
            }
        }

        cin >> inicio.first >> inicio.second;
        cin >> destino.first >> destino.second;

        //el tablero lo marcamos NO VISITADO
        memset(dist, NO_VISITADO, sizeof dist);

        queue <ii> q;
        q.push(inicio);
        dist[inicio.first][inicio.second] = 0;

        while (!q.empty()) {

            ii u = q.front(); q.pop();

            for (int d = 0; d < 4; d++) {

                int nx, ny;

                nx = u.first + dr[d];
                ny = u.second + dc[d];

                if (limites(nx, ny) && !tablero[nx][ny] && dist[nx][ny] == NO_VISITADO) {
                    ii v = ii(nx, ny);
                    //uno mas a la distancia
                    dist[nx][ny] = dist[u.first][u.second] + 1;
                    if (v == destino) {
                        cout << dist[nx][ny] << "\n";
                        break;
                    }
                    q.push(v);
                }
            }
        }
    }



	return 0;
}
