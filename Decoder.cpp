//
// Created by Lyubomir on 1/28/2025.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <format>

int decodeLetters(const int startingPosition, std::vector<unsigned char> buffer)
{
    std::stringstream ss;

    ss << std::hex
    << (buffer.at(startingPosition + 3))
    << (buffer.at(startingPosition + 2))
    << (buffer.at(startingPosition + 1));

    return std::stoi("0x" + ss.str(), nullptr, 16);
}

int readFromFile(const int startingPosition, std::ifstream &input)
{
    std::stringstream ss;

    ss << std::hex
    << input.seekg( startingPosition + 3, std::ios::beg ).get()
    << input.seekg( startingPosition + 2, std::ios::beg ).get()
    << input.seekg( startingPosition + 1, std::ios::beg ).get()
    << std::endl;


    return std::stoi("0x" + ss.str(), nullptr, 16);
}

int main()
{
    std::ifstream input( "picture.bmp", std::ios::binary );

    // // Copies all data into buffer
    // const std::vector<unsigned char> buffer(
    //     std::istreambuf_iterator<char>(input), {}
    // );

    // Start position is 20000. The letter W
    int startingPosition = 20000;

    while (startingPosition < 999999999999) {
        const unsigned char res = input.seekg(startingPosition, std::ios::beg ).get();

        // std::cout << startingPosition << std::endl;
        std::cout << res;

        startingPosition = readFromFile(startingPosition, input);
    }

    return 0;
}