#include <iostream>
#include "Library.h"
#include "Song.h"
#include "SongList.h"
#include "Playlist.h"

//Constructor
Library::Library(){
    songList = new SongList(10);
    playlists = new Playlist[10];
    playlistCount = 0;
}

//Destructor
Library::~Library(){

}

void Library::importSong(std::string title, std::string artist, float duration){
    Song newSong = new Song(title, artist, duration);
    songList->addAlphabetical(newSong);
}

void Library::newPlaylist(std::string name){
    Playlist newPlaylist = new Playlist(name, 0);
    playlists[playlistCount] = newPlaylist;
    playlistCount++;
}

//creates a new playlist of the given length composed of randomly selected songs
void Library::genRandomPlaylist(std::string name, float duration){
    Playlist newPlaylist = new Playlist(name, 0);
    std::string added = new std::string[]
    while(newPlaylist->calcDuration() < duration){

    }
    playlistCount++;
}

//removes the given song from the library of songs
void Library::discontinue(std::string name, std::string artist){
    songList->removeSong(name, artist);
}

//remove all songs from the library and return information about whether any songs couldn’t be removed
void Library::deleteAll(){
    //does it delete the playlists too?
    //todo
}

//save the current library to a file
void Library::saveLib(){
    //todo
}

//return info about all the songs in the library
std::string Library::songsInfo(){
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
        info += playlists[0]->getTitle() + " " + playlists[0]->calcDuration();
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
        throw std::invalid_argument("No playlist called " + title + " in the current library");
    }
    return playlists[index]->getInfo();
}
