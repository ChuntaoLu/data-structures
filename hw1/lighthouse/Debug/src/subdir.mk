################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/binary_search.cpp \
../src/main.cpp \
../src/merge_sort.cpp \
../src/merge_sort_2d.cpp 

OBJS += \
./src/binary_search.o \
./src/main.o \
./src/merge_sort.o \
./src/merge_sort_2d.o 

CPP_DEPS += \
./src/binary_search.d \
./src/main.d \
./src/merge_sort.d \
./src/merge_sort_2d.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


