#include "PathPlanner.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}

int main(void)
{
    //Camera stuff
    double angle = 15.0;
    double skew = 35.0;
    double dist = 39.0;
    double dx = dist*sin(skew*M_PI/180.0);
    double dy = dist*cos(skew*M_PI/180.0);
    double alpha = skew-angle;

    //Pathing parameters
    //double totalTime = 1.5; //seconds
    double timeStep = .01; //period of control loop on Rio, seconds
    double robotTrackWidth = 23; //distance between left and right wheels, inches
    double robotTrackLength = 23;
    double maxAcceleration = 72;

    PathPlanner p;
    p.addWaypoint(50, 20, alpha);
    p.addWaypoint(50+dx, 20+dy-18, 0);
    p.addWaypoint(50+dx, 20+dy, 0);
    double totalTime = p.estimateTime(60, 45);

    //Using these functions for timing requires compiling with -lrt.  If speed profiling is unneeded, comment out
    timespec time1, time2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    p.calculate(totalTime, timeStep, robotTrackWidth, robotTrackLength, maxAcceleration);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);

    for(int i=0;i<p.leftUpperPath->size();i++)
    {
        cout << "(" << p.smoothPath->at(i)->at(0) << "," << p.smoothPath->at(i)->at(1) << ") ";
        cout << "(" << p.leftUpperPath->at(i)[0] << "," << p.leftUpperPath->at(i)[1] << ") ";
	cout << "(" << p.rightUpperPath->at(i)[0] << "," << p.rightUpperPath->at(i)[1] << ") ";
	cout << "(" << p.leftLowerPath->at(i)[0] << "," << p.leftLowerPath->at(i)[1] << ") ";
	cout << "(" << p.rightLowerPath->at(i)[0] << "," << p.rightLowerPath->at(i)[1] << ")" << endl;
    }

    cout << "DEBUG: time to execute path is " << totalTime << " seconds" << endl;
    cout << "DEBUG: execution time  is " << diff(time1, time2).tv_nsec/1000000.0 << " ms." << endl;
}
