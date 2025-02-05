#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
    char* str;
    size_t length;
    static size_t count;

public:
    String();
    explicit String(size_t size);
    explicit String(const char* input);
    ~String();
    void input();
    void display() const;
    static size_t getCount();
};

#endif // STRING_H