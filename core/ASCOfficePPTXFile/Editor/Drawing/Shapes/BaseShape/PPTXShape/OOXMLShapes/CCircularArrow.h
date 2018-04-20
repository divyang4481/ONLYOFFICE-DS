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
	class CCircularArrow : public CPPTXShape
	{
		public:
			CCircularArrow()
			{
				LoadFromXML(
					_T("<ooxml-shape>")
					_T("<avLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"adj1\" fmla=\"val 12500\" />")
					  _T("<gd name=\"adj2\" fmla=\"val 1142319\" />")
					  _T("<gd name=\"adj3\" fmla=\"val 20457681\" />")
					  _T("<gd name=\"adj4\" fmla=\"val 10800000\" />")
					  _T("<gd name=\"adj5\" fmla=\"val 12500\" />")
					_T("</avLst>")
					_T("<gdLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"a5\" fmla=\"pin 0 adj5 25000\" />")
					  _T("<gd name=\"maxAdj1\" fmla=\"*/ a5 2 1\" />")
					  _T("<gd name=\"a1\" fmla=\"pin 0 adj1 maxAdj1\" />")
					  _T("<gd name=\"enAng\" fmla=\"pin 1 adj3 21599999\" />")
					  _T("<gd name=\"stAng\" fmla=\"pin 0 adj4 21599999\" />")
					  _T("<gd name=\"th\" fmla=\"*/ ss a1 100000\" />")
					  _T("<gd name=\"thh\" fmla=\"*/ ss a5 100000\" />")
					  _T("<gd name=\"th2\" fmla=\"*/ th 1 2\" />")
					  _T("<gd name=\"rw1\" fmla=\"+- wd2 th2 thh\" />")
					  _T("<gd name=\"rh1\" fmla=\"+- hd2 th2 thh\" />")
					  _T("<gd name=\"rw2\" fmla=\"+- rw1 0 th\" />")
					  _T("<gd name=\"rh2\" fmla=\"+- rh1 0 th\" />")
					  _T("<gd name=\"rw3\" fmla=\"+- rw2 th2 0\" />")
					  _T("<gd name=\"rh3\" fmla=\"+- rh2 th2 0\" />")
					  _T("<gd name=\"wtH\" fmla=\"sin rw3 enAng\" />")
					  _T("<gd name=\"htH\" fmla=\"cos rh3 enAng\" />")
					  _T("<gd name=\"dxH\" fmla=\"cat2 rw3 htH wtH\" />")
					  _T("<gd name=\"dyH\" fmla=\"sat2 rh3 htH wtH\" />")
					  _T("<gd name=\"xH\" fmla=\"+- hc dxH 0\" />")
					  _T("<gd name=\"yH\" fmla=\"+- vc dyH 0\" />")
					  _T("<gd name=\"rI\" fmla=\"min rw2 rh2\" />")
					  _T("<gd name=\"u1\" fmla=\"*/ dxH dxH 1\" />")
					  _T("<gd name=\"u2\" fmla=\"*/ dyH dyH 1\" />")
					  _T("<gd name=\"u3\" fmla=\"*/ rI rI 1\" />")
					  _T("<gd name=\"u4\" fmla=\"+- u1 0 u3\" />")
					  _T("<gd name=\"u5\" fmla=\"+- u2 0 u3\" />")
					  _T("<gd name=\"u6\" fmla=\"*/ u4 u5 u1\" />")
					  _T("<gd name=\"u7\" fmla=\"*/ u6 1 u2\" />")
					  _T("<gd name=\"u8\" fmla=\"+- 1 0 u7\" />")
					  _T("<gd name=\"u9\" fmla=\"sqrt u8\" />")
					  _T("<gd name=\"u10\" fmla=\"*/ u4 1 dxH\" />")
					  _T("<gd name=\"u11\" fmla=\"*/ u10 1 dyH\" />")
					  _T("<gd name=\"u12\" fmla=\"+/ 1 u9 u11\" />")
					  _T("<gd name=\"u13\" fmla=\"at2 1 u12\" />")
					  _T("<gd name=\"u14\" fmla=\"+- u13 21600000 0\" />")
					  _T("<gd name=\"u15\" fmla=\"?: u13 u13 u14\" />")
					  _T("<gd name=\"u16\" fmla=\"+- u15 0 enAng\" />")
					  _T("<gd name=\"u17\" fmla=\"+- u16 21600000 0\" />")
					  _T("<gd name=\"u18\" fmla=\"?: u16 u16 u17\" />")
					  _T("<gd name=\"u19\" fmla=\"+- u18 0 cd2\" />")
					  _T("<gd name=\"u20\" fmla=\"+- u18 0 21600000\" />")
					  _T("<gd name=\"u21\" fmla=\"?: u19 u20 u18\" />")
					  _T("<gd name=\"maxAng\" fmla=\"abs u21\" />")
					  _T("<gd name=\"aAng\" fmla=\"pin 0 adj2 maxAng\" />")
					  _T("<gd name=\"ptAng\" fmla=\"+- enAng aAng 0\" />")
					  _T("<gd name=\"wtA\" fmla=\"sin rw3 ptAng\" />")
					  _T("<gd name=\"htA\" fmla=\"cos rh3 ptAng\" />")
					  _T("<gd name=\"dxA\" fmla=\"cat2 rw3 htA wtA\" />")
					  _T("<gd name=\"dyA\" fmla=\"sat2 rh3 htA wtA\" />")
					  _T("<gd name=\"xA\" fmla=\"+- hc dxA 0\" />")
					  _T("<gd name=\"yA\" fmla=\"+- vc dyA 0\" />")
					  _T("<gd name=\"wtE\" fmla=\"sin rw1 stAng\" />")
					  _T("<gd name=\"htE\" fmla=\"cos rh1 stAng\" />")
					  _T("<gd name=\"dxE\" fmla=\"cat2 rw1 htE wtE\" />")
					  _T("<gd name=\"dyE\" fmla=\"sat2 rh1 htE wtE\" />")
					  _T("<gd name=\"xE\" fmla=\"+- hc dxE 0\" />")
					  _T("<gd name=\"yE\" fmla=\"+- vc dyE 0\" />")
					  _T("<gd name=\"dxG\" fmla=\"cos thh ptAng\" />")
					  _T("<gd name=\"dyG\" fmla=\"sin thh ptAng\" />")
					  _T("<gd name=\"xG\" fmla=\"+- xH dxG 0\" />")
					  _T("<gd name=\"yG\" fmla=\"+- yH dyG 0\" />")
					  _T("<gd name=\"dxB\" fmla=\"cos thh ptAng\" />")
					  _T("<gd name=\"dyB\" fmla=\"sin thh ptAng\" />")
					  _T("<gd name=\"xB\" fmla=\"+- xH 0 dxB 0\" />")
					  _T("<gd name=\"yB\" fmla=\"+- yH 0 dyB 0\" />")
					  _T("<gd name=\"sx1\" fmla=\"+- xB 0 hc\" />")
					  _T("<gd name=\"sy1\" fmla=\"+- yB 0 vc\" />")
					  _T("<gd name=\"sx2\" fmla=\"+- xG 0 hc\" />")
					  _T("<gd name=\"sy2\" fmla=\"+- yG 0 vc\" />")
					  _T("<gd name=\"rO\" fmla=\"min rw1 rh1\" />")
					  _T("<gd name=\"x1O\" fmla=\"*/ sx1 rO rw1\" />")
					  _T("<gd name=\"y1O\" fmla=\"*/ sy1 rO rh1\" />")
					  _T("<gd name=\"x2O\" fmla=\"*/ sx2 rO rw1\" />")
					  _T("<gd name=\"y2O\" fmla=\"*/ sy2 rO rh1\" />")
					  _T("<gd name=\"dxO\" fmla=\"+- x2O 0 x1O\" />")
					  _T("<gd name=\"dyO\" fmla=\"+- y2O 0 y1O\" />")
					  _T("<gd name=\"dO\" fmla=\"mod dxO dyO 0\" />")
					  _T("<gd name=\"q1\" fmla=\"*/ x1O y2O 1\" />")
					  _T("<gd name=\"q2\" fmla=\"*/ x2O y1O 1\" />")
					  _T("<gd name=\"DO\" fmla=\"+- q1 0 q2\" />")
					  _T("<gd name=\"q3\" fmla=\"*/ rO rO 1\" />")
					  _T("<gd name=\"q4\" fmla=\"*/ dO dO 1\" />")
					  _T("<gd name=\"q5\" fmla=\"*/ q3 q4 1\" />")
					  _T("<gd name=\"q6\" fmla=\"*/ DO DO 1\" />")
					  _T("<gd name=\"q7\" fmla=\"+- q5 0 q6\" />")
					  _T("<gd name=\"q8\" fmla=\"max q7 0\" />")
					  _T("<gd name=\"sdelO\" fmla=\"sqrt q8\" />")
					  _T("<gd name=\"ndyO\" fmla=\"*/ dyO -1 1\" />")
					  _T("<gd name=\"sdyO\" fmla=\"?: ndyO -1 1\" />")
					  _T("<gd name=\"q9\" fmla=\"*/ sdyO dxO 1\" />")
					  _T("<gd name=\"q10\" fmla=\"*/ q9 sdelO 1\" />")
					  _T("<gd name=\"q11\" fmla=\"*/ DO dyO 1\" />")
					  _T("<gd name=\"dxF1\" fmla=\"+/ q11 q10 q4\" />")
					  _T("<gd name=\"q12\" fmla=\"+- q11 0 q10\" />")
					  _T("<gd name=\"dxF2\" fmla=\"*/ q12 1 q4\" />")
					  _T("<gd name=\"adyO\" fmla=\"abs dyO\" />")
					  _T("<gd name=\"q13\" fmla=\"*/ adyO sdelO 1\" />")
					  _T("<gd name=\"q14\" fmla=\"*/ DO dxO -1\" />")
					  _T("<gd name=\"dyF1\" fmla=\"+/ q14 q13 q4\" />")
					  _T("<gd name=\"q15\" fmla=\"+- q14 0 q13\" />")
					  _T("<gd name=\"dyF2\" fmla=\"*/ q15 1 q4\" />")
					  _T("<gd name=\"q16\" fmla=\"+- x2O 0 dxF1\" />")
					  _T("<gd name=\"q17\" fmla=\"+- x2O 0 dxF2\" />")
					  _T("<gd name=\"q18\" fmla=\"+- y2O 0 dyF1\" />")
					  _T("<gd name=\"q19\" fmla=\"+- y2O 0 dyF2\" />")
					  _T("<gd name=\"q20\" fmla=\"mod q16 q18 0\" />")
					  _T("<gd name=\"q21\" fmla=\"mod q17 q19 0\" />")
					  _T("<gd name=\"q22\" fmla=\"+- q21 0 q20\" />")
					  _T("<gd name=\"dxF\" fmla=\"?: q22 dxF1 dxF2\" />")
					  _T("<gd name=\"dyF\" fmla=\"?: q22 dyF1 dyF2\" />")
					  _T("<gd name=\"sdxF\" fmla=\"*/ dxF rw1 rO\" />")
					  _T("<gd name=\"sdyF\" fmla=\"*/ dyF rh1 rO\" />")
					  _T("<gd name=\"xF\" fmla=\"+- hc sdxF 0\" />")
					  _T("<gd name=\"yF\" fmla=\"+- vc sdyF 0\" />")
					  _T("<gd name=\"x1I\" fmla=\"*/ sx1 rI rw2\" />")
					  _T("<gd name=\"y1I\" fmla=\"*/ sy1 rI rh2\" />")
					  _T("<gd name=\"x2I\" fmla=\"*/ sx2 rI rw2\" />")
					  _T("<gd name=\"y2I\" fmla=\"*/ sy2 rI rh2\" />")
					  _T("<gd name=\"dxI\" fmla=\"+- x2I 0 x1I\" />")
					  _T("<gd name=\"dyI\" fmla=\"+- y2I 0 y1I\" />")
					  _T("<gd name=\"dI\" fmla=\"mod dxI dyI 0\" />")
					  _T("<gd name=\"v1\" fmla=\"*/ x1I y2I 1\" />")
					  _T("<gd name=\"v2\" fmla=\"*/ x2I y1I 1\" />")
					  _T("<gd name=\"DI\" fmla=\"+- v1 0 v2\" />")
					  _T("<gd name=\"v3\" fmla=\"*/ rI rI 1\" />")
					  _T("<gd name=\"v4\" fmla=\"*/ dI dI 1\" />")
					  _T("<gd name=\"v5\" fmla=\"*/ v3 v4 1\" />")
					  _T("<gd name=\"v6\" fmla=\"*/ DI DI 1\" />")
					  _T("<gd name=\"v7\" fmla=\"+- v5 0 v6\" />")
					  _T("<gd name=\"v8\" fmla=\"max v7 0\" />")
					  _T("<gd name=\"sdelI\" fmla=\"sqrt v8\" />")
					  _T("<gd name=\"v9\" fmla=\"*/ sdyO dxI 1\" />")
					  _T("<gd name=\"v10\" fmla=\"*/ v9 sdelI 1\" />")
					  _T("<gd name=\"v11\" fmla=\"*/ DI dyI 1\" />")
					  _T("<gd name=\"dxC1\" fmla=\"+/ v11 v10 v4\" />")
					  _T("<gd name=\"v12\" fmla=\"+- v11 0 v10\" />")
					  _T("<gd name=\"dxC2\" fmla=\"*/ v12 1 v4\" />")
					  _T("<gd name=\"adyI\" fmla=\"abs dyI\" />")
					  _T("<gd name=\"v13\" fmla=\"*/ adyI sdelI 1\" />")
					  _T("<gd name=\"v14\" fmla=\"*/ DI dxI -1\" />")
					  _T("<gd name=\"dyC1\" fmla=\"+/ v14 v13 v4\" />")
					  _T("<gd name=\"v15\" fmla=\"+- v14 0 v13\" />")
					  _T("<gd name=\"dyC2\" fmla=\"*/ v15 1 v4\" />")
					  _T("<gd name=\"v16\" fmla=\"+- x1I 0 dxC1\" />")
					  _T("<gd name=\"v17\" fmla=\"+- x1I 0 dxC2\" />")
					  _T("<gd name=\"v18\" fmla=\"+- y1I 0 dyC1\" />")
					  _T("<gd name=\"v19\" fmla=\"+- y1I 0 dyC2\" />")
					  _T("<gd name=\"v20\" fmla=\"mod v16 v18 0\" />")
					  _T("<gd name=\"v21\" fmla=\"mod v17 v19 0\" />")
					  _T("<gd name=\"v22\" fmla=\"+- v21 0 v20\" />")
					  _T("<gd name=\"dxC\" fmla=\"?: v22 dxC1 dxC2\" />")
					  _T("<gd name=\"dyC\" fmla=\"?: v22 dyC1 dyC2\" />")
					  _T("<gd name=\"sdxC\" fmla=\"*/ dxC rw2 rI\" />")
					  _T("<gd name=\"sdyC\" fmla=\"*/ dyC rh2 rI\" />")
					  _T("<gd name=\"xC\" fmla=\"+- hc sdxC 0\" />")
					  _T("<gd name=\"yC\" fmla=\"+- vc sdyC 0\" />")
					  _T("<gd name=\"ist0\" fmla=\"at2 sdxC sdyC\" />")
					  _T("<gd name=\"ist1\" fmla=\"+- ist0 21600000 0\" />")
					  _T("<gd name=\"istAng\" fmla=\"?: ist0 ist0 ist1\" />")
					  _T("<gd name=\"isw1\" fmla=\"+- stAng 0 istAng\" />")
					  _T("<gd name=\"isw2\" fmla=\"+- isw1 0 21600000\" />")
					  _T("<gd name=\"iswAng\" fmla=\"?: isw1 isw2 isw1\" />")
					  _T("<gd name=\"p1\" fmla=\"+- xF 0 xC\" />")
					  _T("<gd name=\"p2\" fmla=\"+- yF 0 yC\" />")
					  _T("<gd name=\"p3\" fmla=\"mod p1 p2 0\" />")
					  _T("<gd name=\"p4\" fmla=\"*/ p3 1 2\" />")
					  _T("<gd name=\"p5\" fmla=\"+- p4 0 thh\" />")
					  _T("<gd name=\"xGp\" fmla=\"?: p5 xF xG\" />")
					  _T("<gd name=\"yGp\" fmla=\"?: p5 yF yG\" />")
					  _T("<gd name=\"xBp\" fmla=\"?: p5 xC xB\" />")
					  _T("<gd name=\"yBp\" fmla=\"?: p5 yC yB\" />")
					  _T("<gd name=\"en0\" fmla=\"at2 sdxF sdyF\" />")
					  _T("<gd name=\"en1\" fmla=\"+- en0 21600000 0\" />")
					  _T("<gd name=\"en2\" fmla=\"?: en0 en0 en1\" />")
					  _T("<gd name=\"sw0\" fmla=\"+- en2 0 stAng\" />")
					  _T("<gd name=\"sw1\" fmla=\"+- sw0 21600000 0\" />")
					  _T("<gd name=\"swAng\" fmla=\"?: sw0 sw0 sw1\" />")
					  _T("<gd name=\"wtI\" fmla=\"sin rw3 stAng\" />")
					  _T("<gd name=\"htI\" fmla=\"cos rh3 stAng\" />")
					  _T("<gd name=\"dxI\" fmla=\"cat2 rw3 htI wtI\" />")
					  _T("<gd name=\"dyI\" fmla=\"sat2 rh3 htI wtI\" />")
					  _T("<gd name=\"xI\" fmla=\"+- hc dxI 0\" />")
					  _T("<gd name=\"yI\" fmla=\"+- vc dyI 0\" />")
					  _T("<gd name=\"aI\" fmla=\"+- stAng 0 cd4\" />")
					  _T("<gd name=\"aA\" fmla=\"+- ptAng cd4 0\" />")
					  _T("<gd name=\"aB\" fmla=\"+- ptAng cd2 0\" />")
					  _T("<gd name=\"idx\" fmla=\"cos rw1 2700000\" />")
					  _T("<gd name=\"idy\" fmla=\"sin rh1 2700000\" />")
					  _T("<gd name=\"il\" fmla=\"+- hc 0 idx\" />")
					  _T("<gd name=\"ir\" fmla=\"+- hc idx 0\" />")
					  _T("<gd name=\"it\" fmla=\"+- vc 0 idy\" />")
					  _T("<gd name=\"ib\" fmla=\"+- vc idy 0\" />")
					_T("</gdLst>")
					_T("<ahLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<ahPolar gdRefAng=\"adj2\" minAng=\"0\" maxAng=\"maxAng\">")
						_T("<pos x=\"xA\" y=\"yA\" />")
					  _T("</ahPolar>")
					  _T("<ahPolar gdRefAng=\"adj4\" minAng=\"0\" maxAng=\"21599999\">")
						_T("<pos x=\"xE\" y=\"yE\" />")
					  _T("</ahPolar>")
					  _T("<ahPolar gdRefR=\"adj1\" minR=\"0\" maxR=\"maxAdj1\" gdRefAng=\"adj3\" minAng=\"0\" maxAng=\"21599999\">")
						_T("<pos x=\"xF\" y=\"yF\" />")
					  _T("</ahPolar>")
					  _T("<ahPolar gdRefR=\"adj5\" minR=\"0\" maxR=\"25000\">")
						_T("<pos x=\"xB\" y=\"yB\" />")
					  _T("</ahPolar>")
					_T("</ahLst>")
					_T("<cxnLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<cxn ang=\"aI\">")
						_T("<pos x=\"xI\" y=\"yI\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"ptAng\">")
						_T("<pos x=\"xGp\" y=\"yGp\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"aA\">")
						_T("<pos x=\"xA\" y=\"yA\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"aB\">")
						_T("<pos x=\"xBp\" y=\"yBp\" />")
					  _T("</cxn>")
					_T("</cxnLst>")
					_T("<rect l=\"il\" t=\"it\" r=\"ir\" b=\"ib\" xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\" />")
					_T("<pathLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<path>")
						_T("<moveTo>")
						  _T("<pt x=\"xE\" y=\"yE\" />")
						_T("</moveTo>")
						_T("<arcTo wR=\"rw1\" hR=\"rh1\" stAng=\"stAng\" swAng=\"swAng\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xGp\" y=\"yGp\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xA\" y=\"yA\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xBp\" y=\"yBp\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC\" y=\"yC\" />")
						_T("</lnTo>")
						_T("<arcTo wR=\"rw2\" hR=\"rh2\" stAng=\"istAng\" swAng=\"iswAng\" />")
						_T("<close />")
					  _T("</path>")
					_T("</pathLst>")
					_T("</ooxml-shape>")
				);
			}
	};
}