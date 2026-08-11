#include<iostream>

using namespace std;


class Burger{

    public:
        virtual void prepare() = 0;
        virtual ~Burger(){}
};


class StandardBurger : public Burger{

    public:
        void prepare() override{
            cout << "Standard Burger is getting ready!" << endl;
        }


};


class PremiumBurger : public Burger{
    public:
        void prepare() override{
            cout << "Premium Burger is getting ready!" << endl;
        }
};


class BurgerFactory{

    public:
        Burger* createBurger(string& type){
            if(type == "standard"){
                return new StandardBurger();
            }
            else if(type == "premium"){
                return new PremiumBurger();
            }
            else{
                cout << "Invalid burger type" << endl;
                return nullptr;
            }
        }
};

int main(){
    
    string Burgertype = "standard";

    BurgerFactory *factory = new BurgerFactory();

    Burger *burger = factory->createBurger(Burgertype);

    burger->prepare();

    return 0;
}