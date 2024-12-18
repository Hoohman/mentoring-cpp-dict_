#include "Dictionary.h"
#include <gtest/gtest.h>
#include <sstream>

class DictionaryTest : public ::testing::Test {
protected:
  Dictionary<std::string, std::string> dict;
};

TEST_F(DictionaryTest, InitiallyEmpty) {
  std::stringstream ss;
  dict.print(ss);
  EXPECT_EQ(ss.str(), "<EMPTY>\n");
}

TEST_F(DictionaryTest, PushAndGet) {
  dict.push("key1", "value1");
  EXPECT_EQ(dict.get("key1"), "value1");
}

TEST_F(DictionaryTest, DropElement) {
  dict.push("key1", "value1");
  dict.push("key2", "value2");

  std::string dropped = dict.drop("key1");
  EXPECT_EQ(dropped, "value1");

  std::stringstream ss;
  dict.print(ss);
  EXPECT_TRUE(ss.str().find("key1") == std::string::npos);
}

TEST_F(DictionaryTest, OrderedKeys) {
  dict.push("z", "last");
  dict.push("a", "first");
  dict.push("m", "middle");

  std::stringstream ss;
  dict.print(ss);
  std::string result = ss.str();

  size_t pos_a = result.find("a");
  size_t pos_m = result.find("m");
  size_t pos_z = result.find("z");

  EXPECT_LT(pos_a, pos_m);
  EXPECT_LT(pos_m, pos_z);
}

TEST_F(DictionaryTest, PrintFormat) {
  dict.push("1", "name");
  dict.push("2", "surname");

  std::stringstream ss;
  dict.print(ss);
  std::string result = ss.str();

  EXPECT_TRUE(result.find("1 name 2 surname") != std::string::npos);
}
