#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define NO_VISITADO -1

typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

vi visitados;
vector <vii> AdjList;

void dfs (int u) {

    visitados[u] = 1;

    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (visitados[v.first] == NO_VISITADO) {
            dfs(v.first);
        }
    }
}

int main () {

    int V, E;
    int i, idx;

    string n1, rel, n2;
    cin >> V >> E;

    AdjList.assign(V, vii());

    map <string, int> mapper;

    for (i = idx = 0; i < E; i++) {
        cin >> n1 >> rel >> n2;

        if (mapper.find(n1) == mapper.end())
          mapper[n1] = idx++;

        if (mapper.find(n2) == mapper.end())
          mapper[n2] = idx++;


        AdjList[mapper[n1]].push_back(ii(mapper[n2],0));
        AdjList[mapper[n2]].push_back(ii(mapper[n1],0));
    }

    visitados.assign(V,NO_VISITADO);
    int totalComponentesConexas = 0;

    for (int i = 0; i < V; ++i) {
        if (visitados[i] == NO_VISITADO) {
            totalComponentesConexas++;
            dfs(i);
        }
    }

    cout << totalComponentesConexas << endl;  return 0;

return 0;
}
