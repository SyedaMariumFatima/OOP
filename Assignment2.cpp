#include <iostream>
#include <string>
using namespace std;

// -------------------- Abstract Classes --------------------
class User {
protected:
    int id;
    string name, contact, email;
public:
    User(int i=0, string n="", string c="", string e=""): id(i), name(n), contact(c), email(e) {}
    virtual void displayRole() const = 0; // Abstraction
    virtual void showDetails() const { cout << "User: " << name << " (" << email << ")" << endl; }
};

class Vehicle {
protected:
    string brand, model;
    int year;
    double price;
public:
    Vehicle(string b="", string m="", int y=0, double p=0.0): brand(b), model(m), year(y), price(p) {}
    virtual void displayDetails() const = 0; // Abstraction
    virtual void updateDetails(string b, string m, int y, double p) { brand=b; model=m; year=y; price=p; }
    friend bool comparePrice(const Vehicle& v1, const Vehicle& v2); // Friend function
};

// -------------------- Derived User Classes --------------------
class Buyer : public User {
public:
    Buyer(int i, string n, string c, string e): User(i,n,c,e) {}
    void displayRole() const override { cout << "Role: Buyer" << endl; }
};

class Seller : public User {
public:
    Seller(int i, string n, string c, string e): User(i,n,c,e) {}
    void displayRole() const override { cout << "Role: Seller" << endl; }
};

class Admin : public User {
public:
    Admin(int i, string n, string c, string e): User(i,n,c,e) {}
    void displayRole() const override { cout << "Role: Admin" << endl; }
};

// -------------------- Derived Vehicle Classes --------------------
class Car : public Vehicle {
    double mileage;
public:
    Car(string b="Unknown", string m="Unknown", int y=0, double p=0.0, double mil=0.0): Vehicle(b,m,y,p), mileage(mil) {}
    void displayDetails() const override {
        cout << "Car: " << brand << " " << model << " (" << year << ") $" << price << " Mileage: " << mileage << endl;
    }
    // Operator overloading
    Car operator+(const Car& other) {
        return Car(brand, model, year, price+other.price, mileage+other.mileage);
    }
    friend ostream& operator<<(ostream& os, const Car& c) {
        os << c.brand << " " << c.model << " $" << c.price;
        return os;
    }
};

class Bike : public Vehicle {
    string type;
public:
    Bike(string b="Unknown", string m="Unknown", int y=0, double p=0.0, string t="Standard"): Vehicle(b,m,y,p), type(t) {}
    void displayDetails() const override {
        cout << "Bike: " << brand << " " << model << " (" << year << ") $" << price << " Type: " << type << endl;
    }
};

// -------------------- Friend Function Implementation --------------------
bool comparePrice(const Vehicle& v1, const Vehicle& v2) {
    return v1.price < v2.price;
}

// -------------------- Marketplace --------------------
class Marketplace {
    User* users[20];
    int userCount;
    Vehicle* vehicles[20];
    int vehicleCount;
public:
    Marketplace(): userCount(0), vehicleCount(0) {}
    void addUser(User* u) { if(userCount<20) users[userCount++] = u; }
    void addVehicle(Vehicle* v) { if(vehicleCount<20) vehicles[vehicleCount++] = v; }
    void showAll() {
        cout << "---- Users ----" << endl;
        for(int i=0;i<userCount;i++) { users[i]->displayRole(); users[i]->showDetails(); }
        cout << "---- Vehicles ----" << endl;
        for(int i=0;i<vehicleCount;i++) vehicles[i]->displayDetails();
    }
};

// -------------------- Main --------------------
int main() {
    // Users
    Buyer b1(1,"Marium","0300-7654321","marium@gmail.com");
    Seller s1(2,"Ali","0300-1234567","ali@gmail.com");
    Admin a1(3,"Admin1","admin@gmail.com","SuperAdmin");

    // Vehicles
    Car c1("Toyota","Corolla",2020,20000,15000);
    Car c2("Honda","Civic",2019,18000,20000);
    Bike b2("Yamaha","R15",2021,5000,"Sports");

    // Operator overloading demo
    Car c3 = c1 + c2;
    cout << "Combined Car: " << c3 << endl;

    // Friend function demo
    cout << "Is Corolla cheaper than Civic? " << (comparePrice(c1,c2) ? "Yes" : "No") << endl;

    // Marketplace
    Marketplace mp;
    mp.addUser(&b1);
    mp.addUser(&s1);
    mp.addUser(&a1);
    mp.addVehicle(&c1);
    mp.addVehicle(&c2);
    mp.addVehicle(&b2);

    mp.showAll();

    return 0;
}

