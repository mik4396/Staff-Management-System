#include "WorkManager.h"
WorkManager::WorkManager() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	//1.文件不存在
	if (!ifs.is_open()) {

	/*	cout << "文件不存在" << endl;*/
		//初始化人数
		this->m_staffnum = 0;
		//初始化数组
		this->m_staffarray = NULL;
		//判断为空文件
		this->fileifemp = true;
		ifs.close();
		return;

	}

	//2.文件存在但数据为空
	char cr;
	ifs >> cr;
	if (ifs.eof()) {

		/*cout << "文件为空" << endl;*/
		//初始化人数
		this->m_staffnum = 0;
		//初始化数组
		this->m_staffarray = NULL;
		//判断为空文件
		this->fileifemp = true;
		ifs.close();
		return;

	}
	//3.文件存在 记录数据
	//记录人数
	int num = this->getstaffnum();
	//cout << "当前记录人数为" << num << endl;//测试
	//人数初始化
	this->m_staffnum = num;
	//数组初始化
	this->m_staffarray = new Worker *[this->m_staffnum];

	this->getstaff();
	
	this->fileifemp = false;
	//for (int i = 0; i < this->m_numperp; i++) {//测试
	//	cout << this->m_numarray[i]->w_id << " "
	//		<< this->m_numarray[i]->w_name << " "
	//		<< this->m_numarray[i]->w_did << endl;
	//}
	
}
//主菜单
void WorkManager:: Show_Menu() {
	cout << "************************************" << endl;
	cout << "******  欢迎使用职工管理系统  ******" << endl;
	cout << "********  0.退出管理系统  **********" << endl;
	cout << "********  1.增加职工信息  **********" << endl;
	cout << "********  2.显示职工信息  **********" << endl;
	cout << "********  3.删除离职职工  **********" << endl;
	cout << "********  4.修改职工信息  **********" << endl;
	cout << "********  5.查找职工信息  **********" << endl;
	cout << "********  6.按照编号排序  **********" << endl;
	cout << "********  7.清空所有文档  **********" << endl;
	cout << "************************************" << endl;
	cout << endl;

}

//退出系统
void WorkManager::Exit_System() {
	cout << "期待您的下次使用" << endl;
	system("pause");
	exit(0);
}

//添加系统
void WorkManager::Add_Staff() {
	cout << "请输入添加职工的人数个数" << endl;
	int addnum = 0; //记录输入的人数

	cin >> addnum;

	if (addnum > 0) {

		//计算空间大小
		int newsize = this->m_staffnum + addnum;

		//开辟新空间
		Worker **newspace = new Worker*[newsize];

		//将原有的内容放入新空间
		if (this->m_staffarray != NULL) {

			for (int i = 0; i < this->m_staffnum; i++) {
				newspace[i] = this->m_staffarray[i];
			}
		}

		//输入新数据
		for (int j = 0; j < addnum; j++) {
			int id;
			string name;
			int did;

			cout << "请输入第" << j +1<< "个员工的编号" << endl;
			cin >> id;
			for (int i = 0; i < this->m_staffnum; i++) {//禁止重复编号的出现
				if (this->m_staffarray[i]->w_id == id) {
					cout << "已存在编号为:" << id << "的员工，请重新输入" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
			cout << "请输入第" << j +1<< "个员工的姓名" << endl;
			cin >> name;
			cout << "请输入第" << j +1<< "个员工的岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.总管" << endl;
			cout << "3.老板" << endl;
			cin >> did;

			Worker *worker = NULL;

			switch (did)
			{
			case 1://普通员工
				worker = new Staff(id, name, 1);
				break;
			case 2://总管
				worker = new Manager(id, name, 2);
				break;
			case 3://老板
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "输入的数字有误，请重新输入" << endl;
				system("pause");
				system("cls");
				return;
				
			}

			newspace[this->m_staffnum + j] = worker;
		}
		//释放原有的数组空间
		delete[]this->m_staffarray;

		//更改指针指向
		this->m_staffarray = newspace;

		//更新人数个数
		this->m_staffnum = newsize;

		//提示添加成功信息
		cout << "成功添加" << addnum << "名员工！" << endl;

		//更新职工文件不为空
		this->fileifemp = false;

		//将数据写入文件中
		this->save();

	}

	else {
		cout << "输入的数量有误" << endl;
	}

	system("pause");
	system("cls");

}

//保存文件
void WorkManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_staffnum; i++) {
		ofs << this->m_staffarray[i]->w_id   << " "
			<< this->m_staffarray[i]->w_name << " "
			<< this->m_staffarray[i]->w_did  << " "
			<< endl;
	}
	ofs.close();
}

//获取记录人数
int WorkManager::getstaffnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num = 0;
	
	int id;
	string name;
	int did;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	return num;
}

//获取记录数据
void WorkManager::getstaff() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int index = 0;

	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker *worker = NULL;
		if (did = 1) { //员工
			worker = new Staff(id, name, did);
		}
		else if (did = 2) {//总管
			worker = new Manager(id, name, did);
		}
		else {
			worker = new boss(id, name, did);
		}
		this->m_staffarray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示员工
void WorkManager::Show_Staff() {
	if (this->fileifemp) {
		cout << "文件为空或未记录员工" << endl;
	}
	else {
		for (int i = 0; i < this->m_staffnum; i++) {
			this->m_staffarray[i]->displayif();
		}
	}
	system("pause");
	system("cls");
}

//删除员工
void WorkManager::Del_Staff() {
	if (this->fileifemp) {
		//文件为空
		cout << "文件为空或未记录员工" << endl;
	}
	else
	{
		cout << "请输入您想删除的员工编号" << endl;
		int delid=0;
		cin >> delid;
		int id = this->staffexist(delid);
		if (id == -1) {
			//输入错误的编号
			cout << "删除失败，未找到编号"<<delid<<"的员工,请重新输入" << endl;
		}
		else {
			cout << "您确定要删除编号为：" << delid << "的员工吗，输入\"delete\"继续" << endl;
			string index;
			cin >> index;

			if (index == "delete") {
				for (int i = id; i < this->m_staffnum - 1; i++) {
					//数据前移
					this->m_staffarray[i] = this->m_staffarray[i + 1];
				}
				//更新人数
				this->m_staffnum--;
				//数据同步到文件中
				this->save();
				cout << "删除成功" << endl;
			}

		}
	} 
	system("pause");
	system("cls");
	
}

//判断员工是否存在并返回员工所在位置
int WorkManager::staffexist(int id) {
	int index = -1;

	for (int i = 0; i <this->m_staffnum; i++)
	{
		if (this->m_staffarray[i]->w_id == id) {
			index = i;
			break;
		}
	}

	return index;
}

//修改员工
void WorkManager::Mod_Staff() {
	if (this->fileifemp) {
		cout << "文件为空或未记录员工" << endl;
	}
	else {
		cout << "请输入您想修改的员工编号" << endl;
		int modid;
		cin >> modid;
		int id = this->staffexist(modid);
		if (id == -1) {
			cout << "修改失败，未找到编号" << modid << "的员工,请重新输入" << endl;
		}
		else {
			delete this->m_staffarray[id];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "成功查找到" << modid << "号员工，请重新输入员工编号" << endl;
			cin >> newid;
			cout << "请重新输入该员工姓名" << endl;
			cin >> newname;
			cout << "请重新输入该员工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.总管" << endl;
			cout << "3.老板" << endl;
			cin >> newdid;

			Worker *worker = NULL;

			switch (newdid)
			{
			case 1://普通员工
				worker = new Staff(newid, newname, 1);
				break;
			case 2://总管
				worker = new Manager(newid, newname, 2);
				break;
			case 3://老板
				worker = new boss(newid, newname, 3);
				break;
			default:
				cout << "输入的数字有误，请重新输入" << endl;
				system("pause");
				system("cls");
				return;

			}
			//更新数据到数组中
			this->m_staffarray[id] = worker;

			cout << "修改成功" << endl;
			//更新数据到文件中
			this->save();


		}
	}
	system("pause");
	system("cls");
}

//查找员工
void WorkManager::Find_Staff() {
	if (this->fileifemp) {
		cout << "文件为空或未记录员工" << endl;
	}
	else {
		cout << "请输入您想查找的方式" << endl;
		cout << "1、按员工编号查找" << endl;
		cout << "2、按员工姓名查找" << endl;
		int index = 0;
		cin >> index;
		if (index == 1) {
			//按照编号查找
			cout << "请输入您想查找的员工编号" << endl;
			int id = 0;
			cin >> id;
			int ret = this->staffexist(id);
			if (ret == -1) {
				cout << "查找失败，未找到编号" << id << "的员工,请重新输入" << endl;
			}
			else {
				cout << "查找成功,员工信息如下" << endl;

				this->m_staffarray[ret]->displayif();
			}
		}
		else if (index == 2) {
			//按照姓名查找
			cout << "请输入您想查找的员工姓名" << endl;
			string name;
			cin >> name;
			bool exist = false;
			for (int i = 0; i < this->m_staffnum; i++) {
				if (this->m_staffarray[i]->w_name == name) {
					cout << "查找成功,员工信息如下" << endl;

					this->m_staffarray[i]->displayif();

					exist = true;
				}
			
			}
			if (exist == false) {
				cout << "查找失败，未找到姓名为" << name << "的员工,请重新输入" << endl;
			}
		}
		else {
			//输入数字有误
			cout << "输入的数字有误，请重新输入" << endl;
		}

	}
	system("pause");
	system("cls");
}

//排序员工
void WorkManager::Sort_Staff() {
	if (this->fileifemp) {
		cout << "文件为空或未记录员工" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序的方式" << endl;
		cout << "1.编号从低到高" << endl;
		cout << "2.编号从高到底" << endl;
		int index = 0;
		cin >> index;
		for (int i = 0; i < this->m_staffnum; i++) {
			int minormax = i;
			for (int j = i + 1; j < this->m_staffnum; j++)
			{
				if (index == 1) {
					//从低到高排
					if (this->m_staffarray[minormax]->w_id > this->m_staffarray[j]->w_id) {
						minormax = j;
					}
				}
				else if (index == 2) {
					//从高到底排
					if (this->m_staffarray[minormax]->w_id < this->m_staffarray[j]->w_id) {
						minormax = j;
					}
				}
				//判定一开始认定 最小值或最大值 是不是 计算的最小值或最大值 ，如果不是 交换数据
				if (i != minormax) {
					Worker *temp = this->m_staffarray[i];
					this->m_staffarray[i] = this->m_staffarray[minormax];
					this->m_staffarray[minormax] = temp;
				}
			}
		}
		cout << "排序成功，排序结果如下" << endl;
		//数据保存至文件中
		this->save();
		this->Show_Staff();
	}
}
//清空数据
void WorkManager::Clear_Data() {
	cout << "您确定要清空所有员工信息吗？输入\"delete\"继续" << endl;
	string flag=" ";
	cin >> flag;
	if (flag == "delete") {
		//打开模式ios::trunc 如果存在文件则删除并重新创建空文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_staffarray != NULL) {
			for (int i = 0; i < this->m_staffnum; i++) {
				if (this->m_staffarray[i] != NULL) {
					delete this->m_staffarray[i];
				}
			}
			this->m_staffnum = 0;
			this->fileifemp = true;
			delete[]this->m_staffarray;
			this->m_staffarray = NULL;
		}
		cout << "清空成功" << endl;

	}
	system("pause");
	system("cls");
}
WorkManager::~WorkManager() {
	//结束时释放空间
	if (this->m_staffarray!=NULL) {
		delete []this->m_staffarray;
		this->m_staffarray = NULL;
	}
}