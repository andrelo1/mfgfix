cmake_minimum_required(VERSION 3.22)

set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

# ---- Project ----
project(
    MfgFix
    VERSION 1.6.1.0
    LANGUAGES CXX
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Plugin.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/include/Plugin.h
    @ONLY
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/version.rc.in
    ${CMAKE_CURRENT_BINARY_DIR}/version.rc
    @ONLY
)

# ---- Globals ----
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Include guards ----
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# ---- Cache build vars ----
macro(set_from_environment VARIABLE)
    if(NOT DEFINED ${VARIABLE} AND DEFINED ENV{${VARIABLE}})
        set(${VARIABLE} $ENV{${VARIABLE}})
    endif()
endmacro()

set_from_environment(VCPKG_ROOT)
if(DEFINED VCPKG_ROOT)
    set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "")
else()
    message(WARNING "Variable VCPKG_ROOT is not set. Continuing without vcpkg.")
endif()

# ---- Dependencies ----
add_subdirectory("./lib/CommonLibSSE" CommonLibSSE)

find_package(spdlog REQUIRED CONFIG)
find_package(binary_io CONFIG REQUIRED)

find_path(DETOURS_INCLUDE_DIRS "detours/detours.h")
find_path(SIMPLEINI_INCLUDE_DIRS "ConvertUTF.c")
find_path(SIMPLEINI_INCLUDE_DIRS "SimpleIni.h")

find_library(DETOURS_LIBRARY detours REQUIRED)

# ---- Add source files ----
include(CMake/source-list.cmake)

source_group(
    TREE "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES ${CXX_FILES}
)

source_group(
    TREE "${CMAKE_CURRENT_BINARY_DIR}"
    FILES "${CMAKE_CURRENT_BINARY_DIR}/include/Plugin.h"
)

    
# ---- Create DLL ----
add_library(
    "${PROJECT_NAME}"
    SHARED
    ${CXX_FILES}
    "${CMAKE_CURRENT_BINARY_DIR}/include/Plugin.h"
    "${CMAKE_CURRENT_BINARY_DIR}/version.rc"
    ".clang-format"
    ".editorconfig"
)

target_compile_features(
    "${PROJECT_NAME}"
    PRIVATE
    cxx_std_23
)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(
        "${PROJECT_NAME}"
        PRIVATE
        "/sdl" # Enable Additional Security Checks
        "/utf-8" # Set Source and Executable character sets to UTF-8
        "/Zi" # Debug Information Format

        "/permissive-" # Standards conformance
        "/Zc:preprocessor" # Enable preprocessor conformance mode

        "/wd4201" # nonstandard extension used : nameless struct/union

        "$<$<CONFIG:DEBUG>:>"
        "$<$<CONFIG:RELEASE>:/Zc:inline;/JMC-;/Ob3>"
    )

    target_link_options(
        "${PROJECT_NAME}"
        PRIVATE
        "$<$<CONFIG:DEBUG>:/INCREMENTAL;/OPT:NOREF;/OPT:NOICF>"
        "$<$<CONFIG:RELEASE>:/INCREMENTAL:NO;/OPT:REF;/OPT:ICF;/DEBUG:FULL>"
    )
endif()

target_include_directories(
    "${PROJECT_NAME}"
    PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${DETOURS_INCLUDE_DIRS}"
    "${SIMPLEINI_INCLUDE_DIRS}"
)

target_link_libraries(
    "${PROJECT_NAME}"
    PRIVATE
    CommonLibSSE
    binary_io::binary_io
    "${DETOURS_LIBRARY}"
    spdlog::spdlog
)

target_precompile_headers(
    "${PROJECT_NAME}"
    PRIVATE
    "src/PCH.h"
)
