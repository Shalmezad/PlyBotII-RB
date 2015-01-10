// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::driveTrainLeftFrontMotor = NULL;
SpeedController* RobotMap::driveTrainLeftRearMotor = NULL;
SpeedController* RobotMap::driveTrainRightFrontMotor = NULL;
SpeedController* RobotMap::driveTrainRightRearMotor = NULL;
RobotDrive* RobotMap::driveTrainMotorController = NULL;
Encoder* RobotMap::driveTrainLeftFrontEncoder = NULL;
Encoder* RobotMap::driveTrainLeftRearEncoder = NULL;
Encoder* RobotMap::driveTrainRightFrontEncoder = NULL;
Encoder* RobotMap::driveTrainRightRearEncoder = NULL;
Gyro* RobotMap::driveTrainMainGyro = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	driveTrainLeftFrontMotor = new TalonSRX(0);
	lw->AddActuator("DriveTrain", "LeftFrontMotor", (TalonSRX*) driveTrainLeftFrontMotor);
	
	driveTrainLeftRearMotor = new Talon(1);
	lw->AddActuator("DriveTrain", "LeftRearMotor", (Talon*) driveTrainLeftRearMotor);
	
	driveTrainRightFrontMotor = new Talon(2);
	lw->AddActuator("DriveTrain", "RightFrontMotor", (Talon*) driveTrainRightFrontMotor);
	
	driveTrainRightRearMotor = new Talon(3);
	lw->AddActuator("DriveTrain", "RightRearMotor", (Talon*) driveTrainRightRearMotor);
	
	driveTrainMotorController = new RobotDrive(driveTrainLeftFrontMotor, driveTrainLeftRearMotor,
              driveTrainRightFrontMotor, driveTrainRightRearMotor);
	
	driveTrainMotorController->SetSafetyEnabled(true);
        driveTrainMotorController->SetExpiration(0.1);
        driveTrainMotorController->SetSensitivity(0.5);
        driveTrainMotorController->SetMaxOutput(1.0);

        driveTrainMotorController->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
        driveTrainMotorController->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	driveTrainLeftFrontEncoder = new Encoder(0, 1, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "LeftFrontEncoder", driveTrainLeftFrontEncoder);
	driveTrainLeftFrontEncoder->SetDistancePerPulse(1.0);
        driveTrainLeftFrontEncoder->SetPIDSourceParameter(Encoder::kRate);
	driveTrainLeftRearEncoder = new Encoder(2, 3, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "LeftRearEncoder", driveTrainLeftRearEncoder);
	driveTrainLeftRearEncoder->SetDistancePerPulse(1.0);
        driveTrainLeftRearEncoder->SetPIDSourceParameter(Encoder::kRate);
	driveTrainRightFrontEncoder = new Encoder(4, 5, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "RightFrontEncoder", driveTrainRightFrontEncoder);
	driveTrainRightFrontEncoder->SetDistancePerPulse(1.0);
        driveTrainRightFrontEncoder->SetPIDSourceParameter(Encoder::kRate);
	driveTrainRightRearEncoder = new Encoder(6, 7, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "RightRearEncoder", driveTrainRightRearEncoder);
	driveTrainRightRearEncoder->SetDistancePerPulse(1.0);
        driveTrainRightRearEncoder->SetPIDSourceParameter(Encoder::kRate);
	driveTrainMainGyro = new Gyro(0);
	lw->AddSensor("DriveTrain", "MainGyro", driveTrainMainGyro);
	driveTrainMainGyro->SetSensitivity(0.007);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
