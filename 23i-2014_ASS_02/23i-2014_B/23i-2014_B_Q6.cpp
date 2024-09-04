#include <iostream>
using namespace std;

class Car{
private:
    double fuelEfficiency;
    double fuelLevel;       

public:
   
    Car();
    Car(double fuelEfficiency, double fuelLevel);

    void drive(double distance);

    // Get the current fuel level
    double getFuelLevel() const;

    // Fill up the gas tank
    void tank(double fuel);
};

Car::Car(){
    fuelEfficiency = 0;
    fuelLevel = 0;
}

Car::Car(double fuelEfficiency, double fuelLevel){
    this->fuelEfficiency = fuelEfficiency;
    this->fuelLevel = fuelLevel;
}

void Car::drive(double distance){
        
        double fuelConsumed = distance / fuelEfficiency;

        if(fuelConsumed<=fuelLevel){
            
            fuelLevel -= fuelConsumed;
            cout<<"\n CAR DRVEN FOR  [ "<<distance<<" ]  MILES. FUEL CONSUMED ::  [ "<<fuelConsumed<<" ] GALLONS. \n";
        } else {
            cout<<"\n NOT ENOUGH FUEL TO COVER THE DISTANCE.\n";
        }
    }

// Fill up the gas tank
void Car::tank(double fuel){
    fuelLevel += fuel;
}

// Get the current fuel level
double Car::getFuelLevel() const{
    return fuelLevel;
}

int main() {
    
    double efficiency;
    int fuel_level;

    cout<<"\n ENTER THE CALL FUELS LEVEL (miles per gallon or liters per km) :: ";
    cin>>efficiency;

    cout<<"\n ENTER THE CURRENT FUEL LEVEL (liters) :: ";
    cin>>fuel_level;

    Car myCar(efficiency, fuel_level);

    double distance;
    cout<<"\n ENTER THE DISTANCE DRIVEN  =  ";
    cin>>distance;

    myCar.drive(distance);      // set the distance.

    double fuelToTank;
    cout<<"\n ENTER THE FUEL AMOUNT TO REFILL THE TANK = ";     // Get the fuel amount to tank up from the user 
    cin>>fuelToTank;

    myCar.tank(fuelToTank);         // REFUELL THE TANK.

    
    cout<<"\n FUEL AFTER REFILLING THE TANK  = [ "<<myCar.getFuelLevel()<<" ] GALLONS\n";

    return 0;
}
