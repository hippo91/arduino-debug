add_library( SerialDebug STATIC )

target_sources( SerialDebug
                PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/serial_debug.c
)

target_include_directories( SerialDebug
                            PUBLIC 
                            ${CMAKE_CURRENT_LIST_DIR}
                            PRIVATE 
                            /usr/lib/avr/include
)

install(TARGETS SerialDebug DESTINATION lib)
install(FILES serial_debug.h DESTINATION include)