#include "Orchestra.h"

Orchestra::Orchestra() {
    max_size = 0;
    num_members = 0;
    members = nullptr;
}

Orchestra::Orchestra(int size) {
    max_size = size;
    num_members = 0;
    members = new Musician[max_size];
}

Orchestra::~Orchestra() {
    delete[] members;
}

int Orchestra::get_current_number_of_members() {
    return num_members;
}

bool Orchestra::has_instrument(std::string instrument) {
    for (int i = 0; i < num_members; i++) {
        if (members[i].get_instrument() == instrument) {
            return true;
        }
    }
    return false;
}

Musician* Orchestra::get_members() {
    return members;
}

bool Orchestra::add_musician(Musician new_musician) {
    if (num_members < max_size) {
        members[num_members] = new_musician;
        num_members++;
        return true;
    }
    return false;
}
