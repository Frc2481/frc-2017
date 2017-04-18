#include <Commands/GearFlickCommandGroup.h>
#include "OI.h"

#include "Commands/DriveTrainShiftSequenceCommand.h"
#include "Commands/HopperOffCommand.h"
#include "Commands/HopperOnCommand.h"
#include "Commands/LoaderOnCommand.h"
#include "Commands/LoaderOffCommand.h"
#include "Commands/ShooterIncreaseSpeedCommand.h"
#include "Commands/ShooterDecreaseSpeedCommand.h"
#include "Commands/ClimberUpCommand.h"
#include "Commands/GearOpenLidCommand.h"
#include "Commands/GearCloseLidCommand.h"
#include "Commands/ShooterHoodToggleCommand.h"
#include "Commands/SendSerialCharCommand.h"
#include "Commands/StopFiringCommandGroup.h"
#include "Commands/FireBallsCommandGroup.h"
#include "Commands/DecOurGearCounterCommand.h"
#include "Commands/DecTheirGearCounterCommand.h"
#include "Commands/IncOurGearCounterCommand.h"
#include "Commands/IncTheirGearCounterCommand.h"
#include "Commands/GearFlickCommand.h"
#include "Commands/GearResetCommand.h"
#include "Commands/SetFieldCentricCommand.h"
#include "Commands/IntakeOnCommand.h"
#include "Commands/IntakeOffCommand.h"
#include "Commands/PlaceGearOnPegCommandGroup.h"
#include "Commands/PickUpGearCommandGroup.h"
#include "Commands/StopGearIntakeCommand.h"
#include "Commands/HomeGearIntakeCommandGroup.h"

OI::OI() {
	m_driverStick = new Joystick2481(DRIVE_STICK_PORT);
	m_operatorStick = new Joystick2481(OPERATOR_STICK_PORT);

	m_shifterButton = SHIFTER_BUTTON;
	m_shifterButton->WhenPressed(new DriveTrainShiftSequenceCommand(true));
	m_shifterButton->WhenReleased(new DriveTrainShiftSequenceCommand(false));

	m_fieldCentricButton = FIELD_CENTRIC_BUTTON;
	m_fieldCentricButton->WhenPressed(new SetFieldCentricCommand(true));
	m_fieldCentricButton->WhenReleased(new SetFieldCentricCommand(false));

	m_unloadGearButton = UNLOAD_GEAR_BUTTON;
	m_unloadGearButton->WhileHeld(new PlaceGearOnPegCommandGroup());

	m_intakeButton = INTAKE_BUTTON;
	m_intakeButton->WhenPressed(new PickUpGearCommandGroup());
	m_intakeButton->WhenReleased(new HomeGearIntakeCommandGroup());

	m_climberButton = CLIMBER_BUTTON;
	m_climberButton->WhileHeld(new ClimberUpCommand());

	m_gearLidButton = GEAR_LID_BUTTON;
	m_gearLidButton->WhenPressed(new GearCloseLidCommand());
	m_gearLidButton->WhenReleased(new GearOpenLidCommand());

//	m_shooterMaxSpeed = SHOOTER_MAX_SPEED;
//	m_shooterMaxSpeed->WhenPressed(new SetShooterMaxSpeedCommand());

	m_frontCameraButton = FRONT_CAMERA_BUTTON;
	m_frontCameraButton->WhenPressed(new SendSerialCharCommand('u'));

	m_leftCameraButton = LEFT_CAMERA_BUTTON;
	m_leftCameraButton->WhenPressed(new SendSerialCharCommand('l'));

	m_rightCameraButton = RIGHT_CAMERA_BUTTON;
	m_rightCameraButton->WhenPressed(new SendSerialCharCommand('r'));

	m_backCameraButton = BACK_CAMERA_BUTTON;
	m_backCameraButton->WhenPressed(new SendSerialCharCommand('d'));

	m_cameraMenuButton = CAMERA_MENU_BUTTON;
	m_cameraMenuButton->WhenPressed(new SendSerialCharCommand('m'));

	m_shooterOnButton = SHOOTER_ON_BUTTON;
	m_shooterOnButton->WhenPressed(new TurnShooterOnCommand());

	m_shooterOffButton = SHOOTER_OFF_BUTTON;
	m_shooterOffButton->WhenPressed(new ShooterOffCommand());

	m_incShooterButton = INC_SHOOTER_BUTTON;
	m_incShooterButton->WhenPressed(new ShooterIncreaseSpeedCommand());

	m_decShooterButton = DEC_SHOOTER_BUTTON;
	m_decShooterButton->WhenPressed(new ShooterDecreaseSpeedCommand());

	m_shooterHoodToggleButton = SHOOTER_HOOD_TOOGLE_BUTTON;
	m_shooterHoodToggleButton->WhenPressed(new ShooterHoodToggleCommand());

	m_fireTrigger = FIRE_TRIGGER;
	m_fireTrigger->WhenPressed(new FireBallsCommandGroup());
	m_fireTrigger->WhenReleased(new StopFiringCommandGroup());

	m_gearLidButtonOP = GEAR_LID_BUTTON_OP;
	m_gearLidButtonOP->WhenPressed(new GearCloseLidCommand());
	m_gearLidButtonOP->WhenReleased(new GearOpenLidCommand());

	m_flickerGearButtonOP = FLICKER_GEAR_BUTTON_OP;
	m_flickerGearButtonOP->WhenPressed(new GearFlickCommand());
	m_flickerGearButtonOP->WhenReleased(new GearResetCommand());

	m_intakeButtonOP = INTAKE_BUTTON_OP;
	m_intakeButtonOP->WhenPressed(new IntakeOnCommand());

//	m_incOurGear = INC_OUR_GEAR_COUNTER;
//	m_incOurGear->WhenPressed(new IncOurGearCounterCommand());
//
//	m_decOurGear = DEC_OUR_GEAR_COUNTER;
//	m_decOurGear->WhenPressed(new DecOurGearCounterCommand());
//
//	m_incTheirGear = INC_THEIR_GEAR_COUNTER;
//	m_incTheirGear->WhenPressed(new IncTheirGearCounterCommand());
//
//	m_decTheirGear = DEC_THEIR_GEAR_COUNTER;
//	m_decTheirGear->WhenPressed(new DecTheirGearCounterCommand());


}

Joystick2481* OI::GetDriverStick(){
	return m_driverStick;
}

Joystick2481* OI::GetOperatorStick() {
	return m_operatorStick;
}
