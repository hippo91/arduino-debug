add_library(SerialDebug STATIC)

target_sources(SerialDebug
               PRIVATE
               ${CMAKE_CURRENT_LIST_DIR}/serial_debug.c
)

target_include_directories(SerialDebug
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

# make cache variables for install destinations
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/ArduinoDebugConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ArduinoDebug
)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfigVersion.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)

install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfig.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/ArduinoDebugConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ArduinoDebug
)

install(
  TARGETS SerialDebug
  EXPORT SerialDebugTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  EXPORT SerialDebugTargets
  FILE ArduinoDebugTargets.cmake
  NAMESPACE ArduinoDebug::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ArduinoDebug
)

install(FILES serial_debug.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
