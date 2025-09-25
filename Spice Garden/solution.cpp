#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

struct garden {
    uint16_t** map;
    int16_t* current_assigment;
    int16_t* best_assigment;
    int8_t* is_assigned;
    int16_t  min_cost = INT16_MAX;
    uint8_t  length;

    garden(uint8_t n, uint16_t** map) {
        current_assigment = new int16_t[n];
        best_assigment = new int16_t[n];
        is_assigned = new int8_t[n];
        length = n;
        this->map = map;

        for (int8_t i = 0; i < n; i++) {
            is_assigned[i] = 0;
        }
    }

    ~garden() {
        delete[] current_assigment;
        delete[] best_assigment;
        delete[] is_assigned;
    }

    void assign(int16_t spice_bed_i, int16_t current_cost) {
        if (current_cost >= min_cost) {
            return;
        }


        if (spice_bed_i == length) {
            if (current_cost < min_cost) {
                min_cost = current_cost;
                for (uint8_t  i = 0; i < length; i++) {
                    best_assigment[i] = current_assigment[i];
                }
            }

            return;
        }

        for (uint8_t  i = 0; i < length; i++) {
            if (is_assigned[i] == 0) {
                is_assigned[i] = 1;

                current_assigment[spice_bed_i] = i;
                assign(spice_bed_i + 1, current_cost + map[spice_bed_i][i]);
                is_assigned[i] = 0;
            }
        }


    }

    void transpose_assigment() {
        auto temp = new int8_t [length];
        for (uint8_t  i = 0; i < length; i++) {
            temp[best_assigment[i]] = i;

        }
        for (int32_t i = 0; i < length; i++) {
            best_assigment[i] = temp[i];
        }
        delete[] temp;
    }

    void find_assigment() {
        assign(0, 0);
        transpose_assigment();
        for (uint8_t  i = 0; i < length; i++) {
            cout << static_cast<int32_t>(best_assigment[i]) << " ";
        }
    }



};


int32_t main() {
    int32_t t_n;
    cin >> t_n;

    uint8_t n = static_cast<uint8_t>(t_n);

    auto** map = new uint16_t*[n];
    for (uint8_t i = 0; i < n; i++) {
        map[i] = new uint16_t[n];
    }


    for (uint8_t i = 0; i < n; i++) {
        for (uint8_t j = 0; j < n; j++) {
            int32_t t_cost;
            cin >> t_cost;
            if (t_cost > 1000) {
                return -1;
            }
            map[i][j] = static_cast<int16_t>(t_cost);
        }
    }


    garden g(n, map);
    g.find_assigment();

    for (uint8_t i = 0; i < n; i++) {
        delete[] map[i];
    }
    delete[] map;
    return 0;
}