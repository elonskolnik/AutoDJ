#include <fstream>
#include <iostream>
#include <string>

#include "Playlist.h"
#include "Song.h"
#include "Library.h"

class FileOut {


    std::string getSong(Song *currentSong) {
        return currentSong->getInfo();
    }

    std::string getSongList(SongList *currentSonglist) {
        return currentSonglist->toString();
    }

    std::string getPlayLists(Playlist *currentPlayList) {
        return currentPlayList->getInfo();
    }

    void fileToLibrary(const std::string& stringIn, Library* currentLib, std::string fileName){
        std::stringstream splitter (stringIn);
        std::string artist, title, duration;

        ifstream infile(filename);
        if (infile){
            while (infile){
                std::string line;
                getline(infile, line);
                if(line.at(0)!="*"){
                    getline(splitter, artist, ' - ');
                    getline(splitter, title, ' - ');
                    getline(splitter, duration, ' - ');
                }
                if(currentLib->findSong(title,artist)!=nullptr){
                    currentLib->importSong(artist,title,duration);}
                else{
                    std::cout<<"Song: "<<title<<" by Artist: "<<artist<<" already exists";
                }

            }
        }
        else {
            throw FileNotFoundException();
        }
    };