#include <gtest/gtest.h>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest){
    // Needs to test that default board is correct
    
    CMancalaBoard gameBoard;
    
    for(int player = 0; player < MANCALA_PLAYERS; player++){
        for (int pit = 0; pit < MANCALA_PITS; pit++){
            EXPECT_EQ(gameBoard.PitStoneCount(player. pit), 4);
        }
        EXPECT_EQ(gameBoard.PlayerScore(player), 0);
    }
    EXPECT_EQ(gameBoard.PlayerTurn(), 0);
}

TEST(MancalaBoardTest, SetBoardTest){
    // Needs to test that setting up an initial board is correct
    
    CMancalaBoard gameBoard;
    int pits[] = {1,2,3,4,5,1,2,3,4,5};
    int scores[] = {5,5};
    CMancalaBoard gameBoard(0, pits, scores);
    
    for(int player = 0; player < MANCALA_PLAYERS; player++){
        for (int pit = 0; pit < MANCALA_PITS; pit++){
            EXPECT_EQ(gameBoard.PitStoneCount(player. pit), pit + 1);
        }
        EXPECT_EQ(gameBoard.PlayerScore(player), 5);
    }
    EXPECT_EQ(gameBoard.PlayerTurn(), 0);
    EXPECT_EQ(std::string(gameBoard), gameBoard.ToString()); //fix tostring
}

TEST(MancalaBoardTest, ResetBoardTest){
    // Needs to test that resetting a board is correct
    
    CMancalaBoard gameBoardSet, gameBoardDefault;
    int pits[] = {1,2,3,4,5,1,2,3,4,5};
    int scores[] = {5,5};
    CMancalaBoard gameBoardSet(0, pits, scores);
    
    for(int player = 0; player < MANCALA_PLAYERS; player++){
        for (int pit = 0; pit < MANCALA_PITS; pit++){
            EXPECT_EQ(gameBoardSet.PitStoneCount(player. pit), pit + 1);
        }
        EXPECT_EQ(gameBoardSet.PlayerScore(player), 5);
    }
    EXPECT_EQ(gameBoardSet.PlayerTurn(), 0);
    EXPECT_EQ(gameBoardSet.ResetBoard(), gameBoardDefault);
}

TEST(MancalaBoardTest, BasicMoveTest){
    // Needs to test that basic non-scoring moves are correct
}

TEST(MancalaBoardTest, ScoringMoveTest){
    // Needs to test that basic scoring, non double moves, non steals are correct
}

TEST(MancalaBoardTest, DoubleMoveTest){
    // Needs to test that double move is correct
}

TEST(MancalaBoardTest, StealMoveTest){
    // Needs to test that stealing move works correctly
}

TEST(MancalaBoardTest, CantMoveTest){
    // Needs to test when player can't move correctly
}

TEST(MancalaBoardTest, BadParametersTest){
    // Needs to check that bad parameters are handled correctly
}

