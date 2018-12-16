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
}
    bool Playlist::isEmpty(){
        if(this->songLinked->isEmpty()){
            return true;
        }
        return false;

}
    std::string Playlist::playNext(){
        if(this->songLinked->itemCount() <=this->songCount){
            this->songCount=0;
        }
        else{
            songCount+=1;
        }
        return "something";
}
    float Playlist::calcDuration(){
        return songLinked->CalcDuration();
}
    std::string Playlist::getInfo(){
        return "Total Duration: " + std::to_string(calcDuration()) + " " + songLinked->toString();
}

    std::string Playlist::getTitle(){
        return this->name;
}





