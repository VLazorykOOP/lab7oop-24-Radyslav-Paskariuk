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

// #4
template<typename T>
class Node {
public:
    T data;
    Node* next;


    Node(const T& newData) : data(newData), next(nullptr) {}
};


template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:

    LinkedList() : head(nullptr) {}

    void push_back(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }


    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* startNode) : current(startNode) {}

        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }


        T& operator*() const {
            return current->data;
        }

        // Перевірка на рівність
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        // Перевірка на нерівність
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    // Початковий ітератор
    Iterator begin() const {
        return Iterator(head);
    }

    // Кінцевий ітератор
    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main()
{
    // #1
    const char* strA = "fruits";
    const char* strB = "vegetables";

    std::cout << "Мінімальний рядок: " << minElement(strA, strB) << std::endl;
    std::cout << "Максимальний рядок: " << maxElement(strA, strB) << std::endl;


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

    // #4
    LinkedList<int> list;
    int n;
    std::cout << "Enter the number of elements for the integer list: ";
    std::cin >> n;
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        list.push_back(value);
    }

    std::cout << "List elements using iterator: ";
    for (LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    return 0;
}