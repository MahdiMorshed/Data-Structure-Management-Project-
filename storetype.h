#ifndef STORETYPE_H_INCLUDED
#define STORETYPE_H_INCLUDED
#include <string>

using namespace std;

class storeItem {
private:
    string name;
    int availability;

public:
    storeItem();
    storeItem(string name, int availability);
    string getName() const;
    int getAvailability() const;
    void setAvailability(int avail);
};

#endif // STORETYPE_H_INCLUDED
