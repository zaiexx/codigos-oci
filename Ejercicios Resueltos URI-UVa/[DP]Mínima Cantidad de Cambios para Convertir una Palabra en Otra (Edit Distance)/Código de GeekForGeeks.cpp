//Minimo numero de operaciones para convertir
//un string str1 en str2

#include<bits/stdc++.h>
using namespace std;

//minimo entre 3 numeros
int min(int x, int y, int z)  {
    return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int m, int n)  {

    int dp[m+1][n+1];

    for (int i=0; i<=m; i++)  {
        for (int j=0; j<=n; j++) {

            //Si el string 1 es vacio, el costo minimo sera j
            if (i == 0) {
                dp[i][j] = j;  // Min. operations = j
            }else if (j==0) {
            //Si el string 2 es vacio, el costo minimo sera i
                dp[i][j] = i; // Min. operations = i

            }else if (str1[i-1] == str2[j-1]) {
                //el ultimo caracter de ambas cadenas es el mismo, nos saltamos al anterior
                dp[i][j] = dp[i-1][j-1];
            } else {
                //si el ultimo caracter es distinto
                //nos quedamos con el menor entre insertar, remover o remplazar el caracter
                //diferente
                dp[i][j] = 1 + min(dp[i][j-1],  // Insertar
                                   dp[i-1][j],  // Remover
                                   dp[i-1][j-1]); // Reemplazar
            }
        }
    }

    return dp[m][n];
}

int main()  {

    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;
}
