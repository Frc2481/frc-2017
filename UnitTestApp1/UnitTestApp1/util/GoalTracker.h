#pragma once
#include "util/Translation2D.h"
#include "util/GoalTrack.h"

class GoalTracker {
public:
	class TrackReport {
	public:
		Translation2D m_fieldToGoal;
		double m_latestTimestamp;
		double m_stability;
		int m_id;
		double m_LastTrackId;
		double m_CurrentTimestamp;
		TrackReport(const GoalTrack &track);
		double score() const;
		friend bool operator<(const TrackReport &lhs, const TrackReport &rhs);
	};
private:
	std::list<GoalTrack> m_currentTracks;
	int m_nextId = 0;
public:
	GoalTracker();
	void reset();
	void update(double timestamp, std::list<Translation2D> &fieldToGoals);
	bool hasTracks();
	std::list<TrackReport> getTracks();
};