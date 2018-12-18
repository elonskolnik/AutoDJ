//Created by Elon Skolnik on 11/28/18.
//Stores a list of all the songs and a list of playlists on which users can perform basic operations.

#include <iostream>
#include "Library.h"
#include "Song.h"
#include "SongList.h"
#include "Playlist.h"

//Constructor
Library::Library(int playlistCapacity){
    songList = new SongList(10);
    playlists = new Playlist*[10];
    playlistsize=10;
    playlistCount = 0;
    this->playlistCapacity = playlistCapacity;
}

//Destructor
Library::~Library(){
    delete songList;
    delete[] playlists;
}

void Library::doubleCapacity(){
    Playlist** newArray = new Playlist*[this->playlistCapacity*2];
    for(int i = 0; i < playlistCount; i++){
        newArray[i] = playlists[i];
    }
    delete[] playlists;
    playlists = newArray;
    playlistCapacity *= 2;
}

void Library::importSong(std::string title, std::string artist, float duration){
    Song* newSong = new Song(title, artist, duration);
    songList->addSong(newSong);
}

void Library::newPlaylist(std::string name){
    if(playlistCapacity <= playlistCount-1) {
        doubleCapacity();
    }
    Playlist* newPlaylist = new Playlist(name);
    playlists[playlistCount] = newPlaylist;
    playlistCount++;
}

//creates a new playlist of the given length composed of randomly selected songs
void Library::genRandomPlaylist(std::string name, float duration){
    if(playlistCapacity <= playlistCount-1) {
        doubleCapacity();
    }

    bool isThere, check;

    Playlist* newPlaylist = new Playlist(name);

    //generate a random index and pick the song of that index in the list
    int randNum = rand() % songList->itemCount() + 1;
    Song* songToAdd = songList->getArray()[randNum];
    newPlaylist->addSong(songToAdd);

    std::string added[100] = {};
    added[0] = songToAdd->getTitle();
    int addedLength = 1;

    //keep going until it reaches the given duration
    while(newPlaylist->calcDuration() < duration) {
        isThere = false;
        check = false;

        //keeps going until it finds a song that wasn't used already
        while (!check) {
            int randNum = rand() % songList->itemCount() + 1;
            songToAdd = songList->getArray()[randNum];
            for (int i = 0; i < addedLength; i++) {
                if (songToAdd->getTitle().compare(added[i]) == 0)
                    isThere = true;
            }
            if (!isThere)
                check = true;
        }
        if ((newPlaylist->calcDuration() + songToAdd->getDuration()) < duration) {
            newPlaylist->addSong(songToAdd);
            std::cout<<"song added" <<std::endl;
            added[addedLength] = songToAdd->getTitle();
            addedLength++;
        }
    }
    playlists[playlistCount] = newPlaylist;
    playlistCount++;
}

//removes the given song from the library of songs
void Library::discontinue(std::string name, std::string artist){
    songList->removeSong(name, artist);
}

//save the current library to a file
void Library::saveLib(){
    //todo
}

//return info about all the songs in the library
std::string Library::songsInfo(){
    if(songList->isEmpty()){
        return "No songs are in the current library";
    }
    return songList->toString();
}

//return info for all songs by the given artist
std::string Library::artistInfo(std::string artist){
    return songList->findArtist(artist);
}

//return the names of all playlists and their durations
std::string Library::playlistsInfo(){
    if(playlistCount < 0){
        throw std::out_of_range("No playlists are in the current library");
    }

    std::string info = "{";
    for(int i = 0; i < playlistCount; i++){
        info += playlists[i]->getTitle() + " " + std::to_string(playlists[i]->calcDuration());
        info += ", " + playlists[i]->getInfo() + "\n";
        if(i < playlistCount -1){
            info += ", ";
        }
        else{
            info += "}";
        }
    }
    return info;
}

//return the contents of the given playlist
std::string Library::playlistInfo(std::string title){
    int index = -1;
    for (int i = 0; i < playlistCount; i++){
        if(playlists[i]->getTitle() == title){
            index = i;
        }
    }
    if(index < 0){
        return "{}";
    }
    return playlists[index]->getInfo();
}

SongList* Library::getSongList() {
    return songList;
}
Playlist** Library::getPlaylist(){
    return playlists;
}
Playlist* Library::findPlaylist(std::string title){
    int index = -1;
    for(int i = 0; i < playlistCount; i++){
        if(title == playlists[i]->getTitle()){
            index = i;
        }
    }
    if(index < 0){
        return nullptr;
    }
    return playlists[index];
}

Song* Library::findSong(std::string title, std::string artist){
   return songList->findSong(title, artist);
}

void Library::emptyLibrary(){
    songList->clearList();

    for (int x=0; x<playlistCount;x++){
        delete playlists[x];
    }
    delete playlists;
}

void Library::removeFromPlaylist(int index, std::string title, std::string artist){
    playlists[index]->removeSong(title, artist);

}

void Library::addToPlaylist(int index, Song* SongToAdd){
    playlists[index]->addSong(SongToAdd);
}

void Library::deletePlaylist(std::string title){
    int index = -1;
    for(int i = 0; i < playlistCount; i++){
        if(title == playlists[i]->getTitle()){
            index = i;
        }
    }
    delete playlists[index];
    for (int i = index; i < playlistCount; i++){
        playlists[i] = playlists[i+1];
    }
    playlistCount--;
}