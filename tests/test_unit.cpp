#include "dictionary_manager.h"
#include <fstream>
#include <gtest/gtest.h>
#include <sstream>

class IntegrationTest : public ::testing::Test {
protected:
  DictionaryManager manager;

  void SetUp() override {
    // Создаем тестовый файл
    std::ofstream testFile("test_input.txt");
    testFile << "first 1 name 2 surname\n";
    testFile << "second 4 mouse 1 name 2 keyboard\n";
    testFile.close();

    // Загружаем словари из файла
    manager.loadFromFile("test_input.txt");
  }

  void TearDown() override { std::remove("test_input.txt"); }
};

TEST_F(IntegrationTest, LoadDictionariesFromFile) {
  std::stringstream ss_first, ss_second;

  manager.printDictionary("first", ss_first);
  manager.printDictionary("second", ss_second);

  EXPECT_TRUE(ss_first.str().find("1 name 2 surname") != std::string::npos);
  EXPECT_TRUE(ss_second.str().find("1 name 2 keyboard 4 mouse") !=
              std::string::npos);
}

TEST_F(IntegrationTest, UnionOperation) {
  manager.unionDictionaries("third", "first", "second");

  std::stringstream ss;
  manager.printDictionary("third", ss);
  std::string result = ss.str();

  EXPECT_TRUE(result.find("1 name 2 keyboard 4 mouse") != std::string::npos);
}

TEST_F(IntegrationTest, IntersectOperation) {
  manager.intersectDictionaries("fourth", "first", "second");

  std::stringstream ss;
  manager.printDictionary("fourth", ss);
  std::string result = ss.str();

  EXPECT_TRUE(result.find("1 name 2 surname") != std::string::npos);
}

TEST_F(IntegrationTest, ComplementOperation) {
  manager.complementDictionaries("fifth", "second", "first");

  std::stringstream ss;
  manager.printDictionary("fifth", ss);
  std::string result = ss.str();

  EXPECT_TRUE(result.find("4 mouse") != std::string::npos);
}

TEST_F(IntegrationTest, InvalidCommandHandling) {
  std::stringstream ss;

  // Проверка обработки некорректных команд
  EXPECT_THROW(manager.processCommand("invalid command", ss),
               std::runtime_error);
  EXPECT_THROW(manager.processCommand("print nonexistent_dict", ss),
               std::runtime_error);
}
