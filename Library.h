#ifndef LIBRARY_H
#define LIBRARY_H

#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include <iostream>

class Library {
private:
    SongList* songList;
    Playlist* playlists;
    int playlistCount;

public:
    //Constructor
    Library();

    //Destructor
    ~Library();

    void importSong(std::string title, std::string artist, float duration);

    void newPlaylist(std::string name);

    //creates a new playlist of the given length composed of randomly selected songs
    void genRandomPlaylist(std::string name, float duration);

    //removes the given song from the library of songs
    void discontinue(std::string name, std::string artist);

    //remove all songs from the library and return information about whether any songs couldn’t be removed
    void deleteAll();

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
};

#endif //LIBRARY_H