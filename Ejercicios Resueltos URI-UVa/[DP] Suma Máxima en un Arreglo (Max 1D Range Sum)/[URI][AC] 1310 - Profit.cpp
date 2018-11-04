#include <iostream>

using namespace std;

int main () {

    int N;
    int costo;

    while (cin >> N) {

        int arr[N];
        cin >> costo;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }


        #Codigo Competitive Programming 3
        int suma = 0, respuesta = 0;

        for (int i = 0; i < N; i++) {
            if ((suma + arr[i]) - costo >= 0) {
                suma += arr[i];
                suma-= costo;
                respuesta = max(respuesta, suma);
            } else {
                suma = 0;
            }
        }

        cout << respuesta << endl;
    }

return 0;
}
