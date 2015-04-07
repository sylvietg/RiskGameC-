################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Battle/Battle.cpp 

OBJS += \
./Battle/Battle.o 

CPP_DEPS += \
<<<<<<< Upstream, based on origin/master
./Battle/Battle.d 


# Each subdirectory must supply rules for building sources it contributes
Battle/%.o: ../Battle/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/orpheus/Documents/Advanced Programming with C++/SFML-feature-gl_dev_new/include/SFML" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


=======
./Battle/Battle.d 


# Each subdirectory must supply rules for building sources it contributes
Battle/%.o: ../Battle/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DSFML_STATIC -I"C:\SFML-2.2\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


>>>>>>> 07773f4 Added folders to the cards
