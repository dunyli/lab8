#pragma once
#include <iostream>
using namespace std;

//Класс для хранения информации о товаре
class Product {
private:
    string name;
    int price;
    int count;
    int category_id;
    int supplier_id;
public:
    Product(); //конструктор
    Product(string name, int price, int count, int category_id, int supplier_id);
    void get(string& name, int* price, int* count, int* category_id, int* supplier_id); //Получение данных класса
    void set(string name, int price, int count, int category_id, int supplier_id); //Получение значений переменных-членов класса
    int getPrice() {
        return price;
    };
    int getCount() {
        return count;
    };
    string getName() {
        return this->name;
    }
    // Метод для копирования данных
    void copyTo(Product& other) {
        other.name = this->name;
        other.price = this->price;
        other.count = this->count;
        other.category_id = this->category_id;
        other.supplier_id = this->supplier_id;
    }
    // Перегрузка оператора вывода
    friend ostream& operator << (ostream& os, Product& p);
};