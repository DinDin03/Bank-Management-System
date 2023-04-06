#include <iostream>
#include "Car.h"
#include "Motorbike.h"
#include "Bus.h"
#include "ParkingLot.h"

int main() {
    ParkingLot parkingLot(10);
    int option = 0;
    while (parkingLot.getCount() < 10) {
        std::cout << "Enter 1 for car, 2 for motorbike, 3 for bus: ";
        std::cin >> option;
        int id = 0;
        std::cout << "Enter ID of the vehicle: ";
        std::cin >> id;
        if (option == 1) {
            Car* car = new Car(id);
            parkingLot.parkVehicle(car);
        }
        else if (option == 2) {
            Motorbike* motorbike = new Motorbike(id);
            parkingLot.parkVehicle(motorbike);
        }
        else if (option == 3) {
            Bus* bus = new Bus(id);
            parkingLot.parkVehicle(bus);
        }
        else {
            std::cout << "Invalid option" << std::endl;
        }
    }
    int id = 0;
    std::cout << "\nEnter ID of the vehicle to unpark: ";
    std::cin >> id;
    parkingLot.unparkVehicle(id);

    return 0;
}
