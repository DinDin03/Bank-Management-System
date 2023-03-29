#include <iostream>
#ifndef ORCHESTRA_H
#define ORCHESTRA_H
#include "Musician.h"

class Orchestra{
    private:
        int size;
        int tSize;
        Musician* musicians;
    public:
        Orchestra(){
            size = 0;
            tSize = 0;
        }
        Orchestra(int size){
            if(size <= 0){
                this->size = 0;
            }
            this->size = size;
            tSize = 0;
            musicians = new Musician[this->size];
        }
        bool add_musician(Musician nMusician){
            if(tSize < size){
                musicians[tSize] = nMusician;
                return true;
            }
            else
            return false;
        }
        void set_size(int size){
            this-> size = size;
        }
        Musician* get_members(){
            return musicians;
        }
        int get_current_number_of_members(){
            return tSize;
        }
        bool has_instrument(std::string instrument){
            for(int i = 0; i < tSize; i++){
                if(musicians[i].get_instrument() == instrument){
                    return true;
                }
            }
            return false;
        }
};

#endif