#include<bits/stdc++.h>
#define INF 1e9+7

using namespace std;

int main(){
	
	int n,money; //cantidad de monedas y el dinero
	scanf("%d %d",&n,&money);
	
	int cambio[money+1], monedas[n]; //el arreglo cambio tendra las monedas necesarias para dar n pesos
	for(int a = 0; a < n; a++) scanf("%d",&monedas[a]); //el arreglo monedas guarda las monedas
	
	cambio[0] = 0; //para devolver 0 pesos se requieren 0 monedas
	
	for(int a = 1; a <= money; a++){ //recorremos cambio desde la pos 1
		cambio[a] = INF; //asignamos un valor grande a la pos para que busque el minimo
		
		//si se ponen 0 como lo hicimos en clase da error, por ej con {2,3} sacar las monedas para 4
		//da 1 porque llegaria al 4, resta 3 y llega al 1 que estaba iniciado como 0
		
		for(int b = 0; b < n; b++){ //recorremos las monedas
			if(a-monedas[b] >= 0){ //si puedo restarle la moneda significa que puedo usar esa
				//escogo el min entre mi opcion actual o una que calcule antes mas una moneda mas
				cambio[a] = min(cambio[a], cambio[a-monedas[b]] + 1);  
			}
		}
	}
	//imprimo la matriz, cada pos es la cantidad de monedas para devolver a dinero
	for(int a = 0; a <= money; a++) printf("%d, ",cambio[a]); 
	
	
	
	return 0;
}
