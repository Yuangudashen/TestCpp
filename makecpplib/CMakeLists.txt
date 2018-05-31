# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             algorithm

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/classicalpse.h
             src/main/cpp/classicalpse-impl.h
             src/main/cpp/constants.h
             src/main/cpp/convolution.h
             src/main/cpp/convolution-impl.h
             src/main/cpp/correlation.h
             src/main/cpp/correlation-impl.h
             src/main/cpp/dwt.h
             src/main/cpp/dwt-impl.h
             src/main/cpp/fft.h
             src/main/cpp/fft-impl.h
             src/main/cpp/fftmr.h
             src/main/cpp/fftmr-impl.h
             src/main/cpp/fftpf.h
             src/main/cpp/fftpf-impl.h
             src/main/cpp/filtercoefs.h
             src/main/cpp/filtercoefs-impl.h
             src/main/cpp/interpolation.h
             src/main/cpp/matrix.h
             src/main/cpp/matrix-impl.h
             src/main/cpp/spline3interp.h
             src/main/cpp/spline3interp-impl.h
             src/main/cpp/timing.h
             src/main/cpp/timing-impl.h
             src/main/cpp/usingdeclare.h
             src/main/cpp/utilities.h
             src/main/cpp/utilities-impl.h
             src/main/cpp/vector.h
             src/main/cpp/vector-impl.h
             src/main/cpp/vectormath.h
             src/main/cpp/vectormath-impl.h
             src/main/cpp/window.h
             src/main/cpp/window-impl.h

             src/main/cpp/algorithmlib.h
             src/main/cpp/impl.cpp

             src/main/cpp/algorithm.h
             src/main/cpp/algorithm.cpp
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       algorithm

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )