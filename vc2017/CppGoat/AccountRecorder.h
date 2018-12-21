#pragma once
#include "Record.h"
#include "Account.h"
#include <cassert>

namespace cx {
	namespace bank {
		namespace dal {
			using namespace cx::bank::model;
			using namespace cx::bank::dal;

			class AccountRecorder
			{
			public:
				AccountRecorder(Record *a) : m_Record(a)
				{
					assert(a != 0);
				}
				void store(const Account1 &data)
				{
					assert(m_Record != 0);
					m_Record->StartRecord();
					m_Record->StoreField("Key : ", "value");
					m_Record->FinishRecord();
				}
			private:
				Record * m_Record;
			};
		}
	}
}