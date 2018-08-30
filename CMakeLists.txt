# CMakeLists.txt

# Always set the cmake min version.
cmake_minimum_required(VERSION 3.0)

set (PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
project(utilitron9000 VERSION ${PROJECT_VERSION})

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Create our library target
add_library(utilitron9000 SHARED)

target_sources(utilitron9000
PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

# This will name your output .so files "libsomething.1.0" which is pretty useful
set_target_properties(utilitron9000
PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
)

# Let's set compiler-specific flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # G++
    target_compile_options(utilitron9000 PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # MSVC
    target_compile_options(utilitron9000 PRIVATE /EHsc /MTd /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(utilitron9000 PRIVATE WIN_EXPORT)
endif()