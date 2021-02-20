#include "Manager.h"
Manager::Manager(int id,string name,int did) {
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}
//显示信息
void Manager::displayif() {
	cout << "员工编号：" << this->w_id
		 << "\t员工姓名：" << this->w_name
		 << "\t员工岗位：" << this->displayname()
		 << "\t员工职责：完成老板交给的任务，并派发给员工 "
		 << endl;
}

//返回姓名
 string Manager::displayname() {
	 return string("总管");
 }