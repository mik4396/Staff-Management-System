#include "WorkManager.h"
using namespace std;
#include "Worker.h"
#include "Staff.h"
#include "boss.h"
#include "Manager.h"
#include <iostream>
//void test() {
//	Worker *w = NULL;
//	w = new Staff(1, "张三", 1);
//	w->displayif();
//	delete w;
//}


int main() {

	WorkManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.Exit_System();
			break;
		case 1: //增加职工
			wm.Add_Staff();
			break;
		case 2: //显示职工
			wm.Show_Staff();
			break;
		case 3: //删除职工
			//测试cout << wm.staffexist(1) << endl;
			wm.Del_Staff();
			break;
		case 4: //修改职工
			wm.Mod_Staff();
			break;
		case 5: //查找职工
			wm.Find_Staff();
			break;
		case 6: //排序职工
			wm.Sort_Staff();
			break;
		case 7: //清空文档
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