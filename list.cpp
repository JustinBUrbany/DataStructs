#include <iostream>
#include "List.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

using std::cin;
using std::cout;
using std::endl;

List::List() : m_head(nullptr)
{
	ifstream musicfile("Music.txt");
	string holdtitle;
	string holdartist;
	if (musicfile.is_open())
	{
		while (!musicfile.eof())
		{
			getline(musicfile, holdtitle, ',');
			getline(musicfile, holdartist, '\n');
			InsertOrder(holdartist, holdtitle);
		}
		musicfile.close();
	}
	else
	{
		cout << "couldn't open file you suck!" << endl;
	}
}

List::~List()
{

	Purge();
}

/**********************************************************************
* Purpose: The purpose of this function is to destroy the list and the
nodes it contains
*
* Precondition: must be called from within the dtor of the list class
*
* Postcondition: list must be destroyed and m_head set to nullptr to leave
the function
*
************************************************************************/
void List::Purge()
{
	node * travel = m_head;
	//node * trail = travel;

	while (m_head)
	{
		travel = m_head;
		m_head = m_head->m_next;

		delete travel;

	}
	m_head = nullptr;

}
/**********************************************************************
* Purpose: The purpose of this function is to search the list for a
certain artist and say wether or not that artist is in the list
*
* Precondition: must pass an artist name in order to search the list 
against
*
* Postcondition: must go through the whole list and return if the
list contained an instance of what was being searched for
*
************************************************************************/
bool List::searchbyartist(string artist)
{
	bool found = false;
	node * travel = m_head;
	while (travel != nullptr)
	{
		if (artist == travel->m_artist)
		{
			found = true;
		}
		travel = travel->m_next;
	}

	return found;
}
/**********************************************************************
* Purpose: The purpose of this function is to search the list for a
certain title and say wether or not that title is in the list
*
* Precondition: must pass an title name in order to search the list
against
*
* Postcondition: must go through the whole list and return if the
list contained an instance of what was being searched for
*
************************************************************************/
bool List::searchbytitle(string title)
{
	bool found = false;
	node * travel = m_head;
	while (travel != nullptr)
	{
		if (title == travel->m_title)
		{
			found = true;
		}
		travel = travel->m_next;
	}

	return found;
}
/**********************************************************************
* Purpose: The purpose of this function is to delete a node from the list
if it contains the title of the song that wants to be deleted
*
* Precondition: must pass an song title  to know what is suppose to be
deleted
*
* Postcondition: must find if the list contains the song title
*
************************************************************************/
void List::Delete(string title)
{
	node * travel = m_head;
	node * trail = travel;
	if (m_head == nullptr)
	{
		cout << "There is nothing in your Playlist to delete" << endl;
	}
	else if (title == m_head->m_title)
	{
		trail = m_head;
		m_head = m_head->m_next;
		delete trail;
	}
	else
	{
		while (travel != nullptr && travel->m_title != title)
		{
			trail = travel;
			travel = travel->m_next;
		}
		if (travel == nullptr)
		{
			cout << "Not in list" << endl;
		}
		else
		{
			trail->m_next = travel->m_next;
			delete travel;
		}

	}

}
/**********************************************************************
* Purpose: The purpose of this function is to delete a group of
nodes from the listif the list contains the title of the songs
that the user wants to be deleted
*
* Precondition: nothing must be passed must be a valid path to a file
*
* Postcondition: must try to open file and read in whats need to be
deleted must either say file can't be open or read all the information
in the file
*
************************************************************************/

void List::BatchDelete()
{

	string filepath = "";
	string holdtitle = "";
	string holdartist = "";


	cout << "Enter in the file path" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, filepath);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();

	ifstream newsongs(filepath);
	if (newsongs.is_open())
	{
		while (!newsongs.eof())
		{
			getline(newsongs, holdtitle, ',');
			getline(newsongs, holdartist, '\n');
			Delete(holdtitle);
		}
		newsongs.close();
	}
	else
	{
		cout << "couldn't open file you suck!" << endl;
	}

}
/**********************************************************************
* Purpose: The purpose of this function is to add an item to the list
also the purpose is to make sure that the added item will appear in 
the list in the correct order by artist name so that everything is sorted
and won't become unsorted
*
* Precondition: must pass song title and artist name 
*
* Postcondition: must find where to put the new node in the list and then
point that node at the next one and the previous at the new node
*
************************************************************************/

void List::InsertOrder(string artist, string title)
{

	node * nn = new node(artist, title);

	if (m_head == nullptr || m_head-> m_artist > nn->m_artist)
	{
		nn->m_next = m_head;
		m_head = nn;
	}
	else
	{
		node * travel = m_head;
		node * trail = nullptr;
		while (travel && travel->m_artist < nn->m_artist)
		{
			trail = travel;
			travel = travel->m_next;
		}
		nn->m_next = travel;
		trail->m_next = nn;
	}
}
/**********************************************************************
* Purpose: This function is used to add a bunch of songs at once
so the user can make a file or take another file with all their music
and be able to add it to this playlist all at once
*
* Precondition: Must be a valid file path
* Postcondition: must have added all the items 
************************************************************************/
void List::BatchAdd()
{
	string filepath = "";
	string holdtitle = "";
	string holdartist = "";


	cout << "Enter in the file path" << endl;
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, filepath);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();

	ifstream newsongs(filepath);
		if (newsongs.is_open())
		{
			while (!newsongs.eof())
			{
				getline(newsongs, holdtitle, ',');
				getline(newsongs, holdartist, '\n');
				InsertOrder(holdartist, holdtitle);
			}
			newsongs.close();
		}
		else
		{
			cout << "couldn't open file you suck!" << endl;
		}


}
/**********************************************************************
* Purpose: The purpose of this function is to save all the changes to
the list in order
* Precondition: must pass an song title  to know what is suppose to be
deleted
*
* Postcondition: 
*
************************************************************************/
void List::save()
{
	ofstream savefile("Music.txt");

	node * travel = m_head;

	if (savefile.is_open())
	{
		savefile << travel->m_title;
		savefile << ",";
		savefile << travel->m_artist;
		savefile << '\n';
		travel = travel->m_next;
		while (travel != nullptr)
		{
			savefile << travel->m_title;
			savefile << ",";
			savefile << travel->m_artist;
			if (travel->m_next != nullptr)
			{
				savefile << '\n';
			}
			travel = travel->m_next;

		}

		savefile.close();
	}

}
