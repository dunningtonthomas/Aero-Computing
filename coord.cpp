#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "coord.h"

using namespace std;

const double pi = M_PI;

//Coord:: tells the compiler that the function is a part of the Point class

//Given inputs of the ground position and sat position, sets private member coordinates equal to inputs
void Coord::setPoint(double xG, double yG, double zG, double xS, double yS, double zS)
{
    xGround = xG;
    yGround = yG;
    zGround = zG;
    xSat = xS;
    ySat = yS;
    zSat = zS;
}

//Uses dot product to calculate angle between two vectors and determines of it is visible based on boolen > 10 degrees
void Coord::setFlag()
{
        double distanceVec[3] = {xSat - xGround, ySat - yGround, zSat - zGround};
        
        double dotProd = ((distanceVec[0] * xGround) + (distanceVec[1] * yGround) + (distanceVec[2] * zGround));
        double magnitudeDist = sqrt((distanceVec[0] * distanceVec[0]) + (distanceVec[1] * distanceVec[1]) + (distanceVec[2] * distanceVec[2]));
        double magnitudeGround = sqrt((xGround * xGround) + (yGround * yGround) + (zGround * zGround));
        
        maskingAngle = (pi / 2.0) - acos(dotProd / (magnitudeDist * magnitudeGround));
        
        double angleDeg = maskingAngle * (180.0 / pi);
        
        
        bool temp = false;
        if (angleDeg > 10.0)
        {
            temp = true;
        }
        
        flagpoint = temp;
}

//Returns the value of the boolen
bool Coord::getFlag()
{
    return flagpoint;
}