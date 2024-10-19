# Install script for directory: /home/ivan/Shortcuts/m1/mobj/tme/tme4-5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX "../install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
    if(BUILD_TYPE)
        string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
                     CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
    else()
        set(CMAKE_INSTALL_CONFIG_NAME "")
    endif()
    message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
    if(COMPONENT)
        message(STATUS "Install component: \"${COMPONENT}\"")
        set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
    else()
        set(CMAKE_INSTALL_COMPONENT)
    endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
    set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
    set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
    set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tme45" AND
         NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tme45")
        file(RPATH_CHECK
                 FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tme45"
                 RPATH "")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/tme45")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tme45" AND
         NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tme45")
        if(CMAKE_INSTALL_DO_STRIP)
            execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tme45")
        endif()
    endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
    include("/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/CMakeFiles/tme45.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Indentation.hpp"
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Term.hpp"
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Net.hpp"
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Instance.hpp"
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Point.hpp"
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Node.hpp"
        "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/Cell.hpp"
        )
endif()

if(CMAKE_INSTALL_COMPONENT)
    if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
        set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
    else()
        string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
        set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
        unset(CMAKE_INST_COMP_HASH)
    endif()
else()
    set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
    string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
             "${CMAKE_INSTALL_MANIFEST_FILES}")
    file(WRITE "/home/ivan/Shortcuts/m1/mobj/tme/tme4-5/${CMAKE_INSTALL_MANIFEST}"
         "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
