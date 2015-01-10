// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveXFeet.h"

DriveXFeet::DriveXFeet(float x) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);

	xfeet = x;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void DriveXFeet::Initialize() {
	Robot::driveTrain->leftFrontEncoder->Reset();

}

// Called repeatedly when this Command is scheduled to run
void DriveXFeet::Execute() {
	//Set motors:
			//Has been done in the drive train
			//To set the speed to a quarter, .25 in front of y input from joystick
			//0 for x because just going forward
			//0 for z, just going forward
		Robot::driveTrain->drive(0, .25, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveXFeet::IsFinished() {
	int ticks = Robot::driveTrain->leftFrontEncoder->Get();
			//Trying to get the distance, but need ticks (pg 175 in manual)
		int ticksNeeded = Robot::driveTrain-> WHEELROTATIONS_PER_FOOT * Robot::driveTrain->ENCODERTICKS_PER_REVOLUTION;
		ticksNeeded = xfeet * (float)ticksNeeded;
			// xfeet * (number of wheel rotations in one ft) * (number of ticks in one rotation)
			//this when you get this many, you stop

		//---------Check if finished----------
		if (ticks >= ticksNeeded)
			return true;
		else
			return false;
		//Now make sure robot stops after this
}

// Called once after isFinished returns true
void DriveXFeet::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveXFeet::Interrupted() {

}
