//Including libraries for input output and string but also math library to make volume calculation easier
#include <iostream>                                                                         
#include <string>
#include <cmath>

using namespace std;

//Delclaring variables to be used in program
 string username;                                                                           
    double radius, density, volume;
    const double pi = 3.141592653589793;

//Creating a function for calculating the volume of a planet given its radius
double volumeFunction(double radius){                                                       
        
        return volume = 4 * pi * pow(radius, 3) / 3;
    }

//Starting main function 
int main(){
    
    //Starting coversation that asks for name, radius, and density
    cout << "Hello, my name is HAL!\n" << "What is your name?\n"; 
    cin >> username;
    cout << "Hello, " << username << ". I am glad to meet you!\n";
    cout << "Enter a radius: ";
    cin >> radius;                                                                          
    cout << "Enter a density: ";
    cin >> density;
    
    //Calling the function to calculate volume
    volume = volumeFunction(radius);                                                        
    
    //Rounding the variables up to whole numbers
    int radiusRounded = radius + 0.5;                                                       
    int densityRounded = density + 0.5;
    int volumeRounded = volume;
   
    //Final output with calculated quantities
    cout << "The radius is " << radiusRounded << "\n";
    cout << "The density is " << densityRounded << "\n";
    cout << "The volume is " << volumeRounded << "\n";
    
    return 0;
}