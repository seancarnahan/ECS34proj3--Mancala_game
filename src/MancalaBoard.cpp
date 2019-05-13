#include "MancalaBoard.h"
#include <iostream>
#include <ostream>
#include <string>

//Default constructor should initialize the board
CMancalaBoard::CMancalaBoard(){
    DTurn = 0;
    for(int Index = 0; Index < MANCALA_TOTAL_PITS; Index++){
        DPits[Index] = 4;
    }
    for(int Index = 0; Index < MANCALA_PLAYERS; Index++){
        DStores[Index] = 0;
    }
}

//constructor to set up the board with the amount in each pit, store, and the turn
CMancalaBoard::CMancalaBoard(int turn, const int pits[MANCALA_TOTAL_PITS], const int stores[MANCALA_PLAYERS]){
    DTurn = turn;
    for(int Index = 0; Index < MANCALA_TOTAL_PITS; Index++){
        DPits[Index] = pits[Index];
    }
    for(int Index = 0; Index < MANCALA_PLAYERS; Index++){
        DStores[Index] = stores[Index];
    }
}

//resets the board back to the intial setup
//TODO: Need to reset scores
//TODO: Need to set DTurn to zero
void CMancalaBoard::ResetBoard(){
    for(int Index = 0; Index < MANCALA_TOTAL_PITS; Index++){
        DPits[Index] = 4;
    }

    for(int Index = 0; Index < MANCALA_PLAYERS; Index++){
        DStores[Index] = 0;
    }

}

//returns which players turn it is
int CMancalaBoard::PlayerTurn() const{
  if (GameOver()) {
    return -1;
  }
  return DTurn;
}



//returns the player score,
// -1 should be returned on bad parameter
//returns the player score,
// -1 should be returned on bad parameter
//TODO: check if valid player
int CMancalaBoard::PlayerScore(int player) const{
  if (player < 0 || player >= MANCALA_PLAYERS) {
    return -1;
  }
  return DStores[player];
}

/**
 * Returns the index in DPits for the given (player, pit)
 * Player must be a valid player and pit must be valid.
 * This will return a number between 0 and (MANCALA_PLAYERS * MANCALA_PIT_SLOTS)
 * Otherwise return -1
 */
int CMancalaBoard::GetPitIndex(int player, int pit){
  if (player < 0 || player >= MANCALA_PLAYERS) {
    return -1;
  }
  if (pit < 0 || pit >= MANCALA_PIT_SLOTS) {
    return -1;
  }
  return (player * MANCALA_PIT_SLOTS) + pit;
}

/**
 * Return the number of stones in the given (player, pit)
 */
int CMancalaBoard::PitStoneCount(int player, int pit){
  int idx = GetPitIndex(player, pit);
  if (idx < 0) {
    return -1;
  }
  return DPits[idx];
}

//returns True if the game is over
//TODO: this looks ok
bool CMancalaBoard::GameOver() const{
  for(int Index = 0; Index < MANCALA_TOTAL_PITS; Index++){
    if (DPits[Index] > 0){
      return false;
    }
  }
  return true;
}

//returns string representation form of the board
//TODO: check the string
std::string CMancalaBoard::ToString() const{


    std::string ReturnString  = "P1          PITS\n";
    ReturnString += "      5   4   3   2   1\n";
    ReturnString += R"(/---------------------------\)";
    ReturnString += "\n";
    ReturnString += "|   |";
    for(int Index = MANCALA_PIT_SLOTS-1; Index >= 0; Index--){
        if(DPits[Index] >= 10){
            ReturnString += std::to_string(DPits[Index]) + " |";
        }
        else{
            ReturnString += std::string(" ") + std::to_string(DPits[Index]) + " |";
        }
    }
    ReturnString += "   |\n|";

    if(DStores[0] > 10){
        ReturnString += std::to_string(DStores[0]);
    }
    else{
        ReturnString += std::string(" ") + std::to_string(DStores[0]);
    }
    ReturnString += " |-------------------|";
    if(DStores[1] >= 10){
        ReturnString += std::to_string(DStores[1]);
    }
    else{
        ReturnString += std::string(" ") + std::to_string(DStores[1]);
    }
    ReturnString += " |\n|   |";
    for(int Index = 0; Index < MANCALA_PIT_SLOTS; Index++){
        if(DPits[MANCALA_PIT_SLOTS + Index] >= 10){
            ReturnString += std::to_string(DPits[MANCALA_PIT_SLOTS + Index]) + " |";
        }
        else{
            ReturnString += std::string(" ") + std::to_string(DPits[MANCALA_PIT_SLOTS + Index]) + " |";
        }
    }
    ReturnString += "   |\n";
    ReturnString += R"(\---------------------------/)";
    ReturnString += "\n";
    ReturnString += "      1   2   3   4   5\n";
    ReturnString += "             PITS          P2\n";

    return ReturnString;
}

CMancalaBoard::operator std::string() const{
  return ToString();
}



// Does a move for the player, by taking the stones from the
// specified pit. If the move failed, or it is not the player's
// turn Move should return false. If the move succeeds true
// should be returned
//
//TODO: check if valid player
//TODO: check if valid pit
//
//Is this a valid move?
//TODO: check if valid pit for player
//TODO: is it this player's turn
//TODO: check if empty pit
//
//TODO: if the stones pass over my store - increment my store, no stone added to the next pit
//TODO: if the stones pass over my opp store - no store is incremented, stone is added to the next pit
//
//TODO: if the last stone goes into my store - its still my turn
//
//TODO: if the last stone goes into an empty pit - that stone and any opposite opp stones go into my store
//
//TODO: are the pits incremented after being dropped
//
//
bool CMancalaBoard::Move(int player, int pit){

  int SCORE_DROP = -2;

  //first check if the player can move the stones in the given pit
  int PitIndex = GetPitIndex(player, pit);
  //std::cout<<"Starting move for player["<<player<<"] pit["<<pit<<"]"<<std::endl;

  //this logic should move to GetPitIndex
  if((PitIndex < 0) or (PitIndex > MANCALA_TOTAL_PITS)){
    return false;
  }

  //check if its this players turn
  if (DTurn != player) {
    return false;
  }

  //grabs the stones into hand
  int Stones = PitStoneCount(player, pit);

  //set the where the last stone was dropped
  int LastPitDrop = PitIndex;

  //check if empty pit
  if (Stones <= 0) {
    return false;
  }

  //take stones out of current pit
  DPits[PitIndex] = 0;

  //std::cout<<"@ line "<<__LINE__<<" "<<Stones<<std::endl;
  PitIndex++;

  //sets the pit index to zero if gets to 10
  PitIndex %= MANCALA_TOTAL_PITS;

  while (Stones > 0){

    //checks if at the beginning of a row (i.e. the move passes over a store)
    if((PitIndex % MANCALA_PIT_SLOTS) == 0){

      //is this the store for this player
      if ( (player == (MANCALA_PLAYERS - 1) && PitIndex == 0) ||
	     player == (PitIndex / MANCALA_PIT_SLOTS) - 1) {
	        if (LastPitDrop != SCORE_DROP) {
	           DStores[player]++;
	           LastPitDrop = SCORE_DROP;
	           //std::cout<<" -- At pitindex["<<PitIndex<<"] stones["<<Stones<<"]: turned corner: adding score"<<std::endl;
	         } else {
	            DPits[PitIndex]++;
	            LastPitDrop = PitIndex;
	            //std::cout<<" -- At pitindex["<<PitIndex<<"] stones["<<Stones<<"]: already scored"<<std::endl;
	            PitIndex++;
	         }
         } else {
	          DPits[PitIndex]++;
	          LastPitDrop = PitIndex;
	          //std::cout<<" -- At pitindex["<<PitIndex<<"] stones["<<Stones<<"]: turned corner: NOT adding score"<<std::endl;
	          PitIndex++;
        }
    } else {
      DPits[PitIndex]++;
      LastPitDrop = PitIndex;
      //std::cout<<" -- At pitindex["<<PitIndex<<"] stones["<<Stones<<"]: regular move"<<std::endl;
      PitIndex++;
    }

    Stones--;

    //sets the pit index to zero if gets to 10
    PitIndex %= MANCALA_TOTAL_PITS;
  }


  if (LastPitDrop == SCORE_DROP) {
    //its still my turn
  } else {

    //check for a steal
    if (DPits[LastPitDrop] == 1 &&
	     LastPitDrop >= (player * MANCALA_PIT_SLOTS) &&
	      LastPitDrop < ( (player+1) * MANCALA_PIT_SLOTS )) {

      //std::cout<<" ---- Doing a steal"<<std::endl;
      int OppositeSide = MANCALA_TOTAL_PITS - 1  - LastPitDrop;
      DStores[player] += DPits[OppositeSide] + 1;
      DPits[OppositeSide] = 0;
      DPits[LastPitDrop] = 0;

    } else {
      //do nothing
    }

    //only 2 players - switch players
    DTurn = 1 - DTurn;

    //check if DTurn can move
    bool canMove = false;
    for (int Index = (DTurn * MANCALA_PIT_SLOTS); Index < ((DTurn + 1) * MANCALA_PIT_SLOTS); Index++) {
      if (DPits[Index] > 0) {
	       canMove = true;
      }
    }
    if (!canMove) {
      DTurn = 1 - DTurn;
    }

  }
  return true;
}
