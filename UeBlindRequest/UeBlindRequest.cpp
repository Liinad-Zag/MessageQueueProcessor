// UeBlindRequest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "UeBlindRequest.h"
#include "MeasObjectToRemoveList.h"
#include "MeasObjectToAddModList.h"
#include "ReportConfigToRemoveList.h"
#include "ReportConfigToAddModList.h"
#include "MeasIdToRemoveList.h"
#include "MeasIdToAddModList.h"
#include "QuantityConfig.h"
#include "MeasGapConfig.h"
#include "PreRegistrationInfoHRPD.h"
#include "MeasObjectToAddModList-v9e0.h"
#include "MeasIdToRemoveListExt-r12.h"
#include "MeasIdToAddModListExt-r12.h"
#include "MeasObjectToRemoveListExt-r13.h"
#include "MeasObjectToAddModListExt-r13.h"
#include "MeasIdToAddModList-v1310.h"
#include "MeasIdToAddModListExt-v1310.h"
#include "MeasGapConfigPerCC-List-r14.h"
#include "MeasGapSharingConfig-r14.h"

namespace JSONModels {
	UeBlindRequest::UeBlindRequest() : target_cell_id(0), measConfig(nullptr) {}

	UeBlindRequest::~UeBlindRequest() {
		delete measConfig;
	}

    void UeBlindRequest::Serialize(rapidjson::Document& config)
    {
        if (!config.IsObject()) {
            config.SetObject();
        }

        rapidjson::Document::AllocatorType& allocator = config.GetAllocator();

        config.AddMember("target_cell_id", target_cell_id, allocator);

        if (measConfig) {
            if (measConfig->measObjectToRemoveList) {
                rapidjson::Value measObjectToRemoveListValue(rapidjson::kArrayType);

                if (!measObjectToRemoveListValue.IsArray()) {
                    measObjectToRemoveListValue.SetArray();
                }

                for (int i = 0; i < measConfig->measObjectToRemoveList->count; i++) {
                    rapidjson::Value objValue;
                    objValue.SetUint(measConfig->measObjectToRemoveList->list[i]->id);
                    measObjectToRemoveListValue.PushBack(objValue, allocator);
                }

                config.AddMember("measObjectToRemoveList", measObjectToRemoveListValue, allocator);
            }
            if (measConfig->measObjectToAddModList) {
                rapidjson::Value measObjectToAddModListValue(rapidjson::kArrayType);

                if (!measObjectToAddModListValue.IsArray()) {
                    measObjectToAddModListValue.SetArray();
                }

                for (int i = 0; i < measConfig->measObjectToAddModList->count; i++) {
                    rapidjson::Value objValue;
                    objValue.SetUint(measConfig->measObjectToAddModList->list[i]->id);
                    measObjectToAddModListValue.PushBack(objValue, allocator);
                }

                config.AddMember("measObjectToAddModList", measObjectToAddModListValue, allocator);
            }

        }
    }

    // Метод десериализации
    void UeBlindRequest::Deserialize(const rapidjson::Document& config) {
        if (config.HasMember("target_cell_id") && config["target_cell_id"].IsUint()) {
            target_cell_id = config["target_cell_id"].GetUint();
        }

        if (config.HasMember("measConfig") && config["measConfig"].IsObject()) {
            // Десериализация measConfig
            const rapidjson::Value& measConfigValue = config["measConfig"];

            if (measConfig == nullptr) {
                measConfig = new MeasConfig();
            }

            // Десериализация measObjectToRemoveList
            if (measConfigValue.HasMember("measObjectToRemoveList") && measConfigValue["measObjectToRemoveList"].IsArray()) {
                const rapidjson::Value& measObjectToRemoveListValue = measConfigValue["measObjectToRemoveList"];
                for (rapidjson::SizeType i = 0; i < measObjectToRemoveListValue.Size(); i++) {
                    if (measObjectToRemoveListValue[i].IsUint()) {
                        MeasObjectId* measObjectId = new MeasObjectId();
                        measObjectId->id = measObjectToRemoveListValue[i].GetUint();
                        if (measConfig->measObjectToRemoveList == nullptr) {
                            measConfig->measObjectToRemoveList = new MeasObjectToRemoveList();
                        }
                        measConfig->measObjectToRemoveList->Add(measObjectId);
                    }
                }
            }

            // Десериализация measObjectToAddModList
            if (measConfigValue.HasMember("measObjectToAddModList") && measConfigValue["measObjectToAddModList"].IsArray()) {
                const rapidjson::Value& measObjectToAddModListValue = measConfigValue["measObjectToAddModList"];
                for (rapidjson::SizeType i = 0; i < measObjectToAddModListValue.Size(); i++) {
                    if (measObjectToAddModListValue[i].IsUint()) {
                        MeasObjectToRemoveList::MeasObjectId* measObjectId = new MeasObjectToRemoveList::MeasObjectId();
                        measObjectId->id = measObjectToAddModListValue[i].GetUint();
                        if (measConfig->measObjectToAddModList == nullptr) {
                            measConfig->measObjectToAddModList = new MeasObjectToAddModList();
                        }
                        measConfig->measObjectToAddModList->Add(measObjectId);
                    }
                }
            }
        }
    }

    uint8_t UeBlindRequest::Target_cell_id() const { return target_cell_id; }
	void UeBlindRequest::Target_cell_id(const uint8_t _target_cell_id) { target_cell_id = _target_cell_id; }
	const UeBlindRequest::MeasConfig* GetMeasConfig() const { return measConfig; }
	void UeBlindRequest::SetMeasConfig(MeasConfig* _measConfig) { measConfig = _measConfig; }
}

int main()
{
    std::cout << "Hello World!\n";
}
