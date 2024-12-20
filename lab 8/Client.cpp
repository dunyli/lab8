#pragma once
#include "Client.h"
#include <iostream>


// Определение контруктора с параметрами класса Client
Client::Client(string name, string phone, string address)
{
    this->name = name;
    this->phone = phone;
    this->address = address;
}

Client::Client(){}

//Получение значений переменных-членов класса и данных класса Client
void Client::get(string &name, string &phone, string &address) {
    name = this->name;
    phone = this->phone;
    address = this->address;
}

//Функция для получения значений переменных-членов класса
void Client::set(string name, string phone, string address) {
    this->name = name;
    this->phone = phone;
    this->address = address;
}

// Перегрузка оператора вывода
ostream& operator << (ostream& os, Client& c) {
    os << "Название клиента: " << c.name << ", Телефон: " << c.phone << ", Адрес: " << c.address;
    return os;
}

