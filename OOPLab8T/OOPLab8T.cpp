// OOPLab8T.cpp :  for Lab7 (new)
//

#include <iostream>
#include <cstring> 

// #1
const char* minElement(const char* a, const char* b) {
    return (std::strcmp(a, b) < 0) ? a : b;
}


const char* maxElement(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}


int main()
{
    // #1
    const char* strA = "fruits";
    const char* strB = "vegetables";

    std::cout << "Мінімальний рядок: " << minElement(strA, strB) << std::endl;
    std::cout << "Максимальний рядок: " << maxElement(strA, strB) << std::endl;


    return 0;

}