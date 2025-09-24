#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

using std::cout;
using std::cin;

struct measurement_node {
    int32_t frequency;
    int32_t length;
    int32_t counter;
    measurement_node* left;
    measurement_node* right;

    measurement_node(int32_t frequency, int32_t length) : frequency(frequency), length(length), counter(1), left(nullptr), right(nullptr) {}
};

struct tree_node {
    int32_t year;
    measurement_node* root;
    tree_node* left;
    tree_node* right;

    tree_node(int32_t year) : year(year), root(nullptr), left(nullptr), right(nullptr) {}
};

struct measurement_tree {
    measurement_node* root;

    measurement_tree() : root(nullptr) {}

    measurement_node* insert(measurement_node* node, int32_t frequency, int32_t length) {
        if (node == nullptr) {
            return new measurement_node(frequency, length);
        }

        if (frequency < node->frequency || (frequency == node->frequency && length < node->length)) {
            node->left = insert(node->left, frequency, length);
        } else if (frequency > node->frequency || (frequency == node->frequency && length > node->length)) {
            node->right = insert(node->right, frequency, length);
        } else {
            node->counter++;
        }
        return node;
    }

    void insert(int32_t frequency, int32_t length) {
        root = insert(root, frequency, length);
    }

    void in_order(measurement_node* node) {
        if (node == nullptr) {
            return;
        }
        in_order(node->left);
        for (int32_t i = 0; i < node->counter; i++) {
            cout << "(" << node->frequency << "," << node->length << ") ";
        }
        in_order(node->right);
    }

    void print() {
        in_order(root);
    }

    bool is_ready(measurement_node* node, bool& found) {
        if (node == nullptr) {
            return false;
        }

        if (node->frequency >= 275 && node->frequency <= 325) {
            found = true;
        } else {
            return false;
        }

        return is_ready(node->left, found) || is_ready(node->right, found) || found;
    }


};

class bin_tree {
private:
    tree_node *root;

    tree_node* insert(tree_node* node, int32_t year, int32_t frequency, int32_t length) {
        if (node == nullptr) {
            tree_node* new_node = new tree_node(year);
            new_node->root = new measurement_node(frequency, length);
            return new_node;
        }

        if (year < node->year) {
            node->left = insert(node->left, year, frequency, length);
        } else if (year > node->year) {
            node->right = insert(node->right, year, frequency, length);
        } else {
            node->root = measurement_tree().insert(node->root, frequency, length);
        }
        return node;
    }

    void in_order(tree_node* node) {
        if (node == nullptr) {
            return;
        }
        in_order(node->left);
        cout << node->year << ": ";
        measurement_tree m_tree;
        m_tree.root = node->root;
        m_tree.print();
        cout << "\n";
        in_order(node->right);
    }

    bool is_ready(tree_node* node) {
        if (node == nullptr) {
            return false;
        }
        measurement_tree m_tree;
        bool found = false;
        if (!m_tree.is_ready(node->root, found)) {
            return false;
        }
        return is_ready(node->left) || is_ready(node->right) || found;

    }

public:
    bin_tree() : root(nullptr) {}

    void insert(int32_t year, int32_t frequency, int32_t length) {
        root = insert(root, year, frequency, length);
    }

    void in_order() {
        in_order(root);
    }

    bool is_ready() {
        return is_ready(root);
    }
};

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int32_t n;
    cin >> n;

    bin_tree tree;

    for (int32_t i = 0; i < n; i++) {
        int32_t year, frequency, length;
        cin >> year >> frequency >> length;

        float speed = length * frequency * 0.01;
        if (speed >= 313 && speed <= 350 && frequency >= 20 && frequency <= 20000) {
            tree.insert(year, frequency, length);
        }
    }

    tree.in_order();
    if (tree.is_ready()) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }

    return 0;