#include "review.h"

void ReadStdIn () {
    int integer;
    double number;
    string word;
    
    cin >> integer >> number >> word;
    cout << integer << endl;
    cout << number << endl;
    cout << word << endl;
}
int WriteOut(string output) {
    cout << output << endl;
    return 1;
}

int WriteOut(int output) {
    cout << output << endl;
    return 2;
}

int WriteOut(double output) {
    cout << output << endl;
    return 3;
}