#include <gtest/gtest.h>
#include "MancalaBoard.h"

TEST(MancalaBoardTest, DefaultBoardTest){
    // Needs to test that default board is correct
    CMancalaBoard newBoard;
    EXPECT_EQ(DTurn, 0);

}

TEST(MancalaBoardTest, SetBoardTest){
    // Needs to test that setting up an initial board is correct
}

TEST(MancalaBoardTest, ResetBoardTest){
    // Needs to test that resetting a board is correct
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
