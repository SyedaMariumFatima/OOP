#include <iostream>
#include <string>

using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int age;
    string joiningDate;

public:
    Employee(string n, int a, string jd) : name(n), age(a), joiningDate(jd) {}
    
    virtual void displayBaseData() {
        cout << "Name: " << name << "\nAge: " << age << "\nJoining Date: " << joiningDate << endl;
    }
};

// Derived Class 1 (Hierarchical)
class Developer : virtual public Employee {
protected:
    string devRole; // frontend or backend

public:
    Developer(string n, int a, string jd, string dr) 
        : Employee(n, a, jd), devRole(dr) {}

    void displayDevRole() {
        cout << "Developer Role: " << devRole << endl;
    }
};

// Derived Class 2 (Hierarchical)
class Debugger : virtual public Employee {
protected:
    string dbgRole; // manual or auto

public:
    Debugger(string n, int a, string jd, string dr) 
        : Employee(n, a, jd), dbgRole(dr) {}

    void displayDbgRole() {
        cout << "Debugger Role: " << dbgRole << endl;
    }
};

// Multiple Inheritance (Hybrid)
class TeamLead : public Developer, public Debugger {
public:
    TeamLead(string n, int a, string jd, string devR, string dbgR)
        : Employee(n, a, jd), Developer(n, a, jd, devR), Debugger(n, a, jd, dbgR) {}

    void displayAllData() {
        displayBaseData(); // From Employee
        displayDevRole();  // From Developer
        displayDbgRole();  // From Debugger
    }
};

int main() {
    // Creating object of Team Lead only
    TeamLead lead("Alice Smith", 30, "2024-01-15", "Backend Developer", "Auto Debugger");

    cout << "--- Team Lead Details ---" << endl;
    lead.displayAllData();

    return 0;
}
