#include "Manager.h"
Manager::Manager(int id,string name,int did) {
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}
//��ʾ��Ϣ
void Manager::displayif() {
	cout << "Ա����ţ�" << this->w_id
		 << "\tԱ��������" << this->w_name
		 << "\tԱ����λ��" << this->displayname()
		 << "\tԱ��ְ������ϰ彻�������񣬲��ɷ���Ա�� "
		 << endl;
}

//��������
 string Manager::displayname() {
	 return string("�ܹ�");
 }