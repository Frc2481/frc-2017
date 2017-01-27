#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Climber.h"
#include "Subsystems/GearLoader.h"
#include "Subsystems/Hopper.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveTrain> m_driveTrain;
	static std::unique_ptr<Climber> m_climber;
	static std::unique_ptr<GearLoader> m_gearLoader;
	static std::unique_ptr<Hopper> m_hopper;
	static std::unique_ptr<Intake> m_intake;
	static std::unique_ptr<Shooter> m_shooter;
	static std::unique_ptr<OI> oi;
};

#endif
