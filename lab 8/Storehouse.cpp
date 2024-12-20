#pragma once
#include "Storehouse.h"
#include "memory"

// ����������� ����������� ������ Storehouse
Storehouse::Storehouse()
{
    num_products = 0;
    capacity = 1;
    products = new shared_ptr<Product>[capacity]; // �������������� ������ ����������
}

//����������� �������-����� ������ Storehouse ��� ������ ������ �������
void Storehouse::listStorehouse(Product& productCopy, int count) {
    for (int i = 0; i < num_products; ++i) {
        if (i == count) products[i]->copyTo(productCopy); // �������� ������ � ���������� ������; 
    }
}

void Storehouse::addProduct(Product& newProduct) {
        if (num_products >= capacity) {
            capacity++;
            // ����������� �����������
            shared_ptr<Product>* new_products = new shared_ptr<Product>[capacity]; // ������� ����� ������
            // �������� ������ ��������� � ����� ������
            for (int i = 0; i < num_products; ++i) {
                new_products[i] = products[i];
            }
            delete[] products; // ����������� ������ ������
            products = new_products; // ��������� ��������� �� ������
        }
        // ������� ����� ������ Product � ��������� ��� � ������
        products[num_products] = make_shared<Product>(newProduct);
        num_products++; // ����������� ���������� ���������
}


void Storehouse::editProduct(int product_id, string name, int price, int volume, int category_id, int supplier_id) {
    products[product_id]->set(name, price, volume, category_id, supplier_id);
}
