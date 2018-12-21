#pragma once
namespace cx {
	namespace bank {
		namespace dal {
			using namespace std;

			class Record
			{
			public:
				virtual void StartRecord() = 0;
				virtual void StoreField(const string &key, const string &value) = 0;
				virtual void FinishRecord() = 0;
				virtual ~Record() { }
			};
		}
	}
}