#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string p1,p2;
	cin >> p1 >> p2;
	
	int t1 = p1.size(), t2 = p2.size();
	int mat[t1+1][t2+1], total = 0,pos = 0; //se crea matriz con ambas palabras
	
	//se rellena la primera fila y columna con 0
	for(int a = 0; a <= t1; a++) mat[a][0] = 0;
	for(int a = 0; a <= t2; a++) mat[0][a] = 0;
	
	//se inicia el LCS
	for(int a = 1; a <= t1; a++){
		for(int b = 1; b <= t2; b++){
			if(p1[a-1] == p2[b-1]){ //si los char son iguales 
				mat[a][b] = mat[a-1][b-1] +1; //la pos actual es su diagonal +1
				if(mat[a][b] > total) pos = a; //poner si se quiere saber cual es el substr
				total = max(total, mat[a][b]); //el tamaño va a ser el max entre el guardado y la pos actual
			}else{
				mat[a][b] = 0; //si no son iguales vale 0
			}
		}
	}
	
	cout << total << "   : "<< p1.substr(pos-total,total); //imprimo el substr desde la pos de fin-total
	
	return 0;
}
