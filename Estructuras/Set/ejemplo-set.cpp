/* Set sirve para almacenar elementos unicos. Los datos repetidos que son guardados en un set no
se insertan, esto permite guardar una copia de cada valor. Si me dan N datos y me preguntan cuantos
elementos repetidos nos ingresaron, puedo con un set rapidamente saber sin necesidad de recorrer los datos
ya que si nos ingresan 100 elementos, pero el tamaño del set es 80, significa que habian 20 repetidos.
Los datos en un set se ordenan de menor a mayor*/

#include <iostream>
#include <set>

using namespace std;

int main () {

    set <int> datos;

    for (int i = 0; i < 10; i++) {
        //guardamos i en el set
        datos.insert(i);
    }

    for (int i = 0; i < 10; i++) {
        //guardamos mas datos en el set
        datos.insert(i*2 - 1);
    }

    //hemos ingresado 20 datos. Dos for de 10

    cout << "La cantidad de datos que se repitieron fue: " << 20 - datos.size() << endl;


    set<int>::iterator it;

    cout << "Los datos guardados fueron: " << endl;
    for (it = datos.begin(); it != datos.end(); it++) {
        cout << (*it) << endl;
    }






return 0;
}
