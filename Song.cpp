//
// Created by Pax on 12/3/2018.
//

#include <iostream>
#include "Song.h"
#include <math.h>

//Constructor
Song::Song(){
    title = "paul";
    artist = "blart";
    duration = 999;
    playCount = 999;
}
Song::Song(std::string title, std::string artist, float duration){
    this->title=title;
    this->artist=artist;
    this->duration=duration;
    this->playCount=0;
}
std::string Song::getInfo(){
    return artist+"-"+title+"–"+std::to_string(duration) +"–"+ std::to_string(playCount);
}

std::string Song::getArtist(){
    return artist;
}
std::string Song::getTitle(){
    return title;
}

int Song::getPlayCount(){
    return playCount;
}
float Song::getDuration(){
    return duration;
}
void Song::addToPlayCount(){
    playCount++;
}
