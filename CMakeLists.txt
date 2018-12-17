cmake_minimum_required(VERSION 3.12)
project(AutoDJ)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AutoDJ
        DJinterface.cpp
        Library.cpp
        Library.h
        LinkedNode.cpp
        LinkedNode.h
        List.h
        Playlist.cpp
        Playlist.h
        Song.cpp
        Song.h
        SongLinked.cpp
        SongLinked.h
        SongList.cpp
        SongList.h)
