#pragma once
#include <rapidjson/document.h>
#include <vector>

using s1_ue_id_t     = uint32_t;

class RrcResetCommand
{
public:
    RrcResetCommand();
    virtual ~RrcResetCommand();

    virtual void Deserialize(rapidjson::Document& config);
    virtual void Serialize(rapidjson::Document& config);

    std::vector<s1_ue_id_t> GetUeIdList() const { return _ue_id_list;}
    void SetUeIdList(const std::vector<s1_ue_id_t> ue_id_list) { _ue_id_list = ue_id_list;}

private:
    std::vector<s1_ue_id_t> _ue_id_list;
};
