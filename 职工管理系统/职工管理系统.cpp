#include "WorkManager.h"
using namespace std;
#include "Worker.h"
#include "Staff.h"
#include "boss.h"
#include "Manager.h"
#include <iostream>
//void test() {
//	Worker *w = NULL;
//	w = new Staff(1, "����", 1);
//	w->displayif();
//	delete w;
//}


int main() {

	WorkManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.Exit_System();
			break;
		case 1: //����ְ��
			wm.Add_Staff();
			break;
		case 2: //��ʾְ��
			wm.Show_Staff();
			break;
		case 3: //ɾ��ְ��
			//����cout << wm.staffexist(1) << endl;
			wm.Del_Staff();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Staff();
			break;
		case 5: //����ְ��
			wm.Find_Staff();
			break;
		case 6: //����ְ��
			wm.Sort_Staff();
			break;
		case 7: //����ĵ�
			wm.Clear_Data();
			break;

		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}