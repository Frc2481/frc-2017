#ifndef PATHPLANNER_H_
#define PATHPLANNER_H_

#include <vector>

using namespace std;

class PathPlanner {
private:
  
    vector<vector<double>*>* origPath;

    double time;
    double pathAlpha;
    double pathBeta;
    double pathTolerance;
    double gradientDescentEscape;
    
    vector<vector<double>*>* doubleArrayCopy(vector<vector<double>*>* arr);
    void doubleArrayDelete(vector<vector<double>*>* arr);
    vector<vector<double>*>* inject(vector<vector<double>*>* orig, int numToInject);
    vector<vector<double>*>* smoother(vector<vector<double>*>* path, double weight_data, double weight_smooth, double tolerance);
    int* injectionCounter2Steps(double numNodeOnlyPoints, double maxTimeToComplete, double timeStep);
    void Paths(vector<vector<double>*>* smoothPath, double robotTrackWidth, double robotTrackLength);
    void computeMotionProfile(vector<vector<double>*>* path, double maxA, double dt);
    double distance(vector<vector<double>*>* path);
    
public:
    vector<vector<double>*>* smoothPath;
    vector<double*>* leftUpperPath;
    vector<double*>* rightUpperPath;
    vector<double*>* leftLowerPath;
    vector<double*>* rightLowerPath;

    vector<double>* acceleration;
    vector<double>* velocity;
    vector<double>* position;

    PathPlanner();
    ~PathPlanner();
    void calculate(double totalTime, double timeStep, double robotTrackWidth, double robotTrackLength, double maxA);
    void addWaypoint(double x, double y, double heading);
};

#endif
