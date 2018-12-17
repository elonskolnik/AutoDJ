//
// Created by Ryan King on 11/27/18.
//
#include <iostream>
#include "Playlist.h"
#include "SongLinked.h"


//constructor
    Playlist::Playlist(){
      this->name = "junk";
      this->songLinked= new SongLinked();
      this->songCount = 0;
}
    Playlist::Playlist(std::string name){
        this->name = name;

        //external mapList - that includes song Name and artist name keys, then the pointer is stored in the arraylist thing
        this->songLinked= new SongLinked();

        //if upNext is nullptr, that means that the playlist is empty
        //****NOTE FOR DJ implementation - know that the playlist is empty
        this->songCount= 0;
}

//destructor
    Playlist::~Playlist(){
        delete this->songLinked;
}

    void Playlist::removeSong(std::string title, std::string artist){
        this->songLinked->removeSong(title,artist);
}
    void Playlist::addSong(Song* songToAdd){
        this->songLinked->addSong(songToAdd);
        this->songCount++;
}
    bool Playlist::isEmpty(){
        return this->songLinked->isEmpty();
}
    std::string Playlist::playNext(){
        std::string song = songLinked->getValueAt(0)->getInfo();
        songLinked->getValueAt(0)->addToPlayCount();
        songLinked->removeValueAtFront();
        return song;
}
    float Playlist::calcDuration(){
        return songLinked->calcDuration();
}
    std::string Playlist::getInfo(){
        return "Total Duration: " + std::to_string(calcDuration()) + "\n" + songLinked->toString();
}

    std::string Playlist::getTitle(){
        return this->name;
}





