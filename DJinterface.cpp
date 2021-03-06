//Created by Ryan King on 12/10/

#include <iostream>
#include <sstream>
#include "Song.h"
#include "Playlist.h"
#include "SongList.h"
#include "SongLinked.h"
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

    std::cout<<"\n"<<"Testing getInfo" <<std::endl;
    std::cout<<"Expecting  Bop-Boop–3.500000–0 " <<std::endl;
    std::cout << song1->getInfo() << std::endl;

    std::cout<<'\n'<<"Expecting  -–0.000000–0 " <<std::endl;
    std::cout <<  song2->getInfo() << std::endl;

    std::cout<< "\n"<<"Testing addToPlayCount" <<std::endl;
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

    std::cout<<"Testing addSong and getInfo" <<std::endl;
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
    printAssertEquals(0, playlist1->calcDuration());

    std::cout<<"Testing playNext" <<std::endl;
    std::cout<<"Expecting A-A-3.000000-0" <<std::endl;
    std::cout<<"Got "<<playlist2->playNext()<<std::endl;
    std::cout<<"Expecting B-B-2.000000-0"<< std::endl;
    std::cout <<"Got " <<playlist2->playNext()<<std::endl;
    printAssertEquals(1, song1->getPlayCount());
    printAssertEquals(1, song2->getPlayCount());
    std::cout<<"Expecting C-C-3.000000-0"<<std::endl;
    std::cout <<"Got " << playlist2->playNext() << std::endl;
    std::cout<<"Expecting F-F-2.000000-0"<< std::endl;
    std::cout <<"Got " << playlist2->playNext()<<std::endl;
    std::cout<<"Expecting G-G-3.000000-0"<<std::endl;
    std::cout <<"Got " << playlist2->playNext()<< std::endl;

    printAssertEquals(false, playlist2->isEmpty());
    printAssertEquals(true, playlist1->isEmpty());

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
    Song* song8 = new Song("Duck", "D", 4.0);

    List* songList1 = new SongList(10);
    List* songList2 = new SongList(10);
    List* songList3 = new SongList(10);
    List* songList4 = new SongList(10);
    List* songList5 = new SongList(10);

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
    songList3->addAlphabetical(song8);
    songList3->addAlphabetical(song2);
    songList3->addAlphabetical(song3);
    songList3->addAlphabetical(song1);
    songList3->addAlphabetical(song6);
    std::cout<<songList3->toString() <<std::endl;

    std::cout<<"Testing isEmpty" <<std::endl;
    printAssertEquals(true, songList4->isEmpty());
    printAssertEquals(false, songList3->isEmpty());

    std::cout<<"Testing itemCount" <<std::endl;
    printAssertEquals(8, songList3->itemCount());
    printAssertEquals(0, songList4->itemCount());
    songList4->addSong(song5);
    printAssertEquals(1, songList4->itemCount());
    songList4->addSong(song4);
    printAssertEquals(2, songList4->itemCount());
    printAssertEquals(4, songList1->itemCount());

    std::cout<<"Testing findArtist" <<std::endl;
    std::cout<<songList4->findArtist("A") <<std::endl;
    std::cout<<songList3->findArtist("A") <<std::endl;
    std::cout<<songList3->findArtist("B") <<std::endl;
    std::cout<<songList3->findArtist("C") <<std::endl;
    std::cout<<songList3->findArtist("D") <<std::endl;
    std::cout<<songList3->findArtist("E") <<std::endl;

    std::cout<<"Testing findSong" <<std::endl;

    std::cout<<"Testing getValueAt" <<std::endl;
    printAssertStringEqual("Bone", songList1->getValueAt(0)->getTitle());
    printAssertStringEqual("Car", songList1->getValueAt(1)->getTitle());
    printAssertStringEqual("Dog", songList1->getValueAt(2)->getTitle());
    printAssertStringEqual("Top", songList1->getValueAt(3)->getTitle());

    printAssertStringEqual("Box", songList3->getValueAt(3)->getTitle());
    printAssertStringEqual("Bone", songList3->getValueAt(0)->getTitle());
    printAssertStringEqual("Duck", songList3->getValueAt(7)->getTitle());

    if(songList4->getValueAt(10) == nullptr)
        std::cout<<"pass" <<std::endl;
    else
        std::cout<<"FAIL" <<std::endl;
    if(songList5->getValueAt(0) == nullptr)
        std::cout<<"pass" <<std::endl;
    else
        std::cout<<"FAIL" <<std::endl;

    std::cout<<"Testing calcDuration" <<std::endl;
    printAssertEquals(0.0, songList5->calcDuration());
    printAssertEquals(12.0, songList1->calcDuration());
    printAssertEquals(10.0, songList2->calcDuration());
    printAssertEquals(24.0, songList3->calcDuration());

    std::cout<<"Testing removeSong" <<std::endl;
    std::cout<<songList3->toString() <<std::endl;
    songList3->removeSong("Bone", "A");
    printAssertEquals(7, songList3->itemCount());
    std::cout<<songList3->toString() <<std::endl;
    songList3->removeSong("Top", "B");
    printAssertEquals(6, songList3->itemCount());
    std::cout<<songList3->toString() <<std::endl;
    songList3->removeSong("Duck", "D");
    printAssertEquals(5, songList3->itemCount());
    std::cout<<songList3->toString() <<std::endl;
//we throw exceptions if it asks for song that's not in the list
//doesn't work well with the tester


    delete song1;
    delete song2;
    delete song3;
    delete song4;
    delete song5;
    delete song6;
    delete song7;
    delete song8;

    delete songList1;
    delete songList2;
    delete songList3;
    delete songList4;
    delete songList5;
}

void songLinkedTester(){
    Song* song1 = new Song("Bone", "A", 3.0);
    Song* song2 = new Song("Car", "A", 2.0);
    Song* song3 = new Song("Dog", "A", 3.0);
    Song* song4 = new Song("Top", "B", 4.0);
    Song* song5 = new Song("Box", "B", 3.0);
    Song* song6 = new Song("Jack", "C", 2.0);
    Song* song7 = new Song("Raft", "C", 3.0);

    List* songLinked1 = new SongLinked();
    List* songLinked2 = new SongLinked();

    std::cout << "Testing isEmpty"<<std::endl;

    std::cout << "Testing empty songlist"<<std::endl;
    printAssertBoolEquals(true,songLinked1->isEmpty());

    std::cout <<'\n'<< "Adding a song"<<std::endl;
    songLinked1->addSong(song1);

    std::cout << "Seeing if isEmpty works on playlist with content"<<std::endl;
    printAssertBoolEquals(false,songLinked1->isEmpty());

    std::cout << "Current item Count should be 1"<<std::endl;
    printAssertEquals(1,songLinked1->itemCount());

    std::cout << '\n'<< "More adding and item count tests"<<std::endl;
    songLinked1->addSong(song2);
    printAssertEquals(2,songLinked1->itemCount());
    songLinked1->addSong(song3);
    printAssertEquals(3,songLinked1->itemCount());
    songLinked1->addSong(song4);
    printAssertEquals(4,songLinked1->itemCount());
    songLinked1->addSong(song5);
    printAssertEquals(5,songLinked1->itemCount());
    songLinked1->addSong(song6);
    printAssertEquals(6,songLinked1->itemCount());

    std::cout << '\n'<< "To String Test"<<std::endl;
    std::cout << "Test on playlist with 7 songs in it"<<std::endl;
    std::cout<<songLinked1->toString()<<std::endl;
    std::cout << "Test on playlist with nothing in it"<<std::endl;
    std::cout << songLinked2->toString()<< std::endl;

    std::cout << '\n'<< "Calc Duration Test"<<std::endl;
    printAssertFloatEquals(18.0,songLinked1->calcDuration());
    printAssertFloatEquals(0.0,songLinked2->calcDuration());

    std::cout << '\n'<< "Testing get index"<<std::endl;
    printAssertStringEqual(song1->getTitle(),songLinked1->getValueAt(0)->getTitle());
    printAssertStringEqual(song2->getTitle(),songLinked1->getValueAt(1)->getTitle());
    printAssertStringEqual(song3->getTitle(),songLinked1->getValueAt(2)->getTitle());
    printAssertStringEqual(song4->getTitle(),songLinked1->getValueAt(3)->getTitle());
    //we know that the throw exception will work, but it's gonna mess up our tester if we do that here

    std::cout << '\n'<< "Testing remove song"<<std::endl;
    //this ensures that the song that is supposed to be at the removed song's spot is there
    //this ensures that remove at front, remove at end, and remove work as well
    songLinked1->removeSong(song1->getTitle(),song1->getArtist());
    printAssertStringEqual(song2->getTitle(),songLinked1->getValueAt(0)->getTitle());
    songLinked1->removeSong(song7->getTitle(),song7->getArtist());
    printAssertStringEqual(song6->getTitle(),songLinked1->getValueAt(4)->getTitle());
    songLinked1->removeSong(song4->getTitle(),song4->getArtist());
    printAssertStringEqual(song5->getTitle(),songLinked1->getValueAt(2)->getTitle());

    std::cout << '\n'<< "Testing insert at"<<std::endl;
    songLinked1->insertAt(song1,3);
    std::cout << songLinked1->getValueAt(3)->getTitle()<< std::endl;
    printAssertStringEqual(song1->getTitle(),songLinked1->getValueAt(3)->getTitle());

    songLinked1->insertAt(song7,4);
    printAssertStringEqual(song7->getTitle(),songLinked1->getValueAt(4)->getTitle());
    //we know that it throws an exception for things that are out of range and testing it in the tester won't work
    //won't test duplicate values with insertAt, because it not designed to deal with duplicate values (it's a behind the scenes thing
    // addSong is designed to deal with preventing duplicate values

    std::cout << '\n'<< "Testing attempt to add duplicate values"<<std::endl;
    std::cout << "Here is what it looks like before the attempt"<<std::endl;
    std::cout<<songLinked1->toString()<<std::endl;
    songLinked1->addSong(song1);
    songLinked1->addSong(song7);
    std::cout << '\n'<<"Here is what it looks like after the attempt"<<std::endl;
    std::cout<<songLinked1->toString()<<std::endl;


    std::cout << '\n'<< "Testing find song by title"<<std::endl;
    std::cout << "Trying a song that doesn't exist"<<std::endl;
    printAssertEquals(-1,songLinked1->findSong(song4->getTitle(), song4->getTitle()));


    std::cout << "Trying a song that does exist"<<std::endl;
    printAssertStringEqual(song1->getTitle(),songLinked1->getValueAt(songLinked1->findSong(song1->getTitle(),song1->getArtist()))->getTitle());

    std::cout << '\n'<< "Testing find song by artist"<<std::endl;
    std::cout << "Trying an artist that doesn't exist - expecting '{}' to be returned"<<std::endl;
    std::cout << songLinked1->findArtist("Fake artist") <<std::endl;
    std::cout << "Trying an artist that does exist"<<std::endl;
    printAssertStringEqual(song1->getArtist(),songLinked1->findArtist(song1->getArtist()));

    std::cout << '\n'<< "Testing clear list"<<std::endl;
    songLinked1->clearList();
    printAssertEquals(0,songLinked1->itemCount());

    delete song1;
    delete song2;
    delete song3;
    delete song4;
    delete song5;
    delete song6;
    delete song7;

    delete songLinked1;
    delete songLinked2;
}

void tester(){
    std::cout <<"Song Class Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    songTester();

    std::cout <<"\nPlaylist Class Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    playlistTester();

    std::cout <<"\nSongList Class Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    songListTester();

    std::cout <<"\nSongLinked Tester" << std::endl;
    std::cout <<"-----------------" <<std::endl;
    songLinkedTester();

}

int main(){
    srand(time(NULL));
    //tester();
    userInterface();

    return 0;
}