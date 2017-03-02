#include "PathPlanner.h"
#include <cmath>
#include <vector>

#include <iostream>

using namespace std;

PathPlanner::PathPlanner()
{
    this->origPath = new vector<vector<double>*>();

    this->pathAlpha = 0.7;
    this->pathBeta = 0.3;
    this->pathTolerance = 0.0000001;
    this->gradientDescentEscape = 100;

    this->smoothPath = new vector<vector<double>*>();
    this->leftLowerPath = new vector<double*>();
    this->rightLowerPath = new vector<double*>();
    this->leftUpperPath = new vector<double*>();
    this->rightUpperPath = new vector<double*>();
}

PathPlanner::~PathPlanner()
{
    for(int i=0;i<this->origPath->size();i++)
    {
        delete this->origPath->operator[](i);
    }
    delete this->origPath;

    for(int i=0;i<this->smoothPath->size();i++)
    {
      delete this->smoothPath->operator[](i);
      delete this->leftLowerPath->operator[](i);
      delete this->rightLowerPath->operator[](i);
      delete this->leftUpperPath->operator[](i);
      delete this->rightUpperPath->operator[](i);
    }

    delete this->smoothPath;
    delete this->leftLowerPath;
    delete this->rightLowerPath;
    delete this->leftUpperPath;
    delete this->rightUpperPath;
}

vector<vector<double>*>* PathPlanner::doubleArrayCopy(vector<vector<double>*>* arr)
{
    vector<vector<double>*>* temp = new vector<vector<double>*>(arr->size());
    for(int i=0;i<arr->size();i++)
    {
        temp->operator[](i) = new vector<double>(arr->operator[](i)->size());
        for(int j=0;j<arr->operator[](i)->size();j++)
        {
	    temp->operator[](i)->operator[](j) = arr->operator[](i)->operator[](j);
        }
    }
    return temp;
}

void PathPlanner::doubleArrayDelete(vector<vector<double>*>* arr)
{
    for(int i=0;i<arr->size();i++)
        delete arr->operator[](i);
    delete arr;
}

vector<vector<double>*>* PathPlanner::inject(vector<vector<double>*>* orig, int numToInject)
{
    //cout << "    Constructing morePoints, numToInject=" << numToInject << endl;
    int temp = orig->size() + ((numToInject)*(orig->size()-1));
    vector<vector<double>*>* morePoints = new vector<vector<double>*>(temp);
    for(int q=0;q<temp;q++)
        morePoints->operator[](q) = new vector<double>(3);

    int index = 0;
    for(int i=0;i<orig->size()-1;i++)
    {
        morePoints->operator[](index)->operator[](0) = orig->operator[](i)->operator[](0);
        morePoints->operator[](index)->operator[](1) = orig->operator[](i)->operator[](1);
        morePoints->operator[](index)->operator[](2) = orig->operator[](i)->operator[](2);
        index++;

        for(int j=1;j<numToInject+1;j++)
        {
	    //cout << "    Iterating idx " << i << " " << j <<  endl;
            morePoints->operator[](index)->operator[](0) = j*((orig->operator[](i+1)->operator[](0)-orig->operator[](i)->operator[](0))/(numToInject+1))+orig->operator[](i)->operator[](0);
	        morePoints->operator[](index)->operator[](1) = j*((orig->operator[](i+1)->operator[](1)-orig->operator[](i)->operator[](1))/(numToInject+1))+orig->operator[](i)->operator[](1);
            morePoints->operator[](index)->operator[](2) = j*((orig->operator[](i+1)->operator[](2)-orig->operator[](i)->operator[](2))/(numToInject+1))+orig->operator[](i)->operator[](2);
            index++;
        }
    }

    //cout << "    Copying..." << endl;
    morePoints->operator[](index)->operator[](0) = orig->operator[](orig->size()-1)->operator[](0);
    morePoints->operator[](index)->operator[](1) = orig->operator[](orig->size()-1)->operator[](1);
    morePoints->operator[](index)->operator[](2) = orig->operator[](orig->size()-1)->operator[](2);

    doubleArrayDelete(orig);
    return morePoints;
}

vector<vector<double>*>* PathPlanner::smoother(vector<vector<double>*>* path, double weight_data, double weight_smooth, double tolerance)
{
    vector<vector<double>*>* newPath = doubleArrayCopy(path);

    double change = tolerance;
    int loopCount = 0;
    while(change >= tolerance)
    {
        if(loopCount > this->gradientDescentEscape)
            break;
        change = 0.0;
        for(int i=1;i<path->size()-1;i++)
        {
            for(int j=0;j<path->operator[](i)->size();j++)
            {
                double aux = newPath->operator[](i)->operator[](j);
                newPath->operator[](i)->operator[](j) += weight_data * (path->operator[](i)->operator[](j) - newPath->operator[](i)->operator[](j)) + weight_smooth * (newPath->operator[](i-1)->operator[](j) + newPath->operator[](i+1)->operator[](j) - (2.0 * newPath->operator[](i)->operator[](j))); 
                change += abs(aux - newPath->operator[](i)->operator[](j));
            }
        }
        loopCount += 1;
    }
    if(loopCount > this->gradientDescentEscape)
    {
        cout << "DEBUG: PathPlanner.smoother() did not converge." << endl;
	doubleArrayDelete(newPath);
	newPath = doubleArrayCopy(path);
    }
    doubleArrayDelete(path);
    return newPath;
}

int* PathPlanner::injectionCounter2Steps(double numNodeOnlyPoints, double maxTimeToComplete, double timeStep)
{
    int first = 0;
    int second = 0;
    int third = 0;

    double oldPointsTotal = 0;

    int* ret = new int(3);

    double totalPoints = maxTimeToComplete/timeStep;

    if(totalPoints < 100)
    {
        double pointsFirst;
        double pointsTotal;

        for(int i=4;i<=6;i++)
        {
            for(int j=1;j<=8;j++)
            {
                pointsFirst = i*(numNodeOnlyPoints-1) + numNodeOnlyPoints;
                pointsTotal = (j*(pointsFirst-1)+pointsFirst);

                if(pointsTotal<=totalPoints && pointsTotal>oldPointsTotal)
                {
                    first = i;
                    second = j;
                    oldPointsTotal = pointsTotal;
                }
            }
        }
    }
    else
    {
        double pointsFirst;
        double pointsSecond;
        double pointsTotal;

        for (int i=1; i<=5; i++)
        {
            for (int j=1; j<=8; j++)
            {
                for (int k=1; k<8; k++)
                {
                    pointsFirst = i *(numNodeOnlyPoints-1) + numNodeOnlyPoints;
                    pointsSecond = (j*(pointsFirst-1)+pointsFirst);
                    pointsTotal =  (k*(pointsSecond-1)+pointsSecond);

                    if(pointsTotal<=totalPoints)
                    {
                        first=i;
                        second=j;
                        third=k;
                    }
                }
            }
        }
    }

    ret[0] = first;
    ret[1] = second;
    ret[2] = third;
    return ret;
}

void PathPlanner::Paths(vector<vector<double>*>* smoothPath, double robotTrackWidth, double robotTrackLength)
{
    this->leftLowerPath->resize(this->smoothPath->size());
    this->rightUpperPath->resize(this->smoothPath->size());
    this->leftUpperPath->resize(this->smoothPath->size());
    this->rightLowerPath->resize(this->smoothPath->size());

    for(int i=0;i<smoothPath->size();i++)
    {
        //cout << smoothPath->operator[](i)->operator[](0) << " " << smoothPath->operator[](i)->operator[](1) << " " << smoothPath->operator[](i)->operator[](2) << endl;
        this->leftLowerPath->operator[](i) = new double[2];
        this->rightLowerPath->operator[](i) = new double[2];
        this->leftUpperPath->operator[](i) = new double[2];
        this->rightUpperPath->operator[](i) = new double[2];

        double angInDeg = smoothPath->operator[](i)->operator[](2);
        smoothPath->operator[](i)->operator[](2) *= M_PI/180.0;

        this->leftLowerPath->operator[](i)[0] = -(robotTrackWidth / 2 * cos(smoothPath->operator[](i)->operator[](2) - M_PI / 2)) - (robotTrackLength / 2 * sin(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](0);
        this->leftLowerPath->operator[](i)[1] = -(robotTrackWidth / 2 * sin(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) - (robotTrackLength / 2 * cos(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](1);

        this->rightUpperPath->operator[](i)[0] = (robotTrackWidth / 2 * cos(smoothPath->operator[](i)->operator[](2) - M_PI / 2)) + (robotTrackLength / 2 * sin(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](0);
        this->rightUpperPath->operator[](i)[1] = (robotTrackWidth / 2 * sin(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + (robotTrackLength / 2 * cos(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](1);

        this->leftUpperPath->operator[](i)[0] = -(robotTrackWidth / 2 * cos(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) - (robotTrackLength / 2 * sin(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](0);
        this->leftUpperPath->operator[](i)[1] = -(robotTrackWidth / 2 * sin(smoothPath->operator[](i)->operator[](2) - M_PI / 2)) - (robotTrackLength / 2 * cos(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](1);

        this->rightLowerPath->operator[](i)[0] = (robotTrackWidth / 2 * cos(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + (robotTrackLength / 2 * sin(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](0);
        this->rightLowerPath->operator[](i)[1] = (robotTrackWidth / 2 * sin(smoothPath->operator[](i)->operator[](2) - M_PI / 2)) + (robotTrackLength / 2 * cos(smoothPath->operator[](i)->operator[](2) + M_PI / 2)) + smoothPath->operator[](i)->operator[](1);

        smoothPath->operator[](i)->operator[](2) = angInDeg;
    }
}

double PathPlanner::distance(vector<vector<double>*>* path)
{
    double distance = 0.0;
    for(int i=0;i<path->size()-1;i++)
    {
        double dx = path->operator[](i+1)->operator[](0) - path->operator[](i)->operator[](0);
        double dy = path->operator[](i+1)->operator[](1) - path->operator[](i)->operator[](1);

        distance += sqrt(dx*dx + dy*dy);
    }
    return distance;
}
void PathPlanner::calculate(double totalTime, double timeStep, double robotTrackWidth, double robotTrackLength, double maxA)
{
    //cout << "Beginning calculate()" << endl;
    int* toInject = injectionCounter2Steps(origPath->size(), totalTime, timeStep);
    //cout << "Finished finding number to inject." << endl;

    delete smoothPath;
    smoothPath = doubleArrayCopy(origPath);
    for(int i=0;i<3;i++)
    {
        smoothPath = inject(smoothPath, toInject[i]);
        smoothPath = smoother(smoothPath, pathAlpha, pathBeta, pathTolerance);
    }

    //cout << "Generating individual paths" << endl;
    Paths(smoothPath, robotTrackWidth, robotTrackLength);

    delete toInject;
}

void PathPlanner::addWaypoint(double x, double y, double heading)
{
    this->origPath->push_back(new vector<double>());
    int idx = this->origPath->size()-1;
    this->origPath->operator[](idx)->push_back(x);
    this->origPath->operator[](idx)->push_back(y);
    this->origPath->operator[](idx)->push_back(heading);
}

double PathPlanner::estimateTime(double Vmax, double a)
{
    double dist = distance(this->origPath);
    double total_time;
    double ad_dist = (Vmax*Vmax)/a;
    if(ad_dist < dist)
    {
        //Trapezoidal, do cruise
        total_time = 2*(Vmax/a) + ((dist-ad_dist)/Vmax);
    }
    else
    {
        //Triangular
        total_time = 2*sqrt(dist/a);
    }
    return total_time;
}
