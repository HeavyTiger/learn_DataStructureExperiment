#pragma once
#include"LinkList.h"
typedef struct student {
	int num;		//学号
	string name;		//姓名
	float grade;		//绩点
}student;

bool ShowData(LinkList<student>& stu);		//显示学生信息
bool InsertData(LinkList<student>& stu);			//录入学生信息
bool FindData(LinkList<student>& stu);		//根据位置或学号查找学生的各项信息
bool DeleteData(LinkList<student>& stu);		//删除指定位置的学生信息记录
bool RefreshData(LinkList<student>& stu);		//更新指定位置学生信息
bool StatisticData(LinkList<student>& stu);		//统计表中学生人数
bool SortData(LinkList<student>& stu);			//按照学号或者绩点进行排序
bool ClearData(LinkList<student>& stu);		//清空所有信息

bool ShowData(LinkList<student>& stu) {		//显示学生信息
	Node<student>* temp = stu.GetHead();
//	if (true == stu.IsEmpty()) return false;		//若链表为空返回false
	cout << "学生信息表格如下所示:" << endl;
	cout << "------------------------------------" << endl;
	cout <<std::left<< setw(15) << "学号" << setw(15) << "姓名" << setw(15) << "绩点" << endl;
	for (int i = 0; i < stu.GetLength(); i++) {
		temp = temp->next;
		cout << std::left << setw(15) << temp->data.num << setw(15) << temp->data.name << setw(15) <<fixed<< setprecision(3) << temp->data.grade<<  endl;
	}
	cout << "------------------------------------" << endl;
	cout << "学生信息共有" << stu.GetLength() << "人数据" << endl;
	system("pause");
	system("cls");
	return true;
}

bool InsertData(LinkList<student>& stu) {		//录入学生信息
	student temp_stu;		//临时存放数据;
	int num;
	cout << "请输入欲插入数据的位置(0-n):";
	cin >> num;
	cin.clear();
	cin.sync();
	cout << "请输入学生学号:";
	cin >> temp_stu.num;
	cin.clear();
	cin.sync();
	cout << "请输入学生姓名:";
	cin >> temp_stu.name;
	cin.clear();
	cin.sync();
	cout << "请输入学生绩点:";
	cin >> temp_stu.grade;
	cout << endl;
	cin.clear();
	cin.sync();
	system("cls");
	stu.Insert(num, temp_stu);
	return true;
}

bool FindData(LinkList<student>& stu) {		//根据位置或学号查找学生的各项信息
	int nSelection, nNumber, nIndex;
	Node<student>* temp = stu.GetHead();
step1:
	cout << "请选择使用学号(0)或位置(1)搜索学生全部信息:";
	cin >> nSelection;
	cin.clear();
	cin.sync();
	system("cls");
	switch (nSelection) {
	case 0: {
		cout << "请输入该学生学号:";
		cin >> nNumber;
		cin.clear();
		cin.sync();
		system("cls");
		for (int i = 0; i < stu.GetLength(); i++) {
			temp = temp->next;
			if (nNumber == temp->data.num) {
				cout << "该学生学号为:" << temp->data.num << "姓名为:" << temp->data.name << "绩点为:" << temp->data.grade << endl;
				system("pause");
				system("cls");
				return true;
			}
		}
		break;
	}
	case 1: {
		cout << "请输入该学生在链表中的位置:";
		cin >> nIndex;
		cin.clear();
		cin.sync();
		system("cls");
		if (nIndex > stu.GetLength())break;
		for (int i = 0; i < nIndex; i++) {
			temp = temp->next;
		}
		cout << "该学生学号为:" << temp->data.num << "姓名为:" << temp->data.name << "绩点为:" << temp->data.grade << endl;
		system("pause");
		system("cls");
		return true;
	}
	default: {
		cout << "无该选项，请重新输入！" << endl;
		system("pause");
		system("cls");
		goto step1;
	}
	}
	cout << "未找到该学生信息" << endl;
	system("pause");
	system("cls");
	return false;
}

bool DeleteData(LinkList<student>& stu) {		//删除指定位置的学生信息记录
	int num;
	student temp;
	cout << "请输入删除的指定位置(1-n):";
	cin >> num;
	cin.clear();
	cin.sync();
	system("cls");
	if (stu.Delete(num, temp)) return  true;
	else return false;
}

bool RefreshData(LinkList<student>& stu) {		//更新指定位置学生信息
	student temp_stu;		//临时存放数据;
	int num;
	cout << "请输入欲更新数据的位置(1-n):";
	cin >> num;
	cin.clear();
	cin.sync();
	cout << "请输入学生学号:";
	cin >> temp_stu.num;
	cin.clear();
	cin.sync();
	cout << "请输入学生姓名:";
	cin >> temp_stu.name;
	cin.clear();
	cin.sync();
	cout << "请输入学生绩点:";
	cin >> temp_stu.grade;
	cin.clear();
	cin.sync();
	system("cls");
	if (stu.Set(num, temp_stu)) return true;
	else return false;
}

bool StatisticData(LinkList<student>& stu) {		//统计表中学生人数
	cout << "学生人数总共有:" << stu.GetLength() << "人" << endl;
	system("pause");
	system("cls");
	return true;
}

bool SortData(LinkList<student>& stu) {			//按照学号或者绩点进行排序
	Node<student>* temp1, * temp2, * head;		//用于遍历stu,存取头节点
	head = stu.GetHead();
	int nSelection = 0;
	cout << "1.按成绩从高到低" << endl << "2.按成绩从低到高" << endl << "3.按学号从高到低" << endl << "4.按学号从低到高" << endl << "请输入排序方式:";
	cin >> nSelection;
	cin.clear();
	cin.sync();
	system("cls");
	if (head->next == nullptr || head->next->next == nullptr) return false;
	for (int i = 0; i < stu.GetLength() - 1; i++) {
		temp1 = head;
		temp2 = head->next;
		for (int j = 0; j < stu.GetLength() - i - 1; j++) {
			switch (nSelection) {
			case 1: {
				if (temp2->data.grade < temp2->next->data.grade) {		//冒泡排序，排序为成绩从大到小。
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//移动，指针变化temp2向后移动一位
					temp1 = temp1->next;
				}
				else {		//未移动，指针向后位移一位
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			case 2: {
				if (temp2->data.grade > temp2->next->data.grade) {		//冒泡排序，排序为成绩从小到大。
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//移动，指针变化temp2向后移动一位
					temp1 = temp1->next;
				}
				else {		//未移动，指针向后位移一位
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			case 3: {
				if (temp2->data.num < temp2->next->data.num) {		//冒泡排序，排序为序号从大到小。
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//移动，指针变化temp2向后移动一位
					temp1 = temp1->next;
				}
				else {		//未移动，指针向后位移一位
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			case 4: {
				if (temp2->data.num > temp2->next->data.num) {		//冒泡排序，排序为序号从小到大。
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//移动，指针变化temp2向后移动一位
					temp1 = temp1->next;
				}
				else {		//未移动，指针向后位移一位
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			default:return false;
			}
		}
	}
	return true;
}

bool ClearData(LinkList<student>& stu) {		//清空所有信息
	stu.GetHead()->next = nullptr;
	stu.SetLength(0);
	return true;
}