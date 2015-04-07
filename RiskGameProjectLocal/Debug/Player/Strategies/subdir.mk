################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Player/Strategies/Agressive.cpp \
../Player/Strategies/Defensive.cpp \
../Player/Strategies/Random.cpp \
../Player/Strategies/Strategy.cpp 

OBJS += \
./Player/Strategies/Agressive.o \
./Player/Strategies/Defensive.o \
./Player/Strategies/Random.o \
./Player/Strategies/Strategy.o 

CPP_DEPS += \
./Player/Strategies/Agressive.d \
./Player/Strategies/Defensive.d \
./Player/Strategies/Random.d \
./Player/Strategies/Strategy.d 


# Each subdirectory must supply rules for building sources it contributes
Player/Strategies/%.o: ../Player/Strategies/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/orpheus/Documents/Advanced Programming with C++/SFML-feature-gl_dev_new/include/SFML" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


