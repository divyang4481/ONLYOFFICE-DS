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

namespace DocFileFormat
{
	typedef enum OperationCode
	{ 
//verison 1995 and earler
		sprmOldPIstd			=	2,
		sprmOldPIstdPermute		=	3,
		sprmOldPIncLvl			=	4,
		sprmOldPJc				=	5,
		sprmOldPFSideBySide		=	6,
		sprmOldPFKeep			=	7,
		sprmOldPFKeepFollow		=	8,
		sprmOldPPageBreakBefore	=	9,
		sprmOldPBrcl			=	10,
		sprmOldPBrcp			=	11,
		sprmOldPAnld			=	12,
		sprmOldPNLvlAnm			=	13,
		sprmOldPFNoLineNumb		=	14,
		sprmOldPChgTabsPapx		=	15,
		sprmOldPDxaRight		=	16,
		sprmOldPDxaLeft			=	17,
		sprmOldPNest			=	18,
		sprmOldPDxaLeft1		=	19,
		sprmOldPDyaLine			=	20,
		sprmOldPDyaBefore		=	21,
		sprmOldPDyaAfter		=	22,
		sprmOldPChgTabs			=	23,
		sprmOldPFInTable		=	24,
		sprmOldPTtp				=	25,
		sprmOldPDxaAbs			=	26,
		sprmOldPDyaAbs			=	27,
		sprmOldPDxaWidth		=	28,
		sprmOldPPc				=	29,
		sprmOldPBrcTop10		=	30,
		sprmOldPBrcLeft10		=	31,
		sprmOldPBrcBottom10		=	32,
		sprmOldPBrcRight10		=	33,
		sprmOldPBrcBetween10	=	34,
		sprmOldPBrcBar10		=	35,
		sprmOldPFromText10		=	36,
		sprmOldPWr				=	37,
		sprmOldPBrcTop			=	38,
		sprmOldPBrcLeft			=	39,
		sprmOldPBrcBottom		=	40,
		sprmOldPBrcRight		=	41,
		sprmOldPBrcBetween		=	42,
		sprmOldPBrcBar			=	43,
		sprmOldPFNoAutoHyph		=	44,
		sprmOldPWHeightAbs		=	45,
		sprmOldPDcs				=	46,
		sprmOldPShd				=	47,
		sprmOldPDyaFromText		=	48,
		sprmOldPDxaFromText		=	49,
		sprmOldPFLocked			=	50,
		sprmOldPFWidowControl	=	51,
		sprmOldPRuler			=	52,
		sprmOldCFStrikeRM		=	65,
		sprmOldCFRMark			=	66,
		sprmOldCFFldVanish		=	67,
		sprmOldCPicLocation		=	68,
		sprmOldCIbstRMark		=	69,
		sprmOldCDttmRMark		=	70,
		sprmOldCFData			=	71,
		sprmOldCRMReason		=	72,
		sprmOldCChse			=	73,
		sprmOldCSymbol			=	74,
		sprmOldCFOle2			=	75,
		sprmCOldHighlight		=	77,
		sprmOldCIstd			=	80,
		sprmOldCIstdPermute		=	81,
		sprmOldCDefault			=	82,
		sprmOldCPlain			=	83,
		sprmOldCFBold			=	85,
		sprmOldCFItalic			=	86,
		sprmOldCFStrike			=	87,
		sprmOldCFOutline		=	88,
		sprmOldCFShadow			=	89,
		sprmOldCFSmallCaps		=	90,
		sprmOldCFCaps			=	91,
		sprmOldCFVanish			=	92,
		sprmOldCFtc				=	93,
		sprmOldCKul				=	94,
		sprmOldCSizePos			=	95,
		sprmOldCDxaSpace		=	96,
		sprmOldCLid				=	97,
		sprmOldCIco				=	98,
		sprmOldCHps				=	99,
		sprmOldCHpsInc			=	100,
		sprmOldCHpsPos			=	101,
		sprmOldCHpsPosAdj		=	102,
		sprmOldCMajority		=	103,
		sprmOldCIss				=	104,
		sprmOldCHpsNew50		=	105,
		sprmOldCHpsInc1			=	106,
		sprmOldCHpsKern			=	107,
		sprmOldCMajority50		=	108,
		sprmOldCHpsMul			=	109,
		sprmOldCCondHyhen		=	110,
		sprmOldCFSpec			=	117,
		sprmOldCFObj			=	118,
		sprmOldPicBrcl			=	119,
		sprmOldPicScale			=	120,
		sprmOldPicBrcTop		=	121,
		sprmOldPicBrcLeft		=	122,
		sprmOldPicBrcBottom		=	123,
		sprmOldPicBrcRight		=	124,
		sprmOldSScnsPgn			=	131,
		sprmOldSiHeadingPgn		=	132,
		sprmOldSOlstAnm			=	133,
		sprmOldSDxaColWidth		=	136,
		sprmOldSDxaColSpacing	=	137,
		sprmOldSFEvenlySpaced	=	138,
		sprmOldSFProtected		=	139,
		sprmOldSDmBinFirst		=	140,
		sprmOldSDmBinOther		=	141,
		sprmOldSBkc				=	142,
		sprmOldSFTitlePage		=	143,
		sprmOldSCcolumns		=	144,
		sprmOldSDxaColumns		=	145,
		sprmOldSFAutoPgn		=	146,
		sprmOldSNfcPgn			=	147,
		sprmOldSDyaPgn			=	148,
		sprmOldSDxaPgn			=	149,
		sprmOldSFPgnRestart		=	150,
		sprmOldSFEndnote		=	151,
		sprmOldSLnc				=	152,
		sprmOldSGprfIhdt		=	153,
		sprmOldSNLnnMod			=	154,
		sprmOldSDxaLnn			=	155,
		sprmOldSDyaHdrTop		=	156,
		sprmOldSDyaHdrBottom	=	157,
		sprmOldSLBetween		=	158,
		sprmOldSVjc				=	159,
		sprmOldSLnnMin			=	160,
		sprmOldSPgnStart		=	161,
		sprmOldSBOrientation	=	162,
		sprmOldSBCustomize		=	163,
		sprmOldSXaPage			=	164,
		sprmOldSYaPage			=	165,
		sprmOldSDxaLeft			=	166,
		sprmOldSDxaRight		=	167,
		sprmOldSDyaTop			=	168,
		sprmOldSDyaBottom		=	169,
		sprmOldSDzaGutter		=	170,
		sprmOldSDMPaperReq		=	171,
		sprmOldTJc				=	182,
		sprmOldTDxaLeft			=	183,
		sprmOldTDxaGapHalf		=	184,
		sprmOldTFCantSplit		=	185,
		sprmOldTTableHeader		=	186,
		sprmOldTTableBorders	=	187,
		sprmOldTDefTable10		=	188,
		sprmOldTDyaRowHeight	=	189,
		sprmOldTDefTable		=	190,
		sprmOldTDefTableShd		=	191,
		sprmOldTTlp				=	192,
		sprmOldTSetBrc			=	193,
		sprmOldTInsert			=	194,
		sprmOldTDelete			=	195,
		sprmOldTDxaCol			=	196,
		sprmOldTMerge			=	197,
		sprmOldTSplit			=	198,
		sprmOldTSetBrc10		=	199,
		sprmOldTSetShd			=	200,
		sprmOldMax				=	208,

//version 1996 and later
	//Paragraph sprmOlds
		sprmPIstd				=	0x4600,
		sprmPIstdPermute		=	0xC601,
		sprmPIncLvl				=	0x2602,
		sprmPJc					=	0x2461,
		sprmPJc80				=	0x2403,
		sprmPFSideBySide		=	0x2404,
		sprmPFKeep				=	0x2405,
		sprmPFKeepFollow		=	0x2406,
		sprmPFPageBreakBefore	=	0x2407,
		sprmPBrcl				=	0x2408,
		sprmPBrcp				=	0x2409,
		sprmPIlvl				=	0x260A,
		sprmPIlfo				=	0x460B,
		sprmPFNoLineNumb		=	0x240C,
		sprmPChgTabsPapx		=	0xC60D,
		sprmPDxaLeft			=	0x845e,
		sprmPDxaLeft80			=	0x840f,
		sprmPDxaLeft1			=	0x8460,
		sprmPDxaLeft180			=	0x8411,
		sprmPDxaRight			=	0x845d,
		sprmPDxaRight80			=	0x840e,
		sprmPDxcLeft			=	0x4456,
		sprmPDxcLeft1			=	0x4457,
		sprmPDxcRight			=	0x4455,
		sprmPNest				=	0x465f,
		sprmPNest80				=	0x4610,
		sprmPDyaLine			=	0x6412,
		sprmPDyaBefore			=	0xA413,
		sprmPDyaAfter			=	0xA414,
		sprmPFDyaAfterAuto		=	0x245c,
		sprmPFDyaBeforeAuto		=	0x245b,
		sprmPDylAfter			=	0x4459,
		sprmPDylBefore			=	0x4458,
		sprmPChgTabs			=	0xC615,
		sprmPFInTable			=	0x2416,
		sprmPFTtp				=	0x2417,
		sprmPDxaAbs				=	0x8418,
		sprmPDyaAbs				=	0x8419,
		sprmPDxaWidth			=	0x841A,
		sprmPPc					=	0x261B,
		sprmPBrcTop10			=	0x461C,
		sprmPBrcLeft10			=	0x461D,
		sprmPBrcBottom10		=	0x461E,
		sprmPBrcRight10			=	0x461F,
		sprmPBrcBetween10		=	0x4620,
		sprmPBrcBar10			=	0x4621,
		sprmPDxaFromText10		=	0x4622,
		sprmPWr					=	0x2423,
		sprmPBrcBar				=	0xc653,
		sprmPBrcBar70			=	0x4629,
		sprmPBrcBar80			=	0x6629,
		sprmPBrcBetween			=	0xc652,
		sprmPBrcBetween70		=	0x4428,
		sprmPBrcBetween80		=	0x6428,
		sprmPBrcBottom			=	0xc650,
		sprmPBrcBottom70		=	0x4426,
		sprmPBrcBottom80		=	0x6426,
		sprmPBrcLeft			=	0xc64f,
		sprmPBrcLeft70			=	0x4425,
		sprmPBrcLeft80			=	0x6425,
		sprmPBrcRight			=	0xc651,
		sprmPBrcRight70			=	0x4427,
		sprmPBrcRight80			=	0x6427,
		sprmPBrcTop				=	0xc64e,
		sprmPBrcTop70			=	0x4424,
		sprmPBrcTop80			=	0x6424,
		sprmPFNoAutoHyph		=	0x242A,
		sprmPWHeightAbs			=	0x442B,
		sprmPDcs				=	0x442C,
		sprmPShd80				=	0x442D,
		sprmPShd				=	0xc64d,
		sprmPDyaFromText		=	0x842E,
		sprmPDxaFromText		=	0x842F,
		sprmPFLocked			=	0x2430,
		sprmPFWidowControl		=	0x2431,
		sprmPRuler				=	0xC632,
		sprmPFKinsoku			=	0x2433,
		sprmPFWordWrap			=	0x2434,
		sprmPFOverflowPunct		=	0x2435,
		sprmPFTopLinePunct		=	0x2436,
		sprmPFAutoSpaceDE		=	0x2437,
		sprmPFAutoSpaceDN		=	0x2438,
		sprmPWAlignFont			=	0x4439,
		sprmPFrameTextFlow		=	0x443A,
		sprmPISnapBaseLine		=	0x243B,
		sprmPAnld80				=	0xC63E,
		sprmPAnldCv				=	0x6654,
		sprmPPropRMark			=	0xC63F,
		sprmPOutLvl				=	0x2640,
		sprmPFBiDi				=	0x2441,
		sprmPFNumRMIns			=	0x2443,
		sprmPNumRM				=	0xC645,
		sprmPHugePapx			=	0x6645,
		sprmPFUsePgsuSettings	=	0x2447,
		sprmPFAdjustRight		=	0x2448,
		sprmPDtap				=	0x664a,
		sprmPFInnerTableCell	=	0x244b,
		sprmPFInnerTtp			=	0x244c,
		sprmPFNoAllowOverlap	=	0x2462,
		sprmPItap				=	0x6649,
		sprmPWall				=	0x2664,
		sprmPIpgp				=	0x6465,
		sprmPCnf				=	0xc666,
		sprmPRsid				=	0x6467,
		sprmPIstdList			=	0x4468,
		sprmPIstdListPermute	=	0xc669,
		sprmPDyaBeforeNotCp0	=	0xa46a,
		sprmPTableProps			=	0x646b,
		sprmPTIstdInfo			=	0xc66c,
		sprmPFContextualSpacing	=	0x246d,
		sprmPRpf				=	0x246e,
		sprmPPropRMark90		=	0xc66f,

	//Character sprms
		sprmCFRMarkDel			=	0x0800,
		sprmCFRMark				=	0x0801,
		sprmCFFldVanish			=	0x0802,
		sprmCFSdtVanish			=	0x2A90,
		sprmCPicLocation		=	0x6A03,
		sprmCIbstRMark			=	0x4804,
		sprmCDttmRMark			=	0x6805,
		sprmCFData				=	0x0806,
		sprmCIdslRMark			=	0x4807,
		sprmCChs				=	0xEA08,
		sprmCSymbol				=	0x6A09,
		sprmCFOle2				=	0x080A,
		sprmCIdCharType			=	0x480B,
		sprmCHighlight			=	0x2A0C,
		sprmCObjLocation		=	0x680E,
		sprmCObjpLocation		=	0x680e,
		sprmCFFtcAsciSymb		=	0x2A10,
		sprmCIstd				=	0x4A30,
		sprmCIstdPermute		=	0xCA31,
		sprmCDefault			=	0x2A32,
		sprmCPlain				=	0x2A33,
		sprmCKcd				=	0x2A34,
		sprmCFBold				=	0x0835,
		sprmCFItalic			=	0x0836,
		sprmCFStrike			=	0x0837,
		sprmCFOutline			=	0x0838,
		sprmCFShadow			=	0x0839,
		sprmCFSmallCaps			=	0x083A,
		sprmCFCaps				=	0x083B,
		sprmCFVanish			=	0x083C,
		sprmCFtcDefault			=	0x4A3D,
		sprmCKul				=	0x2A3E,
		sprmCSizePos			=	0xEA3F,
		sprmCDxaSpace			=	0x8840,
		sprmCLid				=	0x4A41,
		sprmCIco				=	0x2A42,
		sprmCHps				=	0x4A43,
		sprmCHpsInc				=	0x2A44,
		sprmCHpsPos				=	0x4845,
		sprmCHpsPosAdj			=	0x2A46,
		sprmCMajority			=	0xCA47,
		sprmCIss				=	0x2A48,
		sprmCHpsNew50			=	0xCA49,
		sprmCHpsInc1			=	0xCA4A,
		sprmCHpsKern			=	0x484B,
		sprmCMajority50			=	0xCA4C,
		sprmCHpsMul				=	0x4A4D,
		sprmCHresi				=	0x484e,
		sprmCRgFtc0				=	0x4A4F,
		sprmCRgFtc1				=	0x4A50,
		sprmCRgFtc2				=	0x4A51,
		sprmCCharScale			=	0x4852,
		sprmCFDStrike			=	0x2A53,
		sprmCFImprint			=	0x0854,
		sprmCFSpec				=	0x0855,
		sprmCFObj				=	0x0856,
		sprmCPropRMark1			=	0xCA57,
		sprmCFEmboss			=	0x0858,
		sprmCSfxText			=	0x2859,
		sprmCFBiDi				=	0x085A,
		sprmCFDiacColor			=	0x085B,
		sprmCFBoldBi			=	0x085C,
		sprmCFItalicBi			=	0x085D,
		sprmCFtcBi				=	0x4A5E,
		sprmCLidBi				=	0x485F,
		sprmCIcoBi				=	0x4A60,
		sprmCHpsBi				=	0x4A61,
		sprmCDispFldRMark		=	0xCA62,
		sprmCIbstRMarkDel		=	0x4863,
		sprmCDttmRMarkDel		=	0x6864,
		sprmCBrc80				=	0x6865,
		sprmCBrc				=	0xca72,
		sprmCShd80				=	0x4866,
		sprmCShd				=	0xca71,
		sprmCIdslRMarkDel		=	0x4867,
		sprmCFUsePgsuSettings	=	0x0868,
		sprmCCpg				=	0x486B,
		sprmCRgLid0_80			=	0x486D,
		sprmCRgLid0				=	0x4873,
		sprmCRgLid1_80			=	0x486E,
		sprmCRgLid1				=	0x4874,
		sprmCIdctHint			=	0x286F,
		sprmCCv					=	0x6870,
		sprmCCvPermute			=	0xca7c,
		sprmCCvUl				=	0x6877,
		sprmCFBoldPresent		=	0x287d,
		sprmCFELayout			=	0xca78,
		sprmCFItalicPresent		=	0x287e,
		sprmCFitText			=	0xca76,
		sprmCFLangApplied		=	0x2a7a,
		sprmCFNoProof			=	0x875,
		sprmCFWebHidde			=	0x811,
		sprmCHsp				=	0x6a12,
		sprmCLbcCRJ				=	0x2879,
		sprmCNewIbstRM			=	0xca13,
		sprmCTransNoProof0		=	0x287f,
		sprmCTransNoProof1		=	0x2880,
		sprmCFRMMove			=	0x2814,
		sprmCRsidProp			=	0x6815,
		sprmCRsidText			=	0x6816,
		sprmCRsidRMDel			=	0x6817,
		sprmCFSpecVanish		=	0x0818,
		sprmCFComplexScripts	=	0x0882,
		sprmCWall				=	0x2a83,
		sprmCPbi				=	0xca84,
		sprmCCnf				=	0xca85,
		sprmCNeedFontFixup		=	0x2a86,
		sprmCPbiIBullet			=	0x6887,
		sprmCPbiGrf				=	0x4888,
		sprmCPropRMark2			=	0xca89,

	//Picture sprms
		sprmPicBrcl				=	0x2E00,
		sprmPicScale			=	0xCE01,
		sprmPicBrcTop80			=	0x6C02,
		sprmPicBrcBottom		=	0xce0a,
		sprmPicBrcBottom70		=	0x4c04,
		sprmPicBrcLeft80		=	0x6C03,
		sprmPicBrcLeft			=	0xce09,
		sprmPicBrcLeft70		=	0x4c03,
		sprmPicBrcBottom80		=	0x6C04,
		sprmPicBrcRight			=	0xce0b,
		sprmPicBrcRight70		=	0x4c05,
		sprmPicBrcRight80		=	0x6C05,
		sprmPicBrcTop			=	0xce08,
		sprmPicBrcTop70			=	0x4c02,
		sprmPicSpare4			=	0xce06,
		sprmCFOle2WasHere		=	0xce07,

	//Section sprms
		sprmScnsPgn				=	0x3000,
		sprmSiHeadingPgn		=	0x3001,
		sprmSOlstAnm			=	0xD202,
		sprmSOlstAnm80			=	0xd202,
		sprmSOlstCv				=	0xd238,
		sprmSDxaColWidth		=	0xF203,
		sprmSDxaColSpacing		=	0xF204,
		sprmSFEvenlySpaced		=	0x3005,
		sprmSFProtected			=	0x3006,
		sprmSDmBinFirst			=	0x5007,
		sprmSDmBinOther			=	0x5008,
		sprmSBkc				=	0x3009,
		sprmSFTitlePage			=	0x300A,
		sprmSCcolumns			=	0x500B,
		sprmSDxaColumns			=	0x900C,
		sprmSFAutoPgn			=	0x300D,
		sprmSNfcPgn				=	0x300E,
		sprmSDyaPgn				=	0xB00F,
		sprmSDxaPgn				=	0xB010,
		sprmSFPgnRestart		=	0x3011,
		sprmSFEndnote			=	0x3012,
		sprmSLnc				=	0x3013,
		sprmSGprfIhdt			=	0x3014,
		sprmSNLnnMod			=	0x5015,
		sprmSDxaLnn				=	0x9016,
		sprmSDyaHdrTop			=	0xB017,
		sprmSDyaHdrBottom		=	0xB018,
		sprmSLBetween			=	0x3019,
		sprmSVjc				=	0x301A,
		sprmSLnnMin				=	0x501B,
		sprmSPgnStart			=	0x501C,
		sprmSBOrientation		=	0x301D,
		sprmSXaPage				=	0xB01F,
		sprmSYaPage				=	0xB020,
		sprmSDxaLeft			=	0xB021,
		sprmSDxaRight			=	0xB022,
		sprmSDyaTop				=	0x9023,
		sprmSDyaBottom			=	0x9024,
		sprmSDzaGutter			=	0xB025,
		sprmSDmPaperReq			=	0x5026,
		sprmSPropRMark1			=	0xD227,
		sprmSFBiDi				=	0x3228,
		sprmSFFacingCol			=	0x3229,
		sprmSFRTLGutter			=	0x322A,
		sprmSBrcTop80			=	0x702B,
		sprmSBrcTop				=	0xd234,
		sprmSBrcLeft80			=	0x702C,
		sprmSBrcLeft			=	0xd235,
		sprmSBrcBottom80		=	0x702d,
		sprmSBrcBottom			=	0xd236,
		sprmSBrcRight80			=	0x702e,
		sprmSBrcRight			=	0xd237,
		sprmSPgbProp			=	0x522F,
		sprmSDxtCharSpace		=	0x7030,
		sprmSDyaLinePitch		=	0x9031,
		sprmSClm				=	0x5032,
		sprmSTextFlow			=	0x5033,
		sprmSWall				=	0x3239,
		sprmSRsid				=	0x703a,
		sprmSFpc				=	0x303b,
		sprmSRncFtn				=	0x303c,
		sprmSEpc				=	0x303d,
		sprmSRncEdn				=	0x303e,
		sprmSNFtn				=	0x503f,
		sprmSNfcFtnRef			=	0x5040,
		sprmSNEdn				=	0x5041,
		sprmSNfcEdnRef			=	0x5042,
		sprmSPropRMark2			=	0xd243,

	//Table sprms
		sprmTDefTable			=	0xD608,
		sprmTDefTable10			=	0xD606,
		sprmTDefTableShd80		=	0xD609,
		sprmTDefTableShd		=	0xd612,
		sprmTDefTableShd2nd		=	0xd616,
		sprmTDefTableShd3rd		=	0xd60c,
		sprmTDelete				=	0x5622,
		sprmTDiagLine			=	0xd630,
		sprmTDiagLine80			=	0xd62a,
		sprmTDxaCol				=	0x7623,
		sprmTDxaGapHalf			=	0x9602,
		sprmTDxaLeft			=	0x9601,
		sprmTDyaRowHeight		=	0x9407,
		sprmTFBiDi80			=	0x560b,
		sprmTFCantSplit			=	0x3403,
		sprmTHTMLProps			=	0x740C,
		sprmTInsert				=	0x7621,
		sprmTJc					=	0x5400,
		sprmTMerge				=	0x5624,
		sprmTSetBrc80			=	0xD620,
		sprmTSetBrc10			=	0xD626,
		sprmTSetBrc				=	0xd62f,
		sprmTSetShd80			=	0x7627,
		sprmTSetShdOdd80		=	0x7628,
		sprmTSetShd				=	0xd62d,
		sprmTSetShdOdd			=	0xd62e,
		sprmTSetShdTable		=	0xd660,
		sprmTSplit				=	0x5625,
		sprmTTableBorders		=	0xd613,
		sprmTTableBorders80		=	0xd605,
		sprmTTableHeader		=	0x3404,
		sprmTTextFlow			=	0x7629,
		sprmTTlp				=	0x740A,
		sprmTVertAlign			=	0xD62C,
		sprmTVertMerge			=	0xD62B,
		sprmTFCellNoWrap		=	0xd639,
		sprmTFitText			=	0xf636,
		sprmTFKeepFollow		=	0x3619,
		sprmTFNeverBeenAutofit	=	0x3663,
		sprmTFNoAllowOverlap	=	0x3465,
		sprmTPc					=	0x360d,
		sprmTBrcBottomCv		=	0xd61c,
		sprmTBrcLeftCv			=	0xd61b,
		sprmTBrcRightCv			=	0xd61d,
		sprmTBrcTopCv			=	0xd61a,
		sprmTCellBrcType		=	0xd662,
		sprmTCellPadding		=	0xd632,
		sprmTCellPaddingDefault	=	0xd634,
		sprmTCellPaddingOuter	=	0xd638,
		sprmTCellSpacing		=	0xd631,
		sprmTCellSpacingDefault	=	0xd633,
		sprmTCellSpacingOuter	=	0xd637,
		sprmTCellWidth			=	0xd635,
		sprmTDxaAbs				=	0x940e,
		sprmTDxaFromText		=	0x9410,
		sprmTDxaFromTextRight	=	0x941e,
		sprmTDyaAbs				=	0x940f,
		sprmTDyaFromText		=	0x9411,
		sprmTDyaFromTextBottom	=	0x941f,
		sprmTFAutofit			=	0x3615,
		sprmTTableWidth			=	0xf614,
		sprmTWidthAfter			=	0xf618,
		sprmTWidthBefore		=	0xf617,
		sprmTWidthIndent		=	0xf661,
		sprmTIstd				=	0x563a,
		sprmTSetShdRaw			=	0xd63b,
		sprmTSetShdOddRaw		=	0xd63c,
		sprmTIstdPermute		=	0xd63d,
		sprmTCellPaddingStyle	=	0xd63e,
		sprmTFCantSplit90		=	0x3466,
		sprmTPropRMark			=	0xd667,
		sprmTWall				=	0x3668,
		sprmTIpgp				=	0x7469,
		sprmTCnf				=	0xd66a,
		sprmTSetShdTableDef		=	0xd66b,
		sprmTDiagLine2nd		=	0xd66c,
		sprmTDiagLine3rd		=	0xd66d,
		sprmTDiagLine4th		=	0xd66e,
		sprmTDiagLine5th		=	0xd66f,
		sprmTDefTableShdRaw		=	0xd670,
		sprmTDefTableShdRaw2nd	=	0xd671,
		sprmTDefTableShdRaw3rd	=	0xd672,
		sprmTSetShdRowFirst		=	0xd673,
		sprmTSetShdRowLast		=	0xd674,
		sprmTSetShdColFirst		=	0xd675,
		sprmTSetShdColLast		=	0xd676,
		sprmTSetShdBand1		=	0xd677,
		sprmTSetShdBand2		=	0xd678,
		sprmTRsid				=	0x7479,
		sprmTCellWidthStyle		=	0xf47a,
		sprmTCellPaddingStyleBad=	0xd67b,
		sprmTCellVertAlignStyle	=	0x347c,
		sprmTCellNoWrapStyle	=	0x347d,
		sprmTCellFitTextStyle	=	0x347e,
		sprmTCellBrcTopStyle	=	0xd47f,
		sprmTCellBrcBottomStyle	=	0xd680,
		sprmTCellBrcLeftStyle	=	0xd681,
		sprmTCellBrcRightStyle	=	0xd682,
		sprmTCellBrcInsideHStyle=	0xd683,
		sprmTCellBrcInsideVStyle=	0xd684,
		sprmTCellBrcTL2BRStyle	=	0xd685,
		sprmTCellBrcTR2BLStyle	=	0xd686,
		sprmTCellShdStyle		=	0xd687,
		sprmTCHorzBands			=	0x3488,
		sprmTCVertBands			=	0x3489,
		sprmTJcRow				=	0x548a,
		sprmTTableBrcTop		=	0xd68b,
		sprmTTableBrcLeft		=	0xd68c,
		sprmTTableBrcBottom		=	0xd68d,
		sprmTTableBrcRight		=	0xd68e,
		sprmTTableBrcInsideH	=	0xd68f,
		sprmTTableBrcInsideV	=	0xd690,
		sprmTFBiDi				=	0x560b,
		sprmTFBiDi90			=	0x5664
	} OperationCode;
}