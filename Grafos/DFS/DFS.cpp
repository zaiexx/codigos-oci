#include <iostream>
#include <vector>
using namespace std;
// Definiremos la constante NO_VISITADO como -1
#define NO_VISITADO -1
// Par de enteros. Lo utilizaremos para especificar un nodo y su costo.
typedef pair <int, int> ii;
// Vector de enteros. Lo utilizaremos para crear el vector de visitados.
typedef vector <int> vi;
// Vector de pares. Lo utilizaremos para guardar todos los vecinos de
// un nodo.
typedef vector <ii> vii;
// Vector de enteros. Lo utilizaremos para representar que el nodo i
// fue visitado. 1 para visitado. -1 para NO visitado.
vi visitados;
// Vector de Vectores para representar nuestra lista de adyacencia
vector <vii> AdjList;
// El DFS nos permitira explorar el grafo en profundidad. Generalmente
// utilizaremos DFS para encontrar ciclos, contar componentes conexas
void dfs (int u) {
    // Marcamos el nodo u como visitado.
    visitados[u] = 1;
    // Por cada vecino que tenga el nodo u, haremos un dfs si es
    // que ese vecino no fue visitado anteriormente
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      // por comodidad, rescatamos el vecino j del nodo u
      ii v = AdjList[u][j];
      // si no hemos visitado al vecino v, entonces hacemos dfs.
      // Usamos first ya que el vecino es un par (nodo,peso)
      if (visitados[v.first] == NO_VISITADO) {
         // dfs desde el vecino
         dfs(v.first);
      }
    }
}

int main() {
  // V representa la cantidad de nodos. E representa
  // la cantidad de aristas (conexiones) entre estos V nodos
  int V, E;
  // Generalmente nos daran la info de V o E.
  // Sino lo dan de manera explícita es porque se puede calcular
  cin >> V >> E;
  // Inicializamos nuestra lista de adyacencia con V
  // vectores de pares (vii) vacios
  AdjList.assign(V, vii());
  // Llenamos nuestra lista de adyacencia.
  for (int i = 0; i < E; i++) {
    int u, v;
    // leemos los datos de los nodos en conexion
    cin >> u >> v;
    // Agregamos a nuestra lista la conexion entre el nodo u y el v.
    // Si el grafo no tiene peso usamos un 0 en el par
    // Si el grafo tiene peso reemplazamos el 0 por el peso de
    // la arista (conexion). Si los nodos parten en 1 y no 0,
    // hacer --u, --v
    AdjList[u].push_back(ii(v,0));
    // Si es que el grafo es NO dirigido, o sea, puede ir de A a B
    // y de B a A, agregamos el par inverso a la lista de adyacencia
    AdjList[v].push_back(ii(u,0));
  }
  // Para sacar el numero total de componentes conexas, recorremos todos
  // nuestros nodos. Usamos para esto el vector de visitados.
  // Si el nodo i NO esta visitado, contamos una componente conexa y
  // hacemos DFS (el DFS marcara como visitados todos los nodos vecinos a
  // este)
  // Inicializamos todos nuestros nodos como NO visitados
  visitados.assign(V,NO_VISITADO);
  // Inicialmente tenemos 0 componentes conexas
  int totalComponentesConexas = 0;
  
  for (int i = 0; i < V; ++i) {
    // si no hemos visitado este nodo
    if (visitados[i] == NO_VISITADO) {
      // contamos una componente conexa
      totalComponentesConexas++;
      // hacemos DFS desde el nodo
      dfs(i);
    }
  }
  
  cout << totalComponentesConexas << endl;
return 0;
}