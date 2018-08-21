cmake_minimum_required(VERSION 2.9)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		CMAKE_ARGS  -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
					-DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
					-DCMAKE_CXX_FLAGS=
					-Dgtest_force_shared_crt=ON
					-DBUILD_GTEST=ON
		PREFIX "/home/simon/Volume/programming/jenkins_tests/HelloWorld/build/gtest"
		SOURCE_DIR        "/home/simon/Volume/programming/jenkins_tests/HelloWorld/build/googletest-src"
  		BINARY_DIR        "/home/simon/Volume/programming/jenkins_tests/HelloWorld/build/googletest-build"
		INSTALL_COMMAND ""
		)

