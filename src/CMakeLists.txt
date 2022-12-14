add_subdirectory(helpers)
add_subdirectory(std)

set(ALL_TARGETS
        check_unique_chars
        )

foreach (target ${ALL_TARGETS})
    SET(main_target ${target})
    SET(benchmark_target ${target}_benchmark)

    # main
    if (BUILD_TESTING)
        add_executable(${main_target} ${target}.test.cpp ${target}.cpp ${target}.hpp)
        set_target_properties(${main_target} PROPERTIES CXX_EXTENSIONS OFF)
        target_compile_features(${main_target} PUBLIC cxx_std_20)
        target_compile_options(${main_target} PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
        target_link_options(${main_target} PRIVATE ${SANITIZER_LINK_OPTIONS})
        target_link_libraries(${main_target} PRIVATE ${SANITIZER_LINK_LIBRARIES} lib_helpers Catch2::Catch2WithMain)
        add_test(NAME ${main_target} COMMAND ${main_target})
    endif ()

    # benchmark
    add_executable(${benchmark_target} ${target}.benchmark.cpp ${target}.cpp ${target}.hpp)
    set_target_properties(${benchmark_target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${benchmark_target} PUBLIC cxx_std_20)
    target_compile_options(${benchmark_target} PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(${benchmark_target} PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(${benchmark_target} PRIVATE ${SANITIZER_LINK_LIBRARIES} lib_helpers benchmark::benchmark benchmark::benchmark_main)
endforeach ()
