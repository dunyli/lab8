#pragma once
#include "WorkInterface.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Worker {
protected:
    string name_worker;
    int id_worker;
    int yearsOfExperience; //����� ���������� ��� �����
public:
    // ������ ������������ �� ���������
    Worker() = delete;
    //����������� � �����������
    Worker(string name, int id, int yearsOfExperience) {
        if (name.empty()) {
            throw invalid_argument("��� �� ����� ���� ������.");
        }
        if (id < 0) {
            throw invalid_argument("ID �� ����� ���� �������������.");
        }
        if (yearsOfExperience < 0) {
            throw invalid_argument("���� �� ����� ���� �������������.");
        }
        this->name_worker = name;
        this->id_worker = id;
        this->yearsOfExperience = yearsOfExperience;
    }

    // ����������� �������������� ������������
    Worker(Worker* other) {
        if (other == nullptr) {
            throw invalid_argument("��������� �� ������ �� ����� ���� �������.");
        }
        name_worker = other->name_worker;
        id_worker = other->id_worker;
        yearsOfExperience = other->yearsOfExperience;
    }

    //����������
    virtual ~Worker() {};

    // ����� ��� ����������� ���������� � ���������
    virtual void displayInfo() {
        cout << "��������: " << name_worker << ", ID: " << id_worker << ", ����: " << yearsOfExperience << " ���" << endl;
    }

    //����� ��� ������ �������� ����� ������ �������
    int getSalary() {
        int cash = getCash();
        if (cash < 20000) cash = cash - (cash % 10);
        else if (cash < 40000) cash = cash - (cash % 15);
        else if (cash < 80000) cash = cash - (cash % 18);
        else cash = cash - (cash % 20);
        return cash;
    }
    // ����� ��� ��������� ����� ���������
    virtual void changeName(string& newName) {
        if (newName.empty()) {
            throw invalid_argument("����� ��� �� ����� ���� ������.");
            name_worker = newName;
        }
        cout << "��� ��������� ��������:: " << name_worker << endl;
    }

    // ����� ��� �������� �������� ���������
    virtual int getCash() {
        return yearsOfExperience * 1000;
    }

    int getYears() {
        return yearsOfExperience;
    }

    // ����� ��� ��������� ������������������ ������
    int getId() {
        return id_worker;
    }

    // ����� ��� ��������� ����� ���������
    string getName(){
        return name_worker;
    }
};

class Tester : public Worker, public WorkInterface {
private:
    int yearsAsTester; 
public:
    // �����������
    Tester(string name, int id, int yearsOfExperience, int yearsAsTester)
        : Worker(name, id, yearsOfExperience), yearsAsTester(yearsAsTester) {
        testing = new AssistentTester;
        management = new NoManager;
    }

    // ���������� ������ ���������� ��������
    void manageProject(string projectName) {
        cout << "����������� " << name_worker << " ��������� ������������� �������: " << projectName << endl;
    }

    // ���������� ������ ������������
    void conductTesting(string projectName) {
        cout << "����������� " << name_worker << " �������� ������������ ��� �������: " << projectName << endl;
    }

    // ��������������� ������ displayInfo
    void displayInfo() {
        cout << "�����������: " << name_worker << ", ID: " << id_worker << ", ����: " << yearsOfExperience << " ���" << endl;
    }

};

class TeamLead : public Worker, public WorkInterface {
private:
    int yearsAsTeamLead;
    int teamSize; // ������ �������
public:
    // �����������
    TeamLead(string name, int id, int yearsOfExperience, int yearsAsTester, int teamSize)
        : Worker(name, id, yearsOfExperience), yearsAsTeamLead(yearsAsTeamLead), teamSize(teamSize) {
        management = new AssistentManager;
        testing = new MainTester;
    }

    // ���������� ������ ���������� ��������
    void manageProject(string projectName){
        cout << "������ " << name_worker << " ��������� ��������: " << projectName << " � �������� �������: " << teamSize << endl;
    }

    // ��������������� ������ displayInfo
    void displayInfo() {
        cout << "������: " << name_worker << ", ID: " << id_worker << ", ����: " << yearsOfExperience << " ���, ������ �������: " << teamSize << endl;
    }
};

// ����� ��� ���������, �������������� �� Worker
class Manager : public Worker{
private:
    string department;
    vector<string> teamMembers; // ��������� �� ������������ ������ ������ �������
    int teamSize; // ������ �������
    int yearsAsManager; // ���������� ��� ����� � �������� ���������
public:
    //�����������
    Manager(string name, int id, int yearsOfExperience) : Worker(name, id, yearsOfExperience){
        teamSize = 0;
    }

    // ������ ������������ �� ���������
    Manager() = delete;

    // ����������� ���������, ���������� ����������� �������� ������
    Manager(string name, int id, int yearsOfExperience, string department, int yearsAsManager, int teamSize)
        : Worker(name, id, yearsOfExperience), department(department), yearsAsManager(yearsAsManager), teamSize(teamSize) {
        if (department.empty()) {
            throw invalid_argument("����� �� ����� ���� ������.");
        }
        if (yearsAsManager < 0) {
            throw invalid_argument("���� �� ����� ���� �������������.");
        }
    }

    // ����������� ������������
    Manager(Manager& other) : Worker(other) {
        department = other.department;
        yearsAsManager = other.yearsAsManager;
        teamSize = other.teamSize;
        for (int i = 0; i < teamSize; ++i) {
            teamMembers[i] = other.teamMembers[i]; // �������� ������
        }
    }

    // ������� ��� ��������� ���������� ��� ����� � �������� ���������
    int getCash() override {
        int years;
        years = yearsOfExperience - yearsAsManager;
        return yearsAsManager * 5000 + years * 1000;
    }

    //�������� ���������� ������ � ����������� ������, � ������ �� ����������� ��� � ������� ������. 
    void displayInfo() override {
        cout << "��������: " << name_worker << ", ID: " << id_worker << ", ����: " << yearsAsManager << 
            " ��� � �������� ���������" << endl;
        cout << "����� �������: ";
        for (int i = 0; i < teamSize; ++i) {
            cout << teamMembers[i] <<  ", ";
        }
        cout << endl;
    }
    
    // ����� ��� ���������� ����� �������
    void addTeamMember(string& member) {
        teamMembers.push_back(member);
        teamSize++;
    }

    // ���������� ������ changeName, ������� ����� �������� ������
    void changeName(string& newName) override {
        Worker::changeName(newName); // ����� ������ �������� ������
        cout << "��� ��������� �������� ��: " << name_worker << endl;
    }

    void setYears(int year) {
        yearsAsManager = year;
    }

    // ����� ��� ��������� ���������� � ������������
    string getDepartment() {
        return department;
    }

    // ����� ��� ��������� ���������� � 
    int getTeamSize() {
        return teamSize;
    }

    //����� ��� ��������� ������
    void setDepartment(string department) {
        this->department = department;
    }

    // ���������� ��������� ������������ ������� ������������ ������ �������� �������� ������
    void operator=(Worker other) {
        this->name_worker = other.getName();
        this->id_worker = other.getId();
        this->yearsOfExperience = other.getYears();
        // ������� �������� ����������� �����
        department = "����������� �����"; // ������������� �������� �� ���������
        teamSize = 0; // �������� ������ �������
        yearsAsManager = 0;
    }

};


// ����� ��� �������� ����������
class WorkerDatabase {
private:
    vector<unique_ptr<Worker>> workers; // ������ ���������� ���������� �� ����������
    int num_workers;
public:
    WorkerDatabase() { num_workers = 0; }

    // ����� ��� ���������� ���������
    void addWorker(unique_ptr<Worker> worker) {
        workers.push_back(move(worker)); // ��������� ��������� � ����
        num_workers++;
    }

    // ����� ��� ����������� ���� ����������
    void displayAllWorkers() {
        for (int i = 0; i < num_workers; i++) {
            workers[i]->displayInfo(); // �������� ����������� ������� displayInfo
        }
    }

    //����� ��� �������� ID
    int checkID(int id) {
        for (int i = 0; i < num_workers; i++) {
            if (id == workers[i]->getId()) return 1;
        }
        return 0;
    }

    // ����� ��� ������ ��������� �� ID
    void findWorkerById(int id, Worker& worker) {
        for (int i = 0; i < num_workers; i++) {
            if (worker.getId() == id) {
                worker = *workers[i];
            }
        }
    }

    // ����� ��� ������������ ������ ����������� �������
    void showWorkerInfo(Worker* worker) {
        cout << "���������� � ���������:\n";
        worker->displayInfo(); // ����� ����������� �������
    }

    int getnum_workers() {
        return num_workers;
    }
};