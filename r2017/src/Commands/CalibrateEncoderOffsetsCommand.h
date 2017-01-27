/*
 * CalibrateEncoderOffsetsCommand.h
 *
 *  Created on: Jan 24, 2017
 *      Author: FIRSTMentor
 */

#ifndef SRC_COMMANDS_CALIBRATEENCODEROFFSETSCOMMAND_H_
#define SRC_COMMANDS_CALIBRATEENCODEROFFSETSCOMMAND_H_

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotParameters.h"
#include "Components/PersistedSettings.h"

class CalibrateEncoderOffsetsCommand: public CommandBase
{
public:
	CalibrateEncoderOffsetsCommand() : CommandBase("Calibrate Encoder Command"){
		SetRunWhenDisabled(true);
	}
	void Initialize(){
		saveAndApplyEncoderOffset(DriveTrain::FRONT_LEFT_ENCODER, "FL_ENCODER_OFFSET");
		saveAndApplyEncoderOffset(DriveTrain::FRONT_RIGHT_ENCODER, "FR_ENCODER_OFFSET");
		saveAndApplyEncoderOffset(DriveTrain::BACK_LEFT_ENCODER, "BL_ENCODER_OFFSET");
		saveAndApplyEncoderOffset(DriveTrain::BACK_RIGHT_ENCODER, "BR_ENCODER_OFFSET");
	}
	bool IsFinished(){
		return true;
	}

private:
	void saveAndApplyEncoderOffset(DriveTrain::EncoderType encoder, const std::string& key){
		float temp = m_driveTrain->GetEncoderValue(encoder);
		m_driveTrain->SetEncoderOffset(encoder, temp);
		PersistedSettings::GetInstance().Set(key.c_str(),temp);
	}
};

#endif /* SRC_COMMANDS_CALIBRATEENCODEROFFSETSCOMMAND_H_ */
