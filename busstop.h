#include "queue.h"

class Busstop 
{
private:
    int interval;
    int number_of_seats;   //м≥сц€ в автобус≥
    bool is_final;         //тип зупинки
    int passenger_count;   //к≥льк≥сть пасажир≥в
    int waiting_time;      //час оч≥куванн€
public:
    Busstop(int interval, int number_of_seats, bool is_final) 
    {
        this->interval = interval;
        this->number_of_seats = number_of_seats;
        this->is_final = is_final;
        this->passenger_count = 0;
        this->waiting_time = 0;
    }

    void imitation(int simulation_time, int passenger_interval, int bus_interval, int max_passengers) 
    {
        queue<int> passengers;
        srand(time(nullptr));

        for (int i = 0; i < simulation_time; i++) {
            //√енерац≥€ пасажир≥в
            if (i % passenger_interval == 0) 
            {
                int new_passengers = rand() % max_passengers + 1;
                for (int j = 0; j < new_passengers; j++) 
                {
                    passengers.push(i);
                    passenger_count++;
                }
                cout << "Passengers arrived at time " << i << ". All passengers: " << passenger_count << endl;
            }
            //прибутт€ автобуса
            if (i % bus_interval == 0) 
            {
                int free_seats = rand() % number_of_seats + 1;
                int passengers_out = min(free_seats, passenger_count);
                for (int j = 0; j < passengers_out; j++) 
                {
                    int wait_time = i - (*passengers.front());
                    waiting_time += wait_time;
                    passengers.pop();
                    passenger_count--;
                }
                cout << "Bus arrived at time " << i << ". Passengers who got off at the stop: " << passengers_out << ". All passengers: " << passenger_count << endl;
            }
        }
    }

    double get_average_waiting_time() 
    {
        if (passenger_count == 0) {
            return 0;
        }
        return (double)waiting_time / passenger_count;
    }
};




