cmake_minimum_required(VERSION 3.14)
project(dnaSequence)

set(CMAKE_CXX_STANDARD 98)

add_executable(dnaSequence main.cpp dnaSeq.cpp dnaSeq.h nucleotide.cpp nucleotide.h test.cpp test.h)