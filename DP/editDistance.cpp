#include<bits/stdc++.h>
#define printMat(arr,u,v) for(int a = 0; a < u; a++) for(int b = 0; b < v; b++) printf("%d%s",arr[a][b],b==v-1 ? "\n":" ")
#define printArr(arr,u) for(int a = 0; a < u; a++) printf("%d%s",arr[a],a==u-1 ? "\n":" ")

using namespace std;


int main(){
	
	int addCost = 1;
	int delCost = 1;
	int modCost = 1;
	
	string p1,p2;
	cin >> p1 >> p2;
	
	int t1 = p1.size()+1, t2 = p2.size()+1;  //creo las variables tamaño, son el tamaño de las palabras + 1
	int dist[t1][t2]; //creo la matriz de las distancias
	
	//relleno las primeras filas y columnas con lo que costaria llegar de nada a 'x' letra 
	for(int a = 0; a < t1; a++) dist[a][0] = a * addCost;
	for(int a = 0; a < t2; a++) dist[0][a] = a * addCost;
	
	//empiezo a dar los valores, escogiendo el minimo entre eliminar, agregar o modificar
	for(int a = 1; a < t1; a++){
		for(int b = 1; b < t2; b++){
			
			//hay que hacer el minimo entre una opcion y el minimo entre las otras dos (porque min solo acepta 2 parametros)
			dist[a][b] = min( dist[a-1][b] + delCost, //eliminar
						 min( dist[a][b-1] + addCost,  //agregar
							  dist[a-1][b-1] + (p1[a-1] == p2[b-1] ? 0 : modCost))); //cambiar
		}
	}
	
	printMat(dist,t1,t2);
	
	return 0;
}
