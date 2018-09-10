#include <iostream>

using namespace std;

int main () {

    int arr1[5];
    int arr2[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < 5; i++) {
        cin >> arr2[i];
    }

    int flag = 1;

    for (int i = 0; i < 5; i++) {
        if (arr1[i] == arr2[i]) {
            flag = 0;
        }
    }

    if (flag) {
        cout << "Y" << endl;
    }else {
        cout << "N" << endl;
    }


return 0;
}