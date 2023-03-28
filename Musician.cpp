#include "Musician.h"
#include <string>

Musician::Musician(){}

Musician::Musician(std::string s_instrument, int s_experience){
    instrument = s_instrument;
    experience = s_experience; 
}

std::string Musician::get_instrument(){
    return instrument;
}

int Musician::get_experience()  {
    return experience;
}
