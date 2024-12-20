#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���������
class PetStoreService {
public:
    virtual void  doService() = 0;
    // ����� ����������� ����� ��� ��������� �������� ������
    virtual string getServiceName() = 0;

    // ����� ����������� ����� ��� ��������� ���� ������
    virtual int getServicePrice() = 0;

    // ����� ����������� ����� ��� ����������� ���������� �� ������
    virtual void displayServiceInfo() = 0;
};

//���������� ��������
class Grooming : public PetStoreService {
    string petType;
    int price;
public:
    void doService() { printf("������� ���������.\n"); }
    Grooming(string petType, int price) {
        this->petType = petType;
        this->price = price;
    }
    string getServiceName() {
        return "������� ��� " + petType;
    }

    int getServicePrice() {
        return price;
    }

    void displayServiceInfo() {
        cout << getServiceName() << ", ����: " << price << endl;
    }
};

class Training : public PetStoreService {
private:
    string trainingType; // ��� �������� (��������, �������, �����������)
    int price;        // ���� ��������
public:
    void doService() { printf("�������� ���������.\n"); }
    Training(string trainingTyp, int price) {
        this->trainingType = trainingTyp;
        this->price = price;
    }

    string getServiceName() override {
        return trainingType + " ��������";
    }

    int getServicePrice() override {
        return price;
    }

    void displayServiceInfo() override {
        cout << getServiceName() << ", ����: " << price << endl;
    }
};

class Medication : public PetStoreService {
private:
    string medicationType; // ��� �������
    int price;        // ���� �������
public:
    void doService() { printf("������� ���������.\n"); }
    Medication(string medicationType, int price) {
        this->medicationType = medicationType;
        this->price = price;
    }
    string getServiceName() override {
        return "�������: " + medicationType;
    }

    int getServicePrice() override {
        return price;
    }

    void displayServiceInfo() override {
        cout << getServiceName() << ", ����: " << price << endl;
    }
};
