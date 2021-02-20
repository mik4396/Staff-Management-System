#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Worker.h"

class boss :public Worker{
public:
	//构造函数
	boss(int id,string name ,int did);

	//显示信息
	void displayif() ;

	//返回岗位
	string displayname() ;
};