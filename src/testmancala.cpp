#include <gtest/gtest.h>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest){

  CMancalaBoard newBoard;

  EXPECT_EQ(newBoard.PlayerTurn(), 0);

  EXPECT_EQ(newBoard.PitStoneCount(0, 0), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 1), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 2), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 3), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 4), 4);
  EXPECT_EQ(newBoard.PitStoneCount(0, 5), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, 6), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, 7), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, 8), -1);
  EXPECT_EQ(newBoard.PitStoneCount(0, 9), -1);

  EXPECT_EQ(newBoard.PitStoneCount(1, 0), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 1), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 2), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 3), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 4), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 5), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 6), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 7), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 8), 4);
  EXPECT_EQ(newBoard.PitStoneCount(1, 9), 4);

  EXPECT_EQ(newBoard.PitStoneCount(0, 10), -1);
  EXPECT_EQ(newBoard.PitStoneCount(1, 10), -1);

  //check the scores

  //print and check the output

  EXPECT_EQ(newBoard.ToString(),
      "P1          PITS\n"
      "      5   4   3   2   1\n"
      "/---------------------------\\n"
      "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
      "| 0 |-------------------| 0 |\n"
      "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
      "\---------------------------/\n"
      "      1   2   3   4   5\n"
      "             PITS          P2\n");


}

TEST(MancalaBoardTest, SetBoardTest){
    // Needs to test that setting up an initial board is correct

    /*
    CMancalaBoard gameBoard;
    int pits[] = {1,2,3,4,5,1,2,3,4,5};
    int scores[] = {5,5};
    CMancalaBoard gameBoard(0, pits, scores);

    for(int player = 0; player < MANCALA_PLAYERS; player++){
        for (int pit = 0; pit < MANCALA_PITS; pit++){
            EXPECT_EQ(gameBoard.PitStoneCount(player.pit), pit + 1);
        }
        EXPECT_EQ(gameBoard.PlayerScore(player), 5);
    }
    EXPECT_EQ(gameBoard.PlayerTurn(), 0);
    EXPECT_EQ(std::string(gameBoard), gameBoard.ToString()); //fix tostring
    */
}

TEST(MancalaBoardTest, ResetBoardTest){
    // Needs to test that resetting a board is correct
    /*
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
    */
}

TEST(MancalaBoardTest, BasicMoveTest){
    // Needs to test that basic non-scoring moves are correct
    CMancalaBoard newBoard;

    newBoard.Move(0, 0);
    EXPECT_EQ(newBoard.ToString(),
        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 5 | 5 | 5 | 5 | 0 |   |\n"
        "| 0 |-------------------| 0 |\n"
        "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");


    newBoard.Move(1,0);
    EXPECT_EQ(newBoard.ToString(),
        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 5 | 5 | 5 | 5 | 0 |   |\n"
        "| 0 |-------------------| 0 |\n"
        "|   | 0 | 5 | 5 | 5 | 5 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

    newBoard.ResetBoard();

}

TEST(MancalaBoardTest, ScoringMoveTest){
    // Needs to test that basic scoring, non double moves, non steals are correct
    CMancalaBoard newBoard;

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 4);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 0 | 4 | 4 | 4 | 4 |   |\n"
        "| 1 |-------------------| 0 |\n"
        "|   | 5 | 5 | 5 | 4 | 4 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 2);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 0 | 4 | 4 | 5 | 5 |   |\n"
        "| 1 |-------------------| 1 |\n"
        "|   | 5 | 5 | 0 | 5 | 5 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 2);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 1 | 5 | 0 | 5 | 5 |   |\n"
        "| 2 |-------------------| 1 |\n"
        "|   | 6 | 5 | 0 | 5 | 5 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 1);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 1 | 5 | 0 | 5 | 6 |   |\n"
        "| 2 |-------------------| 2 |\n"
        "|   | 6 | 0 | 1 | 6 | 6 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");
}

TEST(MancalaBoardTest, DoubleMoveTest){
    // Needs to test that double move is correct
    CMancalaBoard newBoard;

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 1);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 5 | 5 | 5 | 0 | 4 |   |\n"
        "| 1 |-------------------| 0 |\n"
        "|   | 4 | 4 | 4 | 4 | 4 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");


    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 2);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 6 | 6 | 0 | 0 | 4 |   |\n"
        "| 2 |-------------------| 0 |\n"
        "|   | 5 | 5 | 4 | 4 | 4 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");


    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 0);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 6 | 6 | 0 | 0 | 4 |   |\n"
        "| 2 |-------------------| 1 |\n"
        "|   | 0 | 6 | 5 | 5 | 5 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");


    EXPECT_EQ(newBoard.PlayerTurn(), 1);
    newBoard.Move(1, 4);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 6 | 7 | 1 | 1 | 5 |   |\n"
        "| 2 |-------------------| 2 |\n"
        "|   | 0 | 6 | 5 | 5 | 0 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 0);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 7 | 8 | 2 | 2 | 0 |   |\n"
        "| 3 |-------------------| 2 |\n"
        "|   | 0 | 6 | 5 | 5 | 0 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");


    //checks: "If they reach their opponents store, the store is skipped"

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 3);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 8 | 0 | 2 | 2 | 1 |   |\n"
        "| 4 |-------------------| 2 |\n"
        "|   | 1 | 7 | 6 | 6 | 1 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");
}

TEST(MancalaBoardTest, StealMoveTest){
    // Needs to test that stealing move works correctly


    int pits[] = {0,1,0,0,4,1,0,7,0,0};
    int scores[] = {0,0};
    CMancalaBoard newBoard(0, pits, scores);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 4 | 0 | 0 | 1 | 0 |   |\n"
        "| 0 |-------------------| 0 |\n"
        "|   | 1 | 0 | 7 | 0 | 0 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

    EXPECT_EQ(newBoard.PlayerTurn(), 0);
    newBoard.Move(0, 1);
    EXPECT_EQ(newBoard.ToString(),

        "P1          PITS\n"
        "      5   4   3   2   1\n"
        "/---------------------------\\n"
        "|   | 4 | 0 | 0 | 0 | 0 |   |\n"
        "| 8 |-------------------| 0 |\n"
        "|   | 1 | 0 | 0 | 0 | 0 |   |\n"
        "\---------------------------/\n"
        "      1   2   3   4   5\n"
        "             PITS          P2\n");

}

TEST(MancalaBoardTest, CantMoveTest){
    // Needs to test when player can't move correctly
    //what is meant by: • If a player does not have any stones it their pits, they lose a turn
}

TEST(MancalaBoardTest, BadParametersTest){
    // Needs to check that bad parameters are handled correctly
}

/*
TEST(FileSystemTree, AddDataTest){
    CFileSystemTree Tree;

    EXPECT_TRUE(Tree.Root().AddChild("bin"));
    EXPECT_TRUE(Tree.Root().AddChild("etc"));

    EXPECT_TRUE(Iter2->AddChild("../../bob",true));
    EXPECT_FALSE(Tree.Root().AddChild("/home/bob",true));
    EXPECT_EQ(Iter2->FullPath(), "/home/cjnitta/ecs36c");
    EXPECT_FALSE(Iter2->AddChild("../../../../bob",true));
*/
