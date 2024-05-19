#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "UeBlindRequest.h"

void WriteDocumentToFile(const rapidjson::Document& document, const std::string& filePath)
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    std::ofstream file(filePath);
    if (file.is_open()) {
        file << buffer.GetString();
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
    }
}
rapidjson::Document CreateDocumentFromJsonFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filePath << std::endl;
        return rapidjson::Document(); 
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); 
    file.close(); 

    rapidjson::Document document;
    document.Parse(buffer.str().c_str()); 

    if (document.HasParseError()) {
        std::cerr << "Ошибка парсинга JSON файла " << filePath << std::endl;
        return rapidjson::Document(); 

    return document;
}