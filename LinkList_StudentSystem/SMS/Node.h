#pragma once
//Node.h
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<string>
using namespace std;

template<class Elemtype> struct Node {
	Elemtype data;		//������
	Node<Elemtype>* next;		//ָ����
};
