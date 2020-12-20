#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//declaring and initializing the constants given
const double AVO = 6.02214076e23;
const double BOLTZ = 1.38064852e-23;
const double MASS = (2 * 1.00784) * (1.660538921e-27);
const double SPECIFIC_HEAT = 1000.0;
//declaring variables to be used in program
int gasParticles;
double temperatureAir, temperatureGas, minimumSpeed, maximumSpeed, speedSum, heatTransfer;

//temperature function
double temperature()
{
    srand(1);
    int n;
    for(n = gasParticles; n > 0; n--)
    {
        double rn, r;
        rn = rand() * (1.0 / RAND_MAX); //random number between 0 and 1
        r = round(((maximumSpeed - minimumSpeed) * rn) + minimumSpeed); //random number between minimum and maximum speeds
        speedSum = speedSum + pow(r,2); //sum of all the random speeds
    }
    
    temperatureGas = (MASS) * (speedSum) / (3 * BOLTZ * gasParticles); //calculating temperature of the gas using the given equation
    
    return temperatureGas;
}

//heat transferred function
double heatFunction()
{
    heatTransfer = (SPECIFIC_HEAT * AVO * MASS * (temperatureAir - temperatureGas));
    return heatTransfer;
}

int main()
{
    //asking user for input
    cout << "Enter the number of particles: ";
    cin >> gasParticles;
    cout << "Enter the minimum velocity in m/s: ";
    cin >> minimumSpeed;
    cout << "Enter the maximum velocity in m/s: ";
    cin >> maximumSpeed;
    cout << "Enter the temperature of surrounding air in K: ";
    cin >> temperatureAir;
    
    temperatureGas = temperature(); //calling function for temperature of the gas
    
    cout << "The gas temperature in K: " << round(temperatureGas) << endl;
    
    if(round(temperatureGas) < temperatureAir) //starting conditional statements regarding how heat is transferred
    {
        cout << "Heat is transferred from the surrounding air to the gas" << endl;
        
        heatTransfer = heatFunction(); //calling function for heat transfer
        
        cout << "The transferred heat in J: " << round(heatTransfer) << endl;
    }
    else if(temperatureAir < round(temperatureGas))
    {
        cout << "Heat is transferred away from the gas to the surrounding air" << endl;
        
        heatTransfer = heatFunction(); //calling function for heat transfer
        
        cout << "The transferred heat in J: " << round(heatTransfer) << endl;
    }
    else
    {
        cout << "No heat transfer" << endl;
    }
    
    
    return 0;
}