#pragma once
#include "Order.h"
#include "vector"

//����� ��� �������� ������� �������
class OrderHistory {
private:
    vector<Order> orders; // ������ �������� Order
    int orderCount;
public:
    OrderHistory();
    void addOrder(Order& newOrder);
    void listOrders(Order* order, int count);
    int listorder_count() {
        return orderCount;
    };
};