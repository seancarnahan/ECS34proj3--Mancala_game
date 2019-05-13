#include <gtest/gtest.h>
#include <iostream>
#include <ostream>
#include <string>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest){

  CMancalaBoard newBoard;

  EXPECT_EQ(newBoard.PlayerTurn(), 0);

  EXPECT_EQ(newBoard.PitStoneCount(0, 0), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 1), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 2), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 3), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 4), 4);

  EXPECT_EQ(newBoard.PitStoneCount(1, 0), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 1), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 2), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 3), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 4), 4);

  EXPECT_EQ(newBoard.PitStoneCount(3, 0), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, 5), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 5), -1);
  EXPECT_EQ(newBoard.PitStoneCount(3, 5), -1);
  EXPECT_EQ(newBoard.PitStoneCount(-1, 0), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, -1), -1);

  //check the scores

  //print and check the output

  std::string result = "P1          PITS\n";
  result += "      5   4   3   2   1\n";
  result += R"(/---------------------------\)";
  result += "\n";
  result += "|   | 4 | 4 | 4 | 4 | 4 |   |\n";
  result += "| 0 |-------------------| 0 |\n";
  result += "|   | 4 | 4 | 4 | 4 | 4 |   |\n";
  result += R"(\---------------------------/)";
  result += "\n";
  result += "      1   2   3   4   5\n";
  result += "             PITS          P2\n";

  EXPECT_EQ(newBoard.ToString(), result);


}

TEST(MancalaBoardTest, SetBoardTest){
    // Needs to test that setting up an initial board is correct

    // CMancalaBoard gameBoard;
    // int pits[] = {1,2,3,4,5,1,2,3,4,5};
    // int scores[] = {5,5};
    // CMancalaBoard gameBoard(0, pits, scores);

    // for(int player = 0; player < MANCALA_PLAYERS; player++){
    //     for (int pit = 0; pit < MANCALA_PITS; pit++){
    //         EXPECT_EQ(gameBoard.PitStoneCount(player.pit), pit + 1);
    //     }
    //     EXPECT_EQ(gameBoard.PlayerScore(player), 5);
    // }
    // EXPECT_EQ(gameBoard.PlayerTurn(), 0);
    // EXPECT_EQ(std::string(gameBoard), gameBoard.ToString()); //fix tostring
}

TEST(MancalaBoardTest, ResetBoardTest){
    // Needs to test that resetting a board is correct

    // CMancalaBoard gameBoardSet, gameBoardDefault;
    // int pits[] = {1,2,3,4,5,1,2,3,4,5};
    // int scores[] = {5,5};
    // CMancalaBoard gameBoardSet(0, pits, scores);

    // for(int player = 0; player < MANCALA_PLAYERS; player++){
    //     for (int pit = 0; pit < MANCALA_PITS; pit++){
    //         EXPECT_EQ(gameBoardSet.PitStoneCount(player. pit), pit + 1);
    //     }
    //     EXPECT_EQ(gameBoardSet.PlayerScore(player), 5);
    // }
    // EXPECT_EQ(gameBoardSet.PlayerTurn(), 0);
    // EXPECT_EQ(gameBoardSet.ResetBoard(), gameBoardDefault);

}

TEST(MancalaBoardTest, BasicMoveTest){
    // Needs to test that basic non-scoring moves are correct
    CMancalaBoard newBoard;

    newBoard.Move(0, 0);
    std::string result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 5 | 5 | 5 | 5 | 0 |   |\n";
    result += "| 0 |-------------------| 0 |\n";
    result += "|   | 4 | 4 | 4 | 4 | 4 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);


    newBoard.Move(1,0);
    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 5 | 5 | 5 | 5 | 0 |   |\n";
    result += "| 0 |-------------------| 0 |\n";
    result += "|   | 0 | 5 | 5 | 5 | 5 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

    newBoard.ResetBoard();

}

TEST(MancalaBoardTest, ScoringMoveTest){
    // Needs to test that basic scoring, non double moves, non steals are correct
    CMancalaBoard newBoard;

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 4);

    std::string result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 0 | 4 | 4 | 4 | 4 |   |\n";
    result += "| 1 |-------------------| 0 |\n";
    result += "|   | 5 | 5 | 5 | 4 | 4 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 2);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 0 | 4 | 4 | 5 | 5 |   |\n";
    result += "| 1 |-------------------| 1 |\n";
    result += "|   | 5 | 5 | 0 | 5 | 5 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 2);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 1 | 5 | 0 | 5 | 5 |   |\n";
    result += "| 2 |-------------------| 1 |\n";
    result += "|   | 6 | 5 | 0 | 5 | 5 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 1);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 1 | 5 | 0 | 5 | 6 |   |\n";
    result += "| 2 |-------------------| 2 |\n";
    result += "|   | 6 | 0 | 1 | 6 | 6 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

}

TEST(MancalaBoardTest, DoubleMoveTest){
    // Needs to test that double move is correct
    CMancalaBoard newBoard;

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 1);

    std::string result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 5 | 5 | 5 | 0 | 4 |   |\n";
    result += "| 1 |-------------------| 0 |\n";
    result += "|   | 4 | 4 | 4 | 4 | 4 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);


    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 2);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 6 | 6 | 0 | 0 | 4 |   |\n";
    result += "| 2 |-------------------| 0 |\n";
    result += "|   | 5 | 5 | 4 | 4 | 4 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);


    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 0);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 6 | 6 | 0 | 0 | 4 |   |\n";
    result += "| 2 |-------------------| 1 |\n";
    result += "|   | 0 | 6 | 5 | 5 | 5 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);


    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 4);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 6 | 7 | 1 | 1 | 5 |   |\n";
    result += "| 2 |-------------------| 2 |\n";
    result += "|   | 0 | 6 | 5 | 5 | 0 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 0);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 7 | 8 | 2 | 2 | 0 |   |\n";
    result += "| 3 |-------------------| 2 |\n";
    result += "|   | 0 | 6 | 5 | 5 | 0 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);


    //checks: "If they reach their opponents store, the store is skipped"

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 3);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 8 | 0 | 2 | 2 | 0 |   |\n";
    result += "| 6 |-------------------| 2 |\n";
    result += "|   | 1 | 7 | 6 | 6 | 0 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

}

TEST(MancalaBoardTest, StealMoveTest){
    // Needs to test that stealing move works correctly


    int pits[] = {0,1,0,0,4,1,0,7,0,0};
    int scores[] = {0,0};
    CMancalaBoard newBoard(0, pits, scores);

    std::string result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 4 | 0 | 0 | 1 | 0 |   |\n";
    result += "| 0 |-------------------| 0 |\n";
    result += "|   | 1 | 0 | 7 | 0 | 0 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 1);

    result = "P1          PITS\n";
    result += "      5   4   3   2   1\n";
    result += R"(/---------------------------\)";
    result += "\n";
    result += "|   | 4 | 0 | 0 | 0 | 0 |   |\n";
    result += "| 8 |-------------------| 0 |\n";
    result += "|   | 1 | 0 | 0 | 0 | 0 |   |\n";
    result += R"(\---------------------------/)";
    result += "\n";
    result += "      1   2   3   4   5\n";
    result += "             PITS          P2\n";
    EXPECT_EQ(newBoard.ToString(), result);

}

TEST(MancalaBoardTest, CantMoveTest){
    // Needs to test when player can't move correctly
    //what is meant by: • If a player does not have any stones it their pits, they lose a turn

  int pits[] = {0,0,0,0,0,0,1,1,1,0};
  int scores[] = {0,0};
  CMancalaBoard newBoard(1, pits, scores);

  std::string result = "P1          PITS\n";
  result += "      5   4   3   2   1\n";
  result += R"(/---------------------------\)";
  result += "\n";
  result += "|   | 0 | 0 | 0 | 0 | 0 |   |\n";
  result += "| 0 |-------------------| 0 |\n";
  result += "|   | 0 | 1 | 1 | 1 | 0 |   |\n";
  result += R"(\---------------------------/)";
  result += "\n";
  result += "      1   2   3   4   5\n";
  result += "             PITS          P2\n";
  EXPECT_EQ(newBoard.ToString(), result);

  EXPECT_EQ(true, newBoard.Move(1, 1));

  result = "P1          PITS\n";
  result += "      5   4   3   2   1\n";
  result += R"(/---------------------------\)";
  result += "\n";
  result += "|   | 0 | 0 | 0 | 0 | 0 |   |\n";
  result += "| 0 |-------------------| 0 |\n";
  result += "|   | 0 | 0 | 2 | 1 | 0 |   |\n";
  result += R"(\---------------------------/)";
  result += "\n";
  result += "      1   2   3   4   5\n";
  result += "             PITS          P2\n";
  EXPECT_EQ(newBoard.ToString(), result);

  EXPECT_EQ(newBoard.PlayerTurn(), 1);
  EXPECT_EQ(false, newBoard.Move(0, 1));

  newBoard.Move(1, 2);
  result = "P1          PITS\n";
  result += "      5   4   3   2   1\n";
  result += R"(/---------------------------\)";
  result += "\n";
  result += "|   | 0 | 0 | 0 | 0 | 0 |   |\n";
  result += "| 0 |-------------------| 1 |\n";
  result += "|   | 0 | 0 | 0 | 2 | 0 |   |\n";
  result += R"(\---------------------------/)";
  result += "\n";
  result += "      1   2   3   4   5\n";
  result += "             PITS          P2\n";
  EXPECT_EQ(newBoard.ToString(), result);
  EXPECT_EQ(newBoard.PlayerTurn(), 1);
  EXPECT_EQ(false, newBoard.Move(0, 1));

  newBoard.Move(1, 3);

  result = "P1          PITS\n";
  result += "      5   4   3   2   1\n";
  result += R"(/---------------------------\)";
  result += "\n";
  result += "|   | 0 | 0 | 0 | 0 | 0 |   |\n";
  result += "| 0 |-------------------| 2 |\n";
  result += "|   | 0 | 0 | 0 | 0 | 1 |   |\n";
  result += R"(\---------------------------/)";
  result += "\n";
  result += "      1   2   3   4   5\n";
  result += "             PITS          P2\n";
  EXPECT_EQ(newBoard.ToString(), result);
  EXPECT_EQ(newBoard.PlayerTurn(), 1);
  EXPECT_EQ(false, newBoard.Move(0, 1));

  newBoard.Move(1, 4);

  result = "P1          PITS\n";
  result += "      5   4   3   2   1\n";
  result += R"(/---------------------------\)";
  result += "\n";
  result += "|   | 0 | 0 | 0 | 0 | 0 |   |\n";
  result += "| 0 |-------------------| 3 |\n";
  result += "|   | 0 | 0 | 0 | 0 | 0 |   |\n";
  result += R"(\---------------------------/)";
  result += "\n";
  result += "      1   2   3   4   5\n";
  result += "             PITS          P2\n";
  EXPECT_EQ(newBoard.ToString(), result);

  EXPECT_EQ(newBoard.GameOver(), true);
  EXPECT_EQ(newBoard.PlayerTurn(), -1);

}

TEST(MancalaBoardTest, BadParametersTest){
  // Needs to check that bad parameters are handled correctly
  int pits[] = {0,0,0,0,0,0,1,1,1,0};
  int scores[] = {0,0};
  CMancalaBoard newBoard(0, pits, scores);

  // Returns the score of the player, -1 should be returned on bad parameter
  EXPECT_EQ(0, newBoard.PlayerScore(0));
  EXPECT_EQ(0, newBoard.PlayerScore(1));
  EXPECT_EQ(-1, newBoard.PlayerScore(2));
  EXPECT_EQ(-1, newBoard.PlayerScore(-2));

  //Move
  EXPECT_EQ(false, newBoard.Move(1, 0)); //wrong player
  EXPECT_EQ(false, newBoard.Move(2, 0)); //invalid player
  EXPECT_EQ(false, newBoard.Move(0, 5)); //invalid pit
  EXPECT_EQ(false, newBoard.Move(0, 1)); //pit with no stones

  EXPECT_EQ(newBoard.PitStoneCount(-1, 0), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, -1), -1);
  EXPECT_EQ(newBoard.PitStoneCount(2, 0), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, 5), -1);

}
