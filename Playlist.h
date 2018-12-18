//
// Created by Ryan King on 11/27/18.
//

#ifndef PROJECTPLAYLIST_PLAYLIST_H
#define PROJECTPLAYLIST_PLAYLIST_H
#include <iostream>
#include "List.h"



class Playlist {
private:
    std::string name;
    List* songList;
    int songCount;


public:
    Playlist();
    Playlist(std::string name);
    ~Playlist();
    void removeSong(std::string title, std::string artist);
    void addSong(Song* songToAdd);
    bool isEmpty();
    std::string playNext();
    float calcDuration();
    std::string getInfo();
    std::string getTitle();
};


#endif //PROJECTPLAYLIST_PLAYLIST_H
