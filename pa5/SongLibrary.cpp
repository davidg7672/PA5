/***************
 * Case 5 Unexplainable
***************/

#include "SongLibrary.h"

SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = new Song[numSongs];
	songs = NULL; 
}

// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {
	numSongs = 0;
	delete [] songs;
	songs = nullptr;
}

// Copy constructors
SongLibrary::SongLibrary(const SongLibrary& otherSongLib) {
	numSongs = otherSongLib.numSongs;
	songs = otherSongLib.songs;
}

const SongLibrary & SongLibrary::operator=(const SongLibrary& right) {
	if(this != &right) {
		numSongs = right.numSongs;
		songs = right.songs;
	}
	return *this;
}

int SongLibrary::getNumSongs() {
	return numSongs;
}

void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

Song *SongLibrary::getSongsArray() {
	return songs;
}

void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

// TODO: finish this function
void SongLibrary::displayLibrary() {
	for(int i = 0; i < numSongs; i++) {
		(songs + i)->displaySong();
	}
}

/***********************************************************
Member Function: performLoad()
Inputs: String name of the input file
Outputs: Nothign
General Description: 

This function dynamically allocates memories for proper
amount of songs in the library. It the informaiton and stores
it in the objects respective memory
***********************************************************/
void SongLibrary::performLoad(string filename) {
	ifstream inputFile;
	int size, rating;
	string title, artist, genre, trash;

	// Opening file and making sure it's open
	inputFile.open(filename);
	inputFileOpen(inputFile);

	// Getting the size, the amount of songs
	size = firstReadFromFile(inputFile);

	// Setting num songs and allocating correct amount of memory
	setNumSongs(size);
	songs = new Song[numSongs];

	// Clearing input file so we can re-read it
	inputFile.clear();
  	inputFile.seekg(0, ios::beg);

	// Re-reading file and storing information
	for(int i = 0; i < size; i++) {
		getline(inputFile, title);
		(songs + i)->setTitle(title);

		getline(inputFile, artist);
		(songs + i)->setArtist(artist);

		getline(inputFile, genre);
		(songs + i)->setGenre(genre);

		inputFile>> rating;
		(songs + i)->setRating(rating);

		getline(inputFile, trash);
		getline(inputFile, trash);
	}

	// Closing input file
	inputFile.close();
}

/***********************************************************
Member Function: performSave()
Inputs: String name of the output file
Outputs: Nothing
General Description: 

This function writes out the  data from each of the
songs via memory notation.
***********************************************************/
void SongLibrary::performSave(string filename) {
	ofstream outputFile;

	// Opening file and checking to see if opened properly
	outputFile.open(filename);
	outputFileOpen(outputFile);

	for(int i = 0; i < numSongs; i++) {
		outputFile << "Title: " << (songs + i)->getTitle() << endl;
		outputFile << "Artist: " << (songs + i)->getArtist() << endl;
		outputFile << "Genre: " << (songs + i)->getGenre() << endl;
		outputFile << "Rating: " << (songs + i)->getRating() << endl << endl;
	}
	
	// Closing the output file
	outputFile.close();
}

/***********************************************************
Member Function: performSort()
Inputs: String of attribute
Outputs: Nothing
General Description: 

This function sorts attributes according to what the user input
***********************************************************/
void SongLibrary::performSort(string attribute) {
	Song tempSong;
	int low = 0;

	for(int i = 0; i < numSongs; i++) {
		low = i;
		for(int j = i + 1; j < numSongs; j++) {
			if((songs + j)->getStringAttributeValue(attribute).at(0) < (songs + low)->getStringAttributeValue(attribute).at(0)) {
				low = j;
			}
		}
		tempSong = *(songs + low);
		*(songs + low) = *(songs + i);
		*(songs + i) = tempSong;
	}
}

bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song *foundSong, int *index) {
	string s;

	for(int i = 0; i < numSongs; i++) {
		// assgining s to the title at s
		s = (songs + i)->getStringAttributeValue(searchAttribute);

		// expected output
		// <title> <the ride> <title at (songs + i)> <0/1> \n
		// cout << searchAttribute << " " << searchAttributeValue << " " << s << " " << (searchAttributeValue == s) << endl;
		
		if(s == searchAttributeValue) {
			*foundSong = *(songs + i);
			*index = i;
			return true;
		}
	}
	return false;
}

void SongLibrary::performAddSong(Song newSong) {
	Song *tempSong = songs;

	songs = new Song[numSongs + 1];

	for(int i = 0;i < numSongs; i++) {
		*(songs + i) = *(tempSong + i);
	}

	*(songs + numSongs) = newSong;

	delete [] tempSong;
	tempSong = nullptr;

	numSongs++;
}

void SongLibrary::performRemoveSong(int indexToRemove) {
	Song *tempSong = new Song[numSongs - 1];

	for(int i = 0; i < numSongs; i++) {
		if(indexToRemove == i) {
			continue;
		}
		*(tempSong + i) = *(songs + i);
	}
	Song *songs = new Song[numSongs - 1];
	songs = tempSong;

	delete [] tempSong;
	tempSong = nullptr;

	numSongs--;
}

// TODO: finish this function
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	
}

/***********************************************************
Function: firstReadFromFile()
Inputs: Input file
Outputs: Returns the count of the how many songs
General Description: 

This function reads how many songs there are in the file,
returns that value to be used
***********************************************************/
int firstReadFromFile(ifstream& inputfile) {
	string trash;
	int someTrash, counter = 0;

	while(!inputfile.eof()) {
		getline(inputfile, trash);
		getline(inputfile, trash);
		getline(inputfile, trash);
		inputfile >> someTrash;

		getline(inputfile, trash);
		getline(inputfile, trash);
		counter++;
	}

	return counter;
}

/***********************************************************
Function: inputFileOpen()
Inputs: Input file
Outputs: Returns nothing
General Description: 

This function checks to see if the input file is open
***********************************************************/
void inputFileOpen(ifstream& inputFile) {
    if(!inputFile.is_open()) {
        cout << "File failed to open" << endl;
        exit(-1);
    }
}

/***********************************************************
Function: outputFileOpen()
Inputs: Output File
Outputs: Returns nothing
General Description: 

This function checks to see if the output file is open
***********************************************************/
void outputFileOpen(ofstream& outputFile) {
    if(!outputFile.is_open()) {
        cout << "File failed to open" << endl;
        exit(-1);
    }
}
