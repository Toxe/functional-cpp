option(ENABLE_RELWITHDEBINFO_ASSERT "Enable assert() in RelWithDebInfo builds by removing NDEBUG from CMAKE_{C,CXX}_FLAGS_RELWITHDEBINFO" FALSE)

# Enable assert() in RelWithDebInfo builds by removing NDEBUG from CMAKE_{C,CXX}_FLAGS_RELWITHDEBINFO
if (ENABLE_RELWITHDEBINFO_ASSERT)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
        # MSVC and Clang-cl
        set(DNDEBUG_FLAG "/DNDEBUG")
    else ()
        # GCC and Clang
        set(DNDEBUG_FLAG "-DNDEBUG")
    endif ()

    string(REGEX REPLACE ${DNDEBUG_FLAG} "" CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
    string(REGEX REPLACE ${DNDEBUG_FLAG} "" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
endif ()
