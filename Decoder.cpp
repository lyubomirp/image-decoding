//
// Created by Lyubomir on 1/28/2025.
//

#include <fstream>
#include <iostream>

constexpr int START_POSITION = 20000;

int main() {
    // Stream the file in binary
    std::ifstream input( "picture.bmp", std::ios::binary );

    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    unsigned long symbolPosition = START_POSITION;
    // Last position in the input
    const long long endPosition = input.seekg(0, std::ios::end).tellg();

    while (symbolPosition < endPosition) {
        // First byte is the symbol
        const unsigned char res = input.seekg(symbolPosition, std::ios::beg ).get();

        if (res == '\0') {
            break;
        }

        std::cout << res;

        // We shift the first byte to the left 16 bits, the second 8 and the third 0
        // This is because the number needs to be little endian
        symbolPosition = (input.seekg( symbolPosition + 3, std::ios::beg ).get() << 16) |
        (input.seekg( symbolPosition + 2, std::ios::beg ).get() << 8) |
        input.seekg( symbolPosition + 1, std::ios::beg ).get();
    }

    return 0;
}