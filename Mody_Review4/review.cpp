#include "review.h"

void ReadWrite() {
	string input;
	string output = "q";
	while (cin >> input) {
            if (input != output) {
                cout << input << " ";
            } else {
                cout << endl;
                break;
            }
	}
}
