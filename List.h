#ifndef COMP220_ARRAYLIST_H
#define COMP220_ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "Song.h"

//abstract class to hide implementation
class List {

private:
    //Private to disable copying and assigning from outside class, don't implement these methods
    List(const List& listToCopy);
    List& operator=(const List& listToCopy);

public:
    //constructor
    List() {}

    //Destructor
    virtual ~List() {}

    virtual void addSong(Song* songToAdd) =0;

    virtual void addAlphabetical(Song* songToAdd) =0;

    virtual void insertAt(Song* songToAdd, int index) =0;


    virtual std::string toString() =0;

    virtual bool isEmpty() =0;
    
    virtual int itemCount() =0;

    virtual void clearList() =0;

    virtual std::string findArtist(std::string artist) =0;

    virtual int findSong(std::string title, std::string artist) =0;

    virtual void removeSong(std::string title, std::string artist) =0;

    virtual Song* getValueAt(int index) =0;

    virtual float calcDuration() =0;

};


#endif //COMP220_ARRAYLIST_H