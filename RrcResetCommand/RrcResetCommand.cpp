#include "RrcResetCommand.h"

RrcResetCommand::RrcResetCommand() : _ue_id_list({})
{}

RrcResetCommand::~RrcResetCommand()
{}

void RrcResetCommand::Deserialize(rapidjson::Document& config)
{
    if (config.HasMember("ue_id_list") && config["ue_id_list"].IsArray()) 
    {
        const rapidjson::Value &ue_id_array = config["ue_id_list"];
        _ue_id_list.clear();

        for (const auto& ue_id : config["ue_id_list"].GetArray()) 
        {
            _ue_id_list.push_back(ue_id.GetUint());
        }
    }
}

void RrcResetCommand::Serialize(rapidjson::Document& config) 
{
    rapidjson::Document::AllocatorType& allocator = config.GetAllocator();

    rapidjson::Value ue_id_array(rapidjson::kArrayType);


    for (const auto &ue_id : _ue_id_list) {
        ue_id_array.PushBack(ue_id, allocator);
    }

    config.SetObject();
    config.AddMember("ue_id_list", ue_id_array, allocator);
}
