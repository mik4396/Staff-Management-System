#pragma once
#include <iostream>
#include <string>
using namespace std;


class Worker {
public:
	
	//��ʾ��Ϣ
	virtual void displayif() = 0;
	
	//��������
	virtual string displayname() = 0;
	
	// Ա�����
	int w_id;

	//Ա������
	string w_name;
	
	//��λ���
	int w_did;

};