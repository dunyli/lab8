#pragma once
#include <iostream>
using namespace std;

//����� ��� �������� ���������� � ������
class Product {
private:
    string name;
    int price;
    int count;
    int category_id;
    int supplier_id;
public:
    Product(); //�����������
    Product(string name, int price, int count, int category_id, int supplier_id);
    void get(string& name, int* price, int* count, int* category_id, int* supplier_id); //��������� ������ ������
    void set(string name, int price, int count, int category_id, int supplier_id); //��������� �������� ����������-������ ������
    int getPrice() {
        return price;
    };
    int getCount() {
        return count;
    };
    string getName() {
        return this->name;
    }
    // ����� ��� ����������� ������
    void copyTo(Product& other) {
        other.name = this->name;
        other.price = this->price;
        other.count = this->count;
        other.category_id = this->category_id;
        other.supplier_id = this->supplier_id;
    }
    // ���������� ��������� ������
    friend ostream& operator << (ostream& os, Product& p);
};