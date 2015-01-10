// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* leftFrontMotor;
	SpeedController* leftRearMotor;
	SpeedController* rightFrontMotor;
	SpeedController* rightRearMotor;
	RobotDrive* robotDrive41;
	Gyro* driveGyro;
	Encoder* leftFrontEncoder;
	Encoder* leftRearEncoder;
	Encoder* rightFrontEncoder;
	Encoder* rightRearEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	//This is finding the distance of the wheel
	const float WHEELDIAMETER_IN_INCHES = 6; //wheel diameter
	const float WHEELCIRCUMFERENCE_IN_INCHES = WHEELDIAMETER_IN_INCHES * 3.14;
		//finds the distance covered in one rotation
	const float WHEELCIRCUMFERENCE_IN_FEET = WHEELCIRCUMFERENCE_IN_INCHES / 12;
		//distance covered in one rotation in feet
	const float WHEELROTATIONS_PER_FOOT = 1/WHEELCIRCUMFERENCE_IN_FEET;
		//rotations made in one foot
	const int ENCODERTICKS_PER_REVOLUTION = 220; //this is a guess right now
		//used in finding revs



	DriveTrain();
	void InitDefaultCommand();
	// drive command drives the mecanum and parameters: x,y z as rotation

	/**
	 * Drives the chasis using cartesian coordinates
	 * @param x Magnitude along x axis
	 * @param y Magnitude along y axis
	 * @param z Magnitude along z axis
	 */
	void drive(float x, float y, float z);
};

#endif
