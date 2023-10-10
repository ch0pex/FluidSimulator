# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-src"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-build"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
