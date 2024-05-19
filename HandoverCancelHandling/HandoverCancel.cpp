#include <string>
#include "HandoverCancel.h"

namespace JSONModels
{

    HandoverCancel::HandoverCancel() : _Cp_ue_id(0), _Cause(RrcCause::CAUSE_NOTHING), _Rrc_cause_value_t(0)
    {}

    HandoverCancel::~HandoverCancel()
    {}

    void HandoverCancel::Deserialize(rapidjson::Document& config)
    {
        if (config.HasMember("Cp_ue_id") && config["Cp_ue_id"].IsUint())
        {
            _Cp_ue_id = config["Cp_ue_id"].GetUint();
        }

        if (config.HasMember("Cause") && config["Cause"].IsString())
        {
            std::string causeStr = config["Cause"].GetString();
            if (causeStr == "CAUSE_NOTHING")
                _Cause = RrcCause::CAUSE_NOTHING;
            else if (causeStr == "CAUSE_RADIO_NETWORK")
                _Cause = RrcCause::CAUSE_RADIO_NETWORK;
            else if (causeStr == "CAUSE_TRANSPORT")
                _Cause = RrcCause::CAUSE_TRANSPORT;
            else if (causeStr == "CAUSE_NAS")
                _Cause = RrcCause::CAUSE_NAS;
            else if (causeStr == "CAUSE_PROTOCOL")
                _Cause = RrcCause::CAUSE_PROTOCOL;
            else if (causeStr == "CAUSE_MISC")
                _Cause = RrcCause::CAUSE_MISC;
            else if (causeStr == "CAUSE_EXTENTION")
                _Cause = RrcCause::CAUSE_EXTENTION;
        }

        if (config.HasMember("Rrc_cause_value_t") && config["Rrc_cause_value_t"].IsUint())
        {
            _Rrc_cause_value_t = config["Rrc_cause_value_t"].GetUint();
        }
    }

    void HandoverCancel::Serialize(rapidjson::Document& config)
    {
        if (!config.IsObject()) {
            config.SetObject();
        }
        // Add or update fields in the document
        rapidjson::Document::AllocatorType& allocator = config.GetAllocator();

        config.AddMember("Cp_ue_id", _Cp_ue_id, allocator);

        std::string causeStr;
        switch (_Cause)
        {
        case RrcCause::CAUSE_NOTHING:
            causeStr = "CAUSE_NOTHING";
            break;
        case RrcCause::CAUSE_RADIO_NETWORK:
            causeStr = "CAUSE_RADIO_NETWORK";
            break;
        case RrcCause::CAUSE_TRANSPORT:
            causeStr = "CAUSE_TRANSPORT";
            break;
        case RrcCause::CAUSE_NAS:
            causeStr = "CAUSE_NAS";
            break;
        case RrcCause::CAUSE_PROTOCOL:
            causeStr = "CAUSE_PROTOCOL";
            break;
        case RrcCause::CAUSE_MISC:
            causeStr = "CAUSE_MISC";
            break;
        case RrcCause::CAUSE_EXTENTION:
            causeStr = "CAUSE_EXTENTION";
            break;
        }
        rapidjson::Value causeValue;
        causeValue.SetString(causeStr.c_str(), allocator);
        config.AddMember("Cause", causeValue, allocator);

        config.AddMember("Rrc_cause_value_t", _Rrc_cause_value_t, allocator);
    }


template <typename T>
std::string CauseToString(T causeValue);

template <>
std::string CauseToString<RrcCauseRadioNetwork>(RrcCauseRadioNetwork causeValue)
{
    switch (causeValue)
    {
    case RrcCauseRadioNetwork::UNSPECIFIED:
        return "Unspecified";
    case RrcCauseRadioNetwork::TX2RELOCOVERALL_EXPIRY:
        return "Tx2RelocOverall Expiry";
    case RrcCauseRadioNetwork::SUCCESSFUL_HANDOVER:
        return "Successful Handover";
    case RrcCauseRadioNetwork::RELEASE_DUE_TO_EUTRAN_GENERATED_REASON:
        return "Release Due to E-UTRAN Generated Reason";
    case RrcCauseRadioNetwork::HANDOVER_CANCELLED:
        return "Handover Cancelled";
    case RrcCauseRadioNetwork::PARTIAL_HANDOVER:
        return "Partial Handover";
    case RrcCauseRadioNetwork::HO_FAILURE_IN_TARGET_EPC_ENB_OR_TARGET_SYSTEM:
        return "HO Failure in Target EPC eNB or Target System";
    case RrcCauseRadioNetwork::HO_TARGET_NOT_ALLOWED:
        return "HO Target Not Allowed";
    case RrcCauseRadioNetwork::TS1RELOCOVERALL_EXPIRY:
        return "TS1RelocOverall Expiry";
    case RrcCauseRadioNetwork::TS1RELOCPREP_EXPIRY:
        return "TS1RelocPrep Expiry";
    case RrcCauseRadioNetwork::CELL_NOT_AVAILABLE:
        return "Cell Not Available";
    case RrcCauseRadioNetwork::UNKNOWN_TARGETID:
        return "Unknown Target ID";
    case RrcCauseRadioNetwork::NO_RADIO_RESOURCES_AVAILABLE_IN_TARGET_CELL:
        return "No Radio Resources Available in Target Cell";
    case RrcCauseRadioNetwork::UNKNOWN_MME_UE_S1AP_ID:
        return "Unknown MME UE S1AP ID";
    case RrcCauseRadioNetwork::UNKNOWN_ENB_UE_S1AP_ID:
        return "Unknown eNB UE S1AP ID";
    case RrcCauseRadioNetwork::UNKNOWN_PAIR_UE_S1AP_ID:
        return "Unknown Pair UE S1AP ID";
    case RrcCauseRadioNetwork::HANDOVER_DESIRABLE_FOR_RADIO_REASON:
        return "Handover Desirable for Radio Reason";
    case RrcCauseRadioNetwork::TIME_CRITICAL_HANDOVER:
        return "Time Critical Handover";
    case RrcCauseRadioNetwork::RESOURCE_OPTIMISATION_HANDOVER:
        return "Resource Optimisation Handover";
    case RrcCauseRadioNetwork::REDUCE_LOAD_IN_SERVING_CELL:
        return "Reduce Load in Serving Cell";
    case RrcCauseRadioNetwork::USER_INACTIVITY:
        return "User Inactivity";
    case RrcCauseRadioNetwork::RADIO_CONNECTION_WITH_UE_LOST:
        return "Radio Connection with UE Lost";
    case RrcCauseRadioNetwork::LOAD_BALANCING_TAU_REQUIRED:
        return "Load Balancing TAU Required";
    case RrcCauseRadioNetwork::CS_FALLBACK_TRIGGERED:
        return "CS Fallback Triggered";
    case RrcCauseRadioNetwork::UE_NOT_AVAILABLE_FOR_PS_SERVICE:
        return "UE Not Available for PS Service";
    case RrcCauseRadioNetwork::RADIO_RESOURCES_NOT_AVAILABLE:
        return "Radio Resources Not Available";
    case RrcCauseRadioNetwork::FAILURE_IN_RADIO_INTERFACE_PROCEDURE:
        return "Failure in Radio Interface Procedure";
    case RrcCauseRadioNetwork::INVALID_QOS_COMBINATION:
        return "Invalid QoS Combination";
    case RrcCauseRadioNetwork::INTERRAT_REDIRECTION:
        return "Inter-RAT Redirection";
    case RrcCauseRadioNetwork::INTERACTION_WITH_OTHER_PROCEDURE:
        return "Interaction with Other Procedure";
    case RrcCauseRadioNetwork::UNKNOWN_E_RAB_ID:
        return "Unknown E-RAB ID";
    case RrcCauseRadioNetwork::MULTIPLE_E_RAB_ID_INSTANCES:
        return "Multiple E-RAB ID Instances";
    case RrcCauseRadioNetwork::ENCRYPTION_AND_OR_INTEGRITY_PROTECTION_ALGORITHMS_NOT_SUPPORTED:
        return "Encryption and/or Integrity Protection Algorithms Not Supported";
    case RrcCauseRadioNetwork::S1_INTRA_SYSTEM_HANDOVER_TRIGGERED:
        return "S1 Intra-System Handover Triggered";
    case RrcCauseRadioNetwork::S1_INTER_SYSTEM_HANDOVER_TRIGGERED:
        return "S1 Inter-System Handover Triggered";
    case RrcCauseRadioNetwork::X2_HANDOVER_TRIGGERED:
        return "X2 Handover Triggered";
    case RrcCauseRadioNetwork::REDIRECTION_TOWARDS_1XRTT:
        return "Redirection Towards 1xRTT";
    case RrcCauseRadioNetwork::NOT_SUPPORTED_QCI_VALUE:
        return "Not Supported QCI Value";
    case RrcCauseRadioNetwork::INVALID_CSG_ID:
        return "Invalid CSG ID";
    case RrcCauseRadioNetwork::RELEASE_DUE_TO_PRE_EMPTION:
        return "Release Due to Pre-emption";
    default:
        return "Unknown";
    }
}

template <>
std::string CauseToString<RrcCauseTransport>(RrcCauseTransport causeValue)
{
    switch (causeValue)
    {
    case RrcCauseTransport::TRANSPORT_RESOURCE_UNAVAILABLE:
        return "Transport Resource Unavailable";
    case RrcCauseTransport::UNSPECIFIED:
        return "Unspecified";
    default:
        return "Unknown";
    }
}

template <>
std::string CauseToString<RrcCauseNas>(RrcCauseNas causeValue)
{
    switch (causeValue)
    {
    case RrcCauseNas::NORMAL_RELEASE:
        return "Normal Release";
    case RrcCauseNas::AUTHENTICATION_FAILURE:
        return "Authentication Failure";
    case RrcCauseNas::DETACH:
        return "Detach";
    case RrcCauseNas::UNSPECIFIED:
        return "Unspecified";
    case RrcCauseNas::CSG_SUBSCRIPTION_EXPIRY:
        return "CSG Subscription Expiry";
    default:
        return "Unknown";
    }
}

template <>
std::string CauseToString<RrcCauseProtocol>(RrcCauseProtocol causeValue)
{
    switch (causeValue)
    {
    case RrcCauseProtocol::TRANSFER_SYNTAX_ERROR:
        return "Transfer Syntax Error";
    case RrcCauseProtocol::ABSTRACT_SYNTAX_ERROR_REJECT:
        return "Abstract Syntax Error Reject";
    case RrcCauseProtocol::ABSTRACT_SYNTAX_ERROR_IGNORE_AND_NOTIFY:
        return "Abstract Syntax Error Ignore and Notify";
    case RrcCauseProtocol::MESSAGE_NOT_COMPATIBLE_WITH_RECEIVER_STATE:
        return "Message Not Compatible with Receiver State";
    case RrcCauseProtocol::SEMANTIC_ERROR:
        return "Semantic Error";
    case RrcCauseProtocol::ABSTRACT_SYNTAX_ERROR_FALSELY_CONSTRUCTED_MESSAGE:
        return "Abstract Syntax Error Falsely Constructed Message";
    case RrcCauseProtocol::UNSPECIFIED:
        return "Unspecified";
    default:
        return "Unknown";
    }
}

std::string CauseToString(RrcCauseMisc causeValue)
{
    switch (causeValue)
    {
    case RrcCauseMisc::CONTROL_PROCESSING_OVERLOAD:
        return "Control Processing Overload";
    case RrcCauseMisc::NOT_ENOUGH_USER_PLANE_PROCESSING_RESOURCES:
        return "Not Enough User Plane Processing Resources";
    case RrcCauseMisc::HARDWARE_FAILURE:
        return "Hardware Failure";
    case RrcCauseMisc::OM_INTERVENTION:
        return "OM Intervention";
    case RrcCauseMisc::UNSPECIFIED:
        return "Unspecified";
    case RrcCauseMisc::UNKNOWN_PLMN:
        return "Unknown PLMN";
    default:
        return "Unknown";
    }
}

std::string HandoverCancel::GetDetailedCause() const
{
    switch (_Cause)
    {
    case RrcCause::CAUSE_RADIO_NETWORK:
        return "Radio Network Cause: " + CauseToString(static_cast<RrcCauseRadioNetwork>(_Rrc_cause_value_t));
    case RrcCause::CAUSE_TRANSPORT:
        return "Transport Cause: " + CauseToString(static_cast<RrcCauseTransport>(_Rrc_cause_value_t));
    case RrcCause::CAUSE_NAS:
        return "NAS Cause: " + CauseToString(static_cast<RrcCauseNas>(_Rrc_cause_value_t));
    case RrcCause::CAUSE_PROTOCOL:
        return "Protocol Cause: " + CauseToString(static_cast<RrcCauseProtocol>(_Rrc_cause_value_t));
    case RrcCause::CAUSE_MISC:
        return "Misc Cause: " + CauseToString(static_cast<RrcCauseMisc>(_Rrc_cause_value_t));
    case RrcCause::CAUSE_NOTHING:
    case RrcCause::CAUSE_EXTENTION:
    default:
        return "Unknown Cause";
    }
}
}