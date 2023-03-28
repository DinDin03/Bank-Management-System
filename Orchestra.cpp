#include "Orchestra.h"

#include <string>

Orchestra::Orchestra() {}

Orchestra::Orchestra(int s_size) { size = s_size; }

int Orchestra::get_current_number_of_members() { return size; }
bool Orchestra::has_instrument(std::strinng instrument) {
  if (instrument == "violin") {
    return true;
  } else
    return false;
}
Orchestra::Musician *get_members() { Orchestra *array = new Orchestra[size]; }

bool Orchestra::add_musician(Musician new_musician) {
  if (size <= 50) {
    return true;
  } else
    return false
}
