#include <stdexcept>
#include <iostream>
#include <string>
#include "Song.h"
#include "SongList.h"

/**
 * Constructor
 * @throws an std::invalid_argument exception if size < 1
 */
SongList::SongList(int initialCapacity){
    if(initialCapacity < 1){
        throw std::invalid_argument("Size must be greater than 1");
    }
    currCapacity = initialCapacity;
    array = new Song*[currCapacity];
    currItemCount = 0;
}

/**
 * replaces the old array with an array twice the size
 * private method only called within ArrayList when necessary
 * @post: array points to a new array of twice the size with values copied from the old one,
 *        the old array is deleted.
 */
void SongList::doubleCapacity(){
    Song** newArray = new Song*[this->currCapacity*2];
    for(int i = 0; i < currItemCount; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    currCapacity *= 2;
}

//Destructor
SongList::~SongList(){
    delete[] array;
    array = nullptr;
}

void SongList::insertAt(Song* itemToAdd, int index) {
    if (index < 0 || index > currItemCount) {
        throw std::out_of_range("no item to remove");
    }
    if (currItemCount < currCapacity) {
        for (int x = currItemCount; x > index; x--) {
            array[x] = array[x - 1];
        }
        array[index] = itemToAdd;
        currItemCount += 1;

    } else {
        Song* *newArray = new Song*[currCapacity + 1];
        newArray[0] = itemToAdd;
        for (int x = 0; x < index; x++) {
            newArray[x] = array[x];
        }
        newArray[index] = itemToAdd;
        for (int x = index + 1; x < currCapacity; x++) {
            newArray[x] = array[x - 1];
        }
        Song* *oldArray = array;
        array = newArray;
        newArray = nullptr;
        delete[] oldArray;
        oldArray = nullptr;
        currItemCount += 1;
    }
}


void SongList::addAlphabetical(Song* songToAdd){
    if(currCapacity <= currItemCount-1) {
        doubleCapacity();
    }
    if(currItemCount == 0) {
        array[currItemCount] = songToAdd;
    }
    else{
        for(int x=0; x<currItemCount; x++){
            if (songToAdd->getTitle().compare(array[x]->getTitle())<0){
                insertAt(songToAdd,x);
            }
        }
    }
    currItemCount++;
}
//Possibly get rid of this function below
//_______________________REVISIT THIS!!!!!_________________________________________________________
/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
void SongList::addSong(Song* songToAdd){
    if(currCapacity <= currItemCount-1) {
        doubleCapacity();
    }
    addAlphabetical(songToAdd);
    //array[currItemCount] = songToAdd;
    // currItemCount++;
}

/**
* gives a string representation of the current list
* @returns a string representing the given list
*/
std::string SongList::toString(){
    if(currItemCount == 0){
        return "{}";
    }
    std::string str = "(";
    for(int i = 0; i < currItemCount; i++){
        str += array[i]->getInfo();
        if(i < currItemCount -1){
            str += ", ";
        }
        else{
            str += "}";
        }
    }
    return str;
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
bool SongList::isEmpty(){
    return currItemCount == 0;
}
/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int SongList::itemCount(){
    return currItemCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
void SongList::clearList(){
    currItemCount = 0;
}

/**
 * @return a string of all the songs by a particular artist
 */
std::string SongList::findArtist(std::string artist){
    int count = 0;
    for(int i = 0; i < currItemCount; i++){
        if(array[i]->getArtist() == artist){
            count++;
        }
    }
    if(count == 0){
        return "{}";
    }
    int strCount = 0;
    std::string artists = "{";
    for(int i = 0; i < currItemCount; i++){
        if(array[i]->getArtist() == artist){
            artists += array[i]->getInfo();
            strCount++;
            if(strCount < count){
                artists += ", ";
            }
            else{
                artists += "}";
            }
        }
    }
    return artists;
}

Song* SongList::findSong(std::string title, std::string artist){
    int index = -1;
    for(int i = 0; i < currItemCount; i++){
        if(title == array[i]->getTitle() && artist == array[i]->getArtist()){
            index = i;
        }
    }
    if(index < 0){
        throw std::invalid_argument("Could not find the given song");
    }
    return array[index];
}

void SongList::removeSong(std::string title, std::string artist){
    int index = -1;
    for(int i = 0; i < currItemCount; i++){
        if(array[i]->getTitle() == title && array[i]->getArtist() == artist){
            index = i;
        }
    }
    if(index < 0){
        throw std::invalid_argument("Song not found");
    }
    for (int i = index; i < currItemCount; i++){
        array[i] = array[i+1];
    }
    currItemCount--;
}

Song** SongList::getArray(){
    return this->array;
}

