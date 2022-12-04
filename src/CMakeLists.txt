set(ALL_TARGETS
        std_accumulate
        )

foreach (target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${target} PUBLIC cxx_std_20)
    target_compile_options(${target} PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(${target} PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(${target} PRIVATE ${SANITIZER_LINK_LIBRARIES} lib_helpers)
endforeach ()
