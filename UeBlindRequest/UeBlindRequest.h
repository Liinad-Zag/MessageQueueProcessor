#include "rapidjson\rapidjson.h"
#include "rapidjson\document.h"		
#include "rapidjson\stringbuffer.h"	
#include "rapidjson\prettywriter.h"
#include "MeasConfig.h"


namespace JSONModels {
	class UeBlindRequest {
	private:
		uint8_t  target_cell_id; //!< TBD
		MeasConfig* measConfig;

	public:
		UeBlindRequest();
		virtual ~UeBlindRequest();

		virtual void Serialize(rapidjson::Document& config);
		virtual void Deserialize(rapidjson::Document& config);

		uint8_t Target_cell_id() const { return target_cell_id; }
		void Target_cell_id(const uint8_t _target_cell_id) { target_cell_id = _target_cell_id; }
		const MeasConfig* GetMeasConfig() const { return measConfig; }
		void SetMeasConfig(MeasConfig* _measConfig) { measConfig = _measConfig; }
	};
}