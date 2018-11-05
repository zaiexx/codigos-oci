#include <iostream>
#include <queue>
#include <vector>

//Este codigo considera que los nodos comienzan desde 0
//Si los nodos parten de 1 hasta N, restarles 1 al momento de guadar en la lista

using namespace std;
// Numero muy grande. Tambien sirve tener un numero negativo
#define INF 1000000000
// Par de enteros. Lo utilizaremos para especificar un nodo y su costo.
typedef pair <int, int> ii;
// Vector de enteros. Lo utilizaremos para crear el vector de visitados.
typedef vector <int> vi;
// Vector de pares. Lo utilizaremos para guardar todos los vecinos de un nodo.
typedef vector <ii> vii;
// Vector de Vectores para representar nuestra lista de adyacencia
vector <vii> AdjList;
// Vector de int para guardar el padre/antecesor del nodo actual
vi p;
//Minima ruta desde inicio a destino
int inicio, destino;

// Imprimiremos el camino hasta el nodo u
void imprimirCamino (int u) {
  // si el nodo u es igual al nodo donde partimos el BFS, imprimimos el valor
  // y terminamos. inicio declarada global
  if (u == inicio) {
    cout << u;
    return;
  }
  // Llamada recursiva con el padre de u, formato de la impresion
  // inicio ->...->...-->destino
  imprimirCamino(p[u]);
  cout << " " << u;
}


int main() {
  //total de nodos (V) y total aristas (E) del grafo
  int V, E;
  cin >> V >> E;
  //asignamos tanto espacio a nuestra lista como nodos tengamos en el grafo.
  // Del tipo vii
  AdjList.assign(V, vii());
  
  for (int i = 0; i < E; ++i) {
    int nodo1, nodo2;
    cin >> nodo1 >> nodo2;
    //Si los nodos parten de 0, lo agreamos directamente. Sino,
    // debemos restarle 1. Si el grafo es NO dirigido, tambien debemos agregar
    // el otro nodo de la relacion: AdjList[nodo2].push_back(make_pair(nodo1,0))
    AdjList[nodo1].push_back(make_pair(nodo2,0));
  }
  
  cin >> inicio >> destino;
  // Inicialmente, ningun nodo tiene padres asi que asignamos -1 para cada nodo
  p.assign(V, -1);
  // Vector para marcar el camino recorrido y guardar la distancia.
  // Inicialmente la distancia hacia cualquier nodo es INF
  // (o podria ser -1 o cualquier negativo)
  vi dist(V, INF);
  // La distancia al nodo inicial es 0
  dist[inicio] = 0;
  // La cola nos permitira procesar los nodos en el orden que van siendo
  // visitados. La gran diferencia con el DFS es que aca procesaremos los nodos
  // una vez terminado de explorar todos los vecinos del nodo actual, mientras
  // que en el DFS vamos visitando los vecinos inmediatamente. Ej vida diaria:
  // DFS seria estar haciendo algo y de repente me dieron ganas de hacer otra
  // cosa, entonces dejo de hacer lo que estoy haciendo y empiezo a hacer esta
  // nueva actividad. Si mientras hago esta nueva actividad quiero hacer otra
  // nueva, lo mismo. Dejo de hacer la actual y empiezo la nueva. Una vez
  // terminada la ultima actividad, vuelvo atras a la anterior y la termino.
  // Voy dejando cosas en espera. BFS seria empezar la nueva actividad (o todas
  // las nuevas actividades) solo cuando termino de hacer la que estoy haciendo
  // actualmente. Para generar esa espera usamos una cola(queue)
  
  queue <int> q;
  // procesamos el nodo actual
  q.push(inicio);
  //mientras nos queden nodos por procesar
  while (!q.empty()) {
    // Recuperamos el nodo actual. En las colas, es obligación eliminar el
    // elemento (pop) para poder pasar al siguiente. front nos devuelve el
    // nodo actual
    int actual = q.front();
    q.pop();
    //recorremos todos los vecinos del nodo actual
    for (int j = 0; j < (int)AdjList[actual].size(); j++) {
      // recuperamos la indo del vecino j
      ii vecino = AdjList[actual][j];
      // sino hemos visitado al vecino j
      if (dist[vecino.first] == INF) {
        dist[vecino.first] = dist[actual] + 1;
        // el padre de vecino es actual
        p[vecino.first] = actual;
        q.push(vecino.first);
      }
    }
  }
  
  cout << "Camino minimo = " << dist[destino] << endl;
  
  return 0;
}
