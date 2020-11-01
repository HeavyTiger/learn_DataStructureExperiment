#pragma once
#include"LinkList.h"
typedef struct student {
	int num;		//ѧ��
	string name;		//����
	float grade;		//����
}student;

bool ShowData(LinkList<student>& stu);		//��ʾѧ����Ϣ
bool InsertData(LinkList<student>& stu);			//¼��ѧ����Ϣ
bool FindData(LinkList<student>& stu);		//����λ�û�ѧ�Ų���ѧ���ĸ�����Ϣ
bool DeleteData(LinkList<student>& stu);		//ɾ��ָ��λ�õ�ѧ����Ϣ��¼
bool RefreshData(LinkList<student>& stu);		//����ָ��λ��ѧ����Ϣ
bool StatisticData(LinkList<student>& stu);		//ͳ�Ʊ���ѧ������
bool SortData(LinkList<student>& stu);			//����ѧ�Ż��߼����������
bool ClearData(LinkList<student>& stu);		//���������Ϣ

bool ShowData(LinkList<student>& stu) {		//��ʾѧ����Ϣ
	Node<student>* temp = stu.GetHead();
//	if (true == stu.IsEmpty()) return false;		//������Ϊ�շ���false
	cout << "ѧ����Ϣ���������ʾ:" << endl;
	cout << "------------------------------------" << endl;
	cout <<std::left<< setw(15) << "ѧ��" << setw(15) << "����" << setw(15) << "����" << endl;
	for (int i = 0; i < stu.GetLength(); i++) {
		temp = temp->next;
		cout << std::left << setw(15) << temp->data.num << setw(15) << temp->data.name << setw(15) <<fixed<< setprecision(3) << temp->data.grade<<  endl;
	}
	cout << "------------------------------------" << endl;
	cout << "ѧ����Ϣ����" << stu.GetLength() << "������" << endl;
	system("pause");
	system("cls");
	return true;
}

bool InsertData(LinkList<student>& stu) {		//¼��ѧ����Ϣ
	student temp_stu;		//��ʱ�������;
	int num;
	cout << "���������������ݵ�λ��(0-n):";
	cin >> num;
	cin.clear();
	cin.sync();
	cout << "������ѧ��ѧ��:";
	cin >> temp_stu.num;
	cin.clear();
	cin.sync();
	cout << "������ѧ������:";
	cin >> temp_stu.name;
	cin.clear();
	cin.sync();
	cout << "������ѧ������:";
	cin >> temp_stu.grade;
	cout << endl;
	cin.clear();
	cin.sync();
	system("cls");
	stu.Insert(num, temp_stu);
	return true;
}

bool FindData(LinkList<student>& stu) {		//����λ�û�ѧ�Ų���ѧ���ĸ�����Ϣ
	int nSelection, nNumber, nIndex;
	Node<student>* temp = stu.GetHead();
step1:
	cout << "��ѡ��ʹ��ѧ��(0)��λ��(1)����ѧ��ȫ����Ϣ:";
	cin >> nSelection;
	cin.clear();
	cin.sync();
	system("cls");
	switch (nSelection) {
	case 0: {
		cout << "�������ѧ��ѧ��:";
		cin >> nNumber;
		cin.clear();
		cin.sync();
		system("cls");
		for (int i = 0; i < stu.GetLength(); i++) {
			temp = temp->next;
			if (nNumber == temp->data.num) {
				cout << "��ѧ��ѧ��Ϊ:" << temp->data.num << "����Ϊ:" << temp->data.name << "����Ϊ:" << temp->data.grade << endl;
				system("pause");
				system("cls");
				return true;
			}
		}
		break;
	}
	case 1: {
		cout << "�������ѧ���������е�λ��:";
		cin >> nIndex;
		cin.clear();
		cin.sync();
		system("cls");
		if (nIndex > stu.GetLength())break;
		for (int i = 0; i < nIndex; i++) {
			temp = temp->next;
		}
		cout << "��ѧ��ѧ��Ϊ:" << temp->data.num << "����Ϊ:" << temp->data.name << "����Ϊ:" << temp->data.grade << endl;
		system("pause");
		system("cls");
		return true;
	}
	default: {
		cout << "�޸�ѡ����������룡" << endl;
		system("pause");
		system("cls");
		goto step1;
	}
	}
	cout << "δ�ҵ���ѧ����Ϣ" << endl;
	system("pause");
	system("cls");
	return false;
}

bool DeleteData(LinkList<student>& stu) {		//ɾ��ָ��λ�õ�ѧ����Ϣ��¼
	int num;
	student temp;
	cout << "������ɾ����ָ��λ��(1-n):";
	cin >> num;
	cin.clear();
	cin.sync();
	system("cls");
	if (stu.Delete(num, temp)) return  true;
	else return false;
}

bool RefreshData(LinkList<student>& stu) {		//����ָ��λ��ѧ����Ϣ
	student temp_stu;		//��ʱ�������;
	int num;
	cout << "���������������ݵ�λ��(1-n):";
	cin >> num;
	cin.clear();
	cin.sync();
	cout << "������ѧ��ѧ��:";
	cin >> temp_stu.num;
	cin.clear();
	cin.sync();
	cout << "������ѧ������:";
	cin >> temp_stu.name;
	cin.clear();
	cin.sync();
	cout << "������ѧ������:";
	cin >> temp_stu.grade;
	cin.clear();
	cin.sync();
	system("cls");
	if (stu.Set(num, temp_stu)) return true;
	else return false;
}

bool StatisticData(LinkList<student>& stu) {		//ͳ�Ʊ���ѧ������
	cout << "ѧ�������ܹ���:" << stu.GetLength() << "��" << endl;
	system("pause");
	system("cls");
	return true;
}

bool SortData(LinkList<student>& stu) {			//����ѧ�Ż��߼����������
	Node<student>* temp1, * temp2, * head;		//���ڱ���stu,��ȡͷ�ڵ�
	head = stu.GetHead();
	int nSelection = 0;
	cout << "1.���ɼ��Ӹߵ���" << endl << "2.���ɼ��ӵ͵���" << endl << "3.��ѧ�ŴӸߵ���" << endl << "4.��ѧ�Ŵӵ͵���" << endl << "����������ʽ:";
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
				if (temp2->data.grade < temp2->next->data.grade) {		//ð����������Ϊ�ɼ��Ӵ�С��
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//�ƶ���ָ��仯temp2����ƶ�һλ
					temp1 = temp1->next;
				}
				else {		//δ�ƶ���ָ�����λ��һλ
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			case 2: {
				if (temp2->data.grade > temp2->next->data.grade) {		//ð����������Ϊ�ɼ���С����
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//�ƶ���ָ��仯temp2����ƶ�һλ
					temp1 = temp1->next;
				}
				else {		//δ�ƶ���ָ�����λ��һλ
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			case 3: {
				if (temp2->data.num < temp2->next->data.num) {		//ð����������Ϊ��ŴӴ�С��
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//�ƶ���ָ��仯temp2����ƶ�һλ
					temp1 = temp1->next;
				}
				else {		//δ�ƶ���ָ�����λ��һλ
					temp1 = temp2;
					temp2 = temp2->next;
				}
				break;
			}
			case 4: {
				if (temp2->data.num > temp2->next->data.num) {		//ð����������Ϊ��Ŵ�С����
					temp1->next = temp2->next;
					temp2->next = temp2->next->next;
					temp1->next->next = temp2;
					//�ƶ���ָ��仯temp2����ƶ�һλ
					temp1 = temp1->next;
				}
				else {		//δ�ƶ���ָ�����λ��һλ
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

bool ClearData(LinkList<student>& stu) {		//���������Ϣ
	stu.GetHead()->next = nullptr;
	stu.SetLength(0);
	return true;
}