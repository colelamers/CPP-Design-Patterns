#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#pragma warning(disable:4996)//disables the errors that show for the local time issue

using namespace std;

/* 10/8/2020 Created by Cole Lamers
* The purpose of this project utilizes a singleton object 
* that continually replaces the data typed in by a user and logs it
* to a text file with the date time.
*/

// Datastore as a Singleton
// PRIVATE constructor
// PUBLIC method that RETURNS pointer to the object.
class DataStore {

private:
	static DataStore* instance;
	string data;

	// Private constructor so that no objects can be created.
	DataStore() {
		data = "";
	}

public:
	static DataStore* getInstance() {
		if (!instance) {
			instance = new DataStore;
		}
		return instance;
	}

	string getData() {
		return data;
	}

	void setData(string newData) {
		data = newData;
	}
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance()
// sort of sucks to have to do this, but in C++, we have to do it this way
DataStore* DataStore::instance = nullptr;

int main() {

	string userEntry = "";

	DataStore* dsObject = dsObject->getInstance();
	dsObject->setData(userEntry);

	ofstream textFileWrite;
	textFileWrite.open("cppLog.txt", ios_base::app); //opens the file in append mode

	cout << "Use this program to modify the singleton." << endl << endl;
	cout << "Enter in data. Submit with Enter key. Quit with 0 key. " << endl;



	while (true)
	{
		getline(cin, userEntry);

/*		struct tm date;
		time_t now = time(0);
		localtime_s(&date, &now);//this has to be created each time to contain the date at the time of entry
*/
		time_t rawtime;
		struct tm* timeinfo;

		time(&rawtime);
		timeinfo = localtime(&rawtime);


		if (userEntry != "0")
		{
			dsObject->setData(userEntry);
			textFileWrite << asctime(timeinfo) << ", " << dsObject->getData() << endl;
		}//adds the userEntry with the datetime
		else
		{
			break;
		}
	}

	string f = "";
	ifstream textFileRead("cppLog.txt");

	cout << "New contents written to the file:" << endl << endl;

	while (getline(textFileRead, f))
	{
		cout << f << endl;
	}//this will just display what gets written to the file

	textFileWrite.close();
	textFileRead.close();
	return 0;
}



/*
// a little weird - calling a method instead of a constructor to get "s"
// but ...ok right?
DataStore* s = s->getInstance();
cout << "s->getInstance() " << endl;

// shouldn't be surprising output here, right?
cout << "s->getData() \t\t" << s->getData() << endl << endl;

// here we have a "setter" - no biggie
s->setData(x);
cout << "s->setData(100) " << endl;

// bet you'll never guess what this is!
cout << "s->getData() \t\t" << s->getData() << endl << endl;

// No big deal, same as above right?
DataStore* t = t->getInstance();
cout << "t->getInstance() " << endl;

// boom. This is where the Singleton is useful. We have ONE actual object.
// unlike above, "t" didn't have it's "data" set to 0. It *IS* "s"
cout << "t->getData() \t\t" << t->getData() << endl << endl;

t->setData(y);
cout << "t->setData(200) " << endl;

// bet you'll never guess what this is!
cout << "t->getData() \t\t" << t->getData() << endl << endl;

// bet you'll never guess what this is!
cout << "s->getData() \t\t" << s->getData() << endl;
*/