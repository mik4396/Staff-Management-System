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
	//构造函数
	WorkManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void Exit_System();

	//添加功能
	void Add_Staff();

	//保存文件
	void save();

	//获得记录人数
	int getstaffnum();

	//获得员工数据
	void getstaff();

	//显示员工
	void Show_Staff();

	//删除员工
	void Del_Staff();

	//判断员工是否存在并返回员工所在位置
	int staffexist(int id);

	//修改员工
	void Mod_Staff();

	//查找员工
	void Find_Staff();

	//排序员工
	void Sort_Staff();

	//清空数据
	void Clear_Data();
	
	//析构函数
	~WorkManager();

	//记录人数
	int m_staffnum;
	
	//员工数组的指针
	Worker **m_staffarray;

	//判断文件是否为空
	bool fileifemp;


};
