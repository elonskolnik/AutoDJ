//
// Created by Ryan King on 11/26/18.
//

#ifndef AUTODJ_MUSIC_H
#define AUTODJ_MUSIC_H

#include <iostream>

class Music {
private:
    std::string name;
    SongList* songList;


public:
    virtual Music(std::string name);
    virtual ~Music();
    virtual void removeMusic(std::string title)=0;
    virtual void addMusic(Music* MusicToAdd)=0;
    virtual bool isEmpty()=0;
    virtual std::string getInfo()=0;
};

#endif //AUTODJ_MUSIC_H
