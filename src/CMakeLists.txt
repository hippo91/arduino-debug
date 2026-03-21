# make cache variables for install destinations
include(GNUInstallDirs)
set(qualified_install_libdir ${CMAKE_INSTALL_LIBDIR}/ArduinoDebug)
set(qualified_install_cmakedir ${CMAKE_INSTALL_LIBDIR}/ArduinoDebug/cmake)
set(qualified_install_incdir ${CMAKE_INSTALL_INCLUDEDIR}/ArduinoDebug)

add_library(SerialDebug STATIC)

target_sources(SerialDebug
               PRIVATE
               ${CMAKE_CURRENT_LIST_DIR}/serial_debug.c
)

target_include_directories(SerialDebug
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${qualified_install_incdir}>"
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/ArduinoDebugConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfig.cmake"
  INSTALL_DESTINATION ${qualified_install_cmakedir}
)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfigVersion.cmake"
  VERSION "${CMAKE_PROJECT_VERSION}"
  COMPATIBILITY AnyNewerVersion
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfigVersion.cmake"
        DESTINATION ${qualified_install_cmakedir}
)

install(
  TARGETS SerialDebug
  EXPORT SerialDebugTargets
  LIBRARY DESTINATION ${qualified_install_libdir}
  ARCHIVE DESTINATION ${qualified_install_libdir}
  INCLUDES DESTINATION ${qualified_install_incdir}
)

install(
  EXPORT SerialDebugTargets
  FILE ArduinoDebugTargets.cmake
  NAMESPACE ArduinoDebug::
  DESTINATION ${qualified_install_cmakedir}
)

install(FILES serial_debug.h DESTINATION ${qualified_install_incdir})
