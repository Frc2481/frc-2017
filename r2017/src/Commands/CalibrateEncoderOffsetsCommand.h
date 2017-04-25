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
#include "Components/SwerveModule.h"

class CalibrateEncoderOffsetsCommand: public InstantCommand
{
public:
	CalibrateEncoderOffsetsCommand() : InstantCommand("Calibrate Encoder Command"){
		SetRunWhenDisabled(true);
	}
	void Initialize(){
		saveAndApplyEncoderOffset(DriveTrain::FRONT_LEFT_MODULE, "FL_ENCODER_OFFSET");
		saveAndApplyEncoderOffset(DriveTrain::FRONT_RIGHT_MODULE, "FR_ENCODER_OFFSET");
		saveAndApplyEncoderOffset(DriveTrain::BACK_LEFT_MODULE, "BL_ENCODER_OFFSET");
		saveAndApplyEncoderOffset(DriveTrain::BACK_RIGHT_MODULE, "BR_ENCODER_OFFSET");
	}

private:
	void saveAndApplyEncoderOffset(DriveTrain::SwerveModuleType module, const std::string& key){
		SwerveModule* swerveModule= CommandBase::m_driveTrain->GetModule(module);
		float temp = swerveModule->GetRawAngle();//verify 0 to 360 not -180 to 180
		swerveModule->SetOffset(temp);
		PersistedSettings::GetInstance().Set(key.c_str(),temp);
	}
};

#endif /* SRC_COMMANDS_CALIBRATEENCODEROFFSETSCOMMAND_H_ */
