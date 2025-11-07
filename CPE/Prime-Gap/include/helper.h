#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>

#define DEBUG false
#define LOG(x)                                                                 \
  do {                                                                         \
    if (DEBUG)                                                                 \
      std::cout << x << std::endl;                                             \
  } while (0)

// helper to write file contents
void writeFile(const std::string &filename, const std::string &content);

// helper to read file contents
std::string readFile(const std::string &filename);

// helper to read and write files in the data path
std::string formatPath(const std::string &filename);

// helper to remove test files in the data path
void removeFile(const std::string &filename);

#endif // !HELPER_H
