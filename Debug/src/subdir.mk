################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AttitudeIndicatorWidget.cpp \
../src/BMFontManager.cpp \
../src/ButtonWidget.cpp \
../src/CircularGaugeWidget.cpp \
../src/Command.cpp \
../src/Component.cpp \
../src/DownloadManager.cpp \
../src/FTFontManager.cpp \
../src/FlapsWidget.cpp \
../src/GameObject.cpp \
../src/GameObjectFactory.cpp \
../src/Geometry.cpp \
../src/ImageWidget.cpp \
../src/KeyManageable.cpp \
../src/ListenerComponent.cpp \
../src/LogManager.cpp \
../src/Program.cpp \
../src/RenderComponent.cpp \
../src/RenderContext.cpp \
../src/SPIManager.cpp \
../src/SerialManager.cpp \
../src/Shader.cpp \
../src/ShadingProgramManager.cpp \
../src/SplashView.cpp \
../src/State.cpp \
../src/StateMachine.cpp \
../src/StateManager.cpp \
../src/SubjectComponent.cpp \
../src/SwitchScreenAction.cpp \
../src/TelemetryWidget.cpp \
../src/TextWidget.cpp \
../src/Texture.cpp \
../src/TextureManager.cpp \
../src/TimerWidget.cpp \
../src/TransformComponent.cpp \
../src/TxBatteryMeterWidget.cpp \
../src/UIWidget.cpp \
../src/VertexDeclarations.cpp \
../src/VertexDefinitionManager.cpp \
../src/View.cpp \
../src/ViewManager.cpp \
../src/Widget.cpp \
../src/afx.cpp \
../src/artrix.cpp 

OBJS += \
./src/AttitudeIndicatorWidget.o \
./src/BMFontManager.o \
./src/ButtonWidget.o \
./src/CircularGaugeWidget.o \
./src/Command.o \
./src/Component.o \
./src/DownloadManager.o \
./src/FTFontManager.o \
./src/FlapsWidget.o \
./src/GameObject.o \
./src/GameObjectFactory.o \
./src/Geometry.o \
./src/ImageWidget.o \
./src/KeyManageable.o \
./src/ListenerComponent.o \
./src/LogManager.o \
./src/Program.o \
./src/RenderComponent.o \
./src/RenderContext.o \
./src/SPIManager.o \
./src/SerialManager.o \
./src/Shader.o \
./src/ShadingProgramManager.o \
./src/SplashView.o \
./src/State.o \
./src/StateMachine.o \
./src/StateManager.o \
./src/SubjectComponent.o \
./src/SwitchScreenAction.o \
./src/TelemetryWidget.o \
./src/TextWidget.o \
./src/Texture.o \
./src/TextureManager.o \
./src/TimerWidget.o \
./src/TransformComponent.o \
./src/TxBatteryMeterWidget.o \
./src/UIWidget.o \
./src/VertexDeclarations.o \
./src/VertexDefinitionManager.o \
./src/View.o \
./src/ViewManager.o \
./src/Widget.o \
./src/afx.o \
./src/artrix.o 

CPP_DEPS += \
./src/AttitudeIndicatorWidget.d \
./src/BMFontManager.d \
./src/ButtonWidget.d \
./src/CircularGaugeWidget.d \
./src/Command.d \
./src/Component.d \
./src/DownloadManager.d \
./src/FTFontManager.d \
./src/FlapsWidget.d \
./src/GameObject.d \
./src/GameObjectFactory.d \
./src/Geometry.d \
./src/ImageWidget.d \
./src/KeyManageable.d \
./src/ListenerComponent.d \
./src/LogManager.d \
./src/Program.d \
./src/RenderComponent.d \
./src/RenderContext.d \
./src/SPIManager.d \
./src/SerialManager.d \
./src/Shader.d \
./src/ShadingProgramManager.d \
./src/SplashView.d \
./src/State.d \
./src/StateMachine.d \
./src/StateManager.d \
./src/SubjectComponent.d \
./src/SwitchScreenAction.d \
./src/TelemetryWidget.d \
./src/TextWidget.d \
./src/Texture.d \
./src/TextureManager.d \
./src/TimerWidget.d \
./src/TransformComponent.d \
./src/TxBatteryMeterWidget.d \
./src/UIWidget.d \
./src/VertexDeclarations.d \
./src/VertexDefinitionManager.d \
./src/View.d \
./src/ViewManager.d \
./src/Widget.d \
./src/afx.d \
./src/artrix.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DGL_GLEXT_PROTOTYPES -I../include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


