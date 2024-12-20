#pragma once
#include <iostream>
#include <string>
using namespace std;

//����� ��� �������� ������ � �������
class Client {
private:
    string name;
    string phone;
    string address;
public:
    Client();
    Client(string name, string phone, string address); //����������� � �����������
    void get(string &name, string &phone, string &address); //��������� ������ ������
    void set(string name, string phone, string address);
    // ���������� ��������� ������
    friend ostream& operator << (ostream& os, Client& c);
};