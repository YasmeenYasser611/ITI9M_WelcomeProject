################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DC_Motors.c \
../DIO.c \
../IR.c \
../LCD.c \
../Timer.c \
../UART.c \
../ULTRASONIC.c \
../main.c 

OBJS += \
./DC_Motors.o \
./DIO.o \
./IR.o \
./LCD.o \
./Timer.o \
./UART.o \
./ULTRASONIC.o \
./main.o 

C_DEPS += \
./DC_Motors.d \
./DIO.d \
./IR.d \
./LCD.d \
./Timer.d \
./UART.d \
./ULTRASONIC.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


