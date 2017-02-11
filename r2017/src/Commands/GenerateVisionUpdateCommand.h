#ifndef GenerateVisionUpdateCommand_H
#define GenerateVisionUpdateCommand_H

#include "../CommandBase.h"
#include "Commands/InstantCommand.h"

class GenerateVisionUpdateCommand : public InstantCommand {
public:
	GenerateVisionUpdateCommand() : InstantCommand("GenerateVisionUpdateCommand"){}
	void Initialize(){
		VisionProcessor::GetInstance()->SetActive(true);
		VisionProcessor::GetInstance()->gotUpdate(VisionUpdate::generateFromJsonString(0,
			"{ \"capturedAgoMs\" : 100, \"targets\" : [{\"y\": 1330, \"z\" : 1167.5},{\"y\": 2154, \"z\" : 1160}]}"));
	}
};

#endif  // GenerateVisionUpdateCommand_H
