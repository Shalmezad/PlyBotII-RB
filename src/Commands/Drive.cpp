// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"
#include "../Util/RobotMath.h"

Drive::Drive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	//Alright, here's where I want to do some "fancy" stuff. 
	SmartDashboard::PutNumber(DELINEARIZATION_POWER_DASHBOARD_KEY, DELINEARIZATION_POWER_DEFAULT);
	SmartDashboard::PutNumber(JOYSTICK_DEADBAND_DASHBOARD_KEY, JOYSTICK_DEADBAND_DEFAULT);
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	float x = Robot::oi->getJoystick1()->GetX();
	float y = Robot::oi->getJoystick1()->GetY();
	float z = Robot::oi->getJoystick1()->GetZ();
	float throttle = Robot::oi->getJoystick1()->GetThrottle();

	double joystickDeadband = SmartDashboard::GetNumber(JOYSTICK_DEADBAND_DASHBOARD_KEY, JOYSTICK_DEADBAND_DEFAULT);

	x = RobotMath::deadband(x,joystickDeadband);
	y = RobotMath::deadband(y,joystickDeadband);
	z = RobotMath::deadband(z,joystickDeadband);

	double delinearizationPower = SmartDashboard::GetNumber(DELINEARIZATION_POWER_DASHBOARD_KEY, DELINEARIZATION_POWER_DEFAULT);
	
	x = RobotMath::delinearize(x,throttle,(int)delinearizationPower);
	y = RobotMath::delinearize(y,throttle,(int)delinearizationPower);
	z = RobotMath::delinearize(z,throttle,(int)delinearizationPower);
	Robot::driveTrain->drive(x,y,z);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
