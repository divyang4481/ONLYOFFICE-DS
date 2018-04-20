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
#pragma once

#include <string>
#include <cpdoccore/CPOptional.h>
#include <iosfwd>
#include <cpdoccore/CPScopedPtr.h>
#include "xlsx_fill.h"

namespace cpdoccore { 
namespace odf_reader {

    class text_format_properties_content;
    class paragraph_format_properties;
    class style_table_cell_properties_attlist;
}
}

namespace cpdoccore {
namespace oox {

    class xlsx_fills
    {
    public:
        xlsx_fills();
        ~xlsx_fills();
    public:
        size_t size() const;
       
		size_t fillId(	const odf_reader::text_format_properties_content		* textProp,
						const odf_reader::paragraph_format_properties			* parProp,
						const odf_reader::style_table_cell_properties_attlist	* cellProp, bool  default_set);

        size_t fillId(	const odf_reader::text_format_properties_content		* textProp,
						const odf_reader::paragraph_format_properties			* parProp,
						const odf_reader::style_table_cell_properties_attlist	* cellProp, bool default_set,bool & is_default);

        void serialize(std::wostream & _Wostream) const;

    private:
        class Impl;
        _CP_SCOPED_PTR(Impl) impl_;

    };
}
}
