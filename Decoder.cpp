//
// Created by Lyubomir on 1/28/2025.
//

using namespace std;

#include <fstream>
#include <iostream>
#include <iterator>

int main() {
    // Stream the file in binary
    ifstream input( "picture.bmp", ios::binary );

    // Start position is 20000. The letter W
    unsigned long symbolPosition = 20000;

    // Last position in the input
    const long long endPosition = input.seekg(0, ios::end).tellg();

    while (symbolPosition < endPosition) {
        // First byte is the symbol
        const unsigned char res = input.seekg(symbolPosition, ios::beg ).get();

        if (res == '\0') {
            break;
        }

        cout << res;

        // The next symbol position is the offset made by summing the next 3 bytes
        // The task explains the second and third bytes need to be multiplied by 0x100
        // and 0x10000 respectively
        symbolPosition = input.seekg( symbolPosition + 1, ios::beg ).get()
        + input.seekg( symbolPosition + 2, ios::beg ).get() * 0x100
        + input.seekg( symbolPosition + 3, ios::beg ).get() * 0x10000;
    }

    return 0;
}