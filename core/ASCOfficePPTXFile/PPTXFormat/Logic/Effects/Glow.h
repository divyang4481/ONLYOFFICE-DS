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
#ifndef PPTX_LOGIC_GLOW_INCLUDE_H_
#define PPTX_LOGIC_GLOW_INCLUDE_H_

#include "./../../WrapperWritingElement.h"
#include "./../UniColor.h"

namespace PPTX
{
	namespace Logic
	{
		class Glow : public WrapperWritingElement
		{
		public:
			WritingElement_AdditionConstructors(Glow)
			PPTX_LOGIC_BASE2(Glow)

			Glow& operator=(const Glow& oSrc)
			{
				parentFile		= oSrc.parentFile;
				parentElement	= oSrc.parentElement;

				Color = oSrc.Color;
				rad = oSrc.rad;
				return *this;
			}
			virtual OOX::EElementType getType() const
			{
				return OOX::et_a_clrRepl;
			}	
			void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				ReadAttributes( oReader );

				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring strName = oReader.GetName();

					Color.fromXML(oReader);
				}
				FillParentPointersForChilds();
			}
			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
			{
				WritingElement_ReadAttributes_Start_No_NS( oReader )
					WritingElement_ReadAttributes_Read_if     ( oReader, _T("rad"), rad)
				WritingElement_ReadAttributes_End_No_NS( oReader )
				
				Normalize();
			}
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				Color.GetColorFrom(node);
				node.ReadAttributeBase(L"rad", rad);
				
				FillParentPointersForChilds();
				Normalize();
			}

			virtual std::wstring toXML() const
			{
				XmlUtils::CAttribute oAttr;
				oAttr.Write(_T("rad"), rad);

				return XmlUtils::CreateNode(_T("a:glow"), oAttr, Color.toXML());
			}

			virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
			{
				pWriter->StartRecord(EFFECT_TYPE_GLOW);

				pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeStart);
				pWriter->WriteInt2(0, rad);
				pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeEnd);

				pWriter->WriteRecord1(0, Color);

				pWriter->EndRecord();
			}

		public:
			UniColor		Color;
			nullable_int	rad;
		protected:
			virtual void FillParentPointersForChilds()
			{
				Color.SetParentPointer(this);
			}

			AVSINLINE void Normalize()
			{
				rad.normalize_positive();
			}
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_GLOW_INCLUDE_H_