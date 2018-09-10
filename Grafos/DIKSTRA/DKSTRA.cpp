#include<bits/stdc++.h>
#define INF 1e9+7
using namespace std;

typedef pair<int,int> ii; //creo el tipo de dato ii (es un par de enteros)
typedef vector<int> vi; //creo el tipo de dato vi (es un vector de enteros)
typedef vector<ii> vii; //creo el tipo de dato vii (es un vector de pares de enteros)

bool srt(ii a, ii b){return a.second < b.second;} //funcion para ordenar de menor a mayor

struct dkstra{ //creo la estructura dkstra (basicamente es un objeto pero de c, recuerden la clase)

	vector<vii> grafo; //inicializo el vector de pares que sera el grafo
	vi dis; //creo un vector de enteros que almacenara las distancias desde todos los nodos al q indique como destino
	int tam;
	
	dkstra(int nodos){ //cuando cree una variable dkstra esta funcion se activa, hay q pasarle el total de nodos
	
		grafo.assign(nodos,vii()); //le asigno al vector el tamaño necesario
		tam = nodos; // guardo el tamaño en la variable global de dkstra
	}
	
	void push(int N,int D,int P){//ingreso el nodo,el destino y peso. pone como vecino de N a D pero no al reves N --> D
	
		grafo[N].push_back(ii(D,P));
	}
	
	void pushTwo(int N,int D,int P){//lo mismo q el de arriba pero este conecta bidireccional. N <--> D
	
		grafo[N].push_back(ii(D,P));
		grafo[D].push_back(ii(N,P));
	}
	
	int magia(int ini,int des){ //la funcion magia recibe el nodo inicial y el final. devuelve la distancia minima
	
		dis.assign(tam,INF); //asigno el tamaño del vector de las distancias y lo lleno de infinitos
		priority_queue<ii, vii, srt> cola; //inicializo una cola que ordena de meno a mayor. el dato first es el nodo y el dato second es la distancia
		
		dis[ini] = 0;//la distancia del inicio a si mismo es 0
		
		cola.push(ii(ini,dis[ini]));//meto a la cola el nodo y la distancia
		
		int total; //inicio la variable q guardara el tamaño del camino minimo
		
		while(!cola.empty()){ //hasta q no haya ningun nodo en la cola
			
			ii pos = cola.top();//guardo el dato q esta arriba de la cola
			cola.pop();//borro el dato de la cola
			int tdis = pos.second,tnod = pos.first;//desmenuso el pair
			if(tdis > dis[tnod])continue;//si la distancia es mayor a la guardada ignora
			
			for(int a = 0; a < grafo[tnod].size(); a++){
				ii vecino = grafo[tnod][a];//saco a un vecino
				if(dis[tnod] + vecino.second < dis[vecino.first]){
					//si la suma de las distancias es menor a la registrada las guardo
					dis[vecino.first] = dis[tnod] + vecino.second;
					cola.push(ii(vecino.first,dis[vecino.first]));//encolo el vecino
					if(dis[des] < INF) total = dis[des];//si el vecino lo encuentra almaceno
				}
			}
		}
		return total;
	}
	
	int getdis(int x){return dis[x];};
};

int main(){
	
	dkstra dk(5);
	dk.push(0,4,3);
	dk.push(4,1,1);
	dk.push(0,1,20);
	dk.push(1,3,2);
	dk.push(1,2,5);
	
	printf("%d\n\n",dk.magia(0,2));
	printf("%d\n\n",dk.magia(2,0));
	for(int a = 0; a < 5; a++)printf("%d\n",dk.getdis(a));
	
	return 0;
}
