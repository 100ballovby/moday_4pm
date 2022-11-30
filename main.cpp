#include <iostream>
using namespace std;

struct Student {
    string name;
    string surname;
    string father_name;
    string address;
    int group;
    double rate;
};

void show_data(Student *obj, int amount) {
    cout << "№\t" << "ФИО\t\t\t\t" << "Адрес\t" << "Группа\t" << "Рейтинг\t" << endl;
    for (int i = 0; i < amount; i++) {
        cout << i << "\t" << obj[i].name << obj[i].surname << obj[i].father_name << "\t" << obj[i].address << "\t" << obj[i].group << "\t" << obj[i].rate << "\t" << endl;
    }
}

int main() {
    const int size = 3;
    Student students[size];

    for (int i = 0; i < size; i++) {
        cout << "Имя, Фамилия, Отчество студента: ";
        cin >> students[i].name >> students[i].surname >> students[i].father_name;
        cout << "Адрес";
        getline(cin, students[i].address);
        cin.ignore(32767, '\n');
        cout << "Группа: "; cin >> students[i].group;
        cout << "Рейтинг: "; cin >> students[i].rate;
    }

    show_data(students, size);
    return 0;
}