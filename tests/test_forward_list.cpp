#include "ForwardList.h"
#include <gtest/gtest.h>

class ForwardListTest : public ::testing::Test {
protected:
  ForwardList<int> list;
};

TEST_F(ForwardListTest, InitiallyEmpty) {
  EXPECT_TRUE(list.empty());
  EXPECT_EQ(list.size(), 0);
}

TEST_F(ForwardListTest, PushFrontAndSize) {
  list.push_front(10);
  EXPECT_FALSE(list.empty());
  EXPECT_EQ(list.size(), 1);

  list.push_front(20);
  EXPECT_EQ(list.size(), 2);
}

TEST_F(ForwardListTest, IteratorTraversal) {
  list.push_front(30);
  list.push_front(20);
  list.push_front(10);

  auto it = list.begin();
  EXPECT_EQ(*it, 10);
  ++it;
  EXPECT_EQ(*it, 20);
  ++it;
  EXPECT_EQ(*it, 30);
  ++it;
  EXPECT_EQ(it, list.end());
}

TEST_F(ForwardListTest, PopFront) {
  list.push_front(10);
  list.push_front(20);

  list.pop_front();
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(*list.begin(), 10);
}

TEST_F(ForwardListTest, Clear) {
  list.push_front(10);
  list.push_front(20);

  list.clear();
  EXPECT_TRUE(list.empty());
  EXPECT_EQ(list.size(), 0);
}
