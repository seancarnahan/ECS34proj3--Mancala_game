#include "MancalaBoard.h"
#include <iostream>


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
}

//returns which players turn it is
//players are 0 and 1
//should increment turn, should use modulo of the current DTurn
//actually the increment should be done in move instead
int CMancalaBoard::PlayerTurn() const{
    return DTurn;
}



//returns the player score,
// -1 should be returned on bad parameter
//returns the player score,
// -1 should be returned on bad parameter
//TODO: check if valid player
int CMancalaBoard::PlayerScore(int player) const{
    return DStores[player];
}

//TODO: New Method  returns the index within DPits[] for the given player and pit
//TODO: check if valid player
//TODO: check if valid pit
//TODO: check if valid pit for player
//TODO: check if this is a valid index. if it isnt return -1;
int CMancalaBoard::GetPitIndex(int player, int pit){
  return player * MANCALA_PIT_SLOTS + pit;
}


//returns the number of stones in a player's pit
//returns -1 on a bad parameter
//TODO: if index is not -1
int CMancalaBoard::PitStoneCount(int player, int pit){
    return DPits[player * MANCALA_PIT_SLOTS + pit];
}

//returns True if the game is over
//TODO: this looks ok
bool CMancalaBoard::GameOver() const{
    for(int Index = 0; MANCALA_TOTAL_PITS; Index++){
        if(DPits[Index]){
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
    ReturnString += "/---------------------------\\\n";
    ReturnString += "|   |";
    for(int Index = 0; Index < MANCALA_PIT_SLOTS; Index++){
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
    ReturnString += "\\---------------------------/\n";
    ReturnString += "      1   2   3   4   5\n";
    ReturnString += "             PITS          P2\n";

    return ReturnString;
}

CMancalaBoard::operator std::string() const{
    std::string ReturnString  = "P1          PITS\n";
    ReturnString += "      5   4   3   2   1\n";
    ReturnString += "/---------------------------\\\n";
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

    if(DStores[0] >= 10){
        ReturnString += std::to_string(DStores[0]);
    }
    else{
        ReturnString += std::string(" ") + std::to_string(DStores[0]);
    }
    ReturnString += " |-------------------|";
    if(DStores[1] > 10){
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
    ReturnString += "\\---------------------------/\n";
    ReturnString += "      1   2   3   4   5\n";
    ReturnString += "             PITS          P2\n";

    return ReturnString;
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


  //first check if the player can move the stones in the given pit
  int PitIndex = GetPitIndex(player, pit);

  //this logic should move to GetPitIndex
  if((PitIndex < 0) or (PitIndex > MANCALA_TOTAL_PITS)){
    return false;
  }

  //check if its this players turn

  //grabs the stones into hand
  int Stones = PitStoneCount(player, pit);

  //set the where the last stone was dropped
  int LastPitDrop = PitIndex;

  //check if empty pit

  //take stones out of current pit
  DPits[PitIndex] = 0;

  //std::cout<<"@ line "<<__LINE__<<" "<<Stones<<std::endl;
  while(Stones > 1){
    PitIndex++;

    //checks if at the beginning of a row (i.e. the move passes over a store)
    if((PitIndex % MANCALA_PIT_SLOTS) == 0){

      //is this the store for this player
      if(player == (PitIndex / MANCALA_PIT_SLOTS) - 1){
	DStores[player]++;
	Stones--;
      }

    } else {
      //do nothing because this is not this player's store
    }

    //sets the pit index to zero if gets to 10
    PitIndex %= MANCALA_TOTAL_PITS;

    //increments the stones in that pit
    //decreases the total stones in hand
    if(Stones){
      DPits[PitIndex]++;
      Stones--;
      LastPitDrop = PitIndex;
    }

  }

  //I think this a bug
  PitIndex++;
  PitIndex %= MANCALA_TOTAL_PITS;

  //
  if(DPits[PitIndex] == 0){
    //std::cout<<"@ line "<<__LINE__<<std::endl;
    int OppositeSide = MANCALA_TOTAL_PITS - 1  - PitIndex;
    DStores[player] += DPits[OppositeSide] + 1;
    DPits[OppositeSide] = 0;
  }
  else if(Stones == 1){
        if((PitIndex % MANCALA_PIT_SLOTS) == 0){
            if(player == (PitIndex / MANCALA_PIT_SLOTS) - 1){
                DStores[player]++;
                Stones--;
            }
        }
        PitIndex %= MANCALA_TOTAL_PITS;
        if(Stones){
            DPits[PitIndex]++;
            Stones--;
            LastPitDrop = PitIndex;
        }
    }
    if((LastPitDrop == MANCALA_PIT_SLOTS) or (PitIndex != MANCALA_PIT_SLOTS)){
        DTurn = 1 - DTurn;
    }
    return true;
}
