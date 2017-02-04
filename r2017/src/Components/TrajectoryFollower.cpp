/*
 * TrajectoryFollower.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Team2481
 */

#include "Components/TrajectoryFollower.h"
#include "Components/SwerveModule.h"
#include "CommandBase.h"


TrajectoryFollower::TrajectoryFollower() {
	// TODO Auto-generated constructor stub

}

TrajectoryFollower::~TrajectoryFollower() {
	// TODO Auto-generated destructor stub
}

TrajectoryFollower* TrajectoryFollower::GetInstance(){
	static TrajectoryFollower instance;
	return &instance;
}

void TrajectoryFollower::PeriodicUpdate() {
	//TODO: Get swerve modules
	SwerveModule *frModule = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	SwerveModule *flModule = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
	SwerveModule *brModule = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
	SwerveModule *blModule = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
	//TODO: Get current encoder ticks
	int frDistance = (frModule->GetDistance() / (4));
	int flDistance = (flModule->GetDistance() / (4));
	int brDistance = (brModule->GetDistance() / (4));
	int blDistance = (blModule->GetDistance() / (4));
	//TODO: call pathfinder api
	double flSpeed = pathfinder_follow_encoder(m_flConfig, &m_flFollower, m_flTrajectory, m_flLength, flDistance);
	double frSpeed = pathfinder_follow_encoder(m_frConfig, &m_frFollower, m_frTrajectory, m_frLength, frDistance);
	double blSpeed = pathfinder_follow_encoder(m_blConfig, &m_blFollower, m_blTrajectory, m_blLength, blDistance);
	double brSpeed = pathfinder_follow_encoder(m_brConfig, &m_brFollower, m_brTrajectory, m_brLength, brDistance);
	//TODO: set angle and speed setpoint on swerve module

	frModule->SetClosedLoopSpeed(frSpeed);
	flModule->SetClosedLoopSpeed(flSpeed);
	brModule->SetClosedLoopSpeed(brSpeed);
	blModule->SetClosedLoopSpeed(blSpeed);

	double flDesiredHeading = r2d(m_flFollower.heading);
	double frDesiredHeading = r2d(m_frFollower.heading);
	double blDesiredHeading = r2d(m_blFollower.heading);
	double brDesiredHeading = r2d(m_brFollower.heading);

	frModule->SetAngle(frDesiredHeading);
	flModule->SetAngle(flDesiredHeading);
	brModule->SetAngle(brDesiredHeading);
	blModule->SetAngle(blDesiredHeading);

}

void TrajectoryFollower::SetTrajectories(Segment* frSegment, Segment* flSegment,
		Segment* brSegment, Segment* blSegment) {
	m_frTrajectory = frSegment;
	m_flTrajectory = flSegment;
	m_brTrajectory = brSegment;
	m_blTrajectory = blSegment;
}

//Always reset DriveTrain encoders before using reset
void TrajectoryFollower::Reset() {
	m_frTrajectory = 0;
	m_flTrajectory = 0;
	m_brTrajectory = 0;
	m_blTrajectory = 0;

	SetEncoderConfig(0,m_flConfig.ticks_per_revolution,m_flConfig.wheel_circumference, m_flConfig.kp, m_flConfig.ki, m_flConfig.kd,
			m_flConfig.kv, m_flConfig.ka);
}

void TrajectoryFollower::SetEncoderConfig(int initPos, int ticksPerRev,
		double wheelCircum, double p, double i, double d, double v, double a) {
	m_flConfig.initial_position = initPos;
	m_flConfig.ticks_per_revolution = ticksPerRev;
	m_flConfig.wheel_circumference = wheelCircum;
	m_flConfig.kp = p;
	m_flConfig.ki = i;
	m_flConfig.kd = d;
	m_flConfig.kv = v;
	m_flConfig.ka = a;

	m_frConfig.initial_position = initPos;
	m_frConfig.ticks_per_revolution = ticksPerRev;
	m_frConfig.wheel_circumference = wheelCircum;
	m_frConfig.kp = p;
	m_frConfig.ki = i;
	m_frConfig.kd = d;
	m_frConfig.kv = v;
	m_frConfig.ka = a;

	m_blConfig.initial_position = initPos;
	m_blConfig.ticks_per_revolution = ticksPerRev;
	m_blConfig.wheel_circumference = wheelCircum;
	m_blConfig.kp = p;
	m_blConfig.ki = i;
	m_blConfig.kd = d;
	m_blConfig.kv = v;
	m_blConfig.ka = a;

	m_brConfig.initial_position = initPos;
	m_brConfig.ticks_per_revolution = ticksPerRev;
	m_brConfig.wheel_circumference = wheelCircum;
	m_brConfig.kp = p;
	m_brConfig.ki = i;
	m_brConfig.kd = d;
	m_brConfig.kv = v;
	m_brConfig.ka = a;
}

bool TrajectoryFollower::TrajectoryFinished() {
	return m_flFollower.finished && m_frFollower.finished && m_blFollower.finished && m_brFollower.finished;
}
