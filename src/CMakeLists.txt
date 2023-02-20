set(SF_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SF_INTERNAL_INCLUDE_DIR ${SF_INCLUDE_DIR}/Nevermore)

add_library(SF_CORE
    INTERFACE
        ${SF_INTERNAL_INCLUDE_DIR}/Utility.h
        ${SF_INTERNAL_INCLUDE_DIR}/StringUtility.h
        ${SF_INTERNAL_INCLUDE_DIR}/NumericUtility.h
)
add_library(SF::Core ALIAS SF_CORE)

target_include_directories(SF_CORE INTERFACE ${SF_INCLUDE_DIR})

target_link_libraries(SF_CORE
    INTERFACE
        fmt::fmt
        spdlog::spdlog
)
