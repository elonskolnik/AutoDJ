cmake_minimum_required(VERSION 3.12)
project(AutoDJ)

set(CMAKE_CXX_STANDARD 14)

add_executable(AutoDJ Library.cpp SongList.cpp Song.cpp Playlist.cpp DJinterface.cpp LinkedNode.cpp SongLinked.cpp Tester.cpp)