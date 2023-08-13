#include <string>
#include "../ForceBeing/Jedi.h"
#include "../ForceBeing/Sith.h"

using namespace std;



class Model {
  private:
    Sith darthVader = Sith("Darth Vader", 100);
	Jedi lukeSkyWalker = Jedi("Luke Skywalker", 99);
  public:
    string sithModel() {
      return darthVader.getName();
    }
    string jediModel() {
      return lukeSkyWalker.getName();
    }
};