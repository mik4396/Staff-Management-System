#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class Manager:public Worker {
public:
	//���캯��
	Manager(int id, string name, int did);

	//��ʾ��Ϣ
	void displayif();

	//��������
	string displayname();

};