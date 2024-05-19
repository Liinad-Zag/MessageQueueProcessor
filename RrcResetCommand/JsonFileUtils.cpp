#include "JsonFileUtils.h"

bool SaveJsonToFile(const rapidjson::Document& config, const std::string& filePath) 
{
    
    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
    config.Accept(writer);

    std::ofstream file(filePath);
    if (file.is_open())
    {
        file << buffer.GetString();
        file.close();
        return true;
    } else 
    {
        std::cerr << "Error: Could not open file for writing: " << filePath << std::endl;
        return false;
    }
}

rapidjson::Document LoadJsonFromFile(const std::string& filePath) 
{
    std::ifstream file(filePath);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Error: Could not open file for reading: " + filePath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    rapidjson::Document config;
    rapidjson::ParseResult result = config.Parse(buffer.str().c_str());

    if (!result) 
    {
        throw std::runtime_error("Error: JSON parse error: " + std::string(rapidjson::GetParseError_En(result.Code())) + " (" + std::to_string(result.Offset()) + ")");
    }

    return config;
}