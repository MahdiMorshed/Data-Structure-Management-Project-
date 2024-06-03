#include "storeType.h"

storeItem::storeItem() {}

storeItem::storeItem(string name, int availability) : name(name), availability(availability) {}

string storeItem::getName() const {

    return name;
}

int storeItem::getAvailability() const {
    return availability;
}

void storeItem::setAvailability(int avail) {
    availability = avail;
}
