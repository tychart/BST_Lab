#pragma once

#include <iostream>

template <typename T>
void print(T inputVar) {
    std::cout << inputVar;
}

template <typename T>
void println(T inputVar) {
    std::cout << inputVar << std::endl;
}