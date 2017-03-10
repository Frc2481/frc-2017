#ifndef SendSerialPRMCommandGroup_H
#define SendSerialPRMCommandGroup_H

#include <Commands/CommandGroup.h>
#include "Commands/SendSerialCharCommand.h"

class SendSerialPRMCommandGroup : public CommandGroup {
public:
	SendSerialPRMCommandGroup() : CommandGroup("SendSerialPRMCommandGroup"){
		SetRunWhenDisabled(true);
		AddSequential(new SendSerialCharCommand('p'));
		AddSequential(new SendSerialCharCommand('r'));
		AddSequential(new SendSerialCharCommand('m'));
	}
};

#endif  // SendSerialPRMCommandGroup_H
