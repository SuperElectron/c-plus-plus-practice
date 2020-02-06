#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

// ---------- DEFINE PET CLASS----------
class Pet{
// Private variables are only available to methods in the class
private:
    std::string name;
    double height;
    double weight;

    // Static variables share the same value for all objects of the Pet class
    static int numOfPet;

// Public fields and methods can be accessed by anything with access to the object
public:
    // Because (1) object name is undefined
    // and     (2) class is instantiated before the object
    // we can refer to all objects using this-> to access an objects fields and methods
    void SetName(std::string name){this->name = name;}
    double GetHeight(){return height;}
    void SetHeight(double height){this->height = height;}
    double GetWeight(){return weight;}
    void SetWeight(double weight){this->weight = weight;}
    std::string GetName(){return name;}

    // Static methods are not bound to instance of a single class
    static int GetNumOfPet(){return numOfPet;}

    // Declare constructor, overloaded constructor (no data passed), and destructor
    Pet(std::string, double, double);
    Pet();
    ~Pet();

    // Declare function prototypes
    void SetAll(std::string, double, double);
    void ToString();
};

// ---------- DEFINE PET METHODS & ATTRIBUTES ----------
int Pet::numOfPet = 0;

void Pet::SetAll(std::string name, double height, double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Pet::numOfPet++;
}

Pet::Pet(std::string name, double height, double weight){
    this->name = name;
    this->weight = weight;
    this->height = height;
    Pet::numOfPet++;
}

Pet::Pet(){
    this->name = "";
    this->weight = 0;
    this->height = 0;
    Pet::numOfPet++;
}

Pet::~Pet(){
    std::cout << "Pet " << this -> name <<
              " destroyed\n";
}

void Pet::ToString(){
    std::cout << this -> name << " is " <<
              this -> height <<
              " cms tall and " << this -> weight <<
              " kgs in weight\n";
}

// ---------- DEFINE DOG CLASS----------
class Dog: public Pet{
private:
    std::string sound = "Wooof";

public:
    void MakeSound(){
        std::cout << "The dog " << this->GetName() << " says " << this->sound << "\n";
    }

    // The Dogs constructor
    Dog(std::string, double, double, std::string);

    // Call overloaded parent constructor for default case
    Dog(): Pet(){};

    void ToString();

};

// ---------- DEFINE DOG METHODS & ATTRIBUTES ----------
Dog::Dog(std::string name, double height, double weight, std::string sound) : Pet(name, height, weight){
    this -> sound = sound;
}

void Dog::ToString(){
    // retrieve private attributes in Pet by calling the get methods
    std::cout << this -> GetName() << " is " << this -> GetHeight() << " cms tall, " << this -> GetWeight() <<
              " kgs in weight and says " << this -> sound << "\n";
}

// ---------- MAIN PROGRAM ----------
int main()
{
    // Create object without setting values in constructor
    Pet clifford;
    clifford.SetHeight(33);
    clifford.SetWeight(10);
    clifford.SetName("Clifford");
    // Get the values for the Pet
    clifford.ToString();

    clifford.SetAll("Clifford", 34, 12);

    clifford.ToString();

    // Setting values with constructor
    Pet tom("Tom", 36, 15);
    tom.ToString();

    // Demonstrate inherited Dog class
    Dog spot("Spot", 38, 16, "Wooof");

    // See different output from overwritten ToString()
    spot.ToString();

    // Call static methods by using the class name to show the total Pet created
    std::cout << "Number of Pet " << Pet::GetNumOfPet() << "\n";

    return 0;
}

// ---------- END INTRO TO CLASSES & INHERITANCE ----------