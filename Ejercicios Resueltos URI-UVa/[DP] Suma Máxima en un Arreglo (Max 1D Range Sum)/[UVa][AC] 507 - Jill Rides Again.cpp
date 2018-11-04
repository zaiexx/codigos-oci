#include <iostream>

using namespace std;

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    int N;
    int k = 0;
    int it, i2;
    cin >> TC;

    while (TC--) {

        cin >> N;

        int arr[N];
        int flag = 1;

        for (int i = 1; i < N; i++) {
            cin >> arr[i];
        }

        arr[0] = 0;

        //Codigo del competitive programing 3
        int running_sum = 0, ans = 0;
        int it = 0, it2 = 0, it3 = 0;

        for (int i = 1; i < N; i++) {
            if (running_sum + arr[i] >= 0) {
                running_sum += arr[i];
                if (running_sum > ans) || (running_sum == ans && (i - it2) > (it3 - it))) {
                    ans = running_sum;
                    it3 = i;
                    it = it2;
                }
            }else {
                it2 = i;
                running_sum = 0;
            }
        }

        if (ans <= 0) {
            cout << "Route "<< ++k << " has no nice parts" << endl;
        }else {
            cout << "The nicest part of route " << ++k << " is between stops " << it+1 << " and " << it3+1 << endl;
        }
    }

return 0;
}
