#pragma once

class Constants {
public:
	static constexpr double kMaxGoalTrackAge = 0.3;
	static constexpr double kMaxTrackerDistance = 18.0;
	static constexpr double kCameraFrameRate = 30.0;
	static constexpr double kStabilityWeight = 1.0;
	static constexpr double kAgeWeight = 1.0;
	static constexpr double kSwitchingWeight = 3.0;
};
	