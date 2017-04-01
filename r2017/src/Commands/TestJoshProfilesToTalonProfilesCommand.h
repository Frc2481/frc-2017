#ifndef TestJoshProfilesToTalonProfilesCommand_H
#define TestJoshProfilesToTalonProfilesCommand_H

#include "../CommandBase.h"
#include "Components/TalonMotionProfileFollower.h"
#include "Components/PathPlanner.h"
#include "Components/MotionProfileConverter.h"
#include "CANTalon.h"

class TestJoshProfilesToTalonProfilesCommand : public CommandBase {
private:
	TalonMotionProfileFollower m_flSteer;
	TalonMotionProfileFollower m_frSteer;
	TalonMotionProfileFollower m_blSteer;
	TalonMotionProfileFollower m_brSteer;
	TalonMotionProfileFollower m_flDrive;
	TalonMotionProfileFollower m_frDrive;
	TalonMotionProfileFollower m_blDrive;
	TalonMotionProfileFollower m_brDrive;
	bool m_first;
public:
	TestJoshProfilesToTalonProfilesCommand() : CommandBase("TestJoshProfilesToTalonProfilesCommand"),
	m_flSteer(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR), "FLSTEER", 0),
	m_frSteer(m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR), "FRSTEER", 0),
	m_blSteer(m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR), "BLSTEER", 0),
	m_brSteer(m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR), "BRSTEER", 0),

	m_flDrive(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR), "FLDRIVE", 0),
	m_frDrive(m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR), "FRDRIVE", 0),
	m_blDrive(m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR), "BLDRIVE", 0),
	m_brDrive(m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR), "BRDRIVE", 0),
	m_first(true){
		SetRunWhenDisabled(true);
		Requires(m_driveTrain.get());
	}
	void Initialize(){
		m_first = true;
		m_driveTrain->DisableFollower();
		PathPlanner p;
		p.addWaypoint(0.0, 0.0, 0.0);
		p.addWaypoint(m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(50.0),
				m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(50.0), 45.0);
		double totalTime = p.estimateTime(m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetVelocity()/60.0,
				m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetAcceleration()/60.0);
		//double totalTime = 1.5;
		p.calculate(totalTime, MP_TIMESTEP, m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(ROBOT_TRACK_WIDTH), m_driveTrain->ComputeDriveDistanceInchestoEncoderRotations(ROBOT_TRACK_LENGTH), MP_MAX_ACCEL);

		CANTalon::TrajectoryPoint* flSteer = new CANTalon::TrajectoryPoint[p.leftUpperPath->size()-1];
		CANTalon::TrajectoryPoint* frSteer = new CANTalon::TrajectoryPoint[p.rightUpperPath->size()-1];
		CANTalon::TrajectoryPoint* blSteer = new CANTalon::TrajectoryPoint[p.leftLowerPath->size()-1];
		CANTalon::TrajectoryPoint* brSteer = new CANTalon::TrajectoryPoint[p.rightLowerPath->size()-1];
		CANTalon::TrajectoryPoint* flDrive = new CANTalon::TrajectoryPoint[p.leftUpperPath->size()-1];
		CANTalon::TrajectoryPoint* frDrive = new CANTalon::TrajectoryPoint[p.rightUpperPath->size()-1];
		CANTalon::TrajectoryPoint* blDrive = new CANTalon::TrajectoryPoint[p.leftLowerPath->size()-1];
		CANTalon::TrajectoryPoint* brDrive = new CANTalon::TrajectoryPoint[p.rightLowerPath->size()-1];

		MotionProfileConverter converter = MotionProfileConverter(MP_TIMESTEP);
		converter.ConvertSteer(p.leftUpperPath,flSteer,p.leftUpperPath->size()-1);
		converter.ConvertDrive(p.leftUpperPath,flDrive,p.leftUpperPath->size()-1);
		converter.ConvertSteer(p.rightUpperPath,frSteer,p.rightUpperPath->size()-1);
		converter.ConvertDrive(p.rightUpperPath,frDrive,p.rightUpperPath->size()-1);
		converter.ConvertSteer(p.leftLowerPath,blSteer,p.leftLowerPath->size()-1);
		converter.ConvertDrive(p.leftLowerPath,blDrive,p.leftLowerPath->size()-1);
		converter.ConvertSteer(p.rightLowerPath,brSteer,p.rightLowerPath->size()-1);
		converter.ConvertDrive(p.rightLowerPath,brDrive,p.rightLowerPath->size()-1);

		m_driveTrain->EnableFollower();
		m_flSteer.LoadPath(flSteer, p.leftUpperPath->size()-1);
		m_frSteer.LoadPath(frSteer, p.rightUpperPath->size()-1);
		m_blSteer.LoadPath(blSteer, p.leftLowerPath->size()-1);
		m_brSteer.LoadPath(brSteer, p.rightLowerPath->size()-1);
		m_flDrive.LoadPath(flDrive, p.leftUpperPath->size()-1);
		m_frDrive.LoadPath(frDrive, p.rightUpperPath->size()-1);
		m_blDrive.LoadPath(blDrive, p.leftLowerPath->size()-1);
		m_brDrive.LoadPath(brDrive, p.rightLowerPath->size()-1);
	}
	void Execute(){
		m_flSteer.Periodic();
		m_frSteer.Periodic();
		m_blSteer.Periodic();
		m_brSteer.Periodic();
		m_flDrive.Periodic();
		m_frDrive.Periodic();
		m_blDrive.Periodic();
		m_brDrive.Periodic();
		if(m_flSteer.IsReady()&& m_frSteer.IsReady() && m_blSteer.IsReady() && m_brSteer.IsReady() &&
			 m_flDrive.IsReady() && m_frDrive.IsReady() && m_blDrive.IsReady() && m_brDrive.IsReady()
			&& m_first){
			m_first = false;
			m_flSteer.RunPath();
			m_frSteer.RunPath();
			m_blSteer.RunPath();
			m_brSteer.RunPath();
			m_flDrive.RunPath();
			m_frDrive.RunPath();
			m_blDrive.RunPath();
			m_brDrive.RunPath();
		}
	}
	bool IsFinished(){
		return (m_flSteer.IsFinished()&& m_frSteer.IsFinished() && m_blSteer.IsFinished() && m_brSteer.IsFinished()&&
				m_flDrive.IsFinished() && m_frDrive.IsFinished() && m_blDrive.IsFinished() && m_brDrive.IsFinished());
	}
	void End(){
		m_driveTrain->DisableFollower();
	}
};

#endif  // TestJoshProfilesToTalonProfilesCommand_H
