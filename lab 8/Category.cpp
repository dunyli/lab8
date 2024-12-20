#pragma once
#include "Category.h"

// Определение контруктора с параметрами класса Category
Category::Category(string name)
{
    this->name = name;
    num_products = 0;
}

//Получение значений переменных-членов класса и данных класса Category
std::string Category::get() {
    return name;
}

void Category::set(string name) {
    this->name = name;
}

// Перегрузка оператора вывода
ostream& operator << (ostream& os, Category& c) {
    os << "Название категории: " << c.name;
    return os;
}