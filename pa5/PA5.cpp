#include "PA5.h"

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Display library" << endl;
	cout << "2) Load library" << endl;
	cout << "3) Store library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Add song to library" << endl;
	cout << "7) Remove song from library" << endl;
	cout << "8) Edit song in library" << endl;
	cout << "9) Quit" << endl;
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

void executeUserChoice(int choice, SongLibrary& lib) {
	string filename = "library.txt", outputFileName, attribute, attributeValue, trash, title, artist, genre, searchAttributeValue, searchAttribute;
	Song theSong, newSong;
	int index, rating, indexToRemove;
	bool result = false;

	switch (choice) {
		case 1:
			lib.displayLibrary();
			break;
		case 2:
			lib.performLoad(filename);
			break;
		case 3: 
			cout << "Please enter the you would like to save in this format" << endl;
			cout << "<outputFileName>.txt" << endl;
			cin >> outputFileName;

			lib.performSave(outputFileName);
			break;
		case 4:
			cout << "Please enter the attribute you would like to sort" << endl;
			cout << "In lowercase please" << endl;
			cin >> attribute;
			convertToLowercase(attribute);
			lib.performSort(attribute);
			break;
		case 5:
			cout << "What attribute are you looking for?" << endl;
			getline(cin, searchAttribute);
			cout << "What " << searchAttribute << " are you looking for" << endl;
			getline(cin, searchAttributeValue);

			result = lib.performSearch(searchAttribute, searchAttributeValue, &theSong, &index);
			
			if(result) {
				cout << "We found the song" << endl;
				theSong.displaySong();
				cout << "Index: " << index << endl;
			}
			else {
				cout << "We didn't find the song" << endl;
			}
			break;
		case 6:
			addNewSong(title, artist, genre, rating);

			newSong.setTitle(title);
			newSong.setArtist(artist);
			newSong.setGenre(genre);
			newSong.setRating(rating);

		 	lib.performAddSong(newSong);
		 	break;
		case 7:
			cout << "What attribute are you looking for?" << endl;
			getline(cin, attribute);
			cout << "What " << attribute << " are you looking for" << endl;
			getline(cin, attributeValue);

			result = lib.performSearch(attribute, attribute, &theSong, &indexToRemove);
			cout << indexToRemove << endl;

			lib.performRemoveSong(indexToRemove);
			break;
		case 8:
			//lib.editSongInLibrary();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}

void addNewSong(string &title, string &artist, string &genre, int &rating) {
	cout << "Please enter the title" << endl;
	getline(cin, title);

	cout << "Please enter the artist" << endl;
	getline(cin, artist);

	cout << "Please enter the genre" << endl;
	getline(cin, genre);

	cout << "Please enter the rating" << endl;
	cin >> rating;
}