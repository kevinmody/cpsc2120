#include "review.h"

void ReadStdIn2 () {
    string input;
    int numItems = 0;
    string quit = "q";
    do {
        cin >> input;
        numItems++;
    } while (input.compare(quit) != 0);
    numItems--;

    cout << numItems;
}
