#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string,int> visitados;
map <string,vector<string> > grafo;

int bfs(string inicio, string destino){

    queue<string> s;
    s.push(inicio);
    visitados[inicio] = 0;

    while(!s.empty()){

        string top = s.front();
        s.pop();
        if (top == destino) {
            return visitados[top];
        }

        int total = grafo[top].size();

        for (int i = 0; i < total; i++) {
            if(!visitados.count(grafo[top][i])) {
                visitados[grafo[top][i]] = visitados[top]+1;
                s.push(grafo[top][i]);
            }
        }
    }
}

int main(){

//    freopen("input.in","r",stdin);
//    freopen("output.out","w",stdout);

    int n;
    cin >> n;

    while(n--){

        //limpiamos el grafo
        grafo.clear();
        string palabra, tmp;
        cin >> palabra;

        while(palabra != "*") {

            //Inicializamos la palabra en el grafo
            //se puede hacer más elegante!
            grafo[palabra];

            map<string, vector<string> >::iterator it;

            for (it = grafo.begin(); it != grafo.end(); ++it) {
                tmp = (*it).first;
                int tamTmp = tmp.size(), dif = 0;
                if (tamTmp == palabra.size()){
                    for (int i = 0; i < tamTmp && dif<2; ++i) {
                        if(tmp[i] != palabra[i]) {
                            dif++;
                        }
                    }

                    if(dif == 1) {
                        grafo[tmp].push_back(palabra);
                        grafo[palabra].push_back(tmp);
                    }
                }
            }
            cin >> palabra;
        }

        string inicio, destino, linea;
        size_t pos;

        //Limpiamos el buffer
        getline(cin,linea);
        getline(cin,linea);

        while(linea != "") {

            pos = linea.find(" ");
            inicio = linea.substr(0, pos);
            destino = linea.substr(pos+1, linea.size());
            visitados.clear();
            cout << inicio << " " << destino << " " << bfs(inicio, destino) <<endl;

            if(!getline(cin,linea)) {
                break;
            }
        }

        if(n != 0) {
            cout<<endl;
        }
//        grafo.clear();
    }

  return 0;
}
