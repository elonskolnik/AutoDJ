//
// Created by Pax on 12/3/2018.
//

#ifndef FINALPROJECTITDS_SONG_H
#define FINALPROJECTITDS_SONG_H

#include <iostream>
class Song {

private:
    std::string artist;
    std::string title;
	float duration;
	int playCount;

public:
	Song();
    Song(std::string title, std::string artist, float duration);
	std::string getInfo();
	std::string getArtist();
	std::string getTitle();
	float getDuration();
	void addToPlayCount();
};


#endif //FINALPROJECTITDS_SONG_H
