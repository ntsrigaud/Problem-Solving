#include "helper.h"
#include "constant.h"
#include <cstdio> // for std::remove
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

void writeFile(const std::string &filename, const std::string &content) {
  std::ofstream ofs(formatPath(filename));
  if (!ofs.is_open()) {
    std::cerr << "Error: Could not open file for writing: "
              << formatPath(filename) << std::endl;
    return;
  }
  ofs << content;
}

std::string readFile(const std::string &filename) {
  std::ifstream ifs(formatPath(filename));
  if (!ifs.is_open()) {
    std::cerr << "Error: Could not open file for reading: "
              << formatPath(filename) << std::endl;
    return "";
  }

  std::ostringstream oss;
  oss << ifs.rdbuf();
  return oss.str();
}

std::string formatPath(const std::string &filename) {
  return (filename.find(DATA_PATH) != std::string::npos) ? filename
                                                         : DATA_PATH + filename;
}

void removeFile(const std::string &filename) {
  auto path = formatPath(filename);
  if (std::filesystem::exists(path)) {
    if (std::remove(path.c_str()) != 0) {
      std::cerr << "Error: Failed to remove file '" << path << "'\n";
    }
  }
}
