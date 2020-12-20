#include <iostream>
#include <string>

using namespace std;

//declaring variables
double resistance, current, voltage, efficiency, lossWatts;

int main(){
   
    lossWatts = 320.0;
    
    //user input for variable values
    cout << "Enter a resistance value: ";
    cin >> resistance;
    cout << "Enter a current value: ";
    cin >> current;
    cout << "Enter a voltage value: ";
    cin >> voltage;
    
    //conditional statement, error if any of the inputs are zero
    if(resistance == 0 || current == 0 || voltage == 0){
        cout << "Error: resistance, current and voltage values cannot be zero!" << endl;
        return 1;
    }
    
    //determining if the maximum efficiency condition is satisfied or not 
    if((current * current) == (lossWatts / resistance)){
        cout << "The maximum efficiency condition is met" << endl;
    } else if((current * current) > (lossWatts / resistance)){
        cout << "The load is too high" << endl;
        return 1;
    } else if((current * current) < (lossWatts / resistance)){
        cout << "The load is too low" << endl;
        return 1;
    }
    
    //calculating the maximum efficiency of the motor
    efficiency = (((voltage * current) - (2 * current * current * resistance)) / (voltage * current));
    
    //rounding the calculated value and changing it to a percentage
    efficiency += 0.005;
    int efficiencyRounded = (efficiency * 100);
    
    //output of calculated efficiency
    cout << "The efficiency is " << efficiencyRounded << "%" << endl;
    
    return 0;
}