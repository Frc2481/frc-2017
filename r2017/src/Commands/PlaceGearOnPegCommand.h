#ifndef PlaceGearOnPegCommand_H
#define PlaceGearOnPegCommand_H

#include "../CommandBase.h"

const double GEAR_DOWN_POS = 1250.0;
const double GEAR_UP_POS = 0.0;
const double ONE_FOOT_DRIVE_TICKS = 2327.278;

class PlaceGearOnPegCommand : public CommandBase {
private:
	double m_currentPos;
	double m_ratio;
	SwerveModule* m_blWheel;
	SwerveModule* m_brWheel;
	SwerveModule* m_flWheel;
	SwerveModule* m_frWheel;
public:
	PlaceGearOnPegCommand() : CommandBase("PlaceGearOnPegCommand"){
		Requires(m_driveTrain.get());
		Requires(m_gearIntake.get());
		m_blWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE);
		m_brWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE);
		m_flWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE);
		m_frWheel = CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE);
	}
	void Initialize(){
		m_ratio = GEAR_DOWN_POS / ONE_FOOT_DRIVE_TICKS;
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_gearIntake->SpitGear();
	}
	void Execute(){
		m_driveTrain->Drive(0.0,0.5,0.0);
		m_currentPos = (fabs(m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition() * 128.0) +
				fabs(m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition() * 128.0) +
				fabs(m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition() * 128.0) +
				fabs(m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition() * 128.0)) / 4.0;
		m_gearIntake->SetIntakePos((m_currentPos * m_ratio) + m_gearIntake->GetPivotPos());
		SmartDashboard::PutNumber("Gear Place CurrentPos", m_currentPos * m_ratio);

	}
	bool IsFinished(){
		return false;
	}
	void End(){
		m_driveTrain->Drive(0,0,0);
		m_flWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_frWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_blWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		m_brWheel->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);

		m_gearIntake->StopIntakePivot();
		printf("DropOff StopIntake\n");
		m_gearIntake->StopIntake();
	}
};

#endif  // PlaceGearOnPegCommand_H
