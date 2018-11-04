#include<iostream>
#include<cstring>

using namespace std;

int LCSubStr(string X, string Y, int m, int n)  {

    int LCSuff[m+1][n+1];
    int result = 0;

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0) {
                LCSuff[i][j] = 0;
            }else if (X[i-1] == Y[j-1]) {
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            } else {
                LCSuff[i][j] = 0;
            }
        }
    }

    return result;
}

int main() {

    string s1;
    string s2;

    while (getline(cin, s1)) {
        getline(cin, s2);

        int m = s1.length();
        int n = s2.length();

        cout << LCSubStr(s1, s2, m, n) << endl;
    }

  return 0;
}
