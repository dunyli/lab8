#pragma once
#include <iostream>
#include "Supplier.h"

// Определение контруктора с параметрами класса Supplier
Supplier::Supplier(string name, string phone, string address)
{
    this->name = name;
    this->phone = phone;
    this->address = address;
}

Supplier::Supplier(){}

//Получение значений переменных-членов класса и данных класса Suppplier
void Supplier::get(string& name, string& phone, string& address) {
    name = this->name;
    phone = this->phone;
    address = this->address;
}

void Supplier::set(string name, string phone, string address) {
    this->name = name;
    this->phone = phone;
    this->address = address;
}

// Перегрузка оператора вывода
ostream& operator << (ostream& os, Supplier& s) {
    os << "Название поставшика: " << s.name << ", Телефон: " << s.phone << ", Адрес: " << s.address;
    return os;
}