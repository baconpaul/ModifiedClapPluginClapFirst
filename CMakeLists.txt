cmake_minimum_required(VERSION 3.25)

project(ClapPluginCppTemplate LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CLAP_WRAPPER_DOWNLOAD_DEPENDENCIES TRUE CACHE BOOL "Download Dependencies")
set(CLAP_WRAPPER_OUTPUT_NAME "${PROJECT_NAME}")
set(CLAP_WRAPPER_DONT_ADD_TARGETS TRUE)
include(cmake/Dependencies.cmake)



add_library(${PROJECT_NAME} MODULE
    src/Utils.h
    src/Plugin.h
    src/Plugin.cpp
    src/Factory.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC clap clap-helpers)

if (APPLE)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()



# Packaging
if (APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        BUNDLE True
        BUNDLE_EXTENSION clap
        MACOSX_BUNDLE_GUI_IDENTIFIER your.reversed.domain.name.${PROJECT_NAME}
        MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME}
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/ClapPluginCppTemplate.plist.in
    )
endif()

# VST3 target using clap-wrapper
add_library(${PROJECT_NAME}VST3 MODULE)
target_add_vst3_wrapper(
    TARGET ${PROJECT_NAME}VST3
    OUTPUT_NAME "CabbageClapVST3"
)
