#include <fstream>

FileOut() {


    std::string getSong(Song *currentSong) {
        return currentSong->getInfo();
    }
    std::string getSongList(SongList *currentSonglist) {
        return currentSonglist->toString();
    }
    std::string getPlayLists(Playlist *currentPlayList) {
        return currentPlayList->getInfo();
    }
    void libraryToString(Library *currentLibrary) {
        std::string newString = "PlayList: "getPlayLists(currentLibrary) + "/n""Song List: "getSongList(currentLibrary);
    }

    void writeToFile(std::string fileName, String stringToAdd){
        ofstream myfile;
        myfile.open (fileName,ios::out);
        myfile << stringToAdd<<"\n";
        myfile.close();
    }
    void readFromFile(std::string fileName){
        std::string line;
        ifstream myfile (fileName);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                cout << line << '\n';
            }
            myfile.close();
        }

        else cout << "Unable to open file";
    }

    void printString() {
        std::stringstream splitter(infile);
        std::string words;
        if (splitter) {
            getline(splitter, words, ';');
            while (splitter) {
                std::cout << "\twords:" << words << std::endl;
                getline(splitter, words, ',');
            }
        }
    }

    ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string line;
            getline(infile, line);
//do whatever you want with line…
        }
    } else {
        throw FileNotFoundException();

    }}