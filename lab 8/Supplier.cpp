#pragma once
#include <iostream>
#include "Supplier.h"

// ����������� ����������� � ����������� ������ Supplier
Supplier::Supplier(string name, string phone, string address)
{
    this->name = name;
    this->phone = phone;
    this->address = address;
}

Supplier::Supplier(){}

//��������� �������� ����������-������ ������ � ������ ������ Suppplier
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

// ���������� ��������� ������
ostream& operator << (ostream& os, Supplier& s) {
    os << "�������� ����������: " << s.name << ", �������: " << s.phone << ", �����: " << s.address;
    return os;
}