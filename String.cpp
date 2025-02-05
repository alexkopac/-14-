#include "String.h"
#include <cstring>

size_t String::count = 0;

// Конструктор по умолчанию (создает строку длиной 80)
String::String() : String(80) {}

// Конструктор, выделяющий память под строку заданной длины
String::String(size_t size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    ++count;
}

// Конструктор, создающий строку на основе переданного C-строки
String::String(const char* input) : length(std::strlen(input)) {
    str = new char[length + 1];
    std::strcpy(str, input);
    ++count;
}

// Конструктор копирования
String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    std::strcpy(str, other.str);
    ++count;
}

// Оператор присваивания (гарантирует корректное копирование)
String& String::operator=(const String& other) {
    if (this != &other) {  // Защита от самоприсваивания
        delete[] str;  // Освобождаем старую строку

        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }
    return *this;
}

// Деструктор освобождает память
String::~String() {
    delete[] str;
    str = nullptr;
    --count;
}

// Метод для ввода строки
void String::input() {
    std::cout << "Введите строку: ";
    char buffer[1024];  // Буфер для ввода строки
    std::cin.getline(buffer, 1024);

    delete[] str;  // Удаляем старую строку

    length = std::strlen(buffer);
    str = new char[length + 1];
    std::strcpy(str, buffer);
}

// Метод для вывода строки
void String::display() const {
    std::cout << "Строка: " << str << std::endl;
}

// Метод возвращает количество созданных объектов
size_t String::getCount() {
    return count;
}
