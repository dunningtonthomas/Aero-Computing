#include <iostream> 

class Coord {
  public:
    void setPoint(double , double , double , double , double , double);
    void setFlag();
    bool getFlag();
  private:
    double xGround;
    double yGround;
    double zGround;
    double xSat;
    double ySat;
    double zSat;
    double maskingAngle;
    bool flagpoint;
};