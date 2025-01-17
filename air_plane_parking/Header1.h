#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

// Structure to store parking information
struct ParkingInfo {
    std::string carLicensePlate;
    std::chrono::system_clock::time_point entryTime;
    std::chrono::system_clock::time_point exitTime;
};

// Node for the linked list used in the hash table
struct Node {
    int slotNumber;
    ParkingInfo data;
    Node* next;
    Node(int slot, const ParkingInfo& info) : slotNumber(slot), data(info), next(nullptr) {}
};

// Hash table class
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Node* table[TABLE_SIZE];

    // Hash function to map a slot number to an index in the hash table
    int hashFunction(int slotNumber) {
        return slotNumber % TABLE_SIZE;
    }

public:
    // Constructor to initialize the hash table
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Function to park a car in a specific slot
    void parkCar(int slotNumber, const std::string& carLicensePlate, const std::chrono::system_clock::time_point& entryTime) {
        int index = hashFunction(slotNumber);
        Node* newNode = new Node(slotNumber, { carLicensePlate, entryTime, {} });
        newNode->next = table[index];
        table[index] = newNode;
        std::cout << "Car with license plate " << carLicensePlate << " parked at slot " << slotNumber << std::endl;
    }

    // Function to remove a car from a specific slot
    void removeCar(int slotNumber, const std::chrono::system_clock::time_point& exitTime) {
        int index = hashFunction(slotNumber);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->slotNumber != slotNumber) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            std::cout << "Removing car with license plate " << current->data.carLicensePlate << " from slot " << slotNumber << std::endl;
            current->data.exitTime = exitTime;

            if (prev == nullptr) {
                // If the node to be removed is the first node
                table[index] = current->next;
            }
            else {
                prev->next = current->next;
            }

            delete current;
        }
        else {
            std::cout << "Slot " << slotNumber << " is empty. No car to remove." << std::endl;
        }
    }

    // Function to display the current status of the parking lot
    void displayParkingStatus() {
        std::cout << "Parking Status:" << std::endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                std::cout << "Slot " << current->slotNumber << ": License Plate: " << current->data.carLicensePlate
                    << ", Entry Time: " << std::chrono::system_clock::to_time_t(current->data.entryTime)
                    << ", Exit Time: " << std::chrono::system_clock::to_time_t(current->data.exitTime) << std::endl;
                current = current->next;
            }
        }
    }

    // Function to display parking status within a time range
    void displayParkingStatusWithinTimeRange(const std::chrono::system_clock::time_point& startTime,
        const std::chrono::system_clock::time_point& endTime) {
        std::cout << "Parking Status within Time Range:" << std::endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                if (current->data.entryTime >= startTime && current->data.exitTime <= endTime) {
                    std::cout << "Slot " << current->slotNumber << ": License Plate: " << current->data.carLicensePlate
                        << ", Entry Time: " << std::chrono::system_clock::to_time_t(current->data.entryTime)
                        << ", Exit Time: " << std::chrono::system_clock::to_time_t(current->data.exitTime) << std::endl;
                }
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable parkingSystem;

    // Manually enter entry times
    auto entryTime1 = std::chrono::system_clock::now();
    auto entryTime2 = std::chrono::system_clock::now();
    auto entryTime3 = std::chrono::system_clock::now();

    // Park cars with manual entry times
    parkingSystem.parkCar(1, "ABC123", entryTime1);
    parkingSystem.parkCar(2, "XYZ789", entryTime2);
    parkingSystem.parkCar(3, "DEF456", entryTime3);

    // Display parking status
    parkingSystem.displayParkingStatus();

    // Manually enter exit times
    auto exitTime = std::chrono::system_clock::now();

    // Remove a car with manual exit time
    parkingSystem.removeCar(2, exitTime);

    // Display updated parking status
    parkingSystem.displayParkingStatus();

    // Define a time range (for example, the last hour)
    auto currentTime = std::chrono::system_clock::now();
    auto startTime = currentTime - std::chrono::hours(1);

    // Display parking status within the defined time range
    parkingSystem.displayParkingStatusWithinTimeRange(startTime, currentTime);

    return 0;
}



