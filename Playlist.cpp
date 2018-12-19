//
// Created by Ryan King on 11/27/18.
//
#include <iostream>
#include "Playlist.h"
#include "SongLinked.h"


//constructor
    Playlist::Playlist(){
      this->name = "junk";
      this->songList= new SongLinked();
      this->songCount = 0;
}
    Playlist::Playlist(std::string name){
        this->name = name;

        //external mapList - that includes song Name and artist name keys, then the pointer is stored in the arraylist thing
        this->songList= new SongLinked();

        //if upNext is nullptr, that means that the playlist is empty
        //****NOTE FOR DJ implementation - know that the playlist is empty
        this->songCount= 0;
}

//destructor
    Playlist::~Playlist(){
        delete this->songList;
}

    void Playlist::removeSong(std::string title, std::string artist){
        this->songList->removeSong(title,artist);
        this->songCount--;
}
    void Playlist::addSong(Song* songToAdd){
        this->songList->addSong(songToAdd);
        this->songCount++;
}
    bool Playlist::isEmpty(){
        return this->songList->isEmpty();
}
    std::string Playlist::playNext(){
        if(isEmpty()){
            return "The current playlist is empty";
        }
        Song* songPtr = songList->getValueAt(0);
        std::string song = songPtr->getInfo();
        songList->getValueAt(0)->addToPlayCount();
        songList->removeSong(songPtr->getTitle(), songPtr->getArtist());
        return song;
}
    float Playlist::calcDuration(){
        return songList->calcDuration();
}
    std::string Playlist::getInfo(){
        return "Total Duration: " + std::to_string(calcDuration()) + "\n" + songList->toString();
}

    std::string Playlist::getTitle(){
        return this->name;
}





