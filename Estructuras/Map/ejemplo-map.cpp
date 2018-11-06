/* Map sirve para relacionar dos tipos de datos, es similar al diccionario
de python. Nos permite a un tipo de dato especifico asociarle un valor. Por ejemplo,
si tengo string y cada string tiene un valor numerico (como el precio de un producto)
puedo guardar esa info en un map */

#include <iostream>
#include <map>

using namespace std;

int main () {

    map <string, int> promedios;

    promedios["Manuel"] = 100;
    promedios["Juan"] = 89;
    promedios["Pedro"] = 10;

    string consulta;
    cin >> consulta;

    if (!promedios[consulta]) {
        cout << "Alumno no esta en el curso" << endl;
    }else {
        cout << "El promedio de " << consulta << " es: " << promedios[consulta] <<endl;
    }

    // nota de todos los alumnos
    map <string, int>::iterator it;

    for (it = promedios.begin(); it != promedios.end(); it++) {
        cout << "El alumno: " << (*it).first <<" tiene promedio: " << (*it).second << endl;
    }
return 0;
}
