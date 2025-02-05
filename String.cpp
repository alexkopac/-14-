#include "String.h"
#include <cstring>

size_t String::count = 0;

String::String() : String(80) {}


String::String(size_t size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    ++count;
}


String::String(const char* input) : length(std::strlen(input)) {
    str = new char[length + 1];
    std::strcpy(str, input);
    ++count;
}


String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    std::strcpy(str, other.str);
    ++count;
}


String& String::operator=(const String& other) {
    if (this != &other) {  
        delete[] str;  

        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
    return *this;
}


String::~String() {
    delete[] str;
    str = nullptr;
    --count;
}


void String::input() {
    std::cout << "Ââåäèòå ñòðîêó: ";
    char buffer[1024];  
    std::cin.getline(buffer, 1024);

    delete[] str;  

    length = std::strlen(buffer);
    str = new char[length + 1];
    std::strcpy(str, buffer);
}


void String::display() const {
    std::cout << "Ñòðîêà: " << str << std::endl;
}


size_t String::getCount() {
    return count;
}
