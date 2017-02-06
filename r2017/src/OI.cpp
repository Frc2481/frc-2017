#include <Commands/GearFlickCommandGroup.h>
#include "OI.h"

#include "Commands/DriveTrainShiftSequenceCommand.h"
#include "Commands/HopperOffCommand.h"
#include "Commands/HopperOnCommand.h"
#include "Commands/FeederOnCommand.h"
#include "Commands/FeederOffCommand.h"
#include "Commands/ShooterToggleCommand.h"
#include "Commands/ShooterIncreaseSpeedCommand.h"
#include "Commands/ShooterDecreaseSpeedCommand.h"
#include "Commands/ShooterFireCommand.h"
#include "Commands/ClimberUpCommand.h"


OI::OI() {
	m_driverStick = new Joystick(DRIVE_STICK_PORT);
	m_operatorStick = new Joystick(OPERATOR_STICK_PORT);

	m_shifterButton = SHIFTER_BUTTON;
	m_shifterButton->WhenPressed(new DriveTrainShiftSequenceCommand(true));
	m_shifterButton->WhenReleased(new DriveTrainShiftSequenceCommand(false));

	m_unloadGearButton = UNLOAD_GEAR_BUTTON;
	m_unloadGearButton->WhenPressed(new GearFlickCommandGroup());

	m_hopperButton = HOPPER_BUTTON;
	m_hopperButton->WhenPressed(new HopperOnCommand());
	m_hopperButton->WhenReleased(new HopperOffCommand());

	m_liftButton = LIFT_BUTTON;
	m_liftButton->WhenPressed(new FeederOnCommand());
	m_liftButton->WhenReleased(new FeederOffCommand());

	m_shooterToggleButton = SHOOTER_TOGGLE_BUTTON;
	m_shooterToggleButton->WhenPressed(new ShooterToggleCommand());

	m_incShooterButton = INC_SHOOTER_BUTTON;
	m_incShooterButton->WhenPressed(new ShooterIncreaseSpeedCommand());

	m_decShooterButton = DEC_SHOOTER_BUTTON;
	m_decShooterButton->WhenPressed(new ShooterDecreaseSpeedCommand());

	m_fireTrigger = FIRE_TRIGGER;
	m_fireTrigger->WhileHeld(new ShooterFireCommand());

	m_climberButton = CLIMBER_BUTTON;
	m_climberButton->WhileHeld(new ClimberUpCommand());
}

Joystick* OI::GetDriverStick(){
	return m_driverStick;
}
