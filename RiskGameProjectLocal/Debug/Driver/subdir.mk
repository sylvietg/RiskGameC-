################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Driver/Fortification.cpp \
../Driver/Game.cpp \
../Driver/GameDriver.cpp \
../Driver/Reinforcement.cpp 

OBJS += \
./Driver/Fortification.o \
./Driver/Game.o \
./Driver/GameDriver.o \
./Driver/Reinforcement.o 

CPP_DEPS += \
./Driver/Fortification.d \
./Driver/Game.d \
./Driver/GameDriver.d \
./Driver/Reinforcement.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/%.o: ../Driver/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


