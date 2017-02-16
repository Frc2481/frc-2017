#include <Commands/GearFlickCommandGroup.h>
#include "OI.h"

#include "Commands/DriveTrainShiftSequenceCommand.h"
#include "Commands/HopperOffCommand.h"
#include "Commands/HopperOnCommand.h"
#include "Commands/LoaderOnCommand.h"
#include "Commands/LoaderOffCommand.h"
#include "Commands/ShooterToggleCommand.h"
#include "Commands/ShooterIncreaseSpeedCommand.h"
#include "Commands/ShooterDecreaseSpeedCommand.h"
#include "Commands/ShooterFireCommand.h"
#include "Commands/ClimberUpCommand.h"
#include "Commands/GearOpenLidCommand.h"
#include "Commands/GearCloseLidCommand.h"
#include "Commands/ShooterHoodToggleCommand.h"
#include "Commands/SetShooterMaxSpeedCommand.h"


OI::OI() {
	m_driverStick = new Joystick(DRIVE_STICK_PORT);
	m_operatorStick = new Joystick(OPERATOR_STICK_PORT);

	m_shifterButton = SHIFTER_BUTTON;
	m_shifterButton->WhenPressed(new DriveTrainShiftSequenceCommand(true));
	m_shifterButton->WhenReleased(new DriveTrainShiftSequenceCommand(false));

	m_flickerGearButton = FLICKER_GEAR_BUTTON;
	m_flickerGearButton->WhenPressed(new GearFlickCommandGroup());

	m_climberButton = CLIMBER_BUTTON;
	m_climberButton->WhileHeld(new ClimberUpCommand());

	m_gearLidButton = GEAR_LID_BUTTON;
	m_gearLidButton->WhenPressed(new GearOpenLidCommand());
	m_gearLidButton->WhenReleased(new GearCloseLidCommand());

	m_shooterMaxSpeed = SHOOTER_MAX_SPEED;
	m_shooterMaxSpeed->WhenPressed(new SetShooterMaxSpeedCommand());


	m_hopperButton = HOPPER_BUTTON;
	m_hopperButton->WhenPressed(new HopperOnCommand());
	m_hopperButton->WhenReleased(new HopperOffCommand());

	m_loaderButton = LOADER_BUTTON;
	m_loaderButton->WhenPressed(new LoaderOnCommand());
	m_loaderButton->WhenReleased(new LoaderOffCommand());

	m_shooterToggleButton = SHOOTER_TOGGLE_BUTTON;
	m_shooterToggleButton->WhenPressed(new ShooterToggleCommand());

	m_incShooterButton = INC_SHOOTER_BUTTON;
	m_incShooterButton->WhenPressed(new ShooterIncreaseSpeedCommand());

	m_decShooterButton = DEC_SHOOTER_BUTTON;
	m_decShooterButton->WhenPressed(new ShooterDecreaseSpeedCommand());

	m_shooterHoodToggleButton = SHOOTER_HOOD_TOOGLE_BUTTON;
	m_shooterHoodToggleButton->WhenPressed(new ShooterHoodToggleCommand());

	//m_fireTrigger = FIRE_TRIGGER;
	//m_fireTrigger->WhileHeld(new ShooterFireCommand());


}

Joystick* OI::GetDriverStick(){
	return m_driverStick;
}
