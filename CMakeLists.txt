cmake_minimum_required (VERSION 3.6)

project (v5rtmod)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

set(CMAKE_CPP_FLAGS "-fshort-enums -Wno-unknown-attributes -U__INT32_TYPE__ -U__UINT32_TYPE__ -D__INT32_TYPE__=long -D__UINT32_TYPE__='unsigned long' $(DEFINES)")
set(CMAKE_C_FLAGS "-Wall -ansi -std=gnu99")
set(CMAKE_CXX_FLAGS "-Wall -w")
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=return-type")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type -fno-rtti -fno-threadsafe-statics -fno-exceptions -std=gnu++11 -ffunction-sections -fdata-sections -fpermissive")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif(CMAKE_COMPILER_IS_GNUCXX)
if (CMAKE_GENERATOR MATCHES "Visual Studio")
    add_compile_definitions(_MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -EHsc")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-Os")

include_directories(include/)

add_library(${CMAKE_PROJECT_NAME} STATIC
	src/v5_api.cpp
	src/v5_apiuser.cpp
	src/vex_brain.cpp
	src/vex_color.cpp
	src/vex_competition.cpp
	src/vex_console.cpp
	src/vex_controller.cpp
	src/vex_device.cpp
	src/vex_drivetrain.cpp
	src/vex_event.cpp
	src/vex_global.cpp
	src/vex_imu.cpp
	src/vex_mevent.cpp
	src/vex_motor.cpp
	src/vex_motorgroup.cpp
	src/vex_rotation.cpp
	src/vex_smartdrive.cpp
	src/vex_task.cpp
	src/vex_thread.cpp
	src/vex_timer.cpp
	src/vex_triport.cpp
	src/vex_vexlink.cpp
	src/vex_vision.cpp
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
