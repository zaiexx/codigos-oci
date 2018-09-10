#include <iostream>

using namespace std;

int main () {

    int N;
    int sol = 0;


    while (cin >> N) {

        if (N == 0) {
            break;
        }

        int arr[N+2];
        sol = 0;

        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        arr[N] = arr[0];
        arr[N+1] = arr[1];

        for (int i = 1; i <= N; ++i) {
            if ((arr[i-1] < arr[i] && arr[i] > arr[i+1]) || (arr[i-1] > arr[i] && arr[i] < arr[i+1])) {
                sol++;
            }
        }
        cout << sol << endl;
    }

return 0;
}