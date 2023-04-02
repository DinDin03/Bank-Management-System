#include "Orchestra.h"

Orchestra::Orchestra() {
    max_size = 0;
}

Orchestra::Orchestra(int size) {
    max_size = size;
}

int Orchestra::get_current_number_of_members() {
    return members.size();
}

bool Orchestra::has_instrument(std::string instrument) {
    for (Musician musician : members) {
        if (musician.get_instrument() == instrument) {
            return true;
        }
    }
    return false;
}

Musician* Orchestra::get_members() {
    return members.data();
}

bool Orchestra::add_musician(Musician new_musician) {
    if (members.size() < max_size) {
        members.push_back(new_musician);
        return true;
    }
    return false;
}

Orchestra::~Orchestra() {
    // empty destructor
}
