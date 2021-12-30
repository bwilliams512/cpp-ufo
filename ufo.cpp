/*
Codecademy
Learn C++

This project is similar to the classic game Hangman.

Invaders from outer space have arrived and are abducting humans using tractor beams. 
Players must crack the codeword to stop the abduction!
*/

#include <iostream>
#include "ufo_functions.hpp"


int main() {

  greet();

  // Declare and initialize new variables
  std::string codeword = "codecademy";
  std::string answer = "__________";

  int misses = 0;
  // Create a char vector that we can add to on each iteration of the loop
  std::vector<char> incorrect;
  // Create a bool to track whether the player guessed a correct letter
  bool guess = false;
  char letter;

  // Set up while loop that continues as long as both conditions are true
  while (answer != codeword && misses < 7){
    
    // Display the player's abduction status
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;

    // Loop through each character in codeword to see if the player was right
    for (int i = 0; i < codeword.length(); i++) {

      if (letter == codeword[i]) {

        answer[i] = letter;
        guess = true;

      }

    }

    // Check if the player guessed a letter correctly
    if (guess) {
      
      std::cout << "\nCorrect!\n";

    } else {
      
      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;

    }

    guess = false;
    
  }

  end_game(answer, codeword);

}

// To compile: g++ ufo.cpp ufo_functions.cpp
// To execute: ./a.out
