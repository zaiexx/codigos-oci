#include <iostream>
#include <set>


using namespace std;

int main () {


    int nA, nB;

    while (cin >> nA >> nB) {

        if (nA == 0 && nB == 0) {
            return 0;
        }

        set <int> Alicia;
        set <int> Bety;

        int v;

        for (int i = 0; i < nA; i++) {
            cin >> v;
            Alicia.insert(v);
        }

        for (int i = 0; i < nB; i++) {
            cin >> v;
            Bety.insert(v);
        }


        set <int>::iterator it;
        set <int> AA, BB;

        for (it = Alicia.begin(); it != Alicia.end(); it++) {
            if (!Bety.count((*it))) {
                AA.insert(*it);
            }
        }

        for (it = Bety.begin(); it != Bety.end(); it++) {
            if (!Alicia.count((*it))) {
                BB.insert(*it);
            }
        }

        cout << min(AA.size(), BB.size()) << endl;

    }

return 0;
}
