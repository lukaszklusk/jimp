
project(balls)

set(HEDEAR_FILES Balls.h)
set(SOURCE_FILES Balls.cpp)

add_library(libballs STATIC ${SOURCE_FILES})
target_include_directories(libballs PUBLIC .)

add_executable(balls ${SOURCE_FILES} main.cpp)

target_link_libraries(balls libballs)

