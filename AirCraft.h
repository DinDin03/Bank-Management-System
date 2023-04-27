#ifndef AIRCRAFT_H
#define AIRCRAFT_H

class AirCraft {
public:
    AirCraft();
    AirCraft(int w);
    void refuel();
    virtual void fly(int headwind, int minutes);
    int get_Weight();
    void set_Weight(int w);
    float get_Fuel();
    void set_Fuel(float f);
    int get_NumberOfFlights();
    void set_NumberOfFlights(int n);

protected:
    int weight;
    float fuel;
    int numberOfFlights;
};

#endif
