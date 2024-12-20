#pragma once
#include "Store.h"
#include <string>

// ����������� ����������� ������ Store
Store::Store()
{
    num_clients = 0;
    num_categories = 0;
    num_suppliers = 0;
}

//����������� �������-����� ������ Store ��� ������ ������ ��������
void Store::listClients(Client* client, int count) {
    for (int i = 0; i < num_clients; i++) {
        if (i == count) *client = clients[i];
    }
}

//����������� �������-����� ������ Store ��� ������ ������ ���������
void Store::listCategories(Category* category, int count) {
    for (int i = 0; i < num_categories; i++) {
        if (i == count) *category = categories[i];
    }
}

//����������� �������-����� ������ Store ��� ������ ������ �����������
void Store::listSuppliers(Supplier* supplier, int count) {
    for (int i = 0; i < num_suppliers; i++) {
        if (i == count) *supplier = suppliers[i];
    }
}

void Store::addClient(Client& newClient) {
    clients.push_back(newClient); // ��������� �������
    num_clients++;
}

void Store::addCategory(Category& newCategory) {
    categories.push_back(newCategory); // ��������� ���������
    num_categories++;
}

void Store::addSupplier(Supplier& newSupplier) {
    suppliers.push_back(newSupplier); // ��������� ����������
    num_suppliers++;
}
