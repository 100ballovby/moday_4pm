#include <iostream>
using namespace std;

double *give_memory(double *ptr_arr, int size) { // указатель на функцию
    ptr_arr = new double[size];  // инициализировал динамический массив длиной size
    return ptr_arr;  // передал массив из функции
}

void fill_array(double *ptr_arr, int size) {
    // наполнить массив числами
}

void show_array(double *ptr_arr, int size) {
    // вывести массив на экран
}

double *free_memory(double *ptr_array) {
}

int main() {
    int length;
    cout << "Insert array length: ";
    cin >> length;
}
