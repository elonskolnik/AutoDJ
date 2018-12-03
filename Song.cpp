//
// Created by Pax on 12/3/2018.
//


#include "LinkedNode.h"

//Constructor
Song::Song(std::string title, std::string artist, float duration){
    this->title=title;
    this->artist=artist;
    this->duration=duration;
    this->playCount=0;
}
std::string Song::getInfo(){
    std::string newString="";
    newString=newString+artist+" "+title+" "+duration;
}

std::string Song::getArtist(){
    return artist;
}
std::string Song::getTitle(){
    return title;
}
float Song::getDuration(){
    return duration;
}
void Song::addToPlayCount(){
    playCount++;
}
void Song::addToPlayCount(int i){
    playCount=playCount+i;
}