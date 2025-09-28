set(exe_name "test_usart0")
add_executable(${exe_name})
target_compile_definitions(${exe_name} PRIVATE "-DBAUD=9600")
target_sources(${exe_name} PRIVATE test_usart0.c)
target_link_libraries(${exe_name} PRIVATE SerialDebug)

add_test(
  NAME "${exe_name}"
  COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/test_wrapper.sh" "--test-exe" "$<TARGET_FILE:${exe_name}>"
)

set_target_properties(${exe_name}
  PROPERTIES
    PASS_REGULAR_EXPRESSION "Uptime 11:29:08"
)
