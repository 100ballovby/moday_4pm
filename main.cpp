#include <iostream>
// #include <string>  <- если не работает string, напишите это
using namespace std;

int main() {
    string phrase;
    cout << "Введи фразу: ";
    cin >> phrase;

    cout << phrase << endl;
    sort(phrase.begin(), phrase.end());
    cout << phrase << endl;
}
