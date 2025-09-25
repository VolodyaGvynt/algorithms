#include <cstdint>
#include <iostream>


using std::cin;
using std::cout;


int32_t max(int32_t a, int32_t b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int32_t max(int32_t a, int32_t b, int32_t c, int32_t d) {
    if (a > b && a > c && a > d) {
        return a;
    } else if (b > a && b > c && b > d) {
        return b;
    } else if (c > a && c > b && c > d) {
        return c;
    } else {
        return d;
    }
}

int32_t min(int32_t a, int32_t b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

void swap (int32_t**& a, int32_t**& b) {
    auto* temp = a;
    a = b;
    b = temp;
}

void find_max_artifacts(int32_t** map, int32_t n, int32_t& maximum) {
    auto** current_step = new int32_t*[n];
    auto** prev_step = new int32_t*[n];

    for (int32_t i = 0; i < n; i++) {
        current_step[i] = new int32_t[n];
        prev_step[i] = new int32_t[n];
        for (int32_t j = 0; j < n; j++) {
            current_step[i][j] = -1;
            prev_step[i][j] = -1;
        }
    }

    prev_step[0][0] = map[0][0];

    for (int32_t k = 1; k < 2 * n - 1; k++) {
        for (int32_t i = 0; i < n; i++) {
            for (int32_t j = 0; j < n; j++) {
                current_step[i][j] = -1;
            }
        }

        for (int32_t x1 = max (0, k - (n - 1)); x1 <= min(n - 1, k); x1++) {
            for (int32_t x2 = max (0, k - (n - 1)); x2 <= min(n - 1, k); x2++) {
                int32_t y1 = k - x1;
                int32_t y2 = k - x2;

                if (y1 >= n || y2 >= n) {
                    continue;
                }

                int32_t artifact;
                if (x1 == x2 && y1 == y2) {
                    artifact = map[x1][y1];
                } else {
                    artifact = map[x1][y1] + map[x2][y2];
                }

                int32_t best = -1;

                if (x1 > 0 && x2 > 0) {
                    best = max(best, prev_step[x1 - 1][x2 - 1]);
                }
                if (x1 > 0 && y2 > 0) {
                    best = max(best, prev_step[x1 - 1][x2]);
                }
                if (x2 > 0 && y1 > 0) {
                    best = max(best, prev_step[x1][x2 - 1]);
                }
                if (y1 > 0 && y2 > 0) {
                    best = max(best, prev_step[x1][x2]);
                }

                if (best != -1) {
                    current_step[x1][x2] = best + artifact;
                }
            }
        }

        swap(current_step, prev_step);
    }

    maximum = prev_step[n - 1][n - 1];


    for ( int32_t i = 0; i < n; i++) {
        delete[] current_step[i];
        delete[] prev_step[i];
    }
    delete[] current_step;
    delete[] prev_step;
}

int32_t main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);


    int32_t n;
    cin >> n;

    auto** map = new int32_t*[n];

    for (int32_t i = 0; i < n; i++) {
        map[i] = new int32_t[n];
    }

    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    int32_t maximum;
    find_max_artifacts(map, n, maximum);
    cout << maximum << '\n';

    for (int32_t i = 0; i < n; i++) {
        delete[] map[i];
    }
   delete[] map;

    return 0;
}