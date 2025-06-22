#include "Date.h"

void Fun(const Data& d3, const Data& d4) {
    cout << d3 - d4 << endl;
}

int main() {
    Data d1(2019, 4, 18);
    Data d2(2020, 4, 18);
    Fun(d1, d2);
    cout << d1 - d2 << endl;
    return 0;
}