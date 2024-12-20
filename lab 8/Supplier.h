#pragma once
using namespace std;

//Класс для хранения данных о поставщике
class Supplier {
private:
    string name;
    string phone;
    string address;
public:
    Supplier();
    Supplier(string name, string phone, string address); //конструктор с параметрами
    void get(string& name, string& phone, string& address); //Получение данных класса
    void set(string name, string phone, string address); //Получение значений переменных-членов класса
    // Перегрузка оператора вывода
    friend ostream& operator << (ostream& os, Supplier& s);
};



