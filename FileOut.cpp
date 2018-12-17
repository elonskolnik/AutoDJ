#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <iterator>

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

    std::vector<std::string> splitter(std::string in_pattern, std::string &content) {
        std::vector<std::string> split_content;

        std::regex pattern(in_pattern);
        copy(std::sregex_token_iterator(content.begin(), content.end(), pattern, -1),
             std::sregex_token_iterator(), back_inserter(split_content));
        return split_content;
    }

//stringFileToLib and readFromFile== file->imported to library
//Takes file in string form
//Go through each line and import each song
    void stringFileToLibrary(std::string stringIn, Library *currentLib) {

        std::vector<std::string> lines = splitter(R"(/n)", stringIn);
        std::string new1;
        std::string new2;
        std::string new3;
        std::string word;
        int clock = 0;

        for (std::string line: lines) {
            std::stringstream stream(line);
            //Skip playLists
            if (line.at(0) != '*') {
                while (getline(stream, word)) {
                    if (clock == 0) {
                        new2 = word;
                        clock++;
                    } else if (clock == 1) {
                        new1 = word;
                        clock++;
                    } else {
                        new3 = word;
                        clock = 0;
                    }

                }
            }
            if (currentLib->findSong(new1, new2) != nullptr) {
                currentLib->importSong(new1, new2, stof(new3));
            } else
                std::cout << "Song: " << new1 << " by Artist: " << new2 << " already exists";

        }
//  1) We have a string with multiple lines
//  2) we split those into an array (vector)
//  3) We print out those elements in a for loop


//turn File into string
        //call stringToLib
        void readFromFile(std::string fileName, Library *currentLib) {
            std::string line;
            std::ifstream myfile;
            myfile.open(fileName);
            if (myfile.is_open()) {
                while (getline(myfile, line)) {
                    std::cout << line << '\n';
                }
                myfile.close();

            } else std::cout << "Unable to open file";

            stringFileToLibrary(line, currentLib);
        }

        void writePlayListsFromLibraryToFile(std::string fileName, Library *currentLibrary) {
            std::ofstream myfile;
            myfile.open(fileName, std::ios::out);
            int i = 0;
            while (currentLibrary->getPlaylist[i] != nullptr) {
                myfile << "*" << currentLibrary->getPlayList[i]->getTitle() << "\n";
                i++;
            }
            myfile.close();
        }
    };