#pragma once
#include "util/Translation2D.h"

class GoalTrack {
private: 
	std::map<double, Translation2D> m_observePositions;
	Translation2D m_smoothPosition;
	int m_id;
	
public:
	GoalTrack(double timestamp, const Translation2D &firstObservation, int id);
	void pruneByTime(double timestamp);
	bool tryUpdate(double timestamp, const Translation2D &newObservation);
	bool isAlive() const;
	void smooth();
	Translation2D getSmoothedPosition() const;
	double getLatestTimestamp() const;
	double getStability() const;
	int getId() const;
};