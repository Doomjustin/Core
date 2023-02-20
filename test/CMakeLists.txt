list(APPEND
    CMAKE_MODULE_PATH
            ${PROJECT_SOURCE_DIR}/cmake
            ${catch2_SOURCE_DIR}/extras
)
include(AddCatch2)
include(CTest)
include(Catch)

add_executable(test-catch2 test_catch2.cpp)
target_link_libraries(test-catch2 PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(test-catch2)