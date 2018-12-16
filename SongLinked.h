//
// Created by Ryan King on 12/9/18.
//

#ifndef AUTODJ_SONGLINKED_H
#define AUTODJ_SONGLINKED_H

#include "LinkedNode.h"
#include "Song.h"
#include "List.h"
#include <iostream>

class SongLinked : public List {
private:
    LinkedNode* front;
    LinkedNode* end;
    int currItemCount=0;

    SongLinked(const SongLinked& arrayListToCopy);

    SongLinked& operator=(const SongLinked& arrayListToCopy);

public:

    SongLinked();

    //Destructor
    ~SongLinked();

    void addSong(Song* songToAdd);

    void insertAt(Song* itemToAdd, int index);

    void insertAtEnd(Song* itemToAdd);

    void insertAtFront(Song* itemToAdd);

    Song* removeValueAtEnd();

    std::string toString();

    bool isEmpty();

    int itemCount();

    void clearList();

    std::string findArtist(std::string artist);

    Song* findSong(std::string title, std::string artist);

    void removeSong(std::string title, std::string artist);

    Song* removeValueAtFront();

    Song* removeValueAt(int index);

    Song* getValueAt(int index);

    float calcDuration();

    };

#endif //AUTODJ_SONGLINKED_H
