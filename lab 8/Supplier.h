#pragma once
using namespace std;

//����� ��� �������� ������ � ����������
class Supplier {
private:
    string name;
    string phone;
    string address;
public:
    Supplier();
    Supplier(string name, string phone, string address); //����������� � �����������
    void get(string& name, string& phone, string& address); //��������� ������ ������
    void set(string name, string phone, string address); //��������� �������� ����������-������ ������
    // ���������� ��������� ������
    friend ostream& operator << (ostream& os, Supplier& s);
};



