/*
Description: A system to manage hotel room reservations and guest information.
Questions:
How will you manage room availability and bookings?
How will you handle guest check-ins and check-outs?
What features will you include for managing reservations?
*/

/*
    Created by Inam Ul Hassan
    Github : https://github.com/Inam05
*/

// code

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class User
{
public:
    virtual void displayMenu() const = 0; // Pure virtual function for polymorphism
    virtual ~User() {}
};

class Room
{
public:
    int roomNumber;
    string roomType;
    double pricePerNight;
    bool isReserved;

    Room(int num, string type, double price) : roomNumber(num), roomType(type), pricePerNight(price), isReserved(false) {}

    void display() const
    {
        cout << "Room Number: " << roomNumber << ", Type: " << roomType << ", Price: $" << pricePerNight;
        if (isReserved)
            cout << " (Reserved)";
        cout << endl;
    }

    string toString() const
    {
        return to_string(roomNumber) + "," + roomType + "," + to_string(pricePerNight) + "," + (isReserved ? "1" : "0");
    }
};

class Reservation
{
public:
    int roomNumber;
    string customerName;
    string checkInDate;
    string checkOutDate;

    Reservation(int num, string name, string checkIn, string checkOut)
        : roomNumber(num), customerName(name), checkInDate(checkIn), checkOutDate(checkOut) {}

    void display() const
    {
        cout << "Reservation Details:\n";
        cout << "Room Number: " << roomNumber << ", Customer Name: " << customerName << endl;
        cout << "Check-in Date: " << checkInDate << ", Check-out Date: " << checkOutDate << endl;
    }

    string toString() const
    {
        return to_string(roomNumber) + "," + customerName + "," + checkInDate + "," + checkOutDate;
    }
};

class Admin : public User
{
private:
    vector<Room> rooms;

    void loadRooms()
    {
        ifstream file("rooms.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                int roomNumber = stoi(line.substr(0, pos1));
                string roomType = line.substr(pos1 + 1, pos2 - pos1 - 1);
                double pricePerNight = stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
                bool isReserved = line.substr(pos3 + 1) == "1";
                rooms.push_back(Room(roomNumber, roomType, pricePerNight));
                rooms.back().isReserved = isReserved;
            }
            file.close();
        }
    }

    void saveRooms() const
    {
        ofstream file("rooms.txt");
        if (file.is_open())
        {
            for (const auto &room : rooms)
            {
                file << room.toString() << endl;
            }
            file.close();
        }
    }

public:
    Admin()
    {
        loadRooms();
    }

    ~Admin()
    {
        saveRooms();
    }

    void addRoom(const Room &room)
    {
        rooms.push_back(room);
        cout << "Room added successfully.\n";
    }

    void removeRoom(int roomNumber)
    {
        auto it = remove_if(rooms.begin(), rooms.end(),
                            [roomNumber](const Room &r)
                            { return r.roomNumber == roomNumber; });
        if (it != rooms.end())
        {
            rooms.erase(it, rooms.end());
            cout << "Room removed successfully.\n";
        }
        else
        {
            cout << "Room not found.\n";
        }
    }

    void displayRooms() const
    {
        cout << "Available Rooms:\n";
        for (const auto &room : rooms)
        {
            room.display();
        }
    }

    void checkAvailability(int roomNumber)
    {
        for (const auto &room : rooms)
        {
            if (room.roomNumber == roomNumber)
            {
                if (room.isReserved)
                {
                    cout << "Room " << roomNumber << " is currently reserved.\n";
                }
                else
                {
                    cout << "Room " << roomNumber << " is available.\n";
                }
                return;
            }
        }
        cout << "Room not found.\n";
    }
};

class Receptionist : public User
{
private:
    vector<Reservation> reservations;

    void loadReservations()
    {
        ifstream file("reservations.txt");
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                int roomNumber = stoi(line.substr(0, pos1));
                string customerName = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string checkInDate = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string checkOutDate = line.substr(pos3 + 1);
                reservations.push_back(Reservation(roomNumber, customerName, checkInDate, checkOutDate));
            }
            file.close();
        }
    }

    void saveReservations() const
    {
        ofstream file("reservations.txt");
        if (file.is_open())
        {
            for (const auto &reservation : reservations)
            {
                file << reservation.toString() << endl;
            }
            file.close();
        }
    }

public:
    Receptionist()
    {
        loadReservations();
    }

    ~Receptionist()
    {
        saveReservations();
    }

    void makeReservation(const Reservation &reservation)
    {
        reservations.push_back(reservation);
        cout << "Reservation made successfully.\n";
    }

    void displayReservations() const
    {
        cout << "Current Reservations:\n";
        for (const auto &reservation : reservations)
        {
            reservation.display();
        }
    }

    void displayMenu() const override
    {
        // Placeholder for menu display (can use Admin's displayRooms method if needed)
        cout << "Receptionist Menu:\n";
        cout << "1. View Rooms\n";
        cout << "2. View Reservations\n";
        cout << "3. Logout\n";
    }
};

class Customer : public User
{
public:
    void displayMenu() const override
    {
        cout << "Customer Menu:\n";
        cout << "1. View Rooms\n";
        cout << "2. Make Reservation\n";
        cout << "3. Logout\n";
    }
};

void adminMenu(Admin &admin)
{
    int choice;
    do
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Room\n";
        cout << "2. Remove Room\n";
        cout << "3. Display Rooms\n";
        cout << "4. Check Room Availability\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            int roomNumber;
            string roomType;
            double pricePerNight;
            cout << "Enter room number: ";
            cin >> roomNumber;
            cin.ignore();
            cout << "Enter room type: ";
            getline(cin, roomType);
            cout << "Enter price per night: ";
            cin >> pricePerNight;
            cin.ignore();
            admin.addRoom(Room(roomNumber, roomType, pricePerNight));
            break;
        }
        case 2:
        {
            int roomNumber;
            cout << "Enter room number to remove: ";
            cin >> roomNumber;
            cin.ignore();
            admin.removeRoom(roomNumber);
            break;
        }
        case 3:
            admin.displayRooms();
            break;
        case 4:
        {
            int roomNumber;
            cout << "Enter room number to check availability: ";
            cin >> roomNumber;
            cin.ignore();
            admin.checkAvailability(roomNumber);
            break;
        }
        case 5:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 5);
}

void receptionistMenu(Receptionist &receptionist)
{
    int choice;
    do
    {
        receptionist.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            receptionist.displayRooms(); // Assuming this function is available
            break;
        case 2:
            receptionist.displayReservations();
            break;
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 3);
}

void customerMenu(Customer &customer, Admin &admin, Receptionist &receptionist)
{
    int choice;
    do
    {
        customer.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            admin.displayRooms(); // Display rooms as a placeholder
            break;
        case 2:
        {
            int roomNumber;
            string customerName, checkInDate, checkOutDate;
            cout << "Enter room number to reserve: ";
            cin >> roomNumber;
            cin.ignore();
            cout << "Enter your name: ";
            getline(cin, customerName);
            cout << "Enter check-in date (YYYY-MM-DD): ";
            getline(cin, checkInDate);
            cout << "Enter check-out date (YYYY-MM-DD): ";
            getline(cin, checkOutDate);
            receptionist.makeReservation(Reservation(roomNumber, customerName, checkInDate, checkOutDate));
            break;
        }
        case 3:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 3);
}

int main()
{
    string role;
    cout << "Enter role (admin/receptionist/customer): ";
    getline(cin, role);

    Admin admin;
    Receptionist receptionist;
    Customer customer;

    if (role == "admin")
    {
        adminMenu(admin);
    }
    else if (role == "receptionist")
    {
        receptionistMenu(receptionist);
    }
    else if (role == "customer")
    {
        customerMenu(customer, admin, receptionist);
    }
    else
    {
        cout << "Invalid role.\n";
    }

    return 0;
}
