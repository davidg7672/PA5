#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
	public:
		// Constructor and Destructors
		Song();
		Song(string, string, string, int);
		~Song();
		Song(const Song&);
		const Song & operator=(const Song &);

		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);

		void displaySong();
		string getStringAttributeValue(string);

};

#endif