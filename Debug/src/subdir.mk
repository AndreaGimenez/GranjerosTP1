################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/jugador.cpp \
../src/tanque.cpp \
../src/utilidades.cpp 

OBJS += \
./src/jugador.o \
./src/tanque.o \
./src/utilidades.o 

CPP_DEPS += \
./src/jugador.d \
./src/tanque.d \
./src/utilidades.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


