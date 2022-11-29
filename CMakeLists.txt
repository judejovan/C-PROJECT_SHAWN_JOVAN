cmake_minimum_required(VERSION 3.23)
project(JUDE_JOVAN_C___PROJECT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        JUDE_JOVAN_C___PROJECT
        Airline.cpp Airline.h
        Airport.cpp Airport.h
        Objects.cpp Objects.h
        Routes.cpp Routes.h
        ReadingFile.cpp  SearchingFile.cpp

)
