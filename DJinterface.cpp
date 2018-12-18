//Created by Ryan King on 12/10/

#include <iostream>
#include <sstream>
#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include "Library.h"
#include <fstream>

void fileToLibrary(Library* currentLib, std::string fileName) {
    std::string line;
    std::string artist, title, duration;
    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            getline(infile, line);
            std::stringstream splitter(line);
            if (std::to_string(line.at(0)) != "*") {
                getline(splitter, artist, '-');
                getline(splitter, title, '-');
                getline(splitter, duration, '-');
            }
            if (currentLib->findSong(title, artist) == nullptr) {
                currentLib->importSong(title, artist, stof(duration));
            } else {
                std::cout << "Song: " << title << " by " << artist << " already exists" <<std::endl;
            }

        }
        infile.close();
        std::cout<<"Songs imported" <<std::endl;
    } else {
        std::cout<<"Could not find the requested file" <<std::endl;
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
            DJLibrary->emptyLibrary();
            //We are going to have to revist this one

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
                    std::cout<<"Could not find the given song"<<std::endl;

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

            std::ofstream file(IndivCommand);

            file << DJLibrary->songsInfo();

            file << "\n";
            file << "*";

            file << DJLibrary->playlistsInfo();
            file.close();
            program = false;


            //we may have to revist this and deal with deconstruction or something, idk
        } else{
            std::cout<<"Error. System could not process your command." <<std::endl;
            std::cout<<"Please try again." <<std::endl;

        }
    }
}

void tester(){
    std::cout <<"Song Class Tester" << std::endl;

    std::cout <<"Playlist Class Tester" << std::endl;



    std::cout <<"SongList Class Tester" << std::endl;

    std::cout <<"SongLinked Tester" << std::endl;


    std::cout <<"Song Class Tester" << std::endl;


    std::cout <<"FileOut Tester" << std::endl;

}

int main(){
    srand(time(NULL));
    userInterface();
    tester();


    return 0;
}