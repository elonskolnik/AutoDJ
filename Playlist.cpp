//
// Created by Ryan King on 11/27/18.
//
#include <iostream>
#include "Playlist.h"

//constructor
    Playlist::Playlist(){
      this->name = "junk";
      this->songList= new SongList(10);
      this->songCount  0;
}
    Playlist::Playlist(std::string name){
        this->name = name;

        //external mapList - that includes song Name and artist name keys, then the pointer is stored in the arraylist thing
        this->songList= new SongList(10);

        //if upNext is nullptr, that means that the playlist is empty
        //****NOTE FOR DJ implementation - know that the playlist is empty
        this->songCount= 0;
}

//destructor
    Playlist::~Playlist(){
        delete this->songList();
}

    void Playlist::removeSong(std::string title, std::string artist){
        this->songList->removeSong(title,artist);
}
    void Playlist::addSong(std::string title, std::string artist){
        this->songList->addSong(title,artist);

    }
    bool Playlist::isEmpty(){
        if(this->songList->isEmpty()){
            return true;
        }
        return false;

}
    std::string Playlist::playNext(){
        if(this->songList->itemCount <=this->songCount){
            this->songCount=0;
        }
        else{
            songCount+=1;
        }
        return "something";
}
    float Playlist::calcDuration(){
        return this->songList->duration;
}
    std::string Playlist::getInfo(){
        return this->songList->toString();
}

    std::string Playlist::getTitle(){
    return this->name;
}




