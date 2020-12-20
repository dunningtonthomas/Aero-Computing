#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "coord.h"

using namespace std;

int main()
{
    //Creating two objects of class Coords for both satellites, they are arrays of the length of all the positions
    Coord sat1[1441];
    Coord sat2[1441];
    
    
    //Creating Objects for the files of the positions
    ifstream groundFile;
    groundFile.open("GSPosition.csv");
    
    ifstream sat1File;
    sat1File.open("Sat1Position.csv");
    
    ifstream sat2File;
    sat2File.open("Sat2Position.csv");
    
    
    //Reads in the data for each position
    for(int i = 0; i < 1441; i++)
    {
        string xPosition, yPosition, zPosition, xS1Position, yS1Position, zS1Position, xS2Position, yS2Position, zS2Position;
        
        //Using getline to get the x y and z positions
        getline(groundFile, xPosition, ',');
        getline(groundFile, yPosition, ',');
        getline(groundFile, zPosition, '\n');
        
        //Converting string to a double
        double xG = stod(xPosition);
        double yG = stod(yPosition);
        double zG = stod(zPosition);
        
        getline(sat1File, xS1Position, ',');
        getline(sat1File, yS1Position, ',');
        getline(sat1File, zS1Position, '\n');
        
        double xS1 = stod(xS1Position);
        double yS1 = stod(yS1Position);
        double zS1 = stod(zS1Position);
        
        getline(sat2File, xS2Position, ',');
        getline(sat2File, yS2Position, ',');
        getline(sat2File, zS2Position, '\n');
        
        double xS2 = stod(xS2Position);
        double yS2 = stod(yS2Position);
        double zS2 = stod(zS2Position);
        
        //Calling member function to set point and determine if visibility is true or false
        sat1[i].setPoint(xG, yG, zG, xS1, yS1, zS1);
        sat1[i].setFlag();
        
        sat2[i].setPoint(xG, yG, zG, xS2, yS2, zS2);
        sat2[i].setFlag();
        
    }

    
    //Creating output object to write to file for the visibility
    ofstream sat1OutFile;
    sat1OutFile.open("Sat1Visibility.csv");
    
    //Using for loop to output the boolean values
    for (int i = 0; i < 1441; i++)
    {
        sat1OutFile << sat1[i].getFlag() << endl;
    }
    
    ofstream sat2OutFile;
    sat2OutFile.open("Sat2Visibility.csv");
    
    for (int i = 0; i < 1441; i++)
    {
        sat2OutFile << sat2[i].getFlag() << endl;
    }
    
    //Closing all the files
    groundFile.close();
    sat1File.close();
    sat2File.close();
    sat1OutFile.close();
    sat2OutFile.close();
    return 0;
}