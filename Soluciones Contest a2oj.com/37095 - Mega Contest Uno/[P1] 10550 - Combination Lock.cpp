#include <iostream>

using namespace std;

#define GRADOS 9

int main () {

  int actual, p1, p2, p3;

  while (cin >> actual >> p1 >> p2 >> p3) {

    if (actual == 0 && p1 == 0 && p2 == 0 && p3 == 0) {
      return 0;
    }

    int giros = 1080;

    int comb1 = actual > p1 ? actual - p1 : 40 - (p1 - actual);
    int comb2 = p2 > p1 ? p2 - p1 : 40 - (p1 - p2);
    int comb3 = p2 > p3 ? p2 - p3 : 40 - (p3 - p2);

    int total = giros + GRADOS*(comb1 + comb2 + comb3);

    cout << total << endl;

  }

  return 0;
}
