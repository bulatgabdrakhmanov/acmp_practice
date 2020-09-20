#include <iostream>
#include <fstream>
#include <cmath>
#include <tuple>
#include <vector>

using namespace std;

/**
 *
 * @param floorsInEntrance всего этажей в подъезде
 * @param apartmentNumber номер квартиры
 * @param apartmentEntrance номер подъезда
 * @param apartmentFloor номер этажа
 * @return
 */
vector<int> getApartmentsInFloorVariants(
        int floorsInEntrance,
        int apartmentNumber,
        int apartmentEntrance,
        int apartmentFloor) {

    // на каком этаже находилась бы квартира, если бы дом состоял только из одного подъезда
    int totalFloorsBeforeApartment = floorsInEntrance * (apartmentEntrance - 1) + apartmentFloor;

    int apartmentsInFloorVariant = (int) ceil((float) apartmentNumber / (float) totalFloorsBeforeApartment);

    vector<int> apartmentsInFloorVariants;
    while (apartmentsInFloorVariant * (totalFloorsBeforeApartment - 1) < apartmentNumber &&
           apartmentsInFloorVariant < 15000) {

        apartmentsInFloorVariants.push_back(apartmentsInFloorVariant);
        apartmentsInFloorVariant++;
    }

    return apartmentsInFloorVariants;
}

/**
 *
 * @param apartmentNumber номер квартиры
 * @param floorsInEntrance сколько этаже в одном подъезде
 * @param apartmentsInFloor сколько квартир на одном этаже
 * @return
 */
tuple<int, int> getApartmentEntranceAndFloor(
        int apartmentNumber,
        int floorsInEntrance,
        int apartmentsInFloor) {

    int apartmentsInEntrance = apartmentsInFloor * floorsInEntrance;

    int apartmentEntrance = ceil((float) apartmentNumber / (float) apartmentsInEntrance);
    int apartmentFloor =
            (int) ceil((float) apartmentNumber / (float) apartmentsInFloor) -
            floorsInEntrance * (apartmentEntrance - 1);

    return {apartmentEntrance, apartmentFloor};
}

int main() {
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");

    if (input.is_open() && output.is_open()) {
        int apartment1Number;   // номер квартиры, у которой нужно найти подъезд и этаж
        int floorsInEntrance;   // кол-во этажей в подъезде
        int apartment2Number;   // номер квартиры, у которой известен подъезд и этаж
        int apartment2Entrance; // подъезд этой квартиры
        int apartment2Floor;    // этаж этой квартиры

        // найти на каком подъезде и этаже находится квартира

        input >> apartment1Number >> floorsInEntrance >> apartment2Number >> apartment2Entrance >> apartment2Floor;

        vector<int> apartmentInFloorVariants =
                getApartmentsInFloorVariants(floorsInEntrance, apartment2Number, apartment2Entrance, apartment2Floor);

        if (!apartmentInFloorVariants.empty()) {
            int apartment1Entrance = 0;
            int apartment1Floor = 0;
            bool isAmbiguousApartmentEntrance = false;
            bool isAmbiguousApartmentFloor = false;

            for (int apartmentInFloorVariant: apartmentInFloorVariants) {
                tuple<int, int> apartmentEntranceAndFloor =
                        getApartmentEntranceAndFloor(apartment1Number, floorsInEntrance, apartmentInFloorVariant);

                int apartment1EntranceVariant= get<0>(apartmentEntranceAndFloor);
                int apartment1FloorVariant = get<1>(apartmentEntranceAndFloor);

                if (!apartment1Entrance && !apartment1Floor) {
                    apartment1Entrance = apartment1EntranceVariant;
                    apartment1Floor = apartment1FloorVariant;
                } else {
                    if (apartment1EntranceVariant != apartment1Entrance) {
                        isAmbiguousApartmentEntrance = true;
                    }
                    if (apartment1FloorVariant != apartment1Floor) {
                        isAmbiguousApartmentFloor = true;
                    }
                }

                // если номер подъезда и этаж нельзя определить однозначно
                if (isAmbiguousApartmentEntrance && isAmbiguousApartmentFloor) {
                    break;
                }
            }

            if (!isAmbiguousApartmentEntrance) {
                output << apartment1Entrance;
            } else {
                output << 0;
            }

            output << " ";

            if (!isAmbiguousApartmentFloor) {
                output << apartment1Floor;
            } else {
                output << 0;
            }
        } else {
            output << -1 << " " << -1;
        }
    }

    input.close();
    output.close();
    return 0;
}