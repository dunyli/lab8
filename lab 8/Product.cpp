#pragma once
#include "Product.h"

// Определение контруктора класса Product
Product::Product()
{
    price = 0;
    count = 0;
    category_id = 0;
    supplier_id = 0;
}

// Определение контруктора класса Product
Product::Product(string name, int price, int count, int category_id, int supplier_id)
{
    this->name = name;
    this->price = price;
    this->count = count;
    this->category_id = category_id;
    this->supplier_id = supplier_id;
}

//Получение значений переменных-членов класса и данных класса Product
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

//Перегрузка оператора вывода
ostream& operator << (ostream& os, Product& p) {
    os << "Название товара: " << p.name << ", Цена: " << p.price
        << ", Количество: " << p.count << ", ID Категории: " << p.category_id
        << ", ID Поставщика: " << p.supplier_id;
    return os;
}
