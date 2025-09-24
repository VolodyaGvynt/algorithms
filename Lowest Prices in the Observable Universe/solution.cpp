#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;
using std::min;

struct customer {
    int32_t total_time;
    customer* next;

    customer(int32_t service_time)
        : total_time(service_time),
          next(nullptr) {}
};

class queue {
    customer* head;
    customer* tail;
    int32_t q_size;

public:
    queue() : head(nullptr), tail(nullptr), q_size(0) {}

    bool empty() {
        return head == nullptr;
    }

    void push(customer& c) {
        auto* new_customer = new customer(c.total_time);
        if (empty()) {
            head = tail = new_customer;
        } else {
            tail->next = new_customer;
            tail = new_customer;
        }
        q_size++;
    }

    void pop() {
        if (empty()) {
            return;
        }

        customer* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        q_size--;
    }

    int32_t size() {
        return q_size;
    }

    customer& front() {
        return *head;
    }
};

struct cash_desk {
    bool is_open;
    queue customers_q;
    int32_t total_time;

    cash_desk() : is_open(false), total_time(0) {}

    void open() {
        is_open = true;
        total_time = 0;
        customers_q = queue();
    }

    void close() {
        is_open = false;
        while (!customers_q.empty()) {
            customers_q.pop();
        }
    }

    void add_customer(customer c) {
        total_time += c.total_time;
        customers_q.push(c);
    }

    void serve_customer() {
        if (!customers_q.empty()) {
            customer front = customers_q.front();
            total_time -= front.total_time;
            customers_q.pop();
        }
    }

};

void update_queues(cash_desk* cash_desks, int32_t cash_desk_qty, int32_t time) {
    for (int i = 0; i < cash_desk_qty; i++) {
        if (!cash_desks[i].is_open || cash_desks[i].customers_q.empty()) {
            continue;
        }
        
        int32_t remaining_time = time;
        
        while (!cash_desks[i].customers_q.empty() && remaining_time > 0) {
            customer& front = cash_desks[i].customers_q.front();
            int32_t service_time = std::min(front.total_time, remaining_time);

            front.total_time -= service_time;
            cash_desks[i].total_time -= service_time;
            remaining_time -= service_time;

            if (front.total_time <= 0) {
                cash_desks[i].serve_customer();
            }
        }
    }
}


int32_t find_best_desk(cash_desk* desks, int32_t cash_desk_qty, int32_t ignore = -1) {
    int32_t best_desk = -1;
    int64_t best_time = INT64_MAX;


    for (size_t i = 0; i < cash_desk_qty; i++) {
        if (i == ignore) {
            continue;
        }
        if (desks[i].is_open) {
            if (desks[i].total_time < best_time) {
                best_time = desks[i].total_time;
                best_desk = i;
            } else if (desks[i].total_time == best_time && i < best_desk) {
                best_desk = i;
            }
        }
    }
    return best_desk;
}

void print (cash_desk* cash_desks, int32_t cash_desk_qty) {
    bool first = true;
    for (size_t i = 0; i < cash_desk_qty; i++) {
        if (!first) {
            cout << ", ";
        }
        first = false;

        if (cash_desks[i].is_open) {
            cout << "K" << i << ": " << cash_desks[i].customers_q.size() << "o " << cash_desks[i].total_time << "s";
        } else {
            cout << "K" << i << ": z";
        }
    }
    cout << "\n";
}


int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int32_t t;
    int32_t cash_desk_qty, cash_desk_efficiency, customer_efficiency;
    cin >> t >> cash_desk_qty >> cash_desk_efficiency >> customer_efficiency;

    auto cash_desks = new cash_desk[cash_desk_qty];


    char operation;
    while (t > 0) {
        cin >> operation;
        if (operation == 'o') {
            int32_t id;
            cin >> id;
            cash_desks[id].open();
        } else if (operation == 'z') {
            int32_t id;
            cin >> id;

            cash_desks[id].serve_customer();

            while (!cash_desks[id].customers_q.empty()) {
                customer front = cash_desks[id].customers_q.front();
                cash_desks[id].customers_q.pop();

                int32_t best_desk = find_best_desk(cash_desks, cash_desk_qty, id);
                if (best_desk != -1) {
                    cash_desks[best_desk].add_customer(front);
                }
            }

            cash_desks[id].close();

        } else if (operation == 'k') {
            int32_t time_passed, product_qty;
            cin >> time_passed >> product_qty;

            int32_t time_to_subtract = std::min(time_passed, t);
            update_queues(cash_desks, cash_desk_qty, time_to_subtract);
            t -= time_passed;

            if (t < 0) {
                break;
            }

            int32_t best_desk = find_best_desk(cash_desks, cash_desk_qty);
            int32_t customer_total_time = product_qty * cash_desk_efficiency + customer_efficiency;

            if (best_desk != -1) {
                cash_desks[best_desk].add_customer(customer(customer_total_time));
            }

        }
        //print(cash_desks, cash_desk_qty);

    }
    print(cash_desks, cash_desk_qty);

    delete[] cash_desks;
    return 0;
}