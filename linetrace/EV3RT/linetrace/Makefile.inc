APPL_COBJS += balancer.o balancer_param.o

APPL_CXXOBJS += ETBrightSensor.o ETTouchSensor.o ETGyroSensor.o WheelMotor.o TailMotor.o TurnCalc.o CommandTask.o SerialConnect.o DistanceTask.o DriveTask.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif
