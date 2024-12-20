#pragma once
#include "Order.h"
#include "Product.h"

// ����������� ����������� ������ Order
Order::Order()
{
    client_id = 0;
    num_products = 0;
    total_price = 0;
}

//��������� �������� ����������-������ ������ � ������ ������ Order
void Order::get(int* client_id, int* num_products, int* total_price) {
    *client_id = this->client_id;
    *num_products = this->num_products;
    *total_price = this->total_price;
}

//������� ��� ��������� �������� ����������-������ ������
void Order::set(int client_id, int num_products, int total_price) {
    this->client_id = client_id;
    this->num_products = num_products;
    this->total_price = total_price;
}

//����������� �������-����� ������ Order ��� ������ ������� �������
void Order::listProducts(Product* product, int count) {
    for (int i = 0; i < num_products; i++) {
        if (i == count) *product = products[i];
    }
}

// ����������� ������� - ����� ������ Order - ������� addProduct()
void Order::addProduct(Product& newProduct) {
    products.push_back(newProduct); // ��������� �������
    num_products++;
}