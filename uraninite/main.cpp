#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

struct peasant {
    int16_t performance;
    int16_t performance_loss;
};

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int16_t t;
    cin >> t;

    for (int16_t i = 0; i < t; ++i) {
        int16_t peasant_qty;
        int32_t request_qty, target_mass;
        cin >> peasant_qty >> request_qty >> target_mass;
        const auto peasants = new peasant[peasant_qty];
        const auto requests = new int16_t[request_qty];

        for (int16_t j = 0; j < peasant_qty; ++j) {
            cin >> peasants[j].performance >> peasants[j].performance_loss;
        }
        for (int32_t j = 0; j < request_qty; ++j) {
            cin >> requests[j];
        }

        int32_t success_counter = 0;

        for (int32_t j = 0; j < request_qty; ++j) {
            int64_t total_performance = 0;
            for (int16_t k = 0; k < peasant_qty; ++k) {
                int32_t n = requests[j];
                const int16_t a = peasants[k].performance;
                const int16_t d = peasants[k].performance_loss;

                int32_t performance_max = a / d + 1;
                n = (performance_max > n) ? n : performance_max;

                total_performance += n * (2 * a + (n - 1) * -d) / 2;



            }
            if (total_performance >= target_mass) {
                ++success_counter;
            }

            cout << total_performance << ' ';
        }
        cout << '\n' << success_counter << '\n';

        delete[] peasants;
        delete[] requests;
    }

}


