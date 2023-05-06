// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "busstop.h"

int main()
{
    int simulation_time = 60 * 1;     // 1 ���
    int passenger_interval = 10;      // ������� ��� �� ��������� �������� �� ������� (10 ��) 
    int bus_interval = 30;            // ������� ��� �� ��������� �������� �� ������� (30 ��)
    int max_passengers = 10;          // ����������� ����� ��������, �� ���������� �� ������� �� ���� ���
    int number_of_seats = 20;         // ������� ���� � �������
    bool is_final = true;             // ��� ������� (������ �� �� ������)

    Busstop busstop(passenger_interval, number_of_seats, is_final);
    busstop.imitation(simulation_time, passenger_interval, bus_interval, max_passengers);

    double average_waiting_time = busstop.get_average_waiting_time();
    cout << "Average waiting time: " << average_waiting_time << endl;

    return 0;
}