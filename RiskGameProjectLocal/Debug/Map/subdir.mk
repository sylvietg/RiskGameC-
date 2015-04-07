################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Map/Continent.cpp \
../Map/Map.cpp \
../Map/MapViewer.cpp \
../Map/Observable.cpp \
../Map/Observer.cpp \
../Map/PlayerViewer.cpp \
../Map/Territory.cpp 

OBJS += \
./Map/Continent.o \
./Map/Map.o \
./Map/MapViewer.o \
./Map/Observable.o \
./Map/Observer.o \
./Map/PlayerViewer.o \
./Map/Territory.o 

CPP_DEPS += \
./Map/Continent.d \
./Map/Map.d \
./Map/MapViewer.d \
./Map/Observable.d \
./Map/Observer.d \
./Map/PlayerViewer.d \
<<<<<<< Upstream, based on origin/master
./Map/Territory.d 


# Each subdirectory must supply rules for building sources it contributes
Map/%.o: ../Map/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/orpheus/Documents/Advanced Programming with C++/SFML-feature-gl_dev_new/include/SFML" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


=======
./Map/Territory.d 


# Each subdirectory must supply rules for building sources it contributes
Map/%.o: ../Map/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DSFML_STATIC -I"C:\SFML-2.2\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


>>>>>>> 07773f4 Added folders to the cards
