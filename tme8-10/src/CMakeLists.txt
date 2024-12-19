# -*- explicit-buffer-name: "CMakeLists.txt<M1-MOBJ/8-10>" -*-
#
# To display executed commands, use:
#     > cmake -DCMAKE_VERBOSE_MAKEFILE:STRING=YES ../src

 cmake_minimum_required(VERSION 2.8.0)
 project(SCHEMATIC)
 
 set (CMAKE_CXX_FLAGS            "-Wall -g" CACHE STRING "C++ Compiler Release options." FORCE)
 set (CMAKE_INSTALL_PREFIX       "../install" )

 find_package(LibXml2 REQUIRED)
 #find_package(Qt6     REQUIRED)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)


    include_directories( ${SCHEMATIC_SOURCE_DIR}
                         ${LIBXML2_INCLUDE_DIR}
                       )

                    set( includes     Indentation.hpp
                                      XmlUtil.hpp 
                                      Point.hpp
                                      Box.hpp
                                      Term.hpp
                                      Net.hpp
                                      Instance.hpp
                                      Node.hpp
                                      Line.hpp
                                      Shape.hpp
                                      Symbol.hpp
                                      Cell.hpp
                                      
                       )

                    set( mocIncludes  SaveCellDialog.hpp
                                      CellWidget.hpp
                                      CellViewer.hpp
                                      InstancesWidget.hpp
                                      InstancesModel.hpp
				      CellsModel.hpp
				      CellsLib.hpp
				      OpenCellDialog.hpp
                       )

                    set( cpps         Indentation.cpp
                                      XmlUtil.cpp 
                                      Point.cpp
                                      Box.cpp
                                      Term.cpp
                                      Net.cpp
                                      Instance.cpp
                                      Node.cpp
                                      Line.cpp
                                      Shape.cpp
                                      Symbol.cpp
                                      Cell.cpp
                                      SaveCellDialog.cpp
				      OpenCellDialog.cpp
				      CellsLib.cpp
				      CellsModel.cpp
                                      CellWidget.cpp
                                      CellViewer.cpp
                                      InstancesWidget.cpp
                                      InstancesModel.cpp
                                      Main.cpp
                       )

           qt_wrap_cpp( mocCpps      ${mocIncludes} )

         add_executable( tme810       ${cpps} ${mocCpps} )
  target_link_libraries( tme810       ${QT_LIBRARIES} Qt6::Core Qt6::Widgets Qt6::Gui ${LIBXML2_LIBRARIES} )
                install( TARGETS      tme810                      DESTINATION bin )
                install( FILES        ${includes} ${mocIncludes}  DESTINATION include )
