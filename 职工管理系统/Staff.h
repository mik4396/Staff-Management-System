#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class Staff :public Worker {
public:
	//���캯��
	Staff(int id,string name,int did);

	//��ʾ��Ϣ
	void displayif();

	//���ظ�λ
	string displayname();

	

};