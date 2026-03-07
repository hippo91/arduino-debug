set(exe_name "test_send_data")
add_executable(${exe_name})
target_compile_definitions(${exe_name} PRIVATE "-DBAUD=9600")
target_sources(${exe_name} PRIVATE test_send_data.c)
target_link_libraries(${exe_name} PRIVATE SerialDebug)

set(test_name "Integration_${exe_name}")
add_test(
  NAME ${test_name}
  COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/test_wrapper.sh" "--test-exe" "$<TARGET_FILE:${exe_name}>"
)

set_tests_properties(${test_name}
  PROPERTIES
    PASS_REGULAR_EXPRESSION "Uptime 11:29:08"
)

set(exe_name "test_dump_register")
add_executable(${exe_name})
target_compile_definitions(${exe_name} PRIVATE "-DBAUD=9600")
target_sources(${exe_name} PRIVATE test_dump_register.c)
target_link_libraries(${exe_name} PRIVATE SerialDebug)

set(test_name "Integration_${exe_name}")
add_test(
  NAME ${test_name}
  COMMAND bash "${CMAKE_CURRENT_SOURCE_DIR}/test_wrapper.sh" "--test-exe" "$<TARGET_FILE:${exe_name}>"
)

set_tests_properties(${test_name}
  PROPERTIES
    PASS_REGULAR_EXPRESSION "01010011"
)
