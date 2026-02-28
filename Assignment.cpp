#include <iostream>
#include <string>
using namespace std;


class Car {
private:
    string brand, model;
    int year;
    double price;
    double mileage;
    string status; 
public:
    static int totalCars; // Static member

    
    Car(): brand("Unknown"), model("Unknown"), year(0), price(0.0), mileage(0.0), status("Available") {
        totalCars++;
    }

    
    Car(string b, string m, int y, double p, double mil): brand(b), model(m), year(y), price(p), mileage(mil), status("Available") {
        totalCars++;
    }

    
    Car(const Car &c): brand(c.brand), model(c.model), year(c.year), price(c.price), mileage(c.mileage), status(c.status) {
        totalCars++;
    }

   
    void displayDetails() const {
        cout << brand << " " << model << " (" << year << ") - $" << price << " Mileage: " << mileage << " Status: " << status << endl;
    }

    void updateDetails(string b, string m, int y, double p, double mil) {
        brand = b; model = m; year = y; price = p; mileage = mil;
    }

    void markAsSold() { status = "Sold"; }

    bool matchesFilter(string b, int y, double maxPrice) const {
        return (brand == b && year == y && price <= maxPrice);
    }
};
int Car::totalCars = 0; // Initialize static member


class Seller {
private:
    int sellerID;
    string name, contact, email;
    double rating;
    Car listings[10]; // Array of Cars
    int listingCount;

public:
    Seller(int id=0, string n="", string c="", string e=""): sellerID(id), name(n), contact(c), email(e), rating(0.0), listingCount(0) {}

    void addListing(Car c) { if(listingCount < 10) listings[listingCount++] = c; }
    void removeListing(int index) { if(index < listingCount) { for(int i=index;i<listingCount-1;i++) listings[i]=listings[i+1]; listingCount--; } }
    void updateListing(int index, Car c) { if(index < listingCount) listings[index] = c; }
    void viewListings() {
        for(int i=0;i<listingCount;i++) listings[i].displayDetails();
    }
};


class Buyer {
private:
    int buyerID;
    string name, contact, email;
    Car favorites[10]; // Array of Cars
    int favCount;
    string messages[10];
    int msgCount;

public:
    Buyer(int id=0, string n="", string c="", string e=""): buyerID(id), name(n), contact(c), email(e), favCount(0), msgCount(0) {}

    void addFavorite(Car c) { if(favCount < 10) favorites[favCount++] = c; }
    void removeFavorite(int index) { if(index < favCount) { for(int i=index;i<favCount-1;i++) favorites[i]=favorites[i+1]; favCount--; } }
    void sendMessage(string msg) { if(msgCount < 10) messages[msgCount++] = msg; }
    void viewFavorites() {
        for(int i=0;i<favCount;i++) favorites[i].displayDetails();
    }
};


class Admin {
private:
    int adminID;
    string name, email, role;
    Car approvedListings[10];
    int approvedCount;
    Car removedListings[10];
    int removedCount;

public:
    Admin(int id=0, string n="", string e="", string r=""): adminID(id), name(n), email(e), role(r), approvedCount(0), removedCount(0) {}

    void approveListing(Car c) { if(approvedCount < 10) approvedListings[approvedCount++] = c; }
    void removeListing(Car c) { if(removedCount < 10) removedListings[removedCount++] = c; }
    void viewReports() {
        cout << "Approved Listings: " << approvedCount << " Removed Listings: " << removedCount << endl;
    }
    void manageUsers() { cout << "Managing users..." << endl; }
};

// -------------------- Listing Class (Composition) --------------------
class Listing {
private:
    int listingID;
    Car car; // Composition
    Seller* seller; // Aggregation
    string datePosted, status;
    int views;

public:
    Listing(int id=0, Car c=Car(), Seller* s=nullptr, string d=""): listingID(id), car(c), seller(s), datePosted(d), status("Active"), views(0) {}

    void activate() { status = "Active"; }
    void deactivate() { status = "Inactive"; }
    void update(Car c) { car = c; }
    void display() { car.displayDetails(); cout << "Listing ID: " << listingID << " Status: " << status << endl; }

    bool matchesFilter(string b, int y, double maxPrice) const { return car.matchesFilter(b,y,maxPrice); }
};


class Marketplace {
private:
    string name;
    Listing listings[20];
    int listingCount;
    Buyer buyers[10];
    int buyerCount;
    Seller sellers[10];
    int sellerCount;
    Admin admins[5];
    int adminCount;
    static int totalUsers;

public:
    Marketplace(string n=""): name(n), listingCount(0), buyerCount(0), sellerCount(0), adminCount(0) {}

    void addUser(Buyer b) { if(buyerCount<10) buyers[buyerCount++] = b; totalUsers++; }
    void addUser(Seller s) { if(sellerCount<10) sellers[sellerCount++] = s; totalUsers++; }
    void addUser(Admin a) { if(adminCount<5) admins[adminCount++] = a; totalUsers++; }

    void addListing(Listing l) { if(listingCount<20) listings[listingCount++] = l; }
    void searchListings(string brand, int year, double maxPrice) {
        for(int i=0;i<listingCount;i++) {
            if(listings[i].matchesFilter(brand, year, maxPrice)) listings[i].display();
        }
    }
};
int Marketplace::totalUsers = 0;

int main() {
    Car c1("Toyota", "Corolla", 2020, 20000, 15000);
    Car c2("Honda", "Civic", 2019, 18000, 20000);

    Seller s1(1, "Ali", "0300-1234567", "ali@gmail.com");
    s1.addListing(c1);
    s1.addListing(c2);

    Buyer b1(1, "Marium", "0300-7654321", "marium@gmail.com");
    b1.addFavorite(c1);
    b1.sendMessage("Is the car still available?");

    Admin a1(1, "Admin1", "admin@gmail.com", "SuperAdmin");
    a1.approveListing(c1);

    Listing l1(101, c1, &s1, "2026-02-28");

    Marketplace mp("PakWheels Clone");
    mp.addUser(s1);
    mp.addUser(b1);
    mp.addUser(a1);
    mp.addListing(l1);

    cout << "---- Seller Listings ----" << endl;
    s1.viewListings();

    cout << "---- Buyer Favorites ----" << endl;
    b1.viewFavorites();

    cout << "---- Admin Reports ----" << endl;
    a1.viewReports();

    cout << "Total Cars: " << Car::totalCars << endl;
    cout << "Total Users: " << Marketplace::totalUsers << endl;

    return 0;
}
