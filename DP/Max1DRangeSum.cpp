#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n; //numero de elemntos del arreglo
	scanf("%d",&n);
	int arr[n];
	
	for(int a = 0; a < n; a++) scanf("%d",&arr[a]); //leo los elementos
	
	//sum guarda la suma mas reciente, ans la suma mas grande, iniT es un inicio temporal
	int sum = 0, ans = INT_MIN, inicio = 0, iniT = 0, final = 0;
	
	for(int a = 0; a < n; a++){ //recorro el arreglo, se calcula en O(n)
		sum += arr[a]; //sumo el numero actual
		
		//si quieres calcular ademas de la suma su ini y final usa este if
		if(ans <= sum){ //si la suma se vuelve mas grande q la que recuerdo
		//ans < sum da como resultado la primera MRS, ans <= sum da la ultima MRS (en caso de haber mas de un MRS)
			ans = sum; 
			inicio = iniT; //el inicio temporal pasa a ser el oficial
			final = a; //el final pasa a ser la pos actual
		}
		
		//ans = max(ans,sum); //si solo quieres la suma comenta el if de arriba e usa este max
		
		if(sum < 0){ //si la suma da negativo lo reseteo a 0
			sum = 0;
			//se guarda como un inicio temporal la pos siguiente al reinicio
			iniT = a+1;	//si solo quieres la suma comenta esta linea
		}
	}
	
	printf("suma mas larga: %d desde %d hasta %d\n",ans,inicio,final);
	
	return 0;
}
