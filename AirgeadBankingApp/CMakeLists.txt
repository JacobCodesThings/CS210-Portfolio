cmake_minimum_required(VERSION 3.27)
project(AirgeadBankingApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(AirgeadBankingApp main.cpp
        savings.h
        savings.cpp
)
