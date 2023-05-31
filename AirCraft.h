#ifndef AIRCRAFT_H
#define AIRCRAFT_H

class AirCraft {
public:
    AirCraft();
    AirCraft(int w);
    void refuel();
    virtual void fly(int headwind, int minutes);
    int get_weight();
    void set_weight(int w);
    float get_fuel();
    void set_fuel(float f);
    int get_numberOfFlights();
    void set_numberOfFlights(int n);

protected:
    int weight;
    float fuel;
    int numberOfFlights;
};

#endif
