#include<bits/stdc++.h>
using namespace std;

class Car{
    string model;
    double fuelLevel;
    int year;
    int speed;
    bool isRunning;

    public:
    Car(){
        model = "Unknown Model";
        fuelLevel = 0;
        year = 2024;
        speed = 0;
        isRunning = false;
    }

    Car(string model,int year,int fuelLevel=0,int speed=0,bool isRunning=false){
        cout<<this<<endl;
        this->model = model;
        this->year = year;
        this->fuelLevel = fuelLevel;
        this->speed = speed;
        (*this).isRunning = isRunning;
    }

    void startEngine(){
        if(this->isRunning){
            cout<<"Car "<<this->model<< " already running at speed "<<this->speed<<endl;
        }
        else{
            this->isRunning = true;
            cout<<"Car "<<this->model<< " engine started "<<endl;
        }
    }

    void stopEngine(){
        if(!this->isRunning){
            cout<<"Car "<<this->model<< " is already not running !"<<endl;
        }
        else{
            this->isRunning = false;
            this->speed = 0;
            cout<<"Car "<<this->model<< " engine stopped "<<endl;
        }
    }

    void accelerate(int amount){
        if(this->isRunning == false){
            cout<<"Car engine is not running !!"<<endl;
            return;
        }

        if(amount>100){
            cout<<"Acceleration not possible"<<endl;
        }
        else{
            if(amount > (this->fuelLevel)){
                cout<<"Not enough fuel.\tCan go maximum to-"<<int(this->speed+this->fuelLevel)<<endl;
            }
            else{
                this->speed += amount;
                this->fuelLevel -= amount;
                cout<<"Car "<<this->model<<" accelerated by "<<amount<<". Current speed- "<<this->speed<<" Fuel- "<<this->fuelLevel<<endl;
            }
        }  
    }
    
    void brake(int amount){
        if(!this->isRunning){
            cout<<"Car engine is not running !!"<<endl;
            return;
        }

        this->speed -= min(amount,this->speed);
        cout<<"Car speed reduced to "<<this->speed<<endl;
    }

    void refuel(int amount){
            this->fuelLevel += min(100-int(this->fuelLevel),amount);
            cout<<"ReFueled to fuel level "<<this->fuelLevel<<endl;
    }
    
    void printStatus(){
        cout<<"Status - \n";
        cout<<"Car model- "<<this->model<<endl;
        cout<<"Fuel- "<<this->fuelLevel<<endl;
        cout<<(this->isRunning ? "Running" : "Not Running")<<endl;
        if(this->isRunning)
        cout<<"Speed - "<<this->speed;
    }


};

int main(){
    Car c1("omni",1994,100);
    c1.startEngine();
    c1.accelerate(50);
    c1.accelerate(28);
    c1.stopEngine();
    c1.printStatus();
    c1.startEngine();
    c1.accelerate(99);
    c1.refuel(70);
    c1.brake(20);
    c1.startEngine();
    c1.accelerate(70);
    c1.brake(15);
    c1.printStatus();

}