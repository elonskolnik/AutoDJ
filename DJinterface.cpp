#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include "Library.h"


//so we are probably going to have to change this a lot and basically have it start with the user adding a song and doing a whole list of questions and stuff
//but hopefully this will serve as a sufficient prototype and we'll tell him that we have to revamp the interface a bit

int main(){
    std::cout<<"Hello Ryan" <<std::endl;
    std::cout<<"" <<std::endl;

    bool program = true;
    std::string command;

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

        } else if (command == "artist"){

        } else if (command == "song"){

        } else if (command == "import"){

        } else if (command == "discontinue"){

        } else if (command == "playlists"){

        } else if (command == "playlist"){

        } else if (command == "new"){

        } else if (command == "add"){

        } else if (command == "remove"){

        } else if (command == "playnext"){

        } else if (command == "new random"){

        } else if (command == "quit"){
            program = false;

            //we may have to revist this and deal with deconstruction or something, idk
        } else{
            std::cout<<"Error. System could not process your command." <<std::endl;
        }
    }


    return 0;
}