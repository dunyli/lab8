// Лабораторная №4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Worker.h"
#include "Storehouse.h"
#include "Store.h"
#include "Product.h"
#include "Supplier.h"
#include "Client.h"
#include "Category.h"
#include "Order.h"
#include "OrderHistory.h"
#include "PetStoreService.h"
#include "pet.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm> 
using namespace std;

// Функция для вывода меню
void outmenu() {
    printf("1. Добавление данных\n");
    printf("2. Вывод данных\n");
    printf("3. Создание заказа\n");
    printf("4. Выбор услуги\n");
    printf("5. Поиск и сортировка информации\n");
    printf("0. Выход\n");
    printf("Выберите действие: ");
}

// Функция для добавления данных
void addinfo() {
    printf("1. Добавить клиента\n");
    printf("2. Добавить категорию\n");
    printf("3. Добавить поставщика\n");
    printf("4. Добавить товар\n");
    printf("0. Выход\n");
    printf("Выберите действие: ");
}
// Функция для вывода данных
void listinfo(){
    printf("1. Вывести список клиентов\n");
    printf("2. Вывести список категорий\n");
    printf("3. Вывести список поставщиков\n");
    printf("4. Вывести список товаров\n");
    printf("5. Вывести список заказов\n");
    printf("6. Вывести информацию о магазине\n");
    printf("0. Выход\n");
    printf("Выберите действие: ");
}

// Функция для входа в систему
void login(WorkerDatabase *database) {
    string username;
    int id;
    string department;
    bool succes;
    int check_id = 0;
    int year;
    cout << "Войдите в систему.\n";
    do {
        do {
            check_id = 0;
            succes = true;
            cout << "Введите свое имя: ";
            getline(cin, username);
            cout << "Введите свой ID: ";
            scanf("%d", &id);
            cout << "Введите общее количество лет работы: ";
            scanf("%d", &year);
            check_id = database->checkID(id);
        } while (check_id != 0);
        try {
            Worker worker(username, id, year);
            // Предположим, что если ID меньше 100, это работник, иначе - менеджер
            if (id < 100) {
                worker.displayInfo();
                database->addWorker(make_unique<Worker>(username, id, year));
                database->showWorkerInfo(&worker); // Вызовет Worker::displayInfo
            }
            else {
                Manager manager(username, id, year);
                manager = worker;
                while (getchar() != '\n');
                _flushall();
                cout << "Введите свой отдел: ";
                getline(cin, department);
                manager.setDepartment(department);
                cout << "Введите количество лет работы менеджером: ";
                scanf("%d", &year);
                manager.setYears(year);
                manager.displayInfo();
                database->addWorker(make_unique<Manager>(username, id, worker.getYears(),department, year, manager.getTeamSize()));
                database->showWorkerInfo(&manager); // Вызовет Manager::displayInfo
            }
        }
        catch (invalid_argument& e) {
            cout << "Произошла ошибка: " << e.what() << endl;
            succes = false;
            while (getchar() != '\n');
        }
    } while (succes != 1);
}

void displayOrderHistory(Order new_order, int j) {
    string name;
    int client_id, num_products, total_price, price, count, category_id, supplier_id;
    printf("Заказ №%d. ", j + 1);
    new_order.get(&client_id, &num_products, &total_price);
    printf("ID клиента: %d  ", client_id);
    for (int a = 0; a < num_products; a++) {
        printf("Товары: ");
        printf("%d. ", a + 1);
        Product new_product;
        new_order.listProducts(&new_product, a);
        new_product.get(name, &price, &count, &category_id, &supplier_id);
        printf("Название продукта: ");
        cout << name << endl;
        printf("Цена: %d, Количество: %d\n", price, count);
    }
    printf("Общая стоимость: %d\n", total_price);
    printf("\n");
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "Rus");
    Store store;
    Storehouse storehouse;
    OrderHistory orderhistory;
    Order new_order;
    Product new_product;
    WorkerDatabase database;
    int choice1, choice2;
    string name, address, phone;
    int price, num_products = 0, count, category_id, supplier_id;
    int client_id, product_id, volume;
    int num_products_order = 0, total_price = 0, allprice = 0;
    int count_product_volume;
    string username;
    int id;

    Pet* newPet1 = new Pet("Барбос", 5);
    Pet* newPet2 = new Pet("Бобик", 25);
    Grooming* typeGrooming1 = new Grooming("Собака", 2000);
    Grooming* typeGrooming2 = new Grooming("Кошка", 4000);
    Training* typeTraining1 = new Training("Продвинутый", 3000);
    Medication* typeMedication1 = new Medication("Ветрянка", 5000);
    printf("\n Барбос:\n");
    newPet1->addService(typeGrooming1);
    newPet1->addService(typeTraining1);
    newPet1->addService(typeMedication1);
    newPet1->performAllServices();
    newPet1->performAllServiceInfo();
    printf("\n Бобик:\n");
    newPet2->addService(typeGrooming2);
    newPet2->addService(typeTraining1);
    newPet2->performAllServices();
    newPet2->performAllServiceInfo();
    Tester newTester("Виктор", 56, 35, 5);
    TeamLead newTeamLead("Максим", 32, 24, 2, 5);
    printf("Tester: ");
    newTester.performManage();
    newTester.performTesting();
    printf("TeamLead: ");
    newTeamLead.performManage();
    newTeamLead.performTesting();
    newTester.management = new AssistentManager;
    newTester.performManage();
    //login(&database);
    do {
        outmenu();
        scanf("%d", &choice1);
        getchar();  // Удаляем символ новой строки из буфера
        switch (choice1) {
        case 1: {
            printf("Добавление данных.\n");
            addinfo();
            scanf("%d", &choice2);
            switch (choice2) {
            case 1: {
                while (getchar() != '\n');
                printf("Введите имя клиента: ");
                getline(cin, name);
                _flushall();
                printf("Введите телефон клиента: ");
                getline(cin, phone);
                _flushall();
                printf("Введите адрес клиента: ");
                getline(cin, address);
                _flushall();
                Client new_client(name, phone, address);
                store.addClient(new_client);
                printf("Клиент добавлен!\n");
                break;
            }
            case 2: {
                while (getchar() != '\n');
                printf("Введите название категории:  ");
                getline(cin, name);
                _flushall();
                Category new_category(name);
                store.addCategory(new_category);
                printf("Категория добавлена!\n");
                break;
            }
            case 3: {
                while (getchar() != '\n');
                printf("Введите название поставщика: ");
                getline(cin, name);
                _flushall();
                printf("Введите телефон: ");
                getline(cin, phone);
                _flushall();
                printf("Введите адрес: ");
                getline(cin, address);
                _flushall();
                Supplier new_supplier(name, phone, address);
                store.addSupplier(new_supplier);
                printf("Поставщик добавлен!\n");
                break;
            }
            case 4: {
                do {
                    printf("Введите ID категории (или 0 для выхода): ");
                    scanf("%d", &category_id);
                    if (category_id < 0 || category_id > store.listnum_categories()) printf("Неверный ID категории! ");
                } while (category_id < 0 || category_id > store.listnum_categories());
                if (category_id != 0) {
                    do {
                        printf("Введите ID поставщика (или 0 для выхода): ");
                        scanf("%d", &supplier_id);
                        if (supplier_id < 0 || supplier_id > store.listnum_suppliers()) printf("Неверный ID поставщика! ");
                    } while (supplier_id < 0 || supplier_id > store.listnum_suppliers());
                    if (supplier_id != 0) {
                        while (getchar() != '\n');
                        printf("Введите название товара:");
                        getline(cin, name);
                        _flushall();
                        printf("Введите цену товара: ");
                        scanf("%d", &price);
                        printf("Введите количество товара: ");
                        scanf("%d", &count);
                        new_product.set(name, price, count, category_id, supplier_id);
                        storehouse.addProduct(new_product);
                        printf("Товар добавлен!\n");
                    }
                }
                break;
            }
            case 0: {
                printf("Выход...\n");
                break;
            }
            }
            break;
        }
        case 2: {
            printf("Вывод данных.\n");
            listinfo();
            scanf("%d", &choice2);
            switch (choice2) {
            case 1: {
                printf("Список клиентов:\n");
                for (int j = 0; j < store.listnum_clients(); j++) {
                    printf("ID клиента: %d\n", j + 1);
                    Client new_client(name, phone, address);
                    store.listClients(&new_client, j);
                    cout << new_client << endl;
                }
                break;
            }
            case 2: {
                printf("Список категорий:\n");
                for (int j = 0; j < store.listnum_categories(); j++) {
                    printf("ID категории: %d  ", j + 1);
                    Category new_category;
                    store.listCategories(&new_category, j);
                    cout << new_category << endl;
                }
                break;
            }
            case 3: {
                printf("Список поставщиков:\n");
                for (int j = 0; j < store.listnum_suppliers(); j++) {
                    printf("ID поставщика: %d  ", j + 1);
                    Supplier new_supplier;
                    store.listSuppliers(&new_supplier, j);
                    cout << new_supplier << endl;
                }
                break;
            }
            case 4: {
                printf("Список товаров:\n");
                for (int j = 0; j < storehouse.listnum_products(); j++) {
                    printf("ID: %d. ", j + 1);
                    storehouse.listStorehouse(&new_product, j);
                    cout << new_product << endl;
                }
                break;
            }
            case 5: {
                printf("История заказов:\n");
                for (int j = 0; j < orderhistory.listorder_count(); j++) {
                    orderhistory.listOrders(&new_order, j);
                    displayOrderHistory(new_order, j);
                }
                break;
            }
            case 0: {
                printf("Выход...\n");
                break;
            }
            }
            break;
        case 3: {
            num_products_order = 0;
            total_price = 0;
            do {
                printf("Введите ID клиента (или 0 для завершения): ");
                scanf("%d", &client_id);
                if (client_id < 0 || client_id > store.listnum_categories()) printf("Неверный ID клиента! ");
            } while (client_id < 0 || client_id > store.listnum_clients());
            if (client_id != 0) {
                printf("Введите ID товара (или 0 для завершения): ");
                scanf("%d", &product_id);
                while (product_id != 0) {
                    if (product_id > 0 && product_id <= storehouse.listnum_products()) {
                        Product new_product;
                        storehouse.listStorehouse(&new_product, product_id - 1);
                        printf("Введите количество товара (макс. %d): ", new_product.getCount());
                        scanf("%d", &volume);
                        if (volume > 0 && volume <= new_product.getCount()) {
                            total_price += new_product.getPrice() * volume;
                            new_product.get(name, &price, &count, &category_id, &supplier_id);
                            count_product_volume = count - volume;
                            storehouse.editProduct(product_id - 1, name, price, count_product_volume, category_id, supplier_id);
                            new_product.set(name, price, volume, category_id, supplier_id);
                            new_order.addProduct(new_product);
                            num_products_order++;
                        }
                        else printf("Неверное количество товара!\n");
                    }
                    else printf("Неверный ID товара!\n");
                    printf("Введите ID нового товара (или 0 для завершения): ");
                    scanf("%d", &product_id);
                }
            }
            if (num_products_order > 0) {
                new_order.set(client_id, num_products_order, total_price);
                orderhistory.addOrder(new_order);
                printf("Заказ создан!\n");
            }
            break;
        }
        case 4: {
            int choice_service, price_service, years;
            string petType, trainingType, namepet, medicationType;
            printf("Введите имя животного: ");
            getline(cin, namepet);
            _flushall();
            printf("Введите количество лет: ");
            scanf("%d", &years);
            Pet* newPet = new Pet(namepet, years);
            do {
                printf("1. Стрижка\n");
                printf("2. Обучение\n");
                printf("3. Лечение\n");
                printf("0. Выход\n");
                scanf("%d", &choice_service);
                if (choice_service == 1) {
                    while (getchar() != '\n');
                    printf("Введите тип животного: ");
                    getline(cin, petType);
                    _flushall();
                    printf("Введите цену стрижки: ");
                    scanf("%d", &price_service);
                    Grooming* typeGrooming = new Grooming(petType, price_service);
                    newPet->addService(typeGrooming);
                    typeGrooming->displayServiceInfo();
                }
                if (choice_service == 2) {
                    while (getchar() != '\n');
                    printf("Введите тип обучения: ");
                    getline(cin, trainingType);
                    _flushall();
                    printf("Введите цену обучения: ");
                    scanf("%d", &price_service);
                    Training* typeTraining = new Training(trainingType, price_service);
                    newPet->addService(typeTraining);
                    typeTraining->displayServiceInfo();
                }
                if (choice_service == 3) {
                    while (getchar() != '\n');
                    printf("Введите болезнь животного: ");
                    getline(cin, medicationType);
                    _flushall();
                    printf("Введите цену лечения: ");
                    scanf("%d", &price_service);
                    Medication* typeMedication = new Medication(medicationType, price_service);
                    newPet->addService(typeMedication);
                    typeMedication->displayServiceInfo();
                }
                if (choice_service == 0) {
                    newPet->performAllServiceInfo();
                }
            } while (choice_service != 0);
            break;
        }
        case 5: {
            int choicesearch;
            printf("Поиск и сортировка информации.\n");
            printf("Введите номер функции:\n");
            printf("1. Вывести список товаров, отсортированных по алфавиту.\n");
            printf("2. Вывести список товаров отсортированных по возрастанию цены.\n");
            printf("3. Вывести список товаров отсортированных по убыванию цены.\n");
            printf("4. Вывести список заказов отсортированных по возрастанию цены.\n");
            printf("5. Вывести список заказов отсортированных по убыванию цены.\n");
            printf("6. Поиск товаров.\n");
            printf("7. Поиск заказов.\n");
            scanf("%d", &choicesearch);
            getchar();  // Удаляем символ новой строки из буфера
            switch (choicesearch)
            {
            case 1: {
                vector<Product> newStorehouse;
                newStorehouse = storehouse.getProducts();
                sort(newStorehouse.begin(), newStorehouse.end(), [](Product& p1, Product& p2) {
                    string str1, str2;
                    str1 = p1.getName();
                    str2 = p2.getName();
                    return str1 < str2;
                    });
                for (Product NewProduct : newStorehouse) {
                    cout << NewProduct << endl;
                }
                break;
            }
            case 2: {
                vector<Product> newStorehouse;
                newStorehouse = storehouse.getProducts();
                sort(newStorehouse.begin(), newStorehouse.end(), [](Product& p1, Product& p2) {
                    int price1, price2;
                    price1 = p1.getPrice();
                    price2 = p2.getPrice();
                    return  price1 < price2;
                    });
                for (Product NewProduct : newStorehouse) {
                    cout << NewProduct << endl;
                }
                break;
            }
            case 3: {
                vector<Product> newStorehouse;
                newStorehouse = storehouse.getProducts();
                sort(newStorehouse.begin(), newStorehouse.end(), [](Product& p1, Product& p2) {
                    int price1, price2;
                    price1 = p1.getPrice();
                    price2 = p2.getPrice();
                    return  price1 > price2;
                    });
                for (Product NewProduct : newStorehouse) {
                    cout << NewProduct << endl;
                }
                break;
            }
            case 4: {
                vector<Order> neworderHistory;
                neworderHistory = orderhistory.getOrders();
                sort(neworderHistory.begin(), neworderHistory.end(), [](Order& o1, Order& o2) {
                    int price1, price2;
                    price1 = o1.getTotalprice();
                    price2 = o2.getTotalprice();
                    return  price1 < price2;
                    });
                int j = 0;
                for (Order NewOrder : neworderHistory) {
                    displayOrderHistory(NewOrder, j);
                    j++;
                }
                break;
            }
            case 5: {
                vector<Order> neworderHistory;
                neworderHistory = orderhistory.getOrders();
                sort(neworderHistory.begin(), neworderHistory.end(), [](Order& o1, Order& o2) {
                    int price1, price2;
                    price1 = o1.getTotalprice();
                    price2 = o2.getTotalprice();
                    return  price1 > price2;
                    });
                int j = 0;
                for (Order NewOrder : neworderHistory) {
                    displayOrderHistory(NewOrder, j);
                    j++;
                }
                break;
            }
            default:
                printf("Неверный ввод. Пожалуйста, попробуйте еще раз.\n");
                break;
            }
        }
        case 0:
            printf("Выход...\n");
            break;
        default:
            printf("Неверный ввод. Пожалуйста, попробуйте еще раз.\n");
        }
        }
        } while (choice1 != 0);
        return 0;
    }

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
