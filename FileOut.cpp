#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Playlist.h"
#include "Song.h"
#include "Library.h"
#include "FileOut.h"

std::string FileOut::getSong(Song *currentSong) {
    return currentSong->getInfo();
}

std::string FileOut::getSongList(SongList *currentSonglist) {
    return currentSonglist->toString();
}

std::string FileOut::getPlaylists(Playlist *currentPlayList) {
    return currentPlayList->getInfo();
}

void FileOut::fileToLibrary(Library* currentLib, std::string fileName) {
    std::string line;
    std::stringstream splitter(line);
    std::string artist, title, duration;

    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            getline(infile, line);
            if (std::to_string(line.at(0)) != "*") {
                getline(splitter, artist, ' - ');
                getline(splitter, title, ' - ');
                getline(splitter, duration, ' - ');
            }
            if (currentLib->findSong(title, artist) == nullptr) {
                currentLib->importSong(title, artist, stof(duration));
            } else {
                std::cout << "Song: " << title << " by " << artist << " already exists" <<std::endl;
            }

        }
    } else {
        throw std::runtime_error("Could not find the requested file");
    }
    infile.close();
}