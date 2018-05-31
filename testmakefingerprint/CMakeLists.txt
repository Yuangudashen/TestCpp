# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             fingerprint

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/export.h
             src/main/cpp/file.h
             src/main/cpp/floatfield.h
             src/main/cpp/fvs.h
             src/main/cpp/fvstypes.h
             src/main/cpp/histogram.h
             src/main/cpp/image.h
             src/main/cpp/imagemanip.h
             src/main/cpp/img_base.h
             src/main/cpp/import.h
             src/main/cpp/matching.h
             src/main/cpp/minutia.h
             src/main/cpp/widget.h

             src/main/cpp/export.cpp
             src/main/cpp/file.cpp
             src/main/cpp/floatfield.cpp
             src/main/cpp/histogram.cpp
             src/main/cpp/image.cpp
             src/main/cpp/imagemanip.cpp
             src/main/cpp/img_base.cpp
             src/main/cpp/img_enhance.cpp
             src/main/cpp/img_morphology.cpp
             src/main/cpp/import.cpp
             src/main/cpp/main.cpp
             src/main/cpp/matching.cpp
             src/main/cpp/minutia.cpp
             src/main/cpp/widget.cpp

             #src/main/cpp/fingerprint.h
             #src/main/cpp/fingerprint.cpp
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
                       fingerprint

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )