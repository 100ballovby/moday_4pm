#include <iostream>
using namespace std;

void arrays_basics() {
    int marks[5];  // объявление целочисленного фиксированного массива
    double scores[] = {1.23, 5.6, 10.2, 3.49, 3.15};  // инициализцая фиксированного массива дробей
    // при инициализации фиксированного массива длину можно не указывать
    cout << sizeof(marks) << endl;  // размер массива в битах
    cout << sizeof(marks) / sizeof(marks[0]) << endl; // размер массива в элементах
    // ^ только для статических массивов
}

void arrays_loops() {
    int const len = 5;  // переменная-длина массива
    int marks[len];  // объявление целочисленного фиксированного массива
    double scores[] = {1.23, 5.6, 10.2, 3.49, 3.15};

    int length = sizeof(marks) / sizeof(marks[0]);

    for (int i = 0; i < length; ++i) {  // перебор массива по индексам
        cout << "scores["<< i << "] = "<<  scores[i] << endl;
    }
    cout << endl;
    for (double element : scores) {  // перебор массива по элементам
        cout << element << endl;
    }
}

void task_1() {
    int n, t, k;
    cout << "Insert n: ";
    cin >> n;
    double numbers[n], max, min, summ, mult;
    for (int i = 0; i < n; ++i) {
        double element;
        cout << "Insert " << i << ": ";
        cin >> element;
        numbers[i] = element;
    }

    max = numbers[0];
    min = numbers[0];
    for (int i = 0; i < n; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            t = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            k = i;
        }
    }


    max = numbers[0];
    for (int i = 1; i < n; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
            k = i;
        }

    }

    min = numbers[0];
    for (int i = 1; i < n; i++)
    {
        if (min > numbers[i])
        {
            min = numbers[i];
            t = i;
        }
    }
    numbers[t] = max;
    numbers[k] = min;
    cout << "max = " << max << " " << k << endl;
    cout << "min = " << min << " " << t << endl;

    summ = 0;
    mult = 1;
    for (double elem : numbers) {
        cout << elem << ", ";
        summ += elem;
        mult *= elem;
    }
    cout << endl;
    cout << "summ = " << summ << endl;
    cout << "mult = " << mult << endl;
}

int main() {



    return 0;
}
