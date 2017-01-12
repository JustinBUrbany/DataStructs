#ifndef _NODE_H
#define _NODE_H
#include <string>
using std::string;

class List;
/************************************************************************
* Class: node
*
* Purpose: The purpose of this class is to group together songs and artist
and contain a pointer to point to the next song and artist
*
* Manager functions: 
*
* Methods: node * m_next
			string m_title
			string m_artist
*************************************************************************/
class node
{
	friend class List;
public:
	node(string artist, string title);
	~node();

private:
	node * m_next;
	string m_title;
	string m_artist;
};

#endif
