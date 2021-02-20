#include "Staff.h"
#include "Worker.h"
//

Staff::Staff(int id, string name, int did) {
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}

//显示信息
void Staff::displayif() {
	cout<< "员工编号： " << this->w_id
		<< "\t员工姓名： " << this->w_name
		<< "\t员工岗位： " << this->displayname()
		<< "\t员工职责：完成总管交给的任务 " 
		<< endl;
}

//返回姓名
string Staff::displayname() {
	return string("普通员工");
}
