#include <cassert>
#include <iostream>
#include <string>
#include "Record.h"

namespace cx {
	namespace bank {
		namespace dal {
			using namespace std;

			class StreamRecord : public Record
			{
			public:
				StreamRecord(ostream &s, const string &record_name = string())
					: m_ostream(s), m_record_name(record_name)
				{ }

				void StartRecord() { m_ostream << m_record_name << "( "; }

				void StoreField() {
				}
				void StoreField(const string &key, const string &value)
				{
					m_ostream << key << ": " << value << "; ";
				}

				void FinishRecord() { m_ostream << ")" << endl; }

				void setRecordName(const string &name) { m_record_name = name; }

			private:
				ostream & m_ostream;
				string m_record_name;
			};
		}
	}
};
