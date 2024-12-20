#pragma once
#include <iostream>
#include "Product.h"

// ����� ��� �������� ������ � ��������� ������
class Category {
private:
    string name;   // �������� ��������� ("����", "�������", "����������")
    int num_products;
public:
    Category() {};
    Category(string name); //����������� � �����������
    std::string get(); //��������� ������ ������
    void set(string name); //��������� �������� ����������-������ ������
    // ���������� ��������� ������
    friend ostream& operator << (ostream& os, Category& c);
};

