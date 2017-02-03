#include "OI.h"

#include "Commands/DriveTrainShiftSequenceCommand.h"
#include "Commands/GearLoadCommand.h"

OI::OI()
{
	driverStick = new Joystick(DRIVE_STICK_PORT);

	m_shifterButton = SHIFTER_BUTTON;

	m_shifterButton->WhenPressed(new DriveTrainShiftSequenceCommand(true));
	m_shifterButton->WhenReleased(new DriveTrainShiftSequenceCommand(false));

	m_gearButton = GEAR_BUTTON;
	m_gearButton->WhileHeld(new GearLoadCommand());
}

Joystick* OI::GetDriverStick(){
	return driverStick;
}

