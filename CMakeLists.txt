cmake_minimum_required(VERSION 3.16)

project(AudioEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AudioEngine main.cpp
    AudioBuffer.h
    AudioBuffer.cpp
    AudioSource.h
    SineWaveSource.h
    AudioEngine.h
    AudioEngine.cpp
    LowPassFilter.h
    Limiter.h
    Limiter.cpp

)

include(GNUInstallDirs)
install(TARGETS AudioEngine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

