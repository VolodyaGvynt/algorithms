#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <valarray>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::sqrt;

void insertion_sort(vector<float> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        float temp = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > temp) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = temp;
    }
}


void bucket_sort(float arr[], int n, float min, float max) {
    int32_t buckets_qty = std::min(n, 17000);
    vector<vector<float> > buckets(buckets_qty);

    for (size_t i = 0; i < n; i++) {
        int32_t bucket_i = static_cast<int32_t>((arr[i] - min) / (max - min) * (buckets_qty - 1.0));
        buckets[bucket_i].push_back(arr[i]);
    }

    for (size_t i = 0; i < buckets_qty; i++) {
        insertion_sort(buckets[i]);
    }

    int32_t index = 0;
    for (size_t i = 0; i < buckets_qty; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);


    int32_t n;
    cin >> n;


    float min = 1000000;
    float max = 0;
    auto *poles = new float[n];
    for (size_t i = 0; i < n; i++) {
        cin >> poles[i];
        if (poles[i] > max) {
            max = poles[i];
        } else if (poles[i] < min) {
            min = poles[i];
        }
    }

    bucket_sort(poles, n, min, max);

    float max_distance = 0.0;

    for (size_t i = 1; i < n; i++) {
        max_distance = std::max(max_distance, poles[i] - poles[i - 1]);
    }

    cout << std::fixed << std::setprecision(4) << max_distance;

    delete[] poles;
    return 0;
}