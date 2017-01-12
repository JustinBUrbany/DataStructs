//Justin Urbany
#define _CRTDB_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include "list.h"
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int count = 0; // for menu selection
	List MyPlaylist;  // This is the playlist holds nodes/songs
	string title; // used for user to input a title
	string artist; // used for user to input artist
	bool found = false;  // used to tell if song/artist was found
	bool save = true;  // used to keep track of last save and 
						// unsaved changes
	char savechange = ' ';  // for user to input if they would
							// like to save changes.

	do 
	{
		cout << "1) Search by Song" << endl;
		cout << "2) Search by Artist" << endl;
		cout << "3) Add" << endl;
		cout << "4) Batch Add" << endl;
		cout << "5) Remove" << endl;
		cout << "6) Batch Remove" << endl;
		cout << "7) Save" << endl;
		cout << "8) Exit" << endl<<endl;

		cout << "Make a selection: ";
		cin >> count;

		switch (count)
		{
		case 1:
		{
			cout << "Enter in song you want to search for: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, title);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();

			found=MyPlaylist.searchbytitle(title);
			
			if (found == true)
			{
				cout << title << " is in your playlist." << endl;;
			}
			else
			{
				cout << title << " wasn't found." << endl;
			}

			break;
		}
		case 2:
		{
			cout << "Enter in artist you want to search for: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, artist);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();

			found=MyPlaylist.searchbyartist(artist);

			if (found == true)
			{
				cout << artist << " is in your playlist!" << endl;
			}
			else
			{
				cout << artist << " wasn't found!" << endl;
			}

			break;
		}
		case 3:
		{
			cout << "Enter the title of the song you want to add: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, title);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();
			
			cout << "Enter the artist of the song you want to add: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, artist);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();


			MyPlaylist.InsertOrder(artist, title);

			save = false;
			break;
		}
		case 4:
		{
			MyPlaylist.BatchAdd();
			save = false;
			break;
		}
		case 5:
		{
			cout << "Enter the title of the song you want to delete: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, title);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.clear();

			MyPlaylist.Delete(title);

			save = false;
			break;
		}
		case 6:
		{
			MyPlaylist.BatchDelete();
			save = false;
			break;
		}
		case 7:
		{
			MyPlaylist.save();
			save = true;
			break;
		}
		case 8:
		{
			if (save == false)
			{
				cout << "There are unsaved Changes would you like to save? (y/n)";
				cin >> savechange;
				if (savechange = 'y')
				{
					MyPlaylist.save();
				}
			}
		}
		
		}

	} while (count !=8);

	return (0);
}
