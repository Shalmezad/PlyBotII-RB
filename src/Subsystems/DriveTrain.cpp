// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "DriveTrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Drive.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	speedController1 = RobotMap::driveTrainSpeedController1;
	speedController2 = RobotMap::driveTrainSpeedController2;
	speedController3 = RobotMap::driveTrainSpeedController3;
	speedController4 = RobotMap::driveTrainSpeedController4;
	robotDrive41 = RobotMap::driveTrainRobotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Drive());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::drive(float x, float y, float z)
{
	robotDrive4Motors->MecanumDrive_Cartesian(x,y,z);

}
