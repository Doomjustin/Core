set(SF_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SF_INTERNAL_INCLUDE_DIR ${SF_INCLUDE_DIR}/Nevermore)

add_library(SF_CORE
    STATIC
        ${SF_INTERNAL_INCLUDE_DIR}/Utility.h
        ${SF_INTERNAL_INCLUDE_DIR}/StringUtility.h
        ${SF_INTERNAL_INCLUDE_DIR}/NumericUtility.h
        ${SF_INTERNAL_INCLUDE_DIR}/FunctionWrapper.h
        ${SF_INTERNAL_INCLUDE_DIR}/ThreadPool.h
        ${SF_INTERNAL_INCLUDE_DIR}/Container/Heap.h
        ${SF_INTERNAL_INCLUDE_DIR}/Timer.h
        ThreadPool.cpp
)
add_library(SF::Core ALIAS SF_CORE)

target_include_directories(SF_CORE PUBLIC ${SF_INCLUDE_DIR})
target_include_directories(SF_CORE PRIVATE ${SF_INTERNAL_INCLUDE_DIR})

target_link_libraries(SF_CORE
    PUBLIC
        fmt::fmt
        spdlog::spdlog
)
