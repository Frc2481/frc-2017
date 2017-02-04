#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveTrain> CommandBase::m_driveTrain;
std::unique_ptr<Climber> CommandBase::m_climber;
std::unique_ptr<GearFlicker> CommandBase::m_gearFlicker;
std::unique_ptr<Intake> CommandBase::m_intake;
std::unique_ptr<SuperStructure> CommandBase::m_superStructure;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	m_driveTrain.reset(new DriveTrain());
	m_climber.reset(new Climber());
	m_gearFlicker.reset(new GearFlicker());
	m_intake.reset(new Intake());
	m_superStructure.reset(new SuperStructure());


	//oi goes last!!!
	oi.reset(new OI());
}
