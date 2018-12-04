#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include "Library.h"


//so we are probably going to have to change this a lot and basically have it start with the user adding a song and doing a whole list of questions and stuff
//but hopefully this will serve as a sufficient prototype and we'll tell him that we have to revamp the interface a bit

int main(){
    Library* DJLibrary = new Library;
    std::cout<<"Hello Ryan" <<std::endl;
    std::cout<<"" <<std::endl;

    bool program = true;
    std::string command;
    std::string IndivCommand;
    std::string IndivCommand2;
    std::string IndivCommand3;


    std::cout<<"Welcome to the revolutionary Auto DJ." <<std::endl;
    std::cout<<"You're whole universe is about to change." <<std::endl;
    std::cout<<"" <<std::endl;
    std::cout<<"Possible commands are as follows: library, artist, song, import, discontinue, playlists, playlist, new, add, remove, playnext, newrandom, quit" <<std::endl;
    std::cout<<"" <<std::endl;

    while(program){
        std::cout<<"Enter a command or enter 'help' for assistance" <<std::endl;
        std::getline(std::cin, command);

        if(command=="help"){
            std::cout<<"Possible commands are as follows: library, artist, song, import, discontinue, playlists, playlist, new, add, remove, playnext, newrandom, quit" <<std::endl;
        } else if (command == "library"){
            DJLibrary->songsInfo();

            //I think we will have to revisit this and ensure that it handles situations in which there's nothing in the library

        } else if (command == "artist"){
            std::cout<<"Please enter the name of the artist whose songs you want to find." <<std::endl;
            std::getline(std::cin, IndivCommand);

            DJLibrary->artistInfo(IndivCommand);

            //Again, we are going to have to ensure this handles situations where the name is entered incorrectly or there's nothing in the library

        } else if (command == "song"){
            std::cout<<"Please enter the name of the song." <<std::endl;
            std::getline(std::cin, IndivCommand);

            std::cout<<"Please enter the name of the artist of " << IndivCommand << std::endl;
            std::getline(std::cin, IndivCommand2);

            //DJLibrary->songInfo(IndivCommand, IndivCommand2);

            //W***** We need to add some sort of functionality like this probably in the library

            //Again, we are going to have to ensure this handles situations where the name is entered incorrectly or there's nothing in the library

        } else if (command == "import"){
            std::cout<<"We haven't programmed this command yet. But stayed tune " << IndivCommand << std::endl;

            //come back and program this command.

        } else if (command == "discontinue"){

            //We are going to have to revist this one

        } else if (command == "playlists"){
            DJLibrary->playlistsInfo();


        } else if (command == "playlist"){
            std::cout<<"Please enter the name of the playlist you want more information about." <<std::endl;
            std::getline(std::cin, IndivCommand);
            DJLibrary->playlistsInfo(IndivCommand);

        } else if (command == "new"){
            std::cout<<"Please enter the name of the new random playlist you want to create." <<std::endl;
            DJLibrary->newPlaylist(IndivCommand);

        } else if (command == "add"){


            //we are going to have to revisit this


        } else if (command == "remove"){

            //we are going to have to revisit this

        } else if (command == "playnext"){

            //we are going to have to revisit this

        } else if (command == "new random"){
            std::cout<<"Please enter the name of the playlist you want to create." <<std::endl;
            std::getline(std::cin, IndivCommand);

            std::cout<<"Please enter the duration of the playlist you want to create." << IndivCommand << std::endl;
            std::getline(std::cin, IndivCommand2);

            DJLibrary->newPlaylist(IndivCommand, stoi(IndivCommand2));

        } else if (command == "quit"){
            program = false;

            //we may have to revist this and deal with deconstruction or something, idk
        } else{
            std::cout<<"Error. System could not process your command." <<std::endl;
            std::cout<<"Please try again." <<std::endl;

        }
    }

    return 0;
}