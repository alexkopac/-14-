#include "String.h"

int main() {
    std::cout << "������� ������:\n";

    String s1;
    s1.display();

    String s2(50);
    s2.display();

    String s3("Hello world");
    s3.display();

    std::cout << "������� ����� ������ ��� s2:\n";
    s2.input();
    s2.display();

    std::cout << "���������� ��������� ��������: " << String::getCount() << std::endl;

    return 0;
}
