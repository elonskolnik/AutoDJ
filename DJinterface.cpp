#include <iostream>
#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include "Library.h"

int main(){
    std::cout<<"Hello Ryan" <<std::endl;

    bool program = true;
    std::string command;

    while(program){
        std::cout<<"Enter a command or enter 'help' for assistance" <<std::endl;
        std::getline(std::cin, command);

        if(command==""){

        }



        else{
            std::cout<<"Error. System could not process your command." <<std::endl;
        }
    }


    return 0;
}