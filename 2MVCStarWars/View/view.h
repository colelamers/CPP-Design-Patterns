#include <iostream>
#include <string>

using namespace std;

template <class numval>//simple template
numval printVal(numval a, numval b) {
    numval z;
    z = a + b;
    return z;
};//

class View {
public:
    inline void printRecord(string recordItem) {
        int x = 3, y = 4, z;
        double n = 4.32, m = 5.4, o;
        z = printVal<int>(x, y);//passes through int values
        o = printVal<double>(m, n);//passes through double values

        cout << "-----" << endl;
        cout << recordItem << endl;
        cout << "-----" << endl;

        cout << z << endl; //prints out the int values
        cout << o << endl; //prints through the double values
    }
};

