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

// #2
template<typename T>
void shellSort(T arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template<>
void shellSort<char*>(char* arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char* temp = arr[i];
            int j;
            for (j = i; j >= gap && std::strcmp(arr[j - gap], temp) > 0; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    // #1
    const char* strA = "fruits";
    const char* strB = "vegetables";

    std::cout << "Мінімальний рядок: " << minElement(strA, strB) << std::endl;
    std::cout << "Максимальний рядок: " << maxElement(strA, strB) << std::endl;


    return 0;

    // #2
    int intArr[] = { 12, 34, 54, 2, 3 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    shellSort(intArr, intSize);
    std::cout << "Sorted integer array: ";
    for (int i = 0; i < intSize; ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    const char* charArr[] = { "apple", "banana", "orange", "grape", "pineapple" };
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    shellSort(charArr, charSize);
    std::cout << "Sorted string array: ";
    for (int i = 0; i < charSize; ++i) {
        std::cout << charArr[i] << " ";
    }
    std::cout << std::endl;

}