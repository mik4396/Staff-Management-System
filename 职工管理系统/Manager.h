#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class Manager:public Worker {
public:
	//构造函数
	Manager(int id, string name, int did);

	//显示信息
	void displayif();

	//返回姓名
	string displayname();

};