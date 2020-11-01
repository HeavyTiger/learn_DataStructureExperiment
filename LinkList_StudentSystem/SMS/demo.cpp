#include"Student.h"
#include"LinkList.h"
int main() {
	LinkList<student> stu;
	int nSelection;
	do {
		cout << "��ӭʹ��ѧ����Ϣ����ϵͳ��" << endl;
		cout << "1.��ʾѧ����Ϣ" << endl;
		cout << "2.¼��ѧ����Ϣ" << endl;
		cout << "3.����ѧ����Ϣ" << endl;
		cout << "4.ɾ��ѧ����Ϣ" << endl;
		cout << "5.����ѧ����Ϣ" << endl;
		cout << "6.ͳ��ѧ����Ϣ" << endl;
		cout << "7.����ѧ����Ϣ" << endl;
		cout << "8.���ѧ����Ϣ" << endl;
		cout << "0.��������˳�" << endl;
		cout << "������ִ�еĲ���:";
		cin >> nSelection;
		cin.clear();
		cin.sync();
		system("cls");
		switch (nSelection) {
			case 1: {
				ShowData(stu);
				break;
			}
			case 2: {
				InsertData(stu);
				break;
			}
			case 3: {
				FindData(stu);
				break;
			}
			case 4: {
				DeleteData(stu);
				break;
			}
			case 5: {
				RefreshData(stu);
				break;
			}
			case 6: {
				StatisticData(stu);
				break;
			}
			case 7: {
				SortData(stu);
				break;
			}
			case 8: {
				ClearData(stu);
				break;
			}
			default: {
				nSelection = 0;
				break;
			}
		}
	} while (nSelection != 0);

	return 0;
}