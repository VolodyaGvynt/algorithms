#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void swap (int32_t &a, int32_t &b) {
    int32_t temp = a;
    a = b;
    b = temp;
}

bool is_div_qty_even (int32_t n) {
    int32_t counter = 0;

    if (n % 2 == 0) {
        counter++;
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    for (int32_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            counter++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 2) {
        counter++;
    }

    return counter % 2 == 0;
}

void heapify_down(vector<int32_t>& heap, int32_t n, int32_t i) {
    int32_t root = i;
    int32_t left = 2 * i + 1;
    int32_t right = 2 * i + 2;

    if (left < n && heap[left] > heap[root]) {
        root = left;
    }

    if (right < n && heap[right] > heap[root]) {
        root = right;
    }

    if (root != i) {
        swap(heap[i], heap[root]);
        heapify_down(heap, n, root);
    }
}

void sort (vector<int32_t>& vec) {
    int n = vec.size();

    for (int32_t i = n / 2 - 1; i >= 0; i--) {
        heapify_down(vec, n, i);
    }
    for (int32_t i = n - 1; i > 0; i--) {
        swap(vec[0], vec[i]);
        heapify_down(vec, i, 0);
    }
}

int32_t find_median(vector<int32_t>& vec) {
    sort(vec);
    return vec[vec.size() / 2];;
}

int32_t select(vector<int32_t>& days, int32_t index) {
    if (days.size() <= 5) {
        sort(days);
        return (index < days.size()) ? days[index] : -1;
    }

    vector<int32_t> medians;
    int32_t j = 0;

    for (size_t i = 0; i < days.size(); i += 5) {
        vector<int32_t> temp;
        for (size_t k = i; k < i + 5 && k < days.size(); k++) {
            temp.push_back(days[k]);
        }
        medians.push_back(find_median(temp));
        j++;
    }

    int32_t M = find_median(medians);
    vector<int32_t> left, right;
    int32_t M_count = 0;

    for (int32_t num : days) {
        if (num < M) {
            left.push_back(num);
        } else if (num > M) {
            right.push_back(num);
        } else {
            M_count++;
        }
    }

    if (index < left.size()) {
        return select(left, index);
    }
    if (index < left.size() + M_count) {
        return M;
    }
    return select(right, index - left.size() - M_count);
}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int32_t t;
    cin >> t;


    for (size_t i = 0; i < t; i++) {
        int32_t n;
        cin >> n;
        vector<int32_t> valid_days;
        int32_t index;
        for (size_t j = 0; j < n; j++) {
            int32_t day;
            cin >> day;
            if (is_div_qty_even(day)) {
                valid_days.push_back(day);
            }
        }

        cin >> index;

        int32_t result = select(valid_days, index);
        if (valid_days.empty() || index >= valid_days.size()) {
            cout << "BRAK DANYCH\n";
        } else {
            cout << result << "\n";
        }
    }



    return 0;
}