#include <cstdint>
#include <iostream>

using std::cin;
using std::cout;

struct peasant
{
    int performance;
    int loss;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int psnt_qty, rqst_qty, mass;
        cin >> psnt_qty >> rqst_qty >> mass;

        auto psnt_crew = new peasant[psnt_qty];
        auto requests = new int[rqst_qty];
        auto days_performance = new int32_t[rqst_qty];
        int success_counter = 0;

        for (int j = 0; j < psnt_qty; ++j)
        {
            cin >> psnt_crew[j].performance >> psnt_crew[j].loss;
        }

        for (int j = 0; j < rqst_qty; ++j)
        {
            cin >> requests[j];
        }

        for (int j = 0; j < rqst_qty; ++j)
        {
            int total_performance = 0;


            for (int k = 0; k < requests[j]; ++k)
            {
                for (int l = 0; l < psnt_qty; ++l)
                {
                    int curr_performance = psnt_crew[l].performance;
                    curr_performance -= psnt_crew[l].loss * k;

                    if (curr_performance > 0)
                    {
                        total_performance += curr_performance;
                    }
                }
            }

            days_performance[j] = total_performance;

            if (total_performance >= mass)
            {
                success_counter++;
            }

        }

        // 2 3 100
        // 20 10
        // 30 5
        // 5 1 100

        for (int day = 0; day < rqst_qty; ++day)
        {
            cout << days_performance[day] << " ";
        }

        cout << "\n" << success_counter << "\n";


        delete [] psnt_crew;
        delete [] requests;
        delete [] days_performance;
    }
}
