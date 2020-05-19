Two Wheeled Robot

This is the control code of the robot

    access mpu6050 to get gyro and acceleration information
    compute y-axis error with complimentary filter
    update dc motor speed with PID control

Requirements
    Raspberry Pi
    MPU6050
    L293D
    wiringPi
