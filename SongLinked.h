//
// Created by Ryan King on 12/9/18.
//

#ifndef AUTODJ_SONGLINKED_H
#define AUTODJ_SONGLINKED_H

#include "LinkedNode.h"
#include "Song.h"
#include <iostream>

class SongLinked {
private:
    LinkedNode* front;
    LinkedNode* end;
    int currItemCount=0;


    //Private to disable copying and assigning from outside class, don't implement these methods
    SongLinked(const SongLinked& arrayListToCopy);
    SongLinked& operator=(const SongLinked& arrayListToCopy);
public:

    SongLinked();

    //Destructor
    ~SongLinked();

    void addAlphabetical(Song* songToAdd);

    void addSong(Song* songToAdd);

    void insertAtEnd(int itemToAdd);

    int getValueAt(int index);

    std::string toString();

    bool isEmpty();

    int itemCount();

    void clearList();

    std::string SongLinked::find(std::string artist);

    void insertAtFront(int itemToAdd);

    void insertAt(Song* itemToAdd, int index);

    int removeValueAtEnd();

    int removeValueAtFront();

    int removeValueAt(int index);

};

#endif //AUTODJ_SONGLINKED_H
