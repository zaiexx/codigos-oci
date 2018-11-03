#include <iostream>

using namespace std;

#define MAX_FILAS 150
#define MAX_COLUMNAS 150

// Trabajaremos el tablero como char y lo crearemos tan grande
// como el maximo numero de la entrada (aunque dependiendo el problema)
// puede que el tablero deba ser creado como int

char grilla[MAX_FILAS][MAX_COLUMNAS];


// Arreglo de movimientos. Como es que nos moveremos por la grilla
// Representa todos los posibles movimiento en filas y columnas.
// Es el cambio de coordenadas para cada movimiento
// df = filas
// dc = columnas
// Dependiendo el problema, es como creamos el arreglo de movimiento
// Para 8 movimientos quedaria algo asi

/*  .....
    .123.
    .8X4.
    .765.
    .....
*/

// Si queremos ir desde X a 1, debemos restar 1 a la fila y debemos restar 1 a la columna
// Si queremos ir desde X a 4, la fila no cambia, y debemos sumar 1 a la columna
// Estos movimientos los representamos con los arreglos a continuación.

// movi:     1   2   3   4   5   6   7   8
int df[] = {-1, -1, -1,  0,  1,  1,  1,  0}; 
int dc[] = {-1,  0,  1,  1,  1,  0, -1, -1}; 


// Si fueran solo 4 movimientos, tipo norte, sur, este, oeste quedaria:
// int df[] = {-1, 1, 0,  0}
// int dc[] = { 0, 0, 1, -1}

// Si es un movimiento personalizado, hacer lo mismo y ver como cambian las
// coordenadas en la matriz

// DFS. Recorremos la matriz buscando el caracter c1.
// Si lo encontramos lo cambiaremos por el caracter c2 
// El cambio es para marcar como vistado y no pasar denuevo por ahi
// Contaremos la cantidad de cambios hechos

int dfs(int f, int c, char c1, char c2) {

	// Verificamos limites de la grilla. Si estamos fuera, devolvemos 0
	// (0 caracteres c1 encontrados)
	if (f < 0 || f >= MAX_FILAS || c < 0 || c >=MAX_COLUMNAS) {
		return 0;
	}

	// Si el caracter en la posicion [f, c] no era el buscado.
	// Devolvemos 0 (0 caracteres c1 encontrados)
	
	if (grilla[f][c] != c1) {
		return 0;
	}

	// Si llegamos aca es porque estamos dentro de la grilla y
	// porque encontramos el caracter c1
	// Marcamos visitada la posicion [f,c]. Cambiamos c1 por c2
	// c2 debe ser un caracter nunca antes usado
	// si son numeros, usar como visitado un numero que no se use

	grilla[f][c] = c2; //vistado


	// Hasta este punto hemos cambiado 1 caracter
	// (visto desde otra forma, nuestra componente conexa tiene 1 nodo)
	
	int ans = 1;

	// Tenemos en total 8 movimientos (puede variar segun el problema)
	for (int i = 0; i < 8; ++i) {
		// llamada recursiva por cada posible movimiento. Contamos cuantos
		// caraceres pintamos (o cuantos nodos tiene la componente)
		ans += dfs(f + df[i], c + dc[i], c1, c2);
	}

	// Devolvemos el total de elementos en la componente conexa
	// o cuantos caraceres reemplazamos, visitamos, pintamos, etc...
	return ans;
}



int main() {
	
	// llenamos la matriz
	// tamano 10 a modo de ejemplo
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> grilla[i][j];
		}
	}


	// buscaremos cuantas componentes conexas con '1' existen
	int totalComponentesConexas = 0;

	// recorremos la grilla

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			// si la posicion i,j no ha sido visitada
			if (grilla[i][j] == '1') {
				// contamos una componente
				totalComponentesConexas++;
				// DFS. Marcamos con X los visitados
				dfs(i,j,'1','x');
			}
		}
	}

	cout << totalComponentesConexas;
	
	return 0;
}
