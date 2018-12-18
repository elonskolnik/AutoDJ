//Created by Elon Skolnik on 12/1/18.

#ifndef COMP220_SONGLIST_H
#define COMP220_SONGLIST_H

#include <stdexcept>
#include <string>
#include "Song.h"
#include "List.h"

class SongList : public List {
private:
    //pointer to the start of the array
    Song** array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity();

public:
    /**
     * Constructor
     * @throws an std::invalid_argument exception if size < 1
     */
    SongList(int initialCapacity);

    //Destructor
    ~SongList();

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void addSong(Song* songToAdd);

    void insertAt(Song* itemToAdd, int index);

    void addAlphabetical(Song* songToAdd);

     /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string toString();

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();

    /**
     * @return a string of all the songs by a particular artist
     */
    std::string findArtist(std::string artist);

    Song* findSong(std::string title, std::string artist);

    void removeSong(std::string title, std::string artist);

    Song** getArray();

    Song* getSongbyIndex(int index);
};


#endif //COMP220_SONGLIST_H