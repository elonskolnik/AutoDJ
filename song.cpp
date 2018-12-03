//
// Created by Pax on 12/3/2018.
//


#include "LinkedNode.h"

//Constructor
song::song(std::string title, std::string artist, float duration){
    this->title=title;
    this->artist=artist;
    this->duration=duration;
    this->playCount=0;
}
std::string getInfo(){
    std::string newString="";
    newString=newString+artist+" "+title+" "+duration;
}

std::string getArtist(){
    return artist;
}
std::string getTitle(){
    return title;
}
float getDuration(){
    return duration;
}
void addToPlayCount(){
    playCount++;
}
void addToPlayCount(int i){
    playCount=playCount+i;
}