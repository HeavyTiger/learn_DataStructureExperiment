#pragma once
#include "Node.h" 
//单链表类
template <class ElemType>
class LinkList {
protected:
	//单链表的数据成员
	Node<ElemType>* head; // 头结点指针
	int length; // 单链表长度
public:
	//单链表的函数成员
	LinkList();		//无参数的构造函数
	LinkList(ElemType v[], int n);		//有参数的构造函数
	virtual ~LinkList();	//析构函数
	int GetLength() const;		//求单链表长度
	void SetLength(int length);		//设置链表长度
	Node<ElemType>* GetHead();		//返回头节点指针变量
	bool IsEmpty() const;		//判断单链表是否为空
	int Locate(const ElemType& e) const;		//元素定位
	int Get(int index, ElemType& e);		//求指定位置的元素
	int Set(int index, const ElemType& e);		//设置指定位置的元素值
	int Delete(int index, ElemType& e);		//删除元素
	int Insert(int index, const ElemType& e);		//在制定位置插入元素
};

//[函数]		LinkList::LinkList
//[功能]		默认构造函数
//[参数]		void
//[返回]		void
template<class ElemType> LinkList<ElemType>::LinkList() :length(0), head(new Node<ElemType>) {
	head->next = nullptr;
}

//[函数]		LinkList::LinkList
//[功能]		默认构造函数
//[参数]		ElemType v[], int n(包含了数据个数以及插入的数据)
//[返回]		void
template<class ElemType> LinkList<ElemType>::LinkList(ElemType v[], int n) :length(0), head(new Node<ElemType>) {
	head->next = nullptr;
	for (int i = 0; i < n; i++) {
		if ((this->Insert(0, v[i])) == 0) exit(0);		//插入失败，报错0；
	}
}

//[函数]		LinkList::~LinkList
//[功能]		析构函数
//[参数]		void
//[返回]		void
template<class ElemType> LinkList<ElemType>::~LinkList() {
	if (head->next == nullptr) {
		delete head;
		return;
	}
	Node<ElemType>* temp1 = head, * temp2 = head->next;
	while (temp2 != nullptr) {
		delete temp1;		//删除前结点
		temp1 = temp2;
		temp2 = temp2->next;		//后结点向后移动到为空
	}
	delete temp1;		//将temp1删除
}

//[函数]		LinkList::SetLength
//[功能]		设置长度
//[参数]		int Length
//[返回]		void
template<class ElemType> void LinkList<ElemType>::SetLength(int length) {
	this->length = length;
}

//[函数]		LinkList::GetHead
//[功能]		//返回头节点指针变量
//[参数]		void
//[返回]		Node<ElemType>
template<class ElemType> Node<ElemType>* LinkList<ElemType>::GetHead() {
	return head;
}

//[函数]		LinkList::Insert
//[功能]		//在制定位置插入元素
//[参数]		int index:插入位置	const ElemType &e:插入数据
//[返回]		int TRUE表示成功 FALSE表示失败
template<class ElemType> int LinkList<ElemType>::Insert(int index, const ElemType& e) {
	Node<ElemType>* temp, * temp1, * tpr;		//temp指针用于移动位置，tpr用于申请空间
	tpr = nullptr;
	tpr = new Node<ElemType>;		//申请指向Node结点的指针
	if (tpr == nullptr) return 0;		//分配空间失败
	tpr->data = e;
	if (index >= length) {
		if (index > length) {
			cout << "欲插入位置索引数大于链表长度，将插入到表尾！" << endl;
			system("pause");
			system("cls");
		}
		temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = tpr;
		tpr->next = nullptr;
	}
	else if (index == 0||length == 0) {		//插入表头
		temp = head->next;
		tpr->next = temp;
		head->next = tpr;
	}
	else if (index < length && index > 0) {
		temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;		//将指向index的前一个结点
		}
		temp1 = temp->next;		//指向index的下一个节点
		temp->next = tpr;
		tpr->next = temp1;
	}
	length++;		//链表长度加1
	return 1;
}

//[函数]		LinkList::GetLength
//[功能]		求链表的长度
//[参数]		void
//[返回]		int 返回length长度
template<class ElemType> int LinkList<ElemType>::GetLength() const {
	return this->length;
}

//[函数]		LinkList::IsEmpty
//[功能]		判断单链表是否为空
//[参数]		void
//[返回]		bool TRUE空 FALSE非空
template<class ElemType> bool LinkList<ElemType>::IsEmpty() const {
	if (head->next == nullptr) return true;
	else return false;
}

//[函数]		LinkList::Locate
//[功能]		根据元素定位
//[参数]		const ElemType &e		元素值
//[返回]		int 返回定位位置，若为-1表示未找到数据
template<class ElemType> int LinkList<ElemType>::Locate(const ElemType& e) const {
	Node<ElemType>* temp = head;
	int num = 0;		//计数用于返回位置
	while (num < this->length) {
		temp = temp->next;
		num++;
		if (temp->data == e) return num;
	}
	return -1;	//未找到数据
}

//[函数]		LinkList::Get
//[功能]		求指定位置的元素
//[参数]		int index：指定位置, ElemType& e：返回元素
//[返回]		int 1表示找到，0表示未找到
template<class ElemType> int LinkList<ElemType>::Get(int index, ElemType& e) {
	if (index > length) return 0;		//未找到数据
	Node<ElemType>* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	e = temp->data;
	return 1;
}

//[函数]		LinkList::Set
//[功能]		设置指定位置的元素值
//[参数]		int index：指定位置, ElemType& e：设置元素
//[返回]		int 1表示成功设置，0表示未设置
template<class ElemType> int LinkList<ElemType>::Set(int index, const ElemType& e) {
	if (index > length || index <= 0) {
		cout << "查找位置失败！";
		system("pause");
		system("cls");
		return 0;		//未找到数据
	}
	Node<ElemType>* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	temp->data = e;
	return 1;
}

//[函数]		LinkList::Delete
//[功能]		删除指定元素
//[参数]		int index：指定位置, ElemType& e：返回元素
//[返回]		int 1表示成功，0表示失败
template<class ElemType> int LinkList<ElemType>::Delete(int index, ElemType& e) {
	if (length == 0 || index > length) {
		cout << "删除失败!链表为空或值溢出!";
		system("pause");
		system("cls");
		return 0;		//链表为空或溢出
	}
	Node<ElemType>* temp;
	temp = head;		//指向头节点
	for (int i = 0; i < index - 1; i++) {		//指向欲删除的元素的前继
		temp = temp->next;
	}
	temp->next = temp->next->next;
	this->length--;
	return 1;		//删除成功
}