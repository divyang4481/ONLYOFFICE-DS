﻿/*
 * (c) Copyright Ascensio System SIA 2010-2018
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */

#include "Pls.h"

namespace XLS
{

Pls::Pls()
{
}

Pls::~Pls()
{
}

BaseObjectPtr Pls::clone()
{
	return BaseObjectPtr(new Pls());
}

void Pls::readFields(CFRecord& record)
{
	record.skipNunBytes(2); // reserved
	
	if (record.loadAnyData(rgb) == false) return;

	if (continue_records.size() > 0)
	{
		std::list<CFRecordPtr>& recs = continue_records[rt_Continue];

		if (recs.size())
		{
			while( !recs.empty() )
			{
				record.appendRawData(recs.front()->getData(), recs.front()->getDataSize());
				recs.pop_front();
			}
		}
	}

	int size			= record.getDataSize() - 2;
	const BYTE* data	= (BYTE*)record.getData() + 2;
	
	boost::shared_array<BYTE> buffer(new BYTE[size]);
    memcpy(buffer.get(), data, size);
	
	bin_data_id = -1;

	GlobalWorkbookInfo* globla_info = record.getGlobalWorkbookInfo().get();
	if (globla_info)
	{
		globla_info->bin_data.push_back(std::pair<boost::shared_array<BYTE>, size_t>(buffer, size));

		bin_data_id = globla_info->bin_data.size() - 1;
	}

	record.skipNunBytes(record.getDataSize() - record.getRdPtr()); // avoid size inconsistency warning
}

} // namespace XLS

