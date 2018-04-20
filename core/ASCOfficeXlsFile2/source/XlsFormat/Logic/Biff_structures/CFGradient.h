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

#include "BiffStructure.h"
#include "CFVO.h"
#include "CFColor.h"
#include "Xnum.h"

namespace XLS
{

class CFRecord;

struct CFGradientInterpItem : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(CFGradientInterpItem)
public:
	BiffStructurePtr clone();

	static const ElementType	type = typeAnyObject;

	virtual void load(CFRecord& record);


	CFVO	cfvo;
	double	numDomain;
};
typedef boost::shared_ptr<CFGradientInterpItem> CFGradientInterpItemPtr;


struct CFGradientItem : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(CFGradientItem)
public:
	BiffStructurePtr clone();

	static const ElementType	type = typeAnyObject;

	virtual void load(CFRecord& record);

	Xnum numGrange;
	CFColor	color;
};
typedef boost::shared_ptr<CFGradientItem> CFGradientItemPtr;

class CFGradient : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(CFGradient)
public:
	BiffStructurePtr clone();

	static const ElementType	type = typeCFGradient;
	
	virtual void load(CFRecord& record);


	unsigned char						cInterpCurve;		//MUST be 0x2 or 0x3.
	unsigned char						cGradientCurve;		// == cInterpCurve

	bool								fClamp;
	bool								fBackground;

	std::vector<CFGradientInterpItemPtr>rgInterp;
	std::vector<CFGradientItemPtr>		rgCurve;

};

typedef boost::shared_ptr<CFGradient> CFGradientPtr;

} // namespace XLS

