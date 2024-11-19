# -*- explicit-buffer-name: "CMakeLists.txt<M1-MOBJ/4-5>" -*-
#
# To display executed commands, use:
#         > cmake -DCMAKE_VERBOSE_MAKEFILE:STRING=YES ../src

 cmake_minimum_required(VERSION 2.8.0)
 project(SCHEMATIC)
 
 set (CMAKE_CXX_FLAGS                        "-Wall -g" CACHE STRING "C++ Compiler Release options." FORCE)
 set (CMAKE_INSTALL_PREFIX             "../install" )

#Detextion de LibXml2.
find_package(LibXml2)

        include_directories( ${SCHEMATIC_SOURCE_DIR} ${LIBXML2_INCLUDE_DIR}
                                             )

                                        set( includes         Indentation.hpp
                                                                            Term.hpp
                                                                            Net.hpp
                                                                            Instance.hpp
                                                                            Point.hpp
                                                                            Node.hpp
                                                                            Cell.hpp
                                                                            Box.hpp
                                                                            Symbol.hpp
                                                                            Shape.hpp
                                                                            Line.hpp
                                                                            XmlUtil.hpp
                                             )

                                        set( cpps                 Indentation.cpp
                                                                            Term.cpp
                                                                            Net.cpp
                                                                            Instance.cpp
                                                                            Point.cpp
                                                                            Node.cpp
                                                                            Cell.cpp
                                                                            Box.cpp
                                                                            Symbol.cpp
                                                                            Shape.cpp
                                                                            Line.cpp
                                                                            XmlUtil.cpp
                                                                            Main.cpp
                                             )

                add_executable ( tme7                ${cpps} )
                target_link_libraries(tme7 ${LIBXML2_LIBRARIES})
                             install ( TARGETS            tme7                DESTINATION bin )
                             install ( FILES                ${includes}    DESTINATION include )
