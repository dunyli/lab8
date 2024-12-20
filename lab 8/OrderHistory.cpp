#pragma once
#include "OrderHistory.h"

// ����������� ����������� ������ OrderHistory
OrderHistory::OrderHistory()
{
    orderCount = 0;
}

// ����������� ������� - ����� ������ OrderHistory ��� ������ ������� �������
void OrderHistory::listOrders(Order* order, int count) {
    for (int i = 0; i < orderCount; i++) {
        if (i == count) *order = orders[i];
    }
}

// ����������� ������� - ����� ������ OrderHistory - ������� addOrder()
void OrderHistory::addOrder(Order& newOrder) {
    orders.push_back(newOrder); // ��������� �����
    orderCount++;
}
