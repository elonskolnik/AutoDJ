//Created by Elon Skolnik on 11/28/18.

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Song.h"
#include "Playlist.h"
#include "List.h"
#include <iostream>

class Library {
private:
    List* songList;
    Playlist** playlists;
    int playlistCount;
    int playlistCapacity;
    int playlistsize;
    void doubleCapacity();

public:
    //Constructor
    Library(int playlistCapacity);

    //Destructor
    ~Library();

    //imports a song
    void importSong(std::string title, std::string artist, float duration);

    //imports a playlist
    void newPlaylist(std::string name);

    //creates a new playlist of the given length composed of randomly selected songs
    void genRandomPlaylist(std::string name, float duration);

        //removes the given song from the library of songs
    void discontinue(std::string name, std::string artist);

    //save the current library to a file
    void saveLib();

    //return info about all the songs in the library
    std::string songsInfo();

    //return info for all songs by the given artist
    std::string artistInfo(std::string artist);

    //return the names of all playlists and their durations
    std::string playlistsInfo();

    //return the contents of the given playlist
    std::string playlistInfo(std::string title);

    //returns a playlist pointer
    Playlist** getPlaylist();

    //finds a playlist
    Playlist* findPlaylist(std::string title);

    //finds a song
    Song* findSong(std::string title, std::string artist);

    void emptyLibrary();

    void removeFromPlaylist(int index, std::string title, std::string artist);

    void addToPlaylist(int index, Song* SongToAdd);

    void deletePlaylist(std::string title);
    };

#endif //LIBRARY_H