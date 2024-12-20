#pragma once
#include "Client.h"
#include <iostream>


// ����������� ����������� � ����������� ������ Client
Client::Client(string name, string phone, string address)
{
    this->name = name;
    this->phone = phone;
    this->address = address;
}

Client::Client(){}

//��������� �������� ����������-������ ������ � ������ ������ Client
void Client::get(string &name, string &phone, string &address) {
    name = this->name;
    phone = this->phone;
    address = this->address;
}

//������� ��� ��������� �������� ����������-������ ������
void Client::set(string name, string phone, string address) {
    this->name = name;
    this->phone = phone;
    this->address = address;
}

// ���������� ��������� ������
ostream& operator << (ostream& os, Client& c) {
    os << "�������� �������: " << c.name << ", �������: " << c.phone << ", �����: " << c.address;
    return os;
}

