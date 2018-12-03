//
// Created by Ryan King on 11/27/18.
//

#ifndef PROJECTPLAYLIST_PLAYLIST_H
#define PROJECTPLAYLIST_PLAYLIST_H
#include <iostream>


class Playlist {
    std::string name;
    mapList* songList;
    int songCount;


public:
    Playlist(std::string name);
    ~Playlist();
    void removeSong(std::string title, std::string artist);
    void addSong(std::string title, std::string artist);
    bool isEmpty();
    std::string playNext();
    float calcDuration();
    std::string getInfo();


};


#endif //PROJECTPLAYLIST_PLAYLIST_H
