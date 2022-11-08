#include <iostream>
using namespace std;

void operators() {
    int a = 8;
    cout << &a << endl;
    // & оператор получения адреса переменной
    cout << *&a << endl; // разыменовал адрес переменной
    // * - разыменовывание
}

void ukazateli() {
    int *tbd; // указатель на значение типа int
    double *dtbd; // указать на значение типа double
    int* tbd2; // можно, но лучше так не делать
    int * tbd3;  // можно, но лучше так не делать
    int *x, *y;  // объявляем два указателя на значения типа данных int
    int* t1, t2;  // указателем будет только t1, t2 - обычная переменная

    int value = 5;
    int *u_val = &value;  // указываю на адрес value

    cout << u_val << endl;  // выводим то, на что ссылается указатель (ячейку value)
    cout << *u_val << endl;  // выводим значение, на которое ссылается указатель
    /* тип данных указателя должен строго совпадать с типом данных
     * переменной, на которую он ссылается */
    // int *p = &7;  - нельзя, потому что у 7 нет адреса и даже & не спасет
}

void ptr_weight() {
    cout << "int:" << sizeof(int) << endl;
    cout << "long:" << sizeof(long) << endl;
    cout << "long long:" << sizeof(long long) << endl;
    cout << "float:" << sizeof(float) << endl;
    cout << "double:" << sizeof(double) << endl;
    cout << "char:" << sizeof(char) << endl;
    cout << "string:" << sizeof(string) << endl;
    cout << "int_32:" << sizeof(int32_t) << endl;
    cout << "int_64:" << sizeof(int64_t) << endl;

    char *c_ptr; // тип char занимает 1 байт
    int *i_ptr; // тип int занимает 4 байта
    /* Вес указателя зависит от разрядности ОС и от архитектуры,
     * обычные типы данных в любой системе будет весить одинаково */
    cout << "*c_ptr:" << sizeof(c_ptr) << endl;  // выведет 8 (на 64-битной) и 4 (на 32-битной)
    cout << "*i_ptr:" << sizeof(i_ptr) << endl;  // выведет 8 (на 64-битной) и 4 (на 32-битной)
}

void ptr_array() {
    int arr[] = {4, 5, 2, 1};
    cout << sizeof(arr) << endl;  // общий вес массива
    int *ptr = arr;  // указатель на массив
    cout << sizeof(ptr) << endl;  // вес указателя на массив
}

int main() {
    int length;
    cout << "Insert length of array: ";
    cin >> length;

    double *arr = new double [length]; //  память под массив будет выделена динамически
    for (int i = 0; i < length; i++) {
        cout << "Insert element " << i + 1 << ": ";
        cin >> arr[i];
    }

    double min = 0.0, f_pos = 0.0, l_pos = 0.0, summ = 0.0;
    int i_min = 0, f_pos_i = 0, l_pos_i = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
            i_min = i;
        }
    }
    cout << "Minimum: " << min << " Index: " << i_min << endl;
    for (int i = 0; i < length; i++) {
        if (arr[i] > 0) {
            f_pos = arr[i];
            f_pos_i = i;
            break;
        }
    }
    for (int i = length - 1; i > -1; i--) {
        if (arr[i] > 0) {
            l_pos = arr[i];
            l_pos_i = i;
            break;
        }
    }
    cout << "First positive: " << f_pos << " " << f_pos_i << endl;
    cout << "Last positive: " << l_pos << " " << l_pos_i << endl;

    for (int i = f_pos_i + 1; i < l_pos_i; i++) {
        cout << arr[i] << ", ";
        summ += arr[i];
    }
    cout << "Summ: " << summ << endl;

    delete[] arr;  // удаляем массив из памяти
    arr = nullptr;  // присваиваем нулевой указатель массиву

    return 0;
}
