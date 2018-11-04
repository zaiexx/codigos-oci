#include<bits/stdc++.h>
#define printMat(arr,u,v) for(int a = 0; a < u; a++) for(int b = 0; b < v; b++) printf("%d%s",arr[a][b],b==v-1 ? "\n":" ")

using namespace std;

int main(){
	
	int n,w; //cantidad de objetos y tamaño de la mochila respectivamente
	scanf("%d %d",&n,&w);
	
	int pesos[n], valores[n], mochila[n+1][w+1]; //la mochila al igual q el edit distance deben tener una fila y columna extra con ceros
	//las columnas significan los items y las filas son mochilas de tamaños de 0 a w
	
	for(int a = 0; a < n; a++) scanf("%d %d",&pesos[a],&valores[a]); //leo los objetos con sus pesos y valores
	
	//relleno las primeras filas y columnas con ceros (cuantos items caben en un espacio de 0)
	for(int a = 0; a <= n; a++) mochila[a][0] = 0;
	for(int a = 0; a <= w; a++) mochila[0][a] = 0;
	
	//inicio el dp, es una combinacion entre el problema de las monedas y el de los strings
	for(int a = 1; a <= n; a++){
		for(int b = 1; b <= w; b++){
			
			if(pesos[a-1] <= b){ //si el objeto cabe en una mochila de tamaño b
				//escojo el maximo entre la solucion anterior para este tamaño o el valor del objeto actual + la solucion optima para una mochila del tamaño que falta por rellenar
				mochila[a][b] = max(mochila[a-1][b], valores[a-1] + mochila[a-1][b-pesos[a-1]]); 
			}else{
				//si el objeto no cabe la se toma la solucion que se calculo antes para este tamaño
				mochila[a][b] = mochila[a-1][b];
			}
		}
	}
	
	printMat(mochila,n+1,w+1); //la solucion seria la ultima casilla, la cual significa la ganancia maxima para una mochila de tamaño w
	//la ultima fila son las ganancias maximas para mochilas con tamaños de 0 hasta w
	
	//para saber los objetos que se utilizaron se debe recorrer mochila al revez
	
	int tam = w; //creo una copia del tamaño de la mochila puesto que vamos a usarla como un contador
	vector<int> items; //creo un vector para ir pusheando los items que se usaron
	
	for(int a = n; a > 0; a--){
		if(mochila[a][tam] == mochila[a-1][tam]) continue; //si la solucion en la pos a es igual a una calculada antes significa que no se uso el item a
		else{
			//si resulta que la solucion es distinta a la anterior significa que el item a si se uso
			items.push_back(pesos[a-1]); //pusheo el peso del item usado al arreglo (se podria pushear lo que sea, en este caso ocupo los pesos para identificar, pero podrian ser nombres)
			tam -= pesos[a-1]; //a tam le resto el peso del item usado, asi empiezo a buscar el item que se uso con el espacio que falta
		}
	}
	
	printf("pesos de los items usados: ");
	for(int a = 0; a < items.size(); a++) printf("%d, ",items[a]);
	
	
	return 0;
}
