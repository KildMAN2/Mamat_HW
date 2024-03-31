cmake_minimum_required(VERSION 3.10)
project(FirewallApplication)

# Specify at least C++11
set(CMAKE_CXX_STANDARD 11)

# Add Google Test directly to our build. This defines
# the gtest and gtest_main targets.
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${YOUR_PROJECT_INCLUDE_DIRS})
add_executable(
        firewall_test
        main.cpp
        ip.cpp
        port.cpp
        string.cpp
        string-array.cpp
        test_firewall.cpp  # Add this line for your test file
        test_firewall.cpp)

target_link_libraries(
        firewall_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(firewall_test)
