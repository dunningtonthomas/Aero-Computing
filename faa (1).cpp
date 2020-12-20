#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    //creating arrays for airport name, and the flight operations
    string portName[30];        
    string staticPortName[30];
    int tenYearAverage[30];
    int fy17[30];
    int fy18[30];
    double increasePercent[30];
    
    //opening the file
    ifstream airFile;                   
    airFile.open("AirTraffic.txt");
    
    //checks if file is open
    if (!airFile.is_open())             
    {
        cout << "ERROR" << endl;
        return 1;
    }
    
    //reading in the file and putting data in arrays
    for (int i = 0; i < 30; i++)        
    {
        airFile >> portName[i];
        staticPortName[i] = portName[i];
        airFile >> tenYearAverage[i];
        airFile >> fy17[i];
        airFile >> fy18[i];
    }
    
    //outputting values before sorting
    cout << "Average airport operation data before sorting" << endl;        
    for (int i = 0; i < 30; i++)
    {
        cout << portName[i] << " " << tenYearAverage[i] << endl;
    }
    
    
    //starting nested for loop for sorting
    for (int i = 0; i < 30; i++)        
    {
        for (int j = 0; j < 29; j++)
        {
            if (tenYearAverage[j] > tenYearAverage[j+1])
            {
                //checks if number is greater than the next index, swaps if it is true
                int temp;                                       
                temp = tenYearAverage[j];
                tenYearAverage[j] = tenYearAverage[j+1];
                tenYearAverage[j+1] = temp;
                
                string tempString;
                tempString = portName[j];
                portName[j] = portName[j+1];
                portName[j+1] = tempString;
                
                int temp2;
                temp2 = fy17[j];
                fy17[j] = fy17[j+1];
                fy17[j+1] = temp2;
                
                int temp3;
                temp3 = fy18[j];
                fy18[j] = fy18[j+1];
                fy18[j+1] = temp3;
            }
        }
    }
    
    //outputs the sorted ports and operations
    cout << "Average airport operation data after sorting" << endl;     
    for (int i = 0; i < 30; i++)
    {
        cout << portName[i] << " " << tenYearAverage[i] << endl;
    }
    
    //checks if the operations rose above the average for both 2017 and 2018
    for (int i = 0; i < 30; i++)
    {
        if ((fy17[i] > tenYearAverage[i]) && (fy18[i] > tenYearAverage[i]))
        {
            cout << portName[i] << " airport operation rose above average in FY17-18" << endl;
        }
    }
    
    airFile.close();
    
    return 0;
}