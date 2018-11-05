#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

#define INF 1000000000


int main () {

    int casos;
    int V, E;
    int s, destino;
    int u, v, w;

    cin >> casos;
    int k = 0;

    while (casos--) {

        cin >> V >> E >> s >> destino;

        int tmp;
        tmp = s;
        s = destino;
        destino = tmp;

        vector<vii> AdjList;
        AdjList.assign(V, vii());

        while (E--) {
            cin >> u >> v >> w;
            AdjList[u].push_back(ii(v,w));
            AdjList[v].push_back(ii(u,w));
        }

        vi dist(V, INF);
        dist[s] = 0;

        priority_queue< ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s));

        while (!pq.empty()) {

            ii front = pq.top();
            pq.pop();

            int d = front.first, u = front.second;

            if (d > dist[u]) {
                continue;
            }

            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }

        k++;
        if (dist[destino] != INF) {
            cout << "Case #" << k << ": " << dist[destino] << endl;
        }else {
            cout << "Case #" << k << ": unreachable" << endl;
        }
    }

return 0;
}
