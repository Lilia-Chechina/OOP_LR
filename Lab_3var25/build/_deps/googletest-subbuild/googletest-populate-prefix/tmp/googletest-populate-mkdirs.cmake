# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-src"
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-build"
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/OOP_LR/Lab_3var25/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
