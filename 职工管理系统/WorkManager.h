#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "boss.h"
#include "Staff.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "StaffFile.txt"

class WorkManager {
public:
	//���캯��
	WorkManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void Exit_System();

	//��ӹ���
	void Add_Staff();

	//�����ļ�
	void save();

	//��ü�¼����
	int getstaffnum();

	//���Ա������
	void getstaff();

	//��ʾԱ��
	void Show_Staff();

	//ɾ��Ա��
	void Del_Staff();

	//�ж�Ա���Ƿ���ڲ�����Ա������λ��
	int staffexist(int id);

	//�޸�Ա��
	void Mod_Staff();

	//����Ա��
	void Find_Staff();

	//����Ա��
	void Sort_Staff();

	//�������
	void Clear_Data();
	
	//��������
	~WorkManager();

	//��¼����
	int m_staffnum;
	
	//Ա�������ָ��
	Worker **m_staffarray;

	//�ж��ļ��Ƿ�Ϊ��
	bool fileifemp;


};
