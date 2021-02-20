#include "WorkManager.h"
WorkManager::WorkManager() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//1.�ļ�������
	if (!ifs.is_open()) {

	/*	cout << "�ļ�������" << endl;*/
		//��ʼ������
		this->m_staffnum = 0;
		//��ʼ������
		this->m_staffarray = NULL;
		//�ж�Ϊ���ļ�
		this->fileifemp = true;
		ifs.close();
		return;

	}

	//2.�ļ����ڵ�����Ϊ��
	char cr;
	ifs >> cr;
	if (ifs.eof()) {

		/*cout << "�ļ�Ϊ��" << endl;*/
		//��ʼ������
		this->m_staffnum = 0;
		//��ʼ������
		this->m_staffarray = NULL;
		//�ж�Ϊ���ļ�
		this->fileifemp = true;
		ifs.close();
		return;

	}
	//3.�ļ����� ��¼����
	//��¼����
	int num = this->getstaffnum();
	//cout << "��ǰ��¼����Ϊ" << num << endl;//����
	//������ʼ��
	this->m_staffnum = num;
	//�����ʼ��
	this->m_staffarray = new Worker *[this->m_staffnum];

	this->getstaff();
	
	this->fileifemp = false;
	//for (int i = 0; i < this->m_numperp; i++) {//����
	//	cout << this->m_numarray[i]->w_id << " "
	//		<< this->m_numarray[i]->w_name << " "
	//		<< this->m_numarray[i]->w_did << endl;
	//}
	
}
//���˵�
void WorkManager:: Show_Menu() {
	cout << "************************************" << endl;
	cout << "******  ��ӭʹ��ְ������ϵͳ  ******" << endl;
	cout << "********  0.�˳�����ϵͳ  **********" << endl;
	cout << "********  1.����ְ����Ϣ  **********" << endl;
	cout << "********  2.��ʾְ����Ϣ  **********" << endl;
	cout << "********  3.ɾ����ְְ��  **********" << endl;
	cout << "********  4.�޸�ְ����Ϣ  **********" << endl;
	cout << "********  5.����ְ����Ϣ  **********" << endl;
	cout << "********  6.���ձ������  **********" << endl;
	cout << "********  7.��������ĵ�  **********" << endl;
	cout << "************************************" << endl;
	cout << endl;

}

//�˳�ϵͳ
void WorkManager::Exit_System() {
	cout << "�ڴ������´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ϵͳ
void WorkManager::Add_Staff() {
	cout << "���������ְ������������" << endl;
	int addnum = 0; //��¼���������

	cin >> addnum;

	if (addnum > 0) {

		//����ռ��С
		int newsize = this->m_staffnum + addnum;

		//�����¿ռ�
		Worker **newspace = new Worker*[newsize];

		//��ԭ�е����ݷ����¿ռ�
		if (this->m_staffarray != NULL) {

			for (int i = 0; i < this->m_staffnum; i++) {
				newspace[i] = this->m_staffarray[i];
			}
		}

		//����������
		for (int j = 0; j < addnum; j++) {
			int id;
			string name;
			int did;

			cout << "�������" << j +1<< "��Ա���ı��" << endl;
			cin >> id;
			for (int i = 0; i < this->m_staffnum; i++) {//��ֹ�ظ���ŵĳ���
				if (this->m_staffarray[i]->w_id == id) {
					cout << "�Ѵ��ڱ��Ϊ:" << id << "��Ա��������������" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
			cout << "�������" << j +1<< "��Ա��������" << endl;
			cin >> name;
			cout << "�������" << j +1<< "��Ա���ĸ�λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.�ܹ�" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> did;

			Worker *worker = NULL;

			switch (did)
			{
			case 1://��ͨԱ��
				worker = new Staff(id, name, 1);
				break;
			case 2://�ܹ�
				worker = new Manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "�����������������������" << endl;
				system("pause");
				system("cls");
				return;
				
			}

			newspace[this->m_staffnum + j] = worker;
		}
		//�ͷ�ԭ�е�����ռ�
		delete[]this->m_staffarray;

		//����ָ��ָ��
		this->m_staffarray = newspace;

		//������������
		this->m_staffnum = newsize;

		//��ʾ��ӳɹ���Ϣ
		cout << "�ɹ����" << addnum << "��Ա����" << endl;

		//����ְ���ļ���Ϊ��
		this->fileifemp = false;

		//������д���ļ���
		this->save();

	}

	else {
		cout << "�������������" << endl;
	}

	system("pause");
	system("cls");

}

//�����ļ�
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

//��ȡ��¼����
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

//��ȡ��¼����
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
		if (did = 1) { //Ա��
			worker = new Staff(id, name, did);
		}
		else if (did = 2) {//�ܹ�
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

//��ʾԱ��
void WorkManager::Show_Staff() {
	if (this->fileifemp) {
		cout << "�ļ�Ϊ�ջ�δ��¼Ա��" << endl;
	}
	else {
		for (int i = 0; i < this->m_staffnum; i++) {
			this->m_staffarray[i]->displayif();
		}
	}
	system("pause");
	system("cls");
}

//ɾ��Ա��
void WorkManager::Del_Staff() {
	if (this->fileifemp) {
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�ջ�δ��¼Ա��" << endl;
	}
	else
	{
		cout << "����������ɾ����Ա�����" << endl;
		int delid=0;
		cin >> delid;
		int id = this->staffexist(delid);
		if (id == -1) {
			//�������ı��
			cout << "ɾ��ʧ�ܣ�δ�ҵ����"<<delid<<"��Ա��,����������" << endl;
		}
		else {
			cout << "��ȷ��Ҫɾ�����Ϊ��" << delid << "��Ա��������\"delete\"����" << endl;
			string index;
			cin >> index;

			if (index == "delete") {
				for (int i = id; i < this->m_staffnum - 1; i++) {
					//����ǰ��
					this->m_staffarray[i] = this->m_staffarray[i + 1];
				}
				//��������
				this->m_staffnum--;
				//����ͬ�����ļ���
				this->save();
				cout << "ɾ���ɹ�" << endl;
			}

		}
	} 
	system("pause");
	system("cls");
	
}

//�ж�Ա���Ƿ���ڲ�����Ա������λ��
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

//�޸�Ա��
void WorkManager::Mod_Staff() {
	if (this->fileifemp) {
		cout << "�ļ�Ϊ�ջ�δ��¼Ա��" << endl;
	}
	else {
		cout << "�����������޸ĵ�Ա�����" << endl;
		int modid;
		cin >> modid;
		int id = this->staffexist(modid);
		if (id == -1) {
			cout << "�޸�ʧ�ܣ�δ�ҵ����" << modid << "��Ա��,����������" << endl;
		}
		else {
			delete this->m_staffarray[id];
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "�ɹ����ҵ�" << modid << "��Ա��������������Ա�����" << endl;
			cin >> newid;
			cout << "�����������Ա������" << endl;
			cin >> newname;
			cout << "�����������Ա����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.�ܹ�" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> newdid;

			Worker *worker = NULL;

			switch (newdid)
			{
			case 1://��ͨԱ��
				worker = new Staff(newid, newname, 1);
				break;
			case 2://�ܹ�
				worker = new Manager(newid, newname, 2);
				break;
			case 3://�ϰ�
				worker = new boss(newid, newname, 3);
				break;
			default:
				cout << "�����������������������" << endl;
				system("pause");
				system("cls");
				return;

			}
			//�������ݵ�������
			this->m_staffarray[id] = worker;

			cout << "�޸ĳɹ�" << endl;
			//�������ݵ��ļ���
			this->save();


		}
	}
	system("pause");
	system("cls");
}

//����Ա��
void WorkManager::Find_Staff() {
	if (this->fileifemp) {
		cout << "�ļ�Ϊ�ջ�δ��¼Ա��" << endl;
	}
	else {
		cout << "������������ҵķ�ʽ" << endl;
		cout << "1����Ա����Ų���" << endl;
		cout << "2����Ա����������" << endl;
		int index = 0;
		cin >> index;
		if (index == 1) {
			//���ձ�Ų���
			cout << "������������ҵ�Ա�����" << endl;
			int id = 0;
			cin >> id;
			int ret = this->staffexist(id);
			if (ret == -1) {
				cout << "����ʧ�ܣ�δ�ҵ����" << id << "��Ա��,����������" << endl;
			}
			else {
				cout << "���ҳɹ�,Ա����Ϣ����" << endl;

				this->m_staffarray[ret]->displayif();
			}
		}
		else if (index == 2) {
			//������������
			cout << "������������ҵ�Ա������" << endl;
			string name;
			cin >> name;
			bool exist = false;
			for (int i = 0; i < this->m_staffnum; i++) {
				if (this->m_staffarray[i]->w_name == name) {
					cout << "���ҳɹ�,Ա����Ϣ����" << endl;

					this->m_staffarray[i]->displayif();

					exist = true;
				}
			
			}
			if (exist == false) {
				cout << "����ʧ�ܣ�δ�ҵ�����Ϊ" << name << "��Ա��,����������" << endl;
			}
		}
		else {
			//������������
			cout << "�����������������������" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����Ա��
void WorkManager::Sort_Staff() {
	if (this->fileifemp) {
		cout << "�ļ�Ϊ�ջ�δ��¼Ա��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ķ�ʽ" << endl;
		cout << "1.��Ŵӵ͵���" << endl;
		cout << "2.��ŴӸߵ���" << endl;
		int index = 0;
		cin >> index;
		for (int i = 0; i < this->m_staffnum; i++) {
			int minormax = i;
			for (int j = i + 1; j < this->m_staffnum; j++)
			{
				if (index == 1) {
					//�ӵ͵�����
					if (this->m_staffarray[minormax]->w_id > this->m_staffarray[j]->w_id) {
						minormax = j;
					}
				}
				else if (index == 2) {
					//�Ӹߵ�����
					if (this->m_staffarray[minormax]->w_id < this->m_staffarray[j]->w_id) {
						minormax = j;
					}
				}
				//�ж�һ��ʼ�϶� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ ��������� ��������
				if (i != minormax) {
					Worker *temp = this->m_staffarray[i];
					this->m_staffarray[i] = this->m_staffarray[minormax];
					this->m_staffarray[minormax] = temp;
				}
			}
		}
		cout << "����ɹ�������������" << endl;
		//���ݱ������ļ���
		this->save();
		this->Show_Staff();
	}
}
//�������
void WorkManager::Clear_Data() {
	cout << "��ȷ��Ҫ�������Ա����Ϣ������\"delete\"����" << endl;
	string flag=" ";
	cin >> flag;
	if (flag == "delete") {
		//��ģʽios::trunc ��������ļ���ɾ�������´������ļ�
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
		cout << "��ճɹ�" << endl;

	}
	system("pause");
	system("cls");
}
WorkManager::~WorkManager() {
	//����ʱ�ͷſռ�
	if (this->m_staffarray!=NULL) {
		delete []this->m_staffarray;
		this->m_staffarray = NULL;
	}
}