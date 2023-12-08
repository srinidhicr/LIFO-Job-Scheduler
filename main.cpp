#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX_N = 100;  // Adjust value according to problem size.

int n = 4;
int S = 1;
vector<int> p = {25,10,5,10};
vector<int> d = {45,15,10,30};
vector<int> L = {-20,20,30,20};
vector<vector<vector<vector<int>>> > s(MAX_N, vector<vector<vector<int>>>(MAX_N, vector<vector<int>>(MAX_N, vector<int>(MAX_N, -1))));  // DP table.

void initializeDP() {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int m = 0; m <= j - i; m++) {
                s[i][j][m][0] = numeric_limits<int>::max();  // Set to positive infinity.
                for (int k = i; k <= j; k++) {
                    s[i][j][m][0] = min(s[i][j][m][0], L[k]);
                }
            }
        }
    }
}


void dynamicProgramming() {
    for (int l = 1; l <= S; l++) {
        for (int j = 0; j < n; j++) {
            for (int i = j; i >= 0; i--) {
                for (int k = i; k <= j; k++) {
                    vector<int> Sk;
                    for (int u = 0; u <= k - i - 1; u++) {
                        Sk.push_back(s[i + 1][k][u][l - 1] - p[i]);
                    }
                    for (int u = 0; u <= j - k - 1; u++) {
                        Sk.push_back(s[k + 1][j][u][l]);
                    }
                    Sk.push_back(L[k] - d[k]);

                    sort(Sk.rbegin(), Sk.rend());
                    vector<int> S(Sk.begin(), Sk.begin() + k - i + 1);

                    s[i][j][k - i][l] = *min_element(S.begin(), S.end());
                }
            }
        }
    }
}

int main() {
    // Initialize n, S, p, d, and L with problem-specific values.

    initializeDP();
    dynamicProgramming();
   
    int minLateJobs = 0;
    for (int m = 0; m < n; m++) {
        if (s[0][n - 1][m][S] <= 0) {
            minLateJobs = m;
            break;
        }
    }

    cout << "Minimum number of late jobs: " << minLateJobs << endl;

    return 0;
}
