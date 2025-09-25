#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;
using std::min;

bool max_comparator (int32_t a, int32_t b) {
    return a > b;
}

bool min_comparator (int32_t a, int32_t b) {
    return a < b;
}

void heapify_down(vector<int32_t>& heap, int32_t n, int32_t i, bool (*comparator)(int32_t, int32_t)) {
    int32_t root = i;
    int32_t left = 2 * i + 1;
    int32_t right = 2 * i + 2;

    if (left < n && comparator(heap[left], heap[root])) {
        root = left;
    }

    if (right < n && comparator(heap[right], heap[root])) {
        root = right;
    }

    if (root != i) {
        swap(heap[i], heap[root]);
        heapify_down(heap, n, root, comparator);
    }
}

void heapify_up(vector<int32_t>& heap, int32_t n, int32_t i, bool (*comparator)(int32_t, int32_t)) {
    while (i > 0) {
        int32_t parent = (i - 1) / 2;
        if (comparator(heap[i], heap[parent])) {
            swap(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void insert(vector<int32_t>& heap, int32_t val,bool (*comparator)(int32_t, int32_t)) {
    heap.push_back(val);
    heapify_up(heap, heap.size(), heap.size() - 1, comparator);
}

int32_t pop(vector<int32_t>& heap, bool (*comparator)(int32_t, int32_t)) {
    if (heap.empty()) {
        return -1;
    }

    int32_t root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(heap, heap.size(), 0, comparator);

    return root;
}


int32_t main() {

    int32_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int32_t operation_qty;
        cin >> operation_qty;

        vector<int32_t> prices;
        vector<int32_t> taxes;

        for (size_t j = 0; j < operation_qty; j++) {
            char operation;
            cin >> operation;

            if (operation == 'a') {
                int32_t price, tax;
                cin >> price >> tax;

                insert(prices, price, max_comparator);
                insert(taxes, tax, min_comparator);
            } else if (operation == 'p') {
                int32_t price_modifier;
                cin >> price_modifier;

                int32_t max_price = pop(prices, max_comparator);
                if ( max_price + price_modifier > 0 && max_price != -1) {
                    max_price += price_modifier;
                    insert(prices, max_price, max_comparator);
                } else {
                    insert(prices, max_price, max_comparator);
                }

            } else {
                cout << "Invalid operation\n";
            }
        }

        vector<int32_t> sorted_prices;
        while (!prices.empty()) {
            sorted_prices.push_back(pop(prices, max_comparator));
        }

        vector<int32_t> sorted_taxes;
        while (!taxes.empty()) {
            sorted_taxes.push_back(pop(taxes, min_comparator));
        }

        int32_t total = 0;
        size_t min_size = min(sorted_prices.size(), sorted_taxes.size());
        for (size_t i = 0; i < min_size; i++) {
            total += sorted_prices[i] * sorted_taxes[i];
        }

        cout << total << "\n";
    }

    return 0;
}