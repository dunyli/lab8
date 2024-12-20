#pragma once
#include <iostream>
#include <string>
using namespace std;

// ласс дл€ хранени€ данных о клиенте
class Client {
private:
    string name;
    string phone;
    string address;
public:
    Client();
    Client(string name, string phone, string address); //конструктор с параметрами
    void get(string &name, string &phone, string &address); //ѕолучение данных класса
    void set(string name, string phone, string address);
    // ѕерегрузка оператора вывода
    friend ostream& operator << (ostream& os, Client& c);
};