// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "busstop.h"

int main()
{
    int simulation_time = 60 * 1;     // 1 час
    int passenger_interval = 10;      // середній час між прибуттям пасажирів на зупинку (10 хв) 
    int bus_interval = 30;            // середній час між прибуттям автобусів на зупинку (30 хв)
    int max_passengers = 10;          // максимальне число пасажирів, що прибувають на зупинку за один раз
    int number_of_seats = 20;         // кількість місць в автобусі
    bool is_final = true;             // тип зупинки (кінцева чи не кінцева)

    Busstop busstop(passenger_interval, number_of_seats, is_final);
    busstop.imitation(simulation_time, passenger_interval, bus_interval, max_passengers);

    double average_waiting_time = busstop.get_average_waiting_time();
    cout << "Average waiting time: " << average_waiting_time << endl;

    return 0;
}