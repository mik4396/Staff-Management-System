#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class boss :public Worker{
public:
	//���캯��
	boss(int id,string name ,int did);

	//��ʾ��Ϣ
	void displayif() ;

	//���ظ�λ
	string displayname() ;
};