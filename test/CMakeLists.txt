function(sf_add_core_test target source)
    add_executable(${target} ${source})

    set_target_properties(${target}
        PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/
    )

    target_link_libraries(${target}
        PRIVATE
            Catch2::Catch2WithMain
            SF::Core)
    catch_discover_tests(${target})
endfunction()

function(sf_add_core_test_without_catch2 target source)
    add_executable(${target} ${source})

    set_target_properties(${target}
        PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/
    )

    target_link_libraries(${target}
        PRIVATE
            SF::Core
            spdlog::spdlog
            fmt::fmt
    )
endfunction()

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

sf_add_core_test_without_catch2(test-thread-pool test_thread_pool.cpp)
sf_add_core_test_without_catch2(test-timer test_timer.cpp)
sf_add_core_test_without_catch2(test-unit test_unit.cpp)

sf_add_core_test(test-utility test_utility.cpp)
