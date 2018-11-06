#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;


int main () {


    int casos;
    int cantidadProductos;
    int totalComprar;
    int cantidadComprar;
    double valorProducto;
    string nombreProducto;
    string productoComprar;


    cin >> casos;

    while (casos--) {

        map <string, double> info;
        double totalPagar = 0.0;

        cin >> cantidadProductos;

        for (int i = 0; i < cantidadProductos; i++) {
            cin >> nombreProducto >> valorProducto;
            info[nombreProducto] = valorProducto;
        }

        cin >> totalComprar;

        for (int i = 0; i < totalComprar; i++) {

            cin >> productoComprar >> cantidadComprar;
            totalPagar+= (info[productoComprar] * cantidadComprar);
        }

        cout << "R$ " << setprecision(2) << fixed << totalPagar << endl;

    }

return 0;
}

