#include <iostream>

using std::cin;
using std::cout;
using std::string;

struct artifact {
    string artifact_id;
    int32_t artifact_mass;
};

void sort (artifact arr[], int32_t n) {
    for (int32_t i = 1; i < n; ++i) {
        const artifact temp = arr[i];
        int32_t j = i - 1;

        while(j >= 0 && arr[j].artifact_mass > temp.artifact_mass) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

int32_t main() {

    int32_t t;
    cin >> t;

    for (int32_t i = 0; i < t; ++i) {
        int32_t artifact_qty;
        cin >> artifact_qty;
        const auto artifacts = new artifact[artifact_qty];

        for (int32_t j = 0; j < artifact_qty; ++j) {
            cin >> artifacts[j].artifact_id;
            cin >> artifacts[j].artifact_mass;
        }

        sort(artifacts, artifact_qty);

        int64_t min_energy = 0;
        int64_t prev_sum = 0;

        for (int32_t j = 0; j < artifact_qty; ++j) {
            const int64_t cost = prev_sum + artifacts[j].artifact_mass;
            min_energy += cost;
            prev_sum += artifacts[j].artifact_mass;
        }

        cout << min_energy << "\n";

        for (int32_t j = 0; j < artifact_qty; ++j) {
            cout << artifacts[j].artifact_id <<  " ";
        }

        delete[] artifacts;
    }



    return 0;
}
