//File: DLL_Node.h
//Author: Jairun Diemert
//Class: COP3530
//Project: Class work
//Description: This is the header file for the DLL_Node class

#ifndef DLL_NODE_H
#define DLL_NODE_H

#include <iostream>
using namespace std;

class DLL_Node
 {
  int  data;
  DLL_Node *next;
	DLL_Node *previous;
	DLL_Node *currNodePtr;
	DLL_Node *newNodePtr;
	DLL_Node *head = NULL;
	DLL_Node *tail = NULL;  //nullptr for C++11

  public :
  DLL_Node(){};
  void  create();
  void  insert();
  void  del();
  void  display();
	void  size();
	void  displayBackward();
	void  searchList();
	void  replace();
};


#endif 