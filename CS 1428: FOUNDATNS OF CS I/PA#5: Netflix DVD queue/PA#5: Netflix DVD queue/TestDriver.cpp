// File Name: TestDriver.cpp
//
// Author: Jill Seaman
// Date: 4/1/2022
// Assignment Number: 5
// CS 2308/CS 5301
// Instructor: Jill Seaman
//
// A simple test driver for a MovieList.


#include <iostream>
#include "MovieList.h"

using namespace std;

MovieList* movieQueueFromArray(const string titles[], const int SIZE){
    MovieList* movieQueue = new MovieList();
    for (int i = SIZE - 1; i >= 0; --i){
        movieQueue->addToTop(titles[i]);
    }
    return movieQueue;
}

// Random movies I remember with short titles
const int N_TITLES = 8;
string titles[N_TITLES] = {
    "Star Wars",
    "Mary Poppins",
    "Grease",
    "Titanic",
    "Apocalypse Now",
    "Forrest Gump",
    "Slumdog Millionaire",
    "A League of Their Own"
};
MovieList movieQueue;

int main() {
    
    // ---------------------------------------------------------------
    
    cout << "Add to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Add to the bottom and to the top" << endl;
    movieQueue = MovieList();
    movieQueue.addToBottom("Forrest Gump");
    movieQueue.addToTop("Titanic");
    movieQueue.addToBottom("Grease");
    movieQueue.addToTop("Star Wars");
    movieQueue.addToTop("Disaster Movie");
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Count the movies" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    int total = movieQueue.count();
    movieQueue.display(cout);
    cout << "There are " << total << " movie titles in your queue." << endl;
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Remove a movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool removed = movieQueue.remove(3);
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Remove the first movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    removed = movieQueue.remove(0);
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Try to remove a non-existing movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    removed = movieQueue.remove(10);
    cout << "Movie is " << (removed ? "removed": "not removed") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Delete all movies (should be empty)" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    for (int i = 0; i < N_TITLES; ++i){
        movieQueue.remove(0);
    }
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Move a movie to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToTop("Titanic");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Try to move a non-existing movie to the top" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToTop("Not even a movie");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    
    // ---------------------------------------------------------------
    
    cout << "Try to move a non-existing movie" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    moved = movieQueue.moveToTop("NONAME");
    cout << "Movie is " << (moved ? "moved": "not moved") << endl;
    movieQueue.display(cout);
    cout << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Test next larger: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    string nextLarger = movieQueue.nextLarger("Mary Poppins");
    cout << "Next larger to " << "'Mary Poppins' " << "'" << nextLarger << "'" << endl << endl;
    
    cout << "Test next larger again: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Forrest Gump");
    cout << "Next larger to " << "'Forrest Gump' " << "'" << nextLarger << "'" << endl << endl;
 
    cout << "Test next larger again: ";
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Canada");
    cout << "Next larger to " << "'Canada' " << "'" << nextLarger << "'" << endl << endl;

    // ---------------------------------------------------------------
    
    cout << "Test next larger without next larger: ";
    
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    nextLarger = movieQueue.nextLarger("Z");
    cout << "Next larger to " << "'Z' is " << "'" << nextLarger << "'" << endl << endl;
    
    // ---------------------------------------------------------------
    
    cout << "Display sorted movies" << endl;
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    movieQueue.displaySorted(cout);
    cout << endl;
    
    return 0;
}

// Expected output:
//
//Add to the top
//0: Star Wars
//1: Mary Poppins
//2: Grease
//3: Titanic
//4: Apocalypse Now
//5: Forrest Gump
//6: Slumdog Millionaire
//7: A League of Their Own
//
//Add to the bottom and to the top
//0: Disaster Movie
//1: Star Wars
//2: Titanic
//3: Forrest Gump
//4: Grease
//
//Count the movies
//0: Star Wars
//1: Mary Poppins
//2: Grease
//3: Titanic
//4: Apocalypse Now
//5: Forrest Gump
//6: Slumdog Millionaire
//7: A League of Their Own
//There are 8 movie titles in your queue.
//
//Remove a movie
//Movie is removed
//0: Star Wars
//1: Mary Poppins
//2: Grease
//3: Apocalypse Now
//4: Forrest Gump
//5: Slumdog Millionaire
//6: A League of Their Own
//
//Remove the first movie
//Movie is removed
//0: Mary Poppins
//1: Grease
//2: Titanic
//3: Apocalypse Now
//4: Forrest Gump
//5: Slumdog Millionaire
//6: A League of Their Own
//
//Try to remove a non-existing movie
//Movie is not removed
//0: Star Wars
//1: Mary Poppins
//2: Grease
//3: Titanic
//4: Apocalypse Now
//5: Forrest Gump
//6: Slumdog Millionaire
//7: A League of Their Own
//
//Delete all movies (should be empty)
//
//Move a movie to the top
//Movie is moved
//0: Titanic
//1: Star Wars
//2: Mary Poppins
//3: Grease
//4: Apocalypse Now
//5: Forrest Gump
//6: Slumdog Millionaire
//7: A League of Their Own
//
//Try to move a non-existing movie to the top
//Movie is not moved
//0: Star Wars
//1: Mary Poppins
//2: Grease
//3: Titanic
//4: Apocalypse Now
//5: Forrest Gump
//6: Slumdog Millionaire
//7: A League of Their Own
//
//Try to move a non-existing movie
//Movie is not moved
//0: Star Wars
//1: Mary Poppins
//2: Grease
//3: Titanic
//4: Apocalypse Now
//5: Forrest Gump
//6: Slumdog Millionaire
//7: A League of Their Own
//
//Test next larger: Next larger to 'Mary Poppins' 'Slumdog Millionaire'
//
//Test next larger again: Next larger to 'Forrest Gump' 'Grease'
//
//Test next larger again: Next larger to 'Canada' 'Forrest Gump'
//
//Test next larger without next larger: Next larger to 'Z' is ''
//
//Display sorted movies
//0: A League of Their Own
//1: Apocalypse Now
//2: Forrest Gump
//3: Grease
//4: Mary Poppins
//5: Slumdog Millionaire
//6: Star Wars
//7: Titanic

