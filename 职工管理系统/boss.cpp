#include "boss.h"

boss::boss(int id, string name, int did) {
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}

//��ʾ��Ϣ
void boss::displayif() {
	cout << "Ա����ţ�" << this->w_id
		 << "\tԱ��������" << this->w_name
	 	 << "\tԱ����λ��" << this->displayname()
		 << "\tԱ��ְ�𣺹���������˾ "
		 << endl;

 }

//��������
string boss::displayname() {
	return string("�ϰ�");
}