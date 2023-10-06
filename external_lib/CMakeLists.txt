add_subdirectory(cmake_workshop_mqtt_lib-main)
#target_link_libraries(MyExecutable MyLibrary)
#project(mqttProject)

#ExternalProject_Add(
#	cmake_workshop_mqtt_lib_w_cmake
#	PREFIX ${CMAKE_BINAIRY_DIR}/_deps
#	GIT_REPOSITORY https://github.com/Hoog-V/CMake_Workshop_Exercise/tree/main/src 
#	GIT_TAG main
#	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
#)

#add_dependencies(rpi_pico_mqtt_lib)