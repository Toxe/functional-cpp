add_library(lib_helpers
        generators.cpp
        generators.hpp
        )

set_target_properties(lib_helpers PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(lib_helpers PUBLIC cxx_std_20)
target_compile_options(lib_helpers PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(lib_helpers PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(lib_helpers PRIVATE ${SANITIZER_LINK_LIBRARIES})
target_include_directories(lib_helpers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(lib_helpers_tests
            generators.test.cpp
            )

    set_target_properties(lib_helpers_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(lib_helpers_tests PUBLIC cxx_std_20)
    target_compile_options(lib_helpers_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(lib_helpers_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(lib_helpers_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} lib_helpers Catch2::Catch2WithMain)

    add_test(NAME lib_helpers_tests COMMAND lib_helpers_tests)
endif ()
