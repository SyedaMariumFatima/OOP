#include <iostream>
using namespace std;
class membership{
    string type;
    double discount;
    public:
    membership(string t): type(t){
       if(t=="premium") discount=20;
       else if(t=="gold") discount=15;
       else if(t=="silver") discount=10;
    }
    double getDiscount(){return discount;}
};
class customer{
    int adults;
    int children;
    membership Membership;
    public:
    customer(int a, int c, membership M): adults(a), children(c), Membership(M){}
    int getChildren() const{return children;}
    int getAdults() const{return adults;}
    membership getMembership(){return Membership;}
    
};

class activity{
    string name;
    int price;
    public:
    activity(string n, int p):name(n),price(p){}
    string getName(){return name;}
    int getPrice(){return price;}
};
class bill{
    const int adultTicket=500;
    const int childTicket=1000;
    activity tennis, horseRiding, snowFall;
    bool tennisChosen, horseRidingChosen, snowFallChosen;
    customer Customer;
    public:
    bill(customer c): tennis("tennis", 1000), horseRiding("horse riding", 500), snowFall("snowfall play area", 1500),Customer(c), tennisChosen(false), snowFallChosen(false), horseRidingChosen(false){}
    
    void chooseActivity(string act) {
        if (act == "tennis") tennisChosen = true;
        else if (act == "horse") horseChosen = true;
        else if (act == "snowfall") snowfallChosen = true;
    }
    
     int activity_total = 0;
        if (tennisChosen) activity_total += tennis.getPrice();
        if (horseChosen) activity_total += horse.getPrice();
        if (snowfallChosen) activity_total += snowfall.getPrice();

        int gross_bill = ticket_total + activity_total;
        double discount = customer.getMembership().getDiscountRate();

        return gross_bill * (1 - discount);
    }




};
int main() {
    
    return 0;
}
