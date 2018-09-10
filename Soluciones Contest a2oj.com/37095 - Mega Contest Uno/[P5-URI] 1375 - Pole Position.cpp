#include <iostream>
#include <cstring>

using namespace std;

int main () {
    
  int n_autos;
  int id_auto, posicion;
  
  while (cin >> n_autos) {
    
    if (n_autos == 0) {
      return 0;   
    }
    
    int posiciones[n_autos];
    memset(posiciones, 0, sizeof posiciones);
    
    bool valido = true;
    
    for (int i = 0; i < n_autos; i++) {
      cin >> id_auto >> posicion;
      
      int ind = i + posicion;
      
      if (ind < 0 || ind >= n_autos) {
        valido = false;
      }else {
        
        if (posiciones[ind] == 0) {
          posiciones[ind] = id_auto;
        }else {
          valido = false;
        }
      }
    }
      
    if (!valido) {
      cout << "-1" << endl;
    }else {
      for (int i = 0; i < n_autos; i++) {
        cout << posiciones[i];
        if (i == n_autos-1) {
          cout << endl;
        }else {
          cout << " ";
        }
      }
    }
  }
  
  return 0;  
}