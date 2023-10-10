# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-src"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-build"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/tmp"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src"
  "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/marinabuitrago/Desktop/UC3M/UC3M-23-24/arqui/ArquiCompP1/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
