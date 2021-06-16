cmake_minimum_required (VERSION 3.6)

project (VEXcodeDesktop)

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

include_directories(include/ vex/libv5rt/include)
link_directories(vex/libv5rt/lib)

find_library(V5RTMOD_LIBRARY NAMES v5rtmod PATHS vex/libv5rt/lib)

add_executable(${CMAKE_PROJECT_NAME}
	src/main.cpp
	src/robot-config.cpp
)
target_link_libraries(${CMAKE_PROJECT_NAME} ${V5RTMOD_LIBRARY})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})