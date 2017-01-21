#include "pch.h"
#include "util/GoalTrack.h"
#include "util/Constants.h"

GoalTrack::GoalTrack(double timestamp, const Translation2D &firstObservation, int id) {
	m_observePositions.emplace(timestamp, firstObservation);
	m_smoothPosition = firstObservation;
	m_id = id;
}

void GoalTrack::pruneByTime(double timestamp) {
	double deleteBefore = timestamp - Constants::kMaxGoalTrackAge;
	for (std::map<double, Translation2D>::iterator it = m_observePositions.begin(); it != m_observePositions.end();) {
		if (it->first < deleteBefore) {
			it = m_observePositions.erase(it);
		} 
		else {
			it++;
		}
	}
	if (m_observePositions.empty()) {
		m_smoothPosition = Translation2D();
	}
	else {
		smooth();
	}
}

bool GoalTrack::tryUpdate(double timestamp, const Translation2D &newObservation) {
	if (!isAlive()) {
		return false;
	}
	double distance = m_smoothPosition.inverse().translateBy(newObservation).norm();
	if (distance < Constants::kMaxTrackerDistance) {
		m_observePositions.emplace(timestamp, newObservation);
		pruneByTime(timestamp);
		return true;
	}
	else {
		pruneByTime(timestamp);
		return false;
	}
}

bool GoalTrack::isAlive() const {
	return !m_observePositions.empty();
}

void GoalTrack::smooth() {
	if (isAlive()) {
		double x = 0;
		double y = 0;
		for (std::map<double, Translation2D>::iterator it = m_observePositions.begin(); it != m_observePositions.end(); ++it) {
			x += it->second.getX();
			y += it->second.getY();
		}
		x /= m_observePositions.size();
		y /= m_observePositions.size();
		m_smoothPosition = Translation2D(x, y);
	}
}

Translation2D GoalTrack::getSmoothedPosition() const {
	return m_smoothPosition;
}

double GoalTrack::getLatestTimestamp() const {
	if (isAlive()) {
		return m_observePositions.rbegin()->first;
	}
	return 0;
}

double GoalTrack::getStability() const {
	return min(1.0, m_observePositions.size() / (Constants::kCameraFrameRate * Constants::kMaxGoalTrackAge));
}

int GoalTrack::getId() const {
	return m_id;
}