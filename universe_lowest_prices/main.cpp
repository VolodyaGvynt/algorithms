#include <iostream>


using std::cin;
using std::cout;




struct Client {
    int data;
    Client* next;

    Client(int data) : data(data), next(nullptr) {}
};

struct Checkout {
    Client *front, *rear;

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Client* temp = new Client(data);

        if (rear == nullptr) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        Client* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

};

int32_t main() {

    int32_t sim_time, checkout_qty, checkout_performance, client_performance;
    cin >> sim_time >> checkout_qty >> checkout_performance >> client_performance;


    auto shop = new Checkout[checkout_qty];
    int32_t spent_time = 0;

    while (spent_time < sim_time) {
        char action_flag;
        cin >> action_flag;

        switch (action_flag) {
            case 'k': {
                int relative_time;
                int items_qty;
                cin >> relative_time >> items_qty;
                spent_time += relative_time;
                break;
            }
            case

        }

    }

    return 0;
}
