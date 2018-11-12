SET(COVERAGE OFF CACHE BOOL "Coverage")

enable_testing()
#find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})
include_directories(../inc)
include_directories(mocks)

if(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -rdynamic -Wl,--no-as-needed -ldl")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -rdynamic -Wl,-soname -ldl")
endif()

FILE(GLOB src *.cpp)
add_executable(runUnitTests ${src})

# Link test executable against gtest & gtest_main
add_test(runUnitTests runUnitTests)
target_link_libraries(runUnitTests smartpayment gmock_main gmock gtest gtest_main)