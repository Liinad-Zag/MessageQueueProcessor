enum class RrcCause
{
    CAUSE_NOTHING, /* No components present */
    CAUSE_RADIO_NETWORK,
    CAUSE_TRANSPORT,
    CAUSE_NAS,
    CAUSE_PROTOCOL,
    CAUSE_MISC,
    CAUSE_EXTENTION,
};
enum class RrcCauseRadioNetwork
{
    UNSPECIFIED = 0,
    TX2RELOCOVERALL_EXPIRY = 1,
    SUCCESSFUL_HANDOVER = 2,
    RELEASE_DUE_TO_EUTRAN_GENERATED_REASON = 3,
    HANDOVER_CANCELLED = 4,
    PARTIAL_HANDOVER = 5,
    HO_FAILURE_IN_TARGET_EPC_ENB_OR_TARGET_SYSTEM = 6,
    HO_TARGET_NOT_ALLOWED = 7,
    TS1RELOCOVERALL_EXPIRY = 8,
    TS1RELOCPREP_EXPIRY = 9,
    CELL_NOT_AVAILABLE = 10,
    UNKNOWN_TARGETID = 11,
    NO_RADIO_RESOURCES_AVAILABLE_IN_TARGET_CELL = 12,
    UNKNOWN_MME_UE_S1AP_ID = 13,
    UNKNOWN_ENB_UE_S1AP_ID = 14,
    UNKNOWN_PAIR_UE_S1AP_ID = 15,
    HANDOVER_DESIRABLE_FOR_RADIO_REASON = 16,
    TIME_CRITICAL_HANDOVER = 17,
    RESOURCE_OPTIMISATION_HANDOVER = 18,
    REDUCE_LOAD_IN_SERVING_CELL = 19,
    USER_INACTIVITY = 20,
    RADIO_CONNECTION_WITH_UE_LOST = 21,
    LOAD_BALANCING_TAU_REQUIRED = 22,
    CS_FALLBACK_TRIGGERED = 23,
    UE_NOT_AVAILABLE_FOR_PS_SERVICE = 24,
    RADIO_RESOURCES_NOT_AVAILABLE = 25,
    FAILURE_IN_RADIO_INTERFACE_PROCEDURE = 26,
    INVALID_QOS_COMBINATION = 27,
    INTERRAT_REDIRECTION = 28,
    INTERACTION_WITH_OTHER_PROCEDURE = 29,
    UNKNOWN_E_RAB_ID = 30,
    MULTIPLE_E_RAB_ID_INSTANCES = 31,
    ENCRYPTION_AND_OR_INTEGRITY_PROTECTION_ALGORITHMS_NOT_SUPPORTED = 32,
    S1_INTRA_SYSTEM_HANDOVER_TRIGGERED = 33,
    S1_INTER_SYSTEM_HANDOVER_TRIGGERED = 34,
    X2_HANDOVER_TRIGGERED = 35,
    /*
     * ENUMERATION IS EXTENSIBLE
     */
    REDIRECTION_TOWARDS_1XRTT = 36,
    NOT_SUPPORTED_QCI_VALUE = 37,
    INVALID_CSG_ID = 38,
    RELEASE_DUE_TO_PRE_EMPTION = 39
};

enum class RrcCauseTransport
{
    TRANSPORT_RESOURCE_UNAVAILABLE = 0,
    UNSPECIFIED = 1
    /*
     * ENUMERATION IS EXTENSIBLE
     */
};

enum class RrcCauseNas
{
    NORMAL_RELEASE = 0,
    AUTHENTICATION_FAILURE = 1,
    DETACH = 2,
    UNSPECIFIED = 3,
    /*
     * ENUMERATION IS EXTENSIBLE
     */
    CSG_SUBSCRIPTION_EXPIRY = 4
};

enum class RrcCauseProtocol
{
    TRANSFER_SYNTAX_ERROR = 0,
    ABSTRACT_SYNTAX_ERROR_REJECT = 1,
    ABSTRACT_SYNTAX_ERROR_IGNORE_AND_NOTIFY = 2,
    MESSAGE_NOT_COMPATIBLE_WITH_RECEIVER_STATE = 3,
    SEMANTIC_ERROR = 4,
    ABSTRACT_SYNTAX_ERROR_FALSELY_CONSTRUCTED_MESSAGE = 5,
    UNSPECIFIED = 6
    /*
     * Enumeration is extensible
     */
};

enum class RrcCauseMisc
{
    CONTROL_PROCESSING_OVERLOAD = 0,
    NOT_ENOUGH_USER_PLANE_PROCESSING_RESOURCES = 1,
    HARDWARE_FAILURE = 2,
    OM_INTERVENTION = 3,
    UNSPECIFIED = 4,
    UNKNOWN_PLMN = 5
    /*
     * ENUMERATION IS EXTENSIBLE
     */
};