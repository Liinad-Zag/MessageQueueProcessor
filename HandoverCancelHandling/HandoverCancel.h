#include "RrcCause.h"
#include <list>
#include "JSONIncludes.h"
namespace JSONModels
{
    class HandoverCancel 
    {
    public:
        HandoverCancel();
        virtual ~HandoverCancel();

        // Виртуальные сериализатор и десериализатор
        virtual void Deserialize(rapidjson::Document& config);
        virtual void Serialize(rapidjson::Document& config);

        // Геттеры и сеттеры
        uint32_t Cp_ue_id() const { return _Cp_ue_id; }
        void Cp_ue_id(const uint32_t cp_ue_id) { _Cp_ue_id = cp_ue_id; }

        RrcCause Cause() const { return _Cause; }
        void Cause(const RrcCause cause) { _Cause = cause; }

        uint8_t Rrc_cause_value_t() const { return _Rrc_cause_value_t; }
        void Rrc_cause_value_t(uint8_t rrc_cause_value_t) { _Rrc_cause_value_t = rrc_cause_value_t; }

        virtual std::string GetDetailedCause() const;

    private:
        uint32_t _Cp_ue_id;
        RrcCause _Cause;
        uint8_t _Rrc_cause_value_t;
    };
}