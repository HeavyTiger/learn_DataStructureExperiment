#include"Student.h"
#include"LinkList.h"
int main() {
	LinkList<student> stu;
	int nSelection;
	do {
		cout << "欢迎使用学生信息管理系统！" << endl;
		cout << "1.显示学生信息" << endl;
		cout << "2.录入学生信息" << endl;
		cout << "3.查找学生信息" << endl;
		cout << "4.删除学生信息" << endl;
		cout << "5.更新学生信息" << endl;
		cout << "6.统计学生信息" << endl;
		cout << "7.排序学生信息" << endl;
		cout << "8.清空学生信息" << endl;
		cout << "0.按任意键退出" << endl;
		cout << "请输入执行的操作:";
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