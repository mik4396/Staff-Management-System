#include "boss.h"

boss::boss(int id, string name, int did) {
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}

//显示信息
void boss::displayif() {
	cout << "员工编号：" << this->w_id
		 << "\t员工姓名：" << this->w_name
	 	 << "\t员工岗位：" << this->displayname()
		 << "\t员工职责：管理整个公司 "
		 << endl;

 }

//返回姓名
string boss::displayname() {
	return string("老板");
}