#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//Inicialmente, el costo entre dos nodos es un numero MUY grande
#define INF 1000000000

vector<vii> AdjList;

int main() {

    int V, E;
    int inicio, u, v, peso;

    cin >> V >> E;
    AdjList.assign(V, vii());

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> peso;
        AdjList[u].push_back(ii(v, peso));
    }

    cin >> inicio;
    vi dist(V, INF);

    //La distancia en el punto que partimos es 0
    dist[inicio] = 0;

    // CREAMOS COLA DE PRIORDAD PARA QUE ORDENE DE MENOR A MAYOR
    priority_queue< ii, vector<ii>, greater<ii> > pq;

    // IMPORTANTE: ENCOLAMOS los nodos al reves, el par (distacia, nodo),
    // asi se ordena por distancia dentro de la cola,
    // al sacar un nodo, sacaremos el mas proximo (menor distancia)


    //nodo origen
    pq.push(ii(0, inicio));

    while (!pq.empty()) {

        ii front = pq.top();
        pq.pop();

        // en la cola, first es distancia
        int d = front.first;
        int u = front.second;

        //Si la distancia para llegar al nodo u es mas costosa que algun otro camino hacia u,
        // no procesamos ese nodo
        if (d > dist[u]) {
            continue;
        }

        // por cada vecino de u en la lista
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            // si la distancia hasta u mas la distancia del vecino v (ACA second es
            // distancia ya que v es el nodo en la lista de adyacencia) es menor
            // que alguna distancia previa al vecino v, actualizamos la distancia
            if (dist[u] + v.second < dist[v.first]) {
                // v.first es nodo, v.second es distancia
                dist[v.first] = dist[u] + v.second;
                //encolamos al reves nuevamente, (distancia, nodo)
                //debemos procesar los vecinos de v
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }


    for (int i = 0; i < V; i++) {
        cout << "Distancia minima desde" << inicio << " hasta "<< i << "es: " << dist[i] << endl;
    }

return 0;
}
