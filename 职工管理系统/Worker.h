#pragma once
#include <iostream>
#include <string>
using namespace std;


class Worker {
public:
	
	//显示信息
	virtual void displayif() = 0;
	
	//返回姓名
	virtual string displayname() = 0;
	
	// 员工编号
	int w_id;

	//员工名称
	string w_name;
	
	//岗位编号
	int w_did;

};