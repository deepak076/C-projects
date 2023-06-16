#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for transform

using namespace std;

// Class to represent a train
class Train {
public:
    string name;
    int capacity;
    vector<string> passengers;

    Train(string trainName, int trainCapacity) {
        name = trainName;
        capacity = trainCapacity;
    }

    void addPassenger(const string& passengerName) {
        if (passengers.size() < capacity) {
            passengers.push_back(passengerName);
            cout << passengerName << " added to train " << name << endl;
        } else {
            cout << "Train " << name << " is already full!" << endl;
        }
    }

    void displayPassengers() const {
        cout << "Passengers of train " << name << ":" << endl;
        for (const string& passenger : passengers) {
            cout << "- " << passenger << endl;
        }
    }
};

// Class to manage multiple trains
class RailwayManagementSystem {
private:
    vector<Train> trains;

public:
    void addTrain(const Train& train) {
        trains.push_back(train);
        cout << "Train " << train.name << " added to the railway system." << endl;
    }

    void addPassengerToTrain(const string& trainName, const string& passengerName) {
        for (Train& train : trains) {
            if (train.name == trainName) {
                train.addPassenger(passengerName);
                return;
            }
        }
        cout << "Train " << trainName << " not found in the railway system." << endl;
    }

    void displayTrainPassengers(const string& trainName) const {
        string lowercaseName = trainName;
        transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);

        for (const Train& train : trains) {
            string lowercaseTrainName = train.name;
            transform(lowercaseTrainName.begin(), lowercaseTrainName.end(), lowercaseTrainName.begin(), ::tolower);

            if (lowercaseTrainName == lowercaseName) {
                train.displayPassengers();
                return;
            }
        }
        cout << "Train " << trainName << " not found in the railway system." << endl;
    }

    void displayAllTrains() const {
        cout << "List of all trains:" << endl;
        for (const Train& train : trains) {
            cout << "- " << train.name << endl;
        }
    }
};

int main() {
    RailwayManagementSystem railwaySystem;

    while (true) {
        cout << "==== Railway Management System ====" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. Add Passenger to Train" << endl;
        cout << "3. Display Train Passengers" << endl;
        cout << "4. Display All Trains" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter train name: ";
            string trainName;
            cin.ignore();
            getline(cin, trainName);

            cout << "Enter train capacity: ";
            int trainCapacity;
            cin >> trainCapacity;

            Train train(trainName, trainCapacity);
            railwaySystem.addTrain(train);
        } else if (choice == 2) {
            cout << "Enter train name: ";
            string trainName;
            cin.ignore();
            getline(cin, trainName);

            cout << "Enter passenger name: ";
            string passengerName;
            getline(cin, passengerName);

            railwaySystem.addPassengerToTrain(trainName, passengerName);
        } else if (choice == 3) {
            cout << "Enter train name: ";
            string trainName;
            cin.ignore();
            getline(cin, trainName);

            railwaySystem.displayTrainPassengers(trainName);
        } else if (choice == 4) {
            railwaySystem.displayAllTrains();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}
