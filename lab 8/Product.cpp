#pragma once
#include "Product.h"

// ����������� ����������� ������ Product
Product::Product()
{
    price = 0;
    count = 0;
    category_id = 0;
    supplier_id = 0;
}

// ����������� ����������� ������ Product
Product::Product(string name, int price, int count, int category_id, int supplier_id)
{
    this->name = name;
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

//��������� �������� ����������-������ ������ � ������ ������ Product
void Product::get(string& name, int* price, int* count, int* category_id, int* supplier_id) {
    name = this->name;
    *price = this->price;
    *count = this->count;
    *category_id = this->category_id;
    *supplier_id = this->supplier_id;
}

void Product::set(string name, int price, int count, int category_id, int supplier_id) {
    this->name = name;
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

//���������� ��������� ������
ostream& operator << (ostream& os, Product& p) {
    os << "�������� ������: " << p.name << ", ����: " << p.price
        << ", ����������: " << p.count << ", ID ���������: " << p.category_id
        << ", ID ����������: " << p.supplier_id;
    return os;
}
