#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Интерфейс
class PetStoreService {
public:
    virtual void  doService() = 0;
    // Чисто виртуальный метод для получения названия услуги
    virtual string getServiceName() = 0;

    // Чисто виртуальный метод для получения цены услуги
    virtual int getServicePrice() = 0;

    // Чисто виртуальный метод для отображения информации об услуге
    virtual void displayServiceInfo() = 0;
};

//Конкретные делегаты
class Grooming : public PetStoreService {
    string petType;
    int price;
public:
    void doService() { printf("Стрижка животного.\n"); }
    Grooming(string petType, int price) {
        this->petType = petType;
        this->price = price;
    }
    string getServiceName() {
        return "Стрижка для " + petType;
    }

    int getServicePrice() {
        return price;
    }

    void displayServiceInfo() {
        cout << getServiceName() << ", Цена: " << price << endl;
    }
};

class Training : public PetStoreService {
private:
    string trainingType; // Тип обучения (например, базовое, продвинутое)
    int price;        // Цена обучения
public:
    void doService() { printf("Обучение животного.\n"); }
    Training(string trainingTyp, int price) {
        this->trainingType = trainingTyp;
        this->price = price;
    }

    string getServiceName() override {
        return trainingType + " обучение";
    }

    int getServicePrice() override {
        return price;
    }

    void displayServiceInfo() override {
        cout << getServiceName() << ", Цена: " << price << endl;
    }
};

class Medication : public PetStoreService {
private:
    string medicationType; // Тип лечения
    int price;        // Цена лечения
public:
    void doService() { printf("Лечение животного.\n"); }
    Medication(string medicationType, int price) {
        this->medicationType = medicationType;
        this->price = price;
    }
    string getServiceName() override {
        return "Болезнь: " + medicationType;
    }

    int getServicePrice() override {
        return price;
    }

    void displayServiceInfo() override {
        cout << getServiceName() << ", Цена: " << price << endl;
    }
};
