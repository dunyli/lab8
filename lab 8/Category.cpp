#pragma once
#include "Category.h"

// ����������� ����������� � ����������� ������ Category
Category::Category(string name)
{
    this->name = name;
    num_products = 0;
}

//��������� �������� ����������-������ ������ � ������ ������ Category
std::string Category::get() {
    return name;
}

void Category::set(string name) {
    this->name = name;
}

// ���������� ��������� ������
ostream& operator << (ostream& os, Category& c) {
    os << "�������� ���������: " << c.name;
    return os;
}