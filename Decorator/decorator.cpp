#include <iostream>
#include <string>

using namespace std;

class Character{
public:
    virtual string getAbilities() const = 0;
    virtual ~Character(){ };
};

//Concrete Component : Basic Mario character with no power - ups
class Mario : public Character{
    string getAbilities() const override{
        return "Mario";
    }
};

//Abstract Decorator : CharacterDecorator "is-a" Character and "has-a" Character

class CharacterDecorator : public Character{

protected:
    Character *character; //wrapped component
public:
    CharacterDecorator(Character *c){
        this->character = c;
    }
};

class HeightUp : public CharacterDecorator{
public:
    HeightUp(Character *c): CharacterDecorator(c){};

    string getAbilities() const override{
        return character->getAbilities() + " with Heights";
    }
};

class GunPowerUp : public CharacterDecorator
{
public:
    GunPowerUp(Character *c) : CharacterDecorator(c) {};

    string getAbilities() const override
    {
        return character->getAbilities() + " with Gun-Power";
    }
};

class StarPowerUp : public CharacterDecorator
{
public:
    StarPowerUp(Character *c) : CharacterDecorator(c) {};

    string getAbilities() const override
    {
        return character->getAbilities() + " with Star-Power";
    }
    
    ~StarPowerUp(){
        cout << "Destroying Star - Power Up Decorator" << endl;
    }
};

int main(){
    Character *mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    mario = new HeightUp(mario);
    cout << "After HeighUp: " << mario->getAbilities() << endl;

    mario = new GunPowerUp(mario);
    cout << "After GunUp: " << mario->getAbilities() << endl;

    mario = new StarPowerUp(mario);
    cout << "After star-power: " << mario->getAbilities() << endl;

    delete mario;
    return 0;
}
