cmake_minimum_required(VERSION 3.25)

project(ClapPluginCppTemplate LANGUAGES CXX VERSION 0.1)

if (APPLE)
    enable_language(OBJC)
    enable_language(OBJCXX)
    set(CMAKE_OBJC_VISIBILITY_PRESET hidden)
    set(CMAKE_OBJCXX_VISIBILITY_PRESET hidden)
endif()

option(COPY_AFTER_BUILD "Install local copy aftger build" TRUE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CLAP_WRAPPER_DOWNLOAD_DEPENDENCIES TRUE CACHE BOOL "Download Dependencies")
set(CLAP_WRAPPER_OUTPUT_NAME "${PROJECT_NAME}")
set(CLAP_WRAPPER_DONT_ADD_TARGETS TRUE)
include(cmake/Dependencies.cmake)

set(PRODUCT_NAME "ClapPluginTemplateExample")


add_library(${PROJECT_NAME}-impl STATIC
    src/Utils.h
    src/Plugin.h
    src/Plugin.cpp
    src/FactoryImpl.cpp
)

target_link_libraries(${PROJECT_NAME}-impl PUBLIC clap clap-helpers)

if (APPLE)
    target_compile_options(${PROJECT_NAME}-impl PRIVATE -Wall -Wextra -pedantic)
endif()




make_clapfirst_plugins(
        TARGET_NAME ${PROJECT_NAME}
        IMPL_TARGET ${PROJECT_NAME}-impl

        OUTPUT_NAME "${PRODUCT_NAME}"

        ENTRY_SOURCE src/Factory.cpp

        BUNDLE_IDENTIFER "org.yourproject.yourthing"
        BUNDLE_VERSION ${PROJECT_VERSION}

        COPY_AFTER_BUILD ${COPY_AFTER_BUILD}

        PLUGIN_FORMATS CLAP VST3 # AUV2

        ASSET_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_assets


)
