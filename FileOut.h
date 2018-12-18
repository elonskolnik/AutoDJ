#ifndef FileOut_H
#define FileOut_H

#include <fstream>
#include <iostream>
#include <string>
#include "SongList.h"
#include "Song.h"
#include "Playlist.h"
#include "Library.h"

class FileOut {

public:

    std::string getSong(Song *currentSong);

    std::string getSongList(SongList *currentSonglist);

    std::string getPlaylists(Playlist *currentPlayList);

    void fileToLibrary(Library* currentLib, std::string fileName);
};
#endif //FileOut_H