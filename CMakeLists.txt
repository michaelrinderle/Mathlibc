cmake_minimum_required (VERSION 3.8)

project (mathlibc)

if (WIN32)
    add_definitions("-D_CRT_SECURE_NO_WARNINGS")
    add_definitions("-D_CRT_SCL_SECURE_NO_WARNINGS")
    add_definitions("-D_CRT_SECURE_NO_DEPRECATE")
    add_definitions("-D_CRT_NONSTDC_NO_DEPRECATE")
endif(WIN32)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


add_subdirectory("src")
