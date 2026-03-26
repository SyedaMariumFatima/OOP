#include <iostream>
using namespace std;

class Movie{
    string name;
    int releaseYr;
    int rating;
    bool available;
    public:
    Movie(){}
    Movie(string n, int y, int r): name(n), rating(r), available(true){
        if(y<2014 || y>2021) cout<<"Release date out of scope...Movie not stored";
    }
    bool checkStatus(){return available;}
    void changeStatus(){
        if (available==true) available=false;
        else available=true;
    }
    int getYr(){return releaseYr;}
};
class Customer{
    string name;
    string type;
    int movieNum;
    double discount;
    Movie movies[5];
    int added=0;
    public:
    Customer(){}
    Customer(string n, string t, int m): name(n), type(t), movieNum(m){
        if(m>5) {
            movieNum=5;
            cout<<"Max movies a customer can buy is 5. Setting number of movies that "<<name<<"wants to buy to 5";
        }
        if(type=="premium") discount=20;
        if(type=="gold") discount=15;
        if(type=="silver") discount=10;
        else discount=0;
    }
    void addMovie(Movie &movie){
        if(added==movieNum) cout<<"You have already added the number of movies you wanted to buy";
        else if(movie.checkStatus()==false) cout<<"Movie not available";
        else{
            movies[added]=movie;
            added++;
            movie.changeStatus();
        }
    }
    double getDiscount(){return discount;}
    int getAdded(){return added;}
    Movie getmovie(int i){return movies[i];}
};

class bill{
    Customer customer;
    double total=0;
    public:
    bill(Customer c): customer(c){
        int n=customer.getAdded();
        for(int i=0; i<n; i++){
            int y=customer.getmovie(i).getYr();
            if(y==2021) total+=1000;
            else if(y>2017) total+=700;
            else total+=500;
        }
        total*=(100-customer.getDiscount());
    }
    void displayTotal(){cout<<"Total: "<<total;}
};
int main() {
    return 0;
}
