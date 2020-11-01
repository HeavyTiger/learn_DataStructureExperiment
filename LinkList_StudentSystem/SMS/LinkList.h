#pragma once
#include "Node.h" 
//��������
template <class ElemType>
class LinkList {
protected:
	//����������ݳ�Ա
	Node<ElemType>* head; // ͷ���ָ��
	int length; // ��������
public:
	//������ĺ�����Ա
	LinkList();		//�޲����Ĺ��캯��
	LinkList(ElemType v[], int n);		//�в����Ĺ��캯��
	virtual ~LinkList();	//��������
	int GetLength() const;		//��������
	void SetLength(int length);		//����������
	Node<ElemType>* GetHead();		//����ͷ�ڵ�ָ�����
	bool IsEmpty() const;		//�жϵ������Ƿ�Ϊ��
	int Locate(const ElemType& e) const;		//Ԫ�ض�λ
	int Get(int index, ElemType& e);		//��ָ��λ�õ�Ԫ��
	int Set(int index, const ElemType& e);		//����ָ��λ�õ�Ԫ��ֵ
	int Delete(int index, ElemType& e);		//ɾ��Ԫ��
	int Insert(int index, const ElemType& e);		//���ƶ�λ�ò���Ԫ��
};

//[����]		LinkList::LinkList
//[����]		Ĭ�Ϲ��캯��
//[����]		void
//[����]		void
template<class ElemType> LinkList<ElemType>::LinkList() :length(0), head(new Node<ElemType>) {
	head->next = nullptr;
}

//[����]		LinkList::LinkList
//[����]		Ĭ�Ϲ��캯��
//[����]		ElemType v[], int n(���������ݸ����Լ����������)
//[����]		void
template<class ElemType> LinkList<ElemType>::LinkList(ElemType v[], int n) :length(0), head(new Node<ElemType>) {
	head->next = nullptr;
	for (int i = 0; i < n; i++) {
		if ((this->Insert(0, v[i])) == 0) exit(0);		//����ʧ�ܣ�����0��
	}
}

//[����]		LinkList::~LinkList
//[����]		��������
//[����]		void
//[����]		void
template<class ElemType> LinkList<ElemType>::~LinkList() {
	if (head->next == nullptr) {
		delete head;
		return;
	}
	Node<ElemType>* temp1 = head, * temp2 = head->next;
	while (temp2 != nullptr) {
		delete temp1;		//ɾ��ǰ���
		temp1 = temp2;
		temp2 = temp2->next;		//��������ƶ���Ϊ��
	}
	delete temp1;		//��temp1ɾ��
}

//[����]		LinkList::SetLength
//[����]		���ó���
//[����]		int Length
//[����]		void
template<class ElemType> void LinkList<ElemType>::SetLength(int length) {
	this->length = length;
}

//[����]		LinkList::GetHead
//[����]		//����ͷ�ڵ�ָ�����
//[����]		void
//[����]		Node<ElemType>
template<class ElemType> Node<ElemType>* LinkList<ElemType>::GetHead() {
	return head;
}

//[����]		LinkList::Insert
//[����]		//���ƶ�λ�ò���Ԫ��
//[����]		int index:����λ��	const ElemType &e:��������
//[����]		int TRUE��ʾ�ɹ� FALSE��ʾʧ��
template<class ElemType> int LinkList<ElemType>::Insert(int index, const ElemType& e) {
	Node<ElemType>* temp, * temp1, * tpr;		//tempָ�������ƶ�λ�ã�tpr��������ռ�
	tpr = nullptr;
	tpr = new Node<ElemType>;		//����ָ��Node����ָ��
	if (tpr == nullptr) return 0;		//����ռ�ʧ��
	tpr->data = e;
	if (index >= length) {
		if (index > length) {
			cout << "������λ�����������������ȣ������뵽��β��" << endl;
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
	else if (index == 0||length == 0) {		//�����ͷ
		temp = head->next;
		tpr->next = temp;
		head->next = tpr;
	}
	else if (index < length && index > 0) {
		temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;		//��ָ��index��ǰһ�����
		}
		temp1 = temp->next;		//ָ��index����һ���ڵ�
		temp->next = tpr;
		tpr->next = temp1;
	}
	length++;		//�����ȼ�1
	return 1;
}

//[����]		LinkList::GetLength
//[����]		������ĳ���
//[����]		void
//[����]		int ����length����
template<class ElemType> int LinkList<ElemType>::GetLength() const {
	return this->length;
}

//[����]		LinkList::IsEmpty
//[����]		�жϵ������Ƿ�Ϊ��
//[����]		void
//[����]		bool TRUE�� FALSE�ǿ�
template<class ElemType> bool LinkList<ElemType>::IsEmpty() const {
	if (head->next == nullptr) return true;
	else return false;
}

//[����]		LinkList::Locate
//[����]		����Ԫ�ض�λ
//[����]		const ElemType &e		Ԫ��ֵ
//[����]		int ���ض�λλ�ã���Ϊ-1��ʾδ�ҵ�����
template<class ElemType> int LinkList<ElemType>::Locate(const ElemType& e) const {
	Node<ElemType>* temp = head;
	int num = 0;		//�������ڷ���λ��
	while (num < this->length) {
		temp = temp->next;
		num++;
		if (temp->data == e) return num;
	}
	return -1;	//δ�ҵ�����
}

//[����]		LinkList::Get
//[����]		��ָ��λ�õ�Ԫ��
//[����]		int index��ָ��λ��, ElemType& e������Ԫ��
//[����]		int 1��ʾ�ҵ���0��ʾδ�ҵ�
template<class ElemType> int LinkList<ElemType>::Get(int index, ElemType& e) {
	if (index > length) return 0;		//δ�ҵ�����
	Node<ElemType>* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	e = temp->data;
	return 1;
}

//[����]		LinkList::Set
//[����]		����ָ��λ�õ�Ԫ��ֵ
//[����]		int index��ָ��λ��, ElemType& e������Ԫ��
//[����]		int 1��ʾ�ɹ����ã�0��ʾδ����
template<class ElemType> int LinkList<ElemType>::Set(int index, const ElemType& e) {
	if (index > length || index <= 0) {
		cout << "����λ��ʧ�ܣ�";
		system("pause");
		system("cls");
		return 0;		//δ�ҵ�����
	}
	Node<ElemType>* temp = head;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	temp->data = e;
	return 1;
}

//[����]		LinkList::Delete
//[����]		ɾ��ָ��Ԫ��
//[����]		int index��ָ��λ��, ElemType& e������Ԫ��
//[����]		int 1��ʾ�ɹ���0��ʾʧ��
template<class ElemType> int LinkList<ElemType>::Delete(int index, ElemType& e) {
	if (length == 0 || index > length) {
		cout << "ɾ��ʧ��!����Ϊ�ջ�ֵ���!";
		system("pause");
		system("cls");
		return 0;		//����Ϊ�ջ����
	}
	Node<ElemType>* temp;
	temp = head;		//ָ��ͷ�ڵ�
	for (int i = 0; i < index - 1; i++) {		//ָ����ɾ����Ԫ�ص�ǰ��
		temp = temp->next;
	}
	temp->next = temp->next->next;
	this->length--;
	return 1;		//ɾ���ɹ�
}