#ifndef LIST_H
#define LIST_H

#include "node.h"

/************************************************************************
* Class: List
*
* Purpose: The purpose of this class is to get and contain nodes
which will be songs and artist and connect the songs in artist in one
place to make it easy for the user to have all the data in one area.
Basically is an array of grouped data
*
* Manager functions: Purge Delete InsertOrder
*
* Methods: node * m_head
*************************************************************************/
class List
{
public:
	List();
	~List();
	void Purge();
	bool searchbyartist(string artist);
	bool searchbytitle(string title);
	void Delete(string title);
	void BatchDelete();
	void InsertOrder(string artist, string title);
	void BatchAdd();
	void save();

private:
	node * m_head;
};

#endif