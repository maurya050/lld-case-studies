#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerator() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() =0;
        virtual ~Car() {

        }
};

class SportCar : public Car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        SportCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand <<" " << model << " Engine Started" << endl;
        }
        
        void shiftGear(int gear){

            if(!isEngineOn){
                cout << brand << " " << model << ": Engine is off!!!"<<endl;
                return;
            }
            currentGear = gear;

            cout<< brand << " "<< model << ": Shifted to gear : " << currentGear << endl;

        }
        void accelerator(){
            if(!isEngineOn){
                cout<< brand <<" " << model << ": Engine is OFF!!"<<endl;

            }
            currentSpeed += 20;
            cout<< brand <<" "<< model<< ": Acceleratiing with speed : "<< currentSpeed << endl;
        }

        void brake(){
            currentSpeed -= 20;

            if(currentSpeed < 0)
                currentSpeed = 0;
            
            cout << brand << " " << model << ": Braking , Speed is now : " << currentSpeed << endl;
        }
        void stopEngine(){

            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout << brand << " " << model << ": Engine turned off !!" << endl;
        }
};

int main(){
    Car *mycar = new SportCar("Audi", "a4");

    mycar->startEngine();
    mycar->shiftGear(1);
    mycar->accelerator();
    mycar->shiftGear(2);
    mycar->accelerator();
    mycar->brake();
    mycar->stopEngine();


    return 0;
}