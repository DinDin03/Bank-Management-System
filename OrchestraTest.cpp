#include <iostream>
#include <string>
#include "Musician.h"
#include "Orchestra.h"

Orchestra::Orchestra() {
  size = 0;
  tSize = 0;
}
Orchestra::Orchestra(int size) {
  if (size <= 0) {
    this->size = 0;
  }
  this->size = size;
  tSize = 0;
  musicians = new Musician[this->size];
}
bool Orchestra::add_musician(Musician nMusician) {
  if (tSize < size) {
    musicians[tSize] = nMusician;
    return true;
  } else
    return false;
}
void Orchestra::set_size(int size) { this->size = size; }
Musician* get_members() { return musicians; }
int Orchestra::get_current_number_of_members() { return tSize; }
bool Orchestra::has_instrument(std::string instrument) {
  for (int i = 0; i < tSize; i++) {
    if (musicians[i].get_instrument() == instrument) {
      return true;
    }
  }
  return false;
}
