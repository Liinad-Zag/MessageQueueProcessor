#include "JsonFileUtils.h"
#include "RrcResetCommand.h"
#include <iostream>

int main()
{
    rapidjson::Document config;
    std::string jsonPath = "output.json";
    std::string newJsonPath = "new_output.json";
    rapidjson::Document doc = LoadJsonFromFile(jsonPath);
    rapidjson::Document new_doc;
    RrcResetCommand command;
    command.Deserialize(doc);

    for (const auto &id : command.GetUeIdList()) {
            std::cout << " " << id;
    }

    command.Serialize(new_doc);
    SaveJsonToFile(new_doc, newJsonPath);

    return 0;

}