#include <iostream>
#include <string>

using namespace std;

class Product
{

public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
        ;
    }
};

class ShoppingCart
{

private:
    vector<Product *> products;

public:
    void addProduct(Product *p){
        products.push_back(p);
    }   
    
    const vector<Product*>& getProducts(){
        return products;
    }

    double calculateTotal(){
        double total = 0;
        for(auto p : products){
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter{
    private:
    ShoppingCart *cart;

    public:
        ShoppingCartPrinter(ShoppingCart *cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout << "Shopping Cart Invoice : "<< endl;

            for(auto p : cart->getProducts()){
                cout << p->name <<" : " << p->price << endl;
            }
            cout << "Total Cost" << " : " << cart->calculateTotal() << endl;
        }
};

class ShoppingStore{
    private:
        ShoppingCart *cart;
    
    public:
        ShoppingStore(ShoppingCart *cart){
            this->cart = cart;
        }
        void saveToDB(){
            cout<< "Save to DB , Cost : " <<cart->calculateTotal() << endl;
        }
};


int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 212000));
    cart->addProduct(new Product("Mobile", 75000));
    cart->addProduct(new Product("Watch", 45000));

    ShoppingCartPrinter *printer =  new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingStore *store = new ShoppingStore(cart);
    store->saveToDB();
    return 0;
}