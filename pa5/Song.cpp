#include "Song.h"

/***********************************************************
Function: coverToLowercase()
Inputs: String value
Outputs: Lowercase string value
General Description: 

This function takes in a string, and converts it into a lower
case string
***********************************************************/
string convertToLowercase(string s) {
	for(int i = 0;i < s.length(); i++) {
		if(s[i] > 64 && s[i] < 97) {
			s[i] += 32;
		}
	}
	return s;
}

// Default value constructor
Song::Song() {
	title = "Default Title";
	artist = "Default artist";
	genre = "Default Genre";
	rating = 1;
}

// Explicit value constructor
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = titleParam;
	artist = artistParam;
	genre = genreParam;
	setRating(ratingParam);
}

// Destructor
Song::~Song() {
	title = "";
	artist = "";
	genre = "";
	setRating(1);
}

// Copy Constructors
Song::Song(const Song& otherSong) {
	title = otherSong.title;
	artist = otherSong.artist;
	genre = otherSong.genre;
	setRating(otherSong.rating);
}

const Song & Song::operator=(const Song& right) {
	if(this != &right) {
		title = right.title;
		artist = right.artist;
		genre = right.genre;
		setRating(right.rating);
	}
	return *this;
}


string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

/***********************************************************
Member Function: displaySong()
Inputs: Nothign
Outputs: Returns nothing
General Description: 

This member funciton outputs the songs' title, artist, genre
and rating when called
***********************************************************/
void Song::displaySong() {
	cout << "Song Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Genre: " << genre << endl;
	cout << "Rating: " << rating << endl << endl;
}

/***********************************************************
Member Function: getStringAttributeValue()
Inputs: String of Attribute
Outputs: Return the attribute real value
General Description: 

This function takes in a a string of an attribute, and returns
the actual value according to what was passed in.
***********************************************************/
string Song::getStringAttributeValue(string attribute) {
	if(attribute == "title") {
		return title;
	}
	else if (attribute == "artist") {
		return artist;
	}
	else if(attribute == "genre") {
		return genre;
	}
	else if(attribute == "rating") {
		return to_string(rating);
	}
	return "";
}