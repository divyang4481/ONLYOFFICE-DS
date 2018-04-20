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
#include "../PPTXShape.h"

namespace OOXMLShapes
{
	class CEllipseRibbon : public CPPTXShape
	{
		public:
			CEllipseRibbon()
			{
				LoadFromXML(
					_T("<ooxml-shape>")
					_T("<avLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"adj1\" fmla=\"val 25000\" />")
					  _T("<gd name=\"adj2\" fmla=\"val 50000\" />")
					  _T("<gd name=\"adj3\" fmla=\"val 12500\" />")
					_T("</avLst>")
					_T("<gdLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"a1\" fmla=\"pin 0 adj1 100000\" />")
					  _T("<gd name=\"a2\" fmla=\"pin 25000 adj2 75000\" />")
					  _T("<gd name=\"q10\" fmla=\"+- 100000 0 a1\" />")
					  _T("<gd name=\"q11\" fmla=\"*/ q10 1 2\" />")
					  _T("<gd name=\"q12\" fmla=\"+- a1 0 q11\" />")
					  _T("<gd name=\"minAdj3\" fmla=\"max 0 q12\" />")
					  _T("<gd name=\"a3\" fmla=\"pin minAdj3 adj3 a1\" />")
					  _T("<gd name=\"dx2\" fmla=\"*/ w a2 200000\" />")
					  _T("<gd name=\"x2\" fmla=\"+- hc 0 dx2\" />")
					  _T("<gd name=\"x3\" fmla=\"+- x2 wd8 0\" />")
					  _T("<gd name=\"x4\" fmla=\"+- r 0 x3\" />")
					  _T("<gd name=\"x5\" fmla=\"+- r 0 x2\" />")
					  _T("<gd name=\"x6\" fmla=\"+- r 0 wd8\" />")
					  _T("<gd name=\"dy1\" fmla=\"*/ h a3 100000\" />")
					  _T("<gd name=\"f1\" fmla=\"*/ 4 dy1 w\" />")
					  _T("<gd name=\"q1\" fmla=\"*/ x3 x3 w\" />")
					  _T("<gd name=\"q2\" fmla=\"+- x3 0 q1\" />")
					  _T("<gd name=\"y1\" fmla=\"*/ f1 q2 1\" />")
					  _T("<gd name=\"cx1\" fmla=\"*/ x3 1 2\" />")
					  _T("<gd name=\"cy1\" fmla=\"*/ f1 cx1 1\" />")
					  _T("<gd name=\"cx2\" fmla=\"+- r 0 cx1\" />")
					  _T("<gd name=\"q1\" fmla=\"*/ h a1 100000\" />")
					  _T("<gd name=\"dy3\" fmla=\"+- q1 0 dy1\" />")
					  _T("<gd name=\"q3\" fmla=\"*/ x2 x2 w\" />")
					  _T("<gd name=\"q4\" fmla=\"+- x2 0 q3\" />")
					  _T("<gd name=\"q5\" fmla=\"*/ f1 q4 1\" />")
					  _T("<gd name=\"y3\" fmla=\"+- q5 dy3 0\" />")
					  _T("<gd name=\"q6\" fmla=\"+- dy1 dy3 y3\" />")
					  _T("<gd name=\"q7\" fmla=\"+- q6 dy1 0\" />")
					  _T("<gd name=\"cy3\" fmla=\"+- q7 dy3 0\" />")
					  _T("<gd name=\"rh\" fmla=\"+- b 0 q1\" />")
					  _T("<gd name=\"q8\" fmla=\"*/ dy1 14 16\" />")
					  _T("<gd name=\"y2\" fmla=\"+/ q8 rh 2\" />")
					  _T("<gd name=\"y5\" fmla=\"+- q5 rh 0\" />")
					  _T("<gd name=\"y6\" fmla=\"+- y3 rh 0\" />")
					  _T("<gd name=\"cx4\" fmla=\"*/ x2 1 2\" />")
					  _T("<gd name=\"q9\" fmla=\"*/ f1 cx4 1\" />")
					  _T("<gd name=\"cy4\" fmla=\"+- q9 rh 0\" />")
					  _T("<gd name=\"cx5\" fmla=\"+- r 0 cx4\" />")
					  _T("<gd name=\"cy6\" fmla=\"+- cy3 rh 0\" />")
					  _T("<gd name=\"y7\" fmla=\"+- y1 dy3 0\" />")
					  _T("<gd name=\"cy7\" fmla=\"+- q1 q1 y7\" />")
					  _T("<gd name=\"y8\" fmla=\"+- b 0 dy1\" />")
					_T("</gdLst>")
					_T("<ahLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<ahXY gdRefY=\"adj1\" minY=\"0\" maxY=\"100000\">")
						_T("<pos x=\"hc\" y=\"q1\" />")
					  _T("</ahXY>")
					  _T("<ahXY gdRefX=\"adj2\" minX=\"25000\" maxX=\"75000\">")
						_T("<pos x=\"x2\" y=\"b\" />")
					  _T("</ahXY>")
					  _T("<ahXY gdRefY=\"adj3\" minY=\"minAdj3\" maxY=\"a1\">")
						_T("<pos x=\"l\" y=\"y8\" />")
					  _T("</ahXY>")
					_T("</ahLst>")
					_T("<cxnLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<cxn ang=\"3cd4\">")
						_T("<pos x=\"hc\" y=\"q1\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"cd2\">")
						_T("<pos x=\"wd8\" y=\"y2\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"cd4\">")
						_T("<pos x=\"hc\" y=\"b\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"0\">")
						_T("<pos x=\"x6\" y=\"y2\" />")
					  _T("</cxn>")
					_T("</cxnLst>")
					_T("<rect l=\"x2\" t=\"q1\" r=\"x5\" b=\"y6\" xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\" />")
					_T("<pathLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<path stroke=\"false\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"l\" y=\"t\" />")
						_T("</moveTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx1\" y=\"cy1\" />")
						  _T("<pt x=\"x3\" y=\"y1\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x2\" y=\"y3\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"hc\" y=\"cy3\" />")
						  _T("<pt x=\"x5\" y=\"y3\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x4\" y=\"y1\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx2\" y=\"cy1\" />")
						  _T("<pt x=\"r\" y=\"t\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x6\" y=\"y2\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"r\" y=\"rh\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx5\" y=\"cy4\" />")
						  _T("<pt x=\"x5\" y=\"y5\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x5\" y=\"y6\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"hc\" y=\"cy6\" />")
						  _T("<pt x=\"x2\" y=\"y6\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x2\" y=\"y5\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx4\" y=\"cy4\" />")
						  _T("<pt x=\"l\" y=\"rh\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"wd8\" y=\"y2\" />")
						_T("</lnTo>")
						_T("<close />")
					  _T("</path>")
					  _T("<path fill=\"darkenLess\" stroke=\"false\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"x3\" y=\"y7\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x3\" y=\"y1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x2\" y=\"y3\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"hc\" y=\"cy3\" />")
						  _T("<pt x=\"x5\" y=\"y3\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x4\" y=\"y1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x4\" y=\"y7\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"hc\" y=\"cy7\" />")
						  _T("<pt x=\"x3\" y=\"y7\" />")
						_T("</quadBezTo>")
						_T("<close />")
					  _T("</path>")
					  _T("<path fill=\"none\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"l\" y=\"t\" />")
						_T("</moveTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx1\" y=\"cy1\" />")
						  _T("<pt x=\"x3\" y=\"y1\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x2\" y=\"y3\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"hc\" y=\"cy3\" />")
						  _T("<pt x=\"x5\" y=\"y3\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x4\" y=\"y1\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx2\" y=\"cy1\" />")
						  _T("<pt x=\"r\" y=\"t\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x6\" y=\"y2\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"r\" y=\"rh\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx5\" y=\"cy4\" />")
						  _T("<pt x=\"x5\" y=\"y5\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x5\" y=\"y6\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"hc\" y=\"cy6\" />")
						  _T("<pt x=\"x2\" y=\"y6\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x2\" y=\"y5\" />")
						_T("</lnTo>")
						_T("<quadBezTo>")
						  _T("<pt x=\"cx4\" y=\"cy4\" />")
						  _T("<pt x=\"l\" y=\"rh\" />")
						_T("</quadBezTo>")
						_T("<lnTo>")
						  _T("<pt x=\"wd8\" y=\"y2\" />")
						_T("</lnTo>")
						_T("<close />")
						_T("<moveTo>")
						  _T("<pt x=\"x2\" y=\"y5\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x2\" y=\"y3\" />")
						_T("</lnTo>")
						_T("<moveTo>")
						  _T("<pt x=\"x5\" y=\"y3\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x5\" y=\"y5\" />")
						_T("</lnTo>")
						_T("<moveTo>")
						  _T("<pt x=\"x3\" y=\"y1\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x3\" y=\"y7\" />")
						_T("</lnTo>")
						_T("<moveTo>")
						  _T("<pt x=\"x4\" y=\"y7\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"x4\" y=\"y1\" />")
						_T("</lnTo>")
					  _T("</path>")
					_T("</pathLst>")
					_T("</ooxml-shape>")
				);
			}
	};
}