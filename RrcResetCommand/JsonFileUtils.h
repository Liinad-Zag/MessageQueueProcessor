#pragma once
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h> 
#include <rapidjson/error/en.h>

#include <iostream>
#include <fstream>
#include <sstream>

bool SaveJsonToFile(const rapidjson::Document& config, const std::string& filePath);

rapidjson::Document LoadJsonFromFile(const std::string& filePath);