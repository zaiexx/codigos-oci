#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int V, E, a, b, s, d, n;

vector<vii> AdjList;

int main() {

    while (cin >> V >> E) {

        AdjList.assign(V, vii());

        for (int i = 0; i < E; i++) {

            cin >> a >> b;
            a--;
            b--;

            AdjList[a].push_back(ii(b, 0));
            AdjList[b].push_back(ii(a, 0));
        }

        cin >> s >> d >> n;

        s--;
        d--;
        n--;

        // COMIENZA EL BFS
        vi dist(V, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            if (u == n) {
                continue;
            }

            for (int j = 0; j < (int)AdjList[u].size(); j++) {

                ii v = AdjList[u][j];

                if (dist[v.first] == INF) {
                    dist[v.first] = dist[u] + 1;
                    q.push(v.first);
                  }
            }
        }

        cout << dist[d] << endl;
    }

  return 0;
}
