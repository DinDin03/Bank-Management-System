#ifndef APPLIANCE_H
#define APPLIANCE_H

class Appliance {
protected:
    int powerRating;
    bool isOn;

public:
    Appliance();
    Appliance(int powerRating);

    // getters and setters
    int get_powerRating() const;
    bool get_isOn() const;
    void set_powerRating(int powerRating);
    void set_isOn(bool isOn);

    virtual double getPowerConsumption() const;
    
    void turnOn();
    void turnOff();
};

#endif
