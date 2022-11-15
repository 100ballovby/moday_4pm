#include <iostream>
using namespace std;

int randint(int min, int max) {
    int r = rand() % (max - min) + min;
    return r;
}


int main() {
    return 0;
}