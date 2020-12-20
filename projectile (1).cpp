#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//global variables
const double airDensity = 1.275;
const double mass = 50.0;
const double dragCoefficient = 0.5;
const double gravity = 9.81;
const double pi = 3.141592653589793;
const double crossArea = ((pi) * pow(0.25, 2));

//used later in program so if statement only runs once
bool temp = false;

//prototype functions
double Fx(double vx, double vy);
double Fy(double vx, double vy);
double euler(double &t, double &x, double y, double vx, double vy, double DT);

int main()
{
    //given quantities, velocity, height, and time step
    double vx = (10 * cos((pi / 4)));
    double vy = (10 * sin((pi / 4)));
    double t = 0;
    double y = 1;
    double x = 0;
    double DT = 0.01;
    double peakHeight;
    
    //output to console
    cout << "Initial speed (m/s): 10" << endl;
    cout << "Initial angle (deg): 45" << endl;
    cout << "Initial height (m): 1" << endl;
    cout << "Time step (sec): 0.01" << endl;
    
    //calling euler function, t and x by reference, and the peak height by value
    peakHeight = euler(t, x, y, vx, vy, DT);
    
    cout << "Peak height (m): " << peakHeight << endl;
    cout << "Range (m): " << x << endl;
    cout << "Travel time (sec): " << t << endl;
    
    return 0;
}

//defintion of functions
double Fx(double vx, double vy)
{
    //calculating the rate of change of the x velocity
    double i;
    i = ((((-0.5) * airDensity * dragCoefficient * crossArea) * (pow(vx, 2) + pow(vy, 2)) * (cos(atan2(vy, vx)))) / mass);
    return i;
}

double Fy(double vx, double vy)
{
    //calculating the rate of change of the y velocity
    double i;
    i = (((((-0.5) * airDensity * dragCoefficient * crossArea) * (pow(vx, 2) + pow(vy, 2)) * (sin(atan2(vy, vx)))) / mass) - gravity);
    return i;
}

double euler(double &t, double &x, double y, double vx, double vy, double DT)
{
    //euler function uses the velocity to approximate the location of the projectile
    double peakHeight;
    
    do
    {
    
    //time
    t = t + DT;
    
    if ((vy < 0) && (!temp))
    {
        peakHeight = y;
        temp = true;
    }
    
    //y height
    y = y + (vy * DT);
    
    //x range
    x = x + (vx * DT);
    
    //x velocity updated by calling the Fx funtion
    vx = vx + ((Fx(vx, vy)) * DT);
    
    //y velocity updated by calling the Fy funtion
    vy = vy + ((Fy(vx, vy)) * DT);
    
    } while (y > 0);
    
    return peakHeight;
}
