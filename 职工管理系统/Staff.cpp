#include "Staff.h"
#include "Worker.h"
//

Staff::Staff(int id, string name, int did) {
	this->w_id = id;
	this->w_name = name;
	this->w_did = did;
}

//��ʾ��Ϣ
void Staff::displayif() {
	cout<< "Ա����ţ� " << this->w_id
		<< "\tԱ�������� " << this->w_name
		<< "\tԱ����λ�� " << this->displayname()
		<< "\tԱ��ְ������ܹܽ��������� " 
		<< endl;
}

//��������
string Staff::displayname() {
	return string("��ͨԱ��");
}
