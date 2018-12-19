//Created by Ryan King on 12/10/

#include <iostream>
#include <sstream>
#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include "Library.h"
#include "TestLib.h"
#include <fstream>

void fileToLibrary(Library* currentLib, std::string fileName) {
    std::string line;
    std::string artist, title, duration;
    std::ifstream infile(fileName);
    if (infile) {
        while (getline(infile, line)) {
            std::stringstream splitter(line);
            if (std::to_string(line.at(0)) != "*") {
                getline(splitter, artist, '-');
                getline(splitter, title, '-');
                getline(splitter, duration, '-');
            }
            if (currentLib->findSong(title, artist) == nullptr) {
                currentLib->importSong(title, artist, stof(duration));
            } else {
                std::cout << "Song " << title << " by " << artist << " already exists" <<std::endl;
            }
        }
        infile.close();
        std::cout<<"Songs imported" <<std::endl;
    } else {
        std::cout<<"Could not find the requested file" <<std::endl;
    }
}

void libraryToFile(Library* currentLib, std::string fileout){
    std::ofstream file(fileout);

    file << currentLib->songsInfo();

    file << "\n";
    file << "*";

    file << currentLib->playlistsInfo();
    file.close();
}

void discontinueFile(Library* currentLib, std::string fileName) {
    std::string line;
    std::string artist, title, duration;
    std::ifstream infile(fileName);
    if (infile) {
        while (getline(infile, line)) {
            std::stringstream splitter(line);
            if (std::to_string(line.at(0)) != "*") {
                getline(splitter, artist, '-');
                getline(splitter, title, '-');
                getline(splitter, duration, '-');
            }
            if (currentLib->findSong(title, artist) != nullptr) {
                currentLib->discontinue(title, artist);
            } else {
                std::cout << "Song " << title << " by " << artist << " does not exist in the current library"
                          << std::endl;
            }
        }
        infile.close();
        std::cout << "Songs discontinued" << std::endl;
    }
}

void hardCodeSongs(Library* lib){
    lib->importSong("Come Together", "The Beatles", 4.5);
    lib->importSong("Something", "The Beatles", 4.0);
    lib->importSong("Maxwell's Silver Hammer", "The Beatles", 3.5);
    lib->importSong("Oh! Darling", "The Beatles", 4.3);
    lib->importSong("Octopus' Garden", "The Beatles", 2.8);
    lib->importSong("I Want You", "The Beatles", 3.0);
    lib->importSong("Here Comes the Sun", "The Beatles", 4.5);
    lib->importSong("Because", "The Beatles", 4.0);
    lib->importSong("You Never Give Me Your Money", "The Beatles", 3.5);
    lib->importSong("Sun King", "The Beatles", 4.3);
    lib->importSong("Mean Mr. Mustard", "The Beatles", 2.8);
    lib->importSong("Polythene Pam", "The Beatles", 3.0);
    lib->importSong("She Came in Through the Bathroom Window", "The Beatles", 4.5);
    lib->importSong("Golden Slumbers", "The Beatles", 4.0);
    lib->importSong("Carry That Weight", "The Beatles", 3.5);
    lib->importSong("The End", "The Beatles", 4.3);
    lib->importSong("Her Majesty", "The Beatles", 2.8);

    lib->importSong("Speak To Me", "Pink Floyd", 4.5);
    lib->importSong("Breathe", "Pink Floyd", 4.0);
    lib->importSong("On the Run", "Pink Floyd", 3.5);
    lib->importSong("Time", "Pink Floyd", 2.5);

    //ask why this one song messes things up
    //lib->importSong("The Great Gig in the Sky", "Pink Floyd", 3.2);
    lib->importSong("Money", "Pink Floyd", 2.8);
    lib->importSong("Us and Them", "Pink Floyd", 4.5);
    lib->importSong("Any Colour You Like", "Pink Floyd", 4.0);
    lib->importSong("Brain Damage", "Pink Floyd", 3.5);
    lib->importSong("Eclipse", "Pink Floyd", 2.5);

    lib->importSong("Bones", "Crumb", 4.5);
    lib->importSong("Wolves", "Kanye West", 4.0);
    lib->importSong("Gold Digger", "Kanye West", 3.4);
    lib->importSong("What Does The Fox Say?", "Ylvis", 3.7);
    lib->importSong("High", "Young Thug", 2.5);
}

void userInterface(){
    Library* DJLibrary = new Library(100);
    hardCodeSongs(DJLibrary);
    bool program = true;
    std::string fileName;
    std::string command;
    std::string IndivCommand;
    std::string IndivCommand2;
    std::string IndivCommand3;

    std::cout<<"Welcome to the revolutionary Auto DJ." <<std::endl;
    std::cout<<"Your whole universe is about to change." <<std::endl;
    std::cout<<"" <<std::endl;
    std::cout<<"Possible commands are as follows: library, artist, song, import, discontinue, playlists, playlist, new, add, remove, playnext, newrandom, quit" <<std::endl;
    std::cout<<"" <<std::endl;

    while(program){
        std::cout<<"Enter a command or enter 'help' for assistance:" <<std::endl;
        std::getline(std::cin, command);

        if(command=="help"){
            std::cout<<"Possible commands are as follows: library, artist, song, import, discontinue, playlists, playlist, new, add, remove, playnext, newrandom, quit" <<std::endl;
        } else if (command == "library"){
            std::cout<<DJLibrary->songsInfo() <<std::endl;

        } else if (command == "artist"){
            std::cout<<"Please enter the name of the artist whose songs you want to find:" <<std::endl;
            std::getline(std::cin, IndivCommand);

            if(DJLibrary->artistInfo(IndivCommand) == "{}")
                std::cout<<"Could not find any songs by the artist of the given name." <<std::endl;

            else
                std::cout<<DJLibrary->artistInfo(IndivCommand) <<std::endl;

        } else if (command == "song"){
            std::cout<<"Please enter the name of the song:" <<std::endl;
            std::getline(std::cin, IndivCommand);

            std::cout<<"Please enter the name of the artist: " << std::endl;
            std::getline(std::cin, IndivCommand2);

            if(DJLibrary->findSong(IndivCommand, IndivCommand2) == nullptr)
                std::cout<<"Could not find the given song"<<std::endl;

            else{
                std::cout<<DJLibrary->findSong(IndivCommand, IndivCommand2)->getInfo() <<std::endl;
            }

            //Again, we are going to have to ensure this handles situations where the name is entered incorrectly or there's nothing in the library

        } else if (command == "import"){
            std::cout<<"Please enter the name of the file you want to import:" <<std::endl;
            std::getline(std::cin, IndivCommand);
            fileToLibrary(DJLibrary, IndivCommand);

        } else if (command == "discontinue"){
            std::cout<<"Please enter the name of the file you want to discontinue from: " <<std::endl;
            std::getline(std::cin, IndivCommand);
            discontinueFile(DJLibrary, IndivCommand);

        } else if (command == "playlists"){
            std::cout<<DJLibrary->playlistsInfo() <<std::endl;


        } else if (command == "playlist"){
            std::cout<<"Please enter the name of the playlist you want more information about:" <<std::endl;
            std::getline(std::cin, IndivCommand);

            if(DJLibrary->playlistInfo(IndivCommand)=="{}")
                std::cout<<"Could not find the given playlist." <<std::endl;
            else
                std::cout<<DJLibrary->playlistInfo(IndivCommand) <<std::endl;

        } else if (command == "new"){
            std::cout<<"Please enter the name of the new playlist you want to create:" <<std::endl;
            std::getline(std::cin, IndivCommand);
            DJLibrary->newPlaylist(IndivCommand);
            std::cout<<"New playlist " + IndivCommand + " created." <<std::endl;

        } else if (command == "add"){
            std::cout<<"Please enter the title of the playlist you want to add to:" << std::endl;
            std::getline(std::cin, IndivCommand);
            if(DJLibrary->findPlaylist(IndivCommand) == nullptr){
                std::cout<<"Could not find the given playlist."<<std::endl;
            }
            else {
                std::cout << "Please enter the name of the song you want to add:" << std::endl;
                std::getline(std::cin, IndivCommand2);

                std::cout << "Please enter the artist of the song you want to add:" << std::endl;
                std::getline(std::cin, IndivCommand3);

                if (DJLibrary->findSong(IndivCommand2, IndivCommand3) == nullptr) {
                    std::cout << "Could not find the given song" << std::endl;
                } else {

                    DJLibrary->findPlaylist(IndivCommand)->addSong(DJLibrary->findSong(IndivCommand2, IndivCommand3));

                    std::cout << "Song " + IndivCommand2 + " added to " + IndivCommand + "." << std::endl;
                }
            }

        } else if (command == "remove"){
            std::cout<<"Please enter the name of the playlist you want to remove from: " <<std::endl;
            std::getline(std::cin, IndivCommand);

            if(DJLibrary->findPlaylist(IndivCommand) == nullptr)
                std::cout<<"Could not find the given playlist." <<std::endl;

            else{
                std::cout<<"Please enter the name of the song you want to remove from the playlist: " <<std::endl;
                std::getline(std::cin, IndivCommand2);

                std::cout<<"Please enter the name of the artist: " << std::endl;
                std::getline(std::cin, IndivCommand3);

                if(DJLibrary->findSong(IndivCommand2, IndivCommand3) == nullptr)
                    std::cout<<"Could not find the given song" <<std::endl;

                else{
                    DJLibrary->findPlaylist(IndivCommand)->removeSong(IndivCommand2, IndivCommand3);
                }
            }


        } else if (command == "playnext"){
            std::cout<<"Please enter the name of the playlist you want to play from: " <<std::endl;
            std::getline(std::cin, IndivCommand);

            if(DJLibrary->playlistInfo(IndivCommand) == "{}")
                std::cout<<"Could not find the given playlist"<<std::endl;

            else{
                std::cout<<DJLibrary->findPlaylist(IndivCommand)->playNext()<<std::endl;
            }
            if(DJLibrary->findPlaylist(IndivCommand)->isEmpty()){
                std::cout<<"Last song on the playlist. Playlist deleted." <<std::endl;

                DJLibrary->deletePlaylist(IndivCommand);

            }

        } else if (command == "newrandom"){
            std::cout<<"Please enter the name of the random playlist you want to create:" <<std::endl;
            std::getline(std::cin, IndivCommand);

            std::cout<<"Please enter the duration of the playlist you want to create:" <<std::endl;
            std::getline(std::cin, IndivCommand2);



            DJLibrary->genRandomPlaylist(IndivCommand, stof(IndivCommand2));

            std::cout<<"New playlist " <<IndivCommand <<" created." <<std::endl;

        } else if (command == "quit"){
            std::cout<<"Please enter the name of the file you want to create:" <<std::endl;
            std::getline(std::cin, IndivCommand);
            libraryToFile(DJLibrary, IndivCommand);
            std::cout<<"Library written to file " <<IndivCommand <<std::endl;
            program = false;

        } else{
            std::cout<<"Error. System could not process your command." <<std::endl;
            std::cout<<"Please try again." <<std::endl;

        }
    }
}

void songTester(){
    Song* song1 = new Song("Boop", "Bop", 3.5);
    Song* song2 = new Song("", "", 0.0);

    std::cout<<"Testing getArtist" <<std::endl;
    printAssertStringEqual("Bop", song1->getArtist());
    printAssertStringEqual("", song2->getArtist());

    std::cout<<"Testing getSong" <<std::endl;
    printAssertStringEqual("Boop", song1->getTitle());
    printAssertStringEqual("", song2->getTitle());

    std::cout<<"Testing getDuration" <<std::endl;
    printAssertEquals(3.5, song1->getDuration());
    printAssertEquals(0.0, song2->getDuration());

    std::cout<<"Testing getInfo" <<std::endl;
    printAssertStringEqual("Bop-Boop-3.500000-0", song1->getInfo());
    printAssertStringEqual("--0.000000-0", song2->getInfo());

    std::cout<<"Testing addToPlayCount" <<std::endl;
    song1->addToPlayCount();
    song2->addToPlayCount();
    printAssertEquals(1, song1->getPlayCount());
    printAssertEquals(1, song2->getPlayCount());
    song1->addToPlayCount();
    song1->addToPlayCount();
    printAssertEquals(3, song1->getPlayCount());

    delete song1;
    delete song2;
}

void playlistTester(){
    Song* song1 = new Song("A", "A", 3.0);
    Song* song2 = new Song("B", "B", 2.0);
    Song* song3 = new Song("C", "C", 3.0);
    Song* song4 = new Song("D", "D", 4.0);
    Song* song5 = new Song("E", "E", 3.0);
    Song* song6 = new Song("F", "F", 2.0);
    Song* song7 = new Song("G", "G", 3.0);

    Playlist* playlist1 = new Playlist("Test1");
    Playlist* playlist2 = new Playlist("Test2");

    std::cout<<"Testing getTitle" <<std::endl;
    printAssertStringEqual("Test1", playlist1->getTitle());
    printAssertStringEqual("Test2", playlist2->getTitle());

    std::cout<<"Testing isEmpty" <<std::endl;
    printAssertEquals(true, playlist1->isEmpty());
    playlist1->addSong(song1);
    playlist1->addSong(song2);
    playlist1->addSong(song3);
    printAssertEquals(false, playlist1->isEmpty());

    playlist2->addSong(song1);
    playlist2->addSong(song2);
    playlist2->addSong(song3);
    playlist2->addSong(song4);
    playlist2->addSong(song5);
    playlist2->addSong(song6);
    playlist2->addSong(song7);

    std::cout<<"Testing add song and getInfo" <<std::endl;
    std::cout<<playlist1->getInfo() <<std::endl;
    std::cout<<playlist2->getInfo() <<std::endl;

    std::cout<<"Testing removeSong" <<std::endl;
    playlist1->removeSong("A", "A");
    std::cout<<playlist1->getInfo()<<std::endl;
    playlist1->removeSong("C", "C");
    printAssertEquals(false, playlist1->isEmpty());
    std::cout<<playlist1->getInfo()<<std::endl;
    playlist1->removeSong("B", "B");
    printAssertEquals(true, playlist1->isEmpty());

    std::cout<<"Testing calcDuration" <<std::endl;
    printAssertEquals(20.0, playlist2->calcDuration());
    playlist2->addSong(song6);
    playlist2->addSong(song7);
    printAssertEquals(25.0, playlist2->calcDuration());

    std::cout<<"Testing playNext" <<std::endl;
    printAssertStringEqual("A-A-3.000000-0", playlist2->playNext());
    printAssertStringEqual("B-B-2.000000-0", playlist2->playNext());
    printAssertEquals(1, song1->getPlayCount());
    printAssertEquals(1, song2->getPlayCount());
    printAssertStringEqual("C-C-3.000000-0", playlist2->playNext());
    printAssertStringEqual("F-F-2.000000-0", playlist2->playNext());
    printAssertStringEqual("G-G-3.000000-0", playlist2->playNext());
    printAssertStringEqual("The current playlist is empty", playlist2->playNext());
    printAssertStringEqual("The current playlist is empty", playlist2->playNext());
    printAssertEquals(true, playlist2->isEmpty());

    delete song1;
    delete song2;
    delete song3;
    delete song4;
    delete song5;
    delete song6;
    delete song7;

    delete playlist1;
    delete playlist2;
}

void songListTester(){
    Song* song1 = new Song("Bone", "A", 3.0);
    Song* song2 = new Song("Car", "A", 2.0);
    Song* song3 = new Song("Dog", "A", 3.0);
    Song* song4 = new Song("Top", "B", 4.0);
    Song* song5 = new Song("Box", "B", 3.0);
    Song* song6 = new Song("Jack", "C", 2.0);
    Song* song7 = new Song("Raft", "C", 3.0);

    List* songList1 = new SongList(10);
    List* songList2 = new SongList(10);
    List* songList3 = new SongList(10);

    std::cout<<"Testing addSong and toString" <<std::endl;
    songList1->addSong(song1);
    songList1->addSong(song2);
    songList1->addSong(song3);
    songList1->addSong(song4);

    songList2->addSong(song1);
    songList2->addSong(song4);
    songList2->addSong(song5);
    std::cout<<songList1->toString() <<std::endl;
    std::cout<<songList2->toString() <<std::endl;

    std::cout<<"Testing addAlphabetical" <<std::endl;
    songList3->addAlphabetical(song7);
    songList3->addAlphabetical(song5);
    songList3->addAlphabetical(song4);
    songList3->addAlphabetical(song2);
    songList3->addAlphabetical(song3);
    songList3->addAlphabetical(song1);
    songList3->addAlphabetical(song6);
    std::cout<<songList3->toString() <<std::endl;

    std::cout<<"Testing isEmpty" <<std::endl;
}

void songLinkedTester(){

}

void libraryTester(){

}

void interfaceTester(){

}

void fileTester(){

}


void tester(){
    std::cout <<"Song Class Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    songTester();

    std::cout <<"\nPlaylist Class Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    //playlistTester();

    std::cout <<"\nLibrary Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    libraryTester();

    std::cout <<"\nSongList Class Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    songListTester();

    std::cout <<"\nSongLinked Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    songLinkedTester();



    std::cout <<"\nInterface Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    interfaceTester();

    std::cout <<"\nFile Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    fileTester();
}

int main(){
    srand(time(NULL));
    //userInterface();
    tester();

    return 0;
}