#pragma once

class Constants {
public:
	static constexpr double kMaxGoalTrackAge = 0.3;
	static constexpr double kMaxTrackerDistance = 18.0;
	static constexpr double kCameraFrameRate = 30.0;
	static constexpr double kStabilityWeight = 0.5;
	static constexpr double kAgeWeight = 1.0;
	static constexpr double kSwitchingWeight = 3.0;
	static constexpr double kTrackScrubFactor = 0.5;
	static constexpr double kTrackLengthInches = 8.265;
	static constexpr double kTrackWidthInches = 23.8;
	static constexpr double kTrackEffectiveDiameter = (kTrackWidthInches * kTrackWidthInches + kTrackLengthInches * kTrackLengthInches) / kTrackWidthInches;
	static constexpr double kCameraPitchAngleDegrees = -20;
	static constexpr double kCameraYawAngleDegrees = 0.0;
	static constexpr double kCenterOfTargetHeight = 13;
	static constexpr double kCameraZOffset = 19;
	static constexpr double kCameraXOffset = 13;
	static constexpr double kCameraYOffset = 0.0; //Maybe Wrong
	static constexpr double kTurretXOffset = -7.376; //Probably Wrong
	static constexpr double kTurretYOffset = 0.0; //Maybe Wrong
	static constexpr double kTurretAngleOffsetDegrees = 0.0;
	static constexpr double kAutoAimPredictionTime = 0.25;
	static constexpr double kCameraDeadBand = 0.0;
	static constexpr double kGearYPosThreshold = 20.0; //tune
	static constexpr double kGearCameraWidth = 3000; //tune
	static constexpr double kBoilerYPosThreshold = 20.0; //tune
	static constexpr double kBoilerZPosThreshold = 100.0; //tune

};
	
