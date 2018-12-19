cmake_minimum_required(VERSION 3.12)
project(AutoDJ)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AutoDJ
        DJinterface.cpp
        Library.cpp
        LinkedNode.cpp
        Playlist.cpp
        Song.cpp
        SongLinked.cpp
        SongList.cpp
        TestLib.cpp
        )
