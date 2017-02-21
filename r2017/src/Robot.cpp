#include <Commands/GenerateGearRotationPathCommand.h>
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/DriveTrainSetPIDCommand.h"
#include "Commands/ShooterIncreaseSpeedCommand.h"
#include "Commands/ShooterDecreaseSpeedCommand.h"
#include "Commands/ShooterOnCommand.h"
#include "Commands/ShooterOffCommand.h"
#include "Commands/ShooterSetPIDCommand.h"
#include "Commands/CalibrateEncoderOffsetsCommand.h"
#include "Commands/SetEncoderConfigsCommand.h"
#include "Commands/ToggleOptimizedCommand.h"
#include "Commands/FollowFakePathCommand.h"
#include "Commands/SwerveModuleTestClosedLoopVelocityCommand.h"
#include "Commands/GeneratePathToTargetCommand.h"
#include "Commands/FollowGearPathCommandGroup.h"
#include "Commands/GenerateGearRotationPathCommand.h"
#include "Commands/SetDriveTalonToSlaveCommand.h"
#include "Commands/AutoDriveToGearCommandGroup.h"
#include "Commands/TimeAccelAndDecelCommandGroup.h"
#include "Commands/DriveTrainDisableGyroCorrectionCommand.h"
#include "Commands/DriveTrainEnableGyroCorrectionCommand.h"
#include "Commands/DriveToDistanceEncoderCommand.h"
#include "Commands/DriveTrainZeroYawCommand.h"
#include "Commands/RotateToAngleGyroCommand.h"
#include "Commands/MiddleGearAutoCommandGroup.h"
#include "Commands/SetShooterOpenLoopFullSpeed.h"
#include "Commands/TurnShooterOnCommand.h"
#include "Loops/VisionProcessor.h"
#include "Vision/VisionServer.h"
#include "Commands/BirdEyeDelayedSetupCommandGroup.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> birdEyeSetupCommand;
	frc::SendableChooser<Command*> *chooser;
	std::unique_ptr<Compressor> pcm;
	std::unique_ptr<PowerDistributionPanel> pdp;
	VisionProcessor* m_visionProcessor = VisionProcessor::GetInstance();
	//VisionServer* m_visionServer;
	Scheduler* m_scheduler;

	void RobotInit()
	{
		birdEyeSetupCommand = new BirdEyeDelayedSetupCommandGroup();
		birdEyeSetupCommand->Start();
		//m_visionServer = new VisionServer("8254");
		SmartDashboard::PutData("Scheduler", m_scheduler->GetInstance());
		CommandBase::init();
		CommandBase::m_driveTrain->SetLengthAndWidth(ROBOT_LENGTH, ROBOT_WIDTH);
		m_visionProcessor->OnStart();
		chooser = new frc::SendableChooser<Command*>();
		pcm.reset(new Compressor());
		pcm->SetClosedLoopControl(true);
		pdp.reset(new PowerDistributionPanel());
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
//		chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);
		SmartDashboard::PutNumber("Speed P", CommandBase::m_driveTrain->GetSpeedP());
		SmartDashboard::PutNumber("Speed I", CommandBase::m_driveTrain->GetSpeedI());
		SmartDashboard::PutNumber("Speed D", CommandBase::m_driveTrain->GetSpeedD());
		SmartDashboard::PutNumber("Steer P", CommandBase::m_driveTrain->GetSteerP());
		SmartDashboard::PutNumber("Steer I", CommandBase::m_driveTrain->GetSteerI());
		SmartDashboard::PutNumber("Steer D", CommandBase::m_driveTrain->GetSteerD());

		SmartDashboard::PutNumber("Overall Power", pdp->GetTotalCurrent());

		SmartDashboard::PutNumber("Shooter P", CommandBase::m_superStructure->GetP());
		SmartDashboard::PutNumber("Shooter I", CommandBase::m_superStructure->GetI());
		SmartDashboard::PutNumber("Shooter D", CommandBase::m_superStructure->GetD());
		SmartDashboard::PutNumber("Hopper Speed", CommandBase::m_superStructure->GetSpeed());
		SmartDashboard::PutData(new ToggleOptimizedCommand());

		SmartDashboard::PutData(new DriveTrainSetPIDCommand());
		SmartDashboard::PutData(new ShooterIncreaseSpeedCommand());
		SmartDashboard::PutData(new ShooterDecreaseSpeedCommand());
		SmartDashboard::PutData(new ShooterOnCommand());
		SmartDashboard::PutData(new ShooterOffCommand());
		SmartDashboard::PutData(new ShooterSetPIDCommand());
		SmartDashboard::PutData(new CalibrateEncoderOffsetsCommand());
		SmartDashboard::PutData(new SetEncoderConfigsCommand());
		SmartDashboard::PutData(new FollowFakePathCommand());
		SmartDashboard::PutData(new SwerveModuleTestClosedLoopVelocityCommand());
		SmartDashboard::PutData(new GenerateGearRotationPathCommand(30));
		SmartDashboard::PutData(new FollowGearPathCommandGroup());
		SmartDashboard::PutData(new SetDriveTalonToSlaveCommand(true));
		SmartDashboard::PutData(new AutoDriveToGearCommandGroup());
		SmartDashboard::PutData(new TimeAccelAndDecelCommandGroup());
		SmartDashboard::PutData(new DriveTrainEnableGyroCorrectionCommand(0));
		SmartDashboard::PutData(new DriveTrainDisableGyroCorrectionCommand());
		SmartDashboard::PutData(new DriveToDistanceEncoderCommand());
		SmartDashboard::PutData(new DriveTrainZeroYawCommand());
		SmartDashboard::PutData(new RotateToAngleGyroCommand(-60));
		SmartDashboard::PutData(new MiddleGearAutoCommandGroup());
		SmartDashboard::PutData(new SetShooterOpenLoopFullSpeed());
		SmartDashboard::PutData(new TurnShooterOnCommand());

		SmartDashboard::PutNumber("EncoderConfig InitPos", 0);
		SmartDashboard::PutNumber("EncoderConfig P", 0.0);
		SmartDashboard::PutNumber("EncoderConfig I", 0.0);
		SmartDashboard::PutNumber("EncoderConfig D", 0.0);
		SmartDashboard::PutNumber("EncoderConfig V", 0.0);
		SmartDashboard::PutNumber("EncoderConfig A", 0.0);

		SmartDashboard::PutNumber("Auto Gear Drive Distance", 0.0);

		SmartDashboard::PutNumber("Shooter Setpoint", 0.0);

		SmartDashboard::PutNumber("Gyro Correction P", 0.0);
		SmartDashboard::PutNumber("Gyro Correction I", 0.0);
		SmartDashboard::PutNumber("Gyro Rotation P", 0.0);
		SmartDashboard::PutNumber("Gyro Rotation I", 0.0);
		SmartDashboard::PutNumber("Gyro Rotation D", 0.0);

		SmartDashboard::PutNumber("Drive Velocity Setpoint TEST", 0.0);
		SmartDashboard::PutNumber("RotateToAngle Angle", 0.0);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		SmartDashboard::PutNumber("Shooter Setpoint", CommandBase::m_superStructure->GetShooterSetpoint());
		SmartDashboard::PutNumber("Loader Speed", CommandBase::m_superStructure->GetLoaderSpeed());
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.

		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
		CommandBase::m_driveTrain->SetGyroCorrection(false);
		CommandBase::m_driveTrain->ResetSlaveTalons();
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetMotor(SwerveModule::DRIVE_MOTOR)->SetEncPosition(0);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetMagicBool(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->SetMagicBool(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_RIGHT_MODULE)->SetMagicBool(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->SetMagicBool(false);
		CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->SetMagicBool(false);
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
//		SmartDashboard::PutNumber("Shooter Setpoint", CommandBase::m_shooter->GetShooterSetpoint());
//		SmartDashboard::PutNumber("Feeder Speed", CommandBase::m_shooter->GetFeederSpeed());
		SmartDashboard::PutNumber("Overall Power", pdp->GetTotalCurrent());
		SmartDashboard::PutNumber("DriveTrain Distance", CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetDistance());
		SmartDashboard::PutNumber("Drive Velocity", CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->GetSpeed());
		SmartDashboard::PutNumber("GetFLClosedLoopError", CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::DRIVE_MOTOR)->GetClosedLoopError());
		SmartDashboard::PutNumber("GetFLPosition", CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition());
		SmartDashboard::PutNumber("GetFLError+Position", CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::DRIVE_MOTOR)->GetClosedLoopError() + CommandBase::m_driveTrain->GetModule(DriveTrain::FRONT_LEFT_MODULE)->
				GetMotor(SwerveModule::DRIVE_MOTOR)->GetPosition());
		SmartDashboard::PutNumber("Current BL Error", CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetError());
		SmartDashboard::PutNumber("BL Encoder Value", CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_LEFT_MODULE)->GetAngle());
		SmartDashboard::PutNumber("Gyro Angle", CommandBase::m_driveTrain->GetHeading());
		SmartDashboard::PutNumber("Shooter Speed", CommandBase::m_superStructure->GetSpeed());
		SmartDashboard::PutNumber("MotionMagic Setpoint", CommandBase::m_driveTrain->GetMotionMagicSetpoint());
		SmartDashboard::PutNumber("BRSteerValue", CommandBase::m_driveTrain->GetModule(DriveTrain::BACK_RIGHT_MODULE)->GetMotor(SwerveModule::STEER_MOTOR)->GetPulseWidthPosition());
		SmartDashboard::PutBoolean("Shooter Hood", CommandBase::m_superStructure->IsRaised());
		SmartDashboard::PutNumber("Hopper Current", CommandBase::m_superStructure->GetHopperCurrent());
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

