#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <time.h>
#include <thread>
#include <ctime>

using namespace std;

void firstThread(vector<string> names, int numOfLines){
for (int i = 0; i < names.size(); i++){
    cout << names.at(i) << " Line " << i << endl;
}
}

void secondThread(vector<string> names, int remainingLines){
  for (int i = remainingLines; i < names.size(); i++){
    cout << names.at(i) << " Line " << i << endl;
  }
}

int main() {

time_t starttime = time(0);
cout << starttime << endl;


ofstream textFileWrite;
textFileWrite.open("cppLog.txt", ios_base::app); //opens the file in append mode

ifstream textFileRead("LastNames.txt");
istream_iterator<string> iterator(textFileRead), end;
vector<string> namesList(iterator, end);
cout << "Read " << namesList.size() << " numbers" << endl;

thread core1 (firstThread(namesList, 30000));
thread core2 (secondThread(vector<std::string> names, int remainingLines));
firstThread(namesList, 30000);

  time_t endtime = time(0);
  cout << endtime << endl;
  int elapsed = endtime - starttime;
  cout << elapsed << endl;

	textFileWrite.close();
	return 0;
}