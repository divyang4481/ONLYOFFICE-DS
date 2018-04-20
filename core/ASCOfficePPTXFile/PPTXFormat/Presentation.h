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
#ifndef PPTX_PRESENTATION_FILE_INCLUDE_H_
#define PPTX_PRESENTATION_FILE_INCLUDE_H_

#include "WrapperFile.h"
#include "FileContainer.h"
#include "FileTypes.h"

#include "Presentation/EmbeddedFont.h"
#include "Presentation/Kinsoku.h"
#include "Presentation/NotesSz.h"
#include "Presentation/PhotoAlbum.h"
#include "Presentation/SldSz.h"
#include "CommentAuthors.h"

#include "Limit/Conformance.h"
#include "Logic/TextListStyle.h"
#include "Logic/ClrMap.h"
#include "Logic/ExtP.h"
#include "Theme/ClrScheme.h"
#include "Comments.h"

#include "../../Common/DocxFormat/Source/DocxFormat/Media/VbaProject.h"
#include "../../Common/DocxFormat/Source/DocxFormat/Media/JsaProject.h"

namespace PPTX
{
	class Presentation : public WrapperFile, public PPTX::FileContainer
	{
	public:
		Presentation(OOX::Document *pMain) : WrapperFile(pMain), PPTX::FileContainer(pMain)
		{
			m_bMacroEnabled = false;
		}
		Presentation(OOX::Document *pMain, const OOX::CPath& filename, FileMap& map) : WrapperFile(pMain), PPTX::FileContainer(pMain)
		{
			m_bMacroEnabled = false;
			read(filename, map);
		}
		virtual ~Presentation()
		{
		}
		virtual void read(const OOX::CPath& filename, FileMap& map)
		{
			XmlUtils::CXmlNode oNode;
			oNode.FromXmlFile(filename.m_strFilename);

			oNode.ReadAttributeBase(L"autoCompressPictures", attrAutoCompressPictures);
			oNode.ReadAttributeBase(L"bookmarkIdSeed", attrBookmarkIdSeed);
			oNode.ReadAttributeBase(L"compatMode", attrCompatMode);
			oNode.ReadAttributeBase(L"conformance", attrConformance);
			oNode.ReadAttributeBase(L"embedTrueTypeFonts", attrEmbedTrueTypeFonts);
			oNode.ReadAttributeBase(L"firstSlideNum", attrFirstSlideNum);
			oNode.ReadAttributeBase(L"removePersonalInfoOnSave", attrRemovePersonalInfoOnSave);
			oNode.ReadAttributeBase(L"rtl", attrRtl);
			oNode.ReadAttributeBase(L"saveSubsetFonts", attrSaveSubsetFonts);
			oNode.ReadAttributeBase(L"serverZoom", attrServerZoom);
			oNode.ReadAttributeBase(L"showSpecialPlsOnTitleSld", attrShowSpecialPlsOnTitleSld);
			oNode.ReadAttributeBase(L"strictFirstAndLastChars", attrStrictFirstAndLastChars);

			//custDataLst (Customer Data List)
			//custShowLst (List of Custom Shows)
			defaultTextStyle = oNode.ReadNode(_T("p:defaultTextStyle"));
			if(defaultTextStyle.is_init())
				defaultTextStyle->SetParentFilePointer(this);

			embeddedFontLst.clear();
			XmlUtils::CXmlNode oNodeEmbeddedFonts;
			if (oNode.GetNode(_T("p:embeddedFontLst"), oNodeEmbeddedFonts))
			{
				oNodeEmbeddedFonts.LoadArray(_T("p:embeddedFont"), embeddedFontLst);

				for (size_t i = 0; i < embeddedFontLst.size(); ++i)
					embeddedFontLst[i].SetParentFilePointer(this);
			}
			
			handoutMasterIdLst.clear();
			XmlUtils::CXmlNode oNodeHMList;
			if (oNode.GetNode(_T("p:handoutMasterIdLst"), oNodeHMList))
			{
				oNodeHMList.LoadArray(_T("p:handoutMasterId"), handoutMasterIdLst);

				for (size_t i = 0; i < handoutMasterIdLst.size(); ++i)
					handoutMasterIdLst[i].SetParentFilePointer(this);
			}


			kinsoku = oNode.ReadNode(_T("p:kinsoku"));
			if (kinsoku.is_init())
				kinsoku->SetParentFilePointer(this);
			
			//modifyVerifier (Modification Verifier)
			notesMasterIdLst.clear();
			XmlUtils::CXmlNode oNodeMIDList;
			if (oNode.GetNode(_T("p:notesMasterIdLst"), oNodeMIDList))
			{
				oNodeMIDList.LoadArray(_T("p:notesMasterId"), notesMasterIdLst);

				for (size_t i = 0; i < notesMasterIdLst.size(); ++i)
					notesMasterIdLst[i].SetParentFilePointer(this);
			}

			notesSz = oNode.ReadNode(_T("p:notesSz"));
			if (notesSz.is_init())
				notesSz->SetParentFilePointer(this);

			photoAlbum = oNode.ReadNode(_T("p:photoAlbum"));
			if(photoAlbum.is_init())
				photoAlbum->SetParentFilePointer(this);

			sldIdLst.clear();
			XmlUtils::CXmlNode oNode_sldId;
			if (oNode.GetNode(_T("p:sldIdLst"), oNode_sldId))
			{
				oNode_sldId.LoadArray(_T("p:sldId"), sldIdLst);

				for (size_t i = 0; i < sldIdLst.size(); ++i)
					sldIdLst[i].SetParentFilePointer(this);
			}

			sldMasterIdLst.clear();
			XmlUtils::CXmlNode oNode_sldM_Id;
			if (oNode.GetNode(_T("p:sldMasterIdLst"), oNode_sldM_Id))
			{
				oNode_sldM_Id.LoadArray(_T("p:sldMasterId"), sldMasterIdLst);

				for (size_t i = 0; i < sldMasterIdLst.size(); ++i)
					sldMasterIdLst[i].SetParentFilePointer(this);
			}

			sldSz = oNode.ReadNode(_T("p:sldSz"));
			if (sldSz.is_init())
				sldSz->SetParentFilePointer(this);

			XmlUtils::CXmlNode list = oNode.ReadNodeNoNS(_T("extLst"));
			if (list.IsValid())
			{		
				XmlUtils::CXmlNodes oNodes;
				if (list.GetNodes(_T("*"), oNodes))
				{
					int nCount = oNodes.GetCount();
					for (int i = 0; i < nCount; ++i)
					{
						XmlUtils::CXmlNode oNode;
						oNodes.GetAt(i, oNode);	

						PPTX::Logic::Ext ext;
						ext.fromXML(oNode);
						if (ext.sectionLst.IsInit())
						{
							sectionLst = ext.sectionLst;
						}
					}
				}
			}

			//smartTags (Smart Tags)
			Normalize();
		}
		virtual void write(const OOX::CPath& filename, const OOX::CPath& directory, OOX::CContentTypes& content)const
		{
			WrapperFile::write(filename, directory, content);
			FileContainer::write(filename, directory, content);
		}

		virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
		{
			pWriter->StartRecord(NSBinPptxRW::NSMainTables::Presentation);

			pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeStart);
			
			pWriter->WriteBool2(0, attrAutoCompressPictures);
			pWriter->WriteInt2(1, attrBookmarkIdSeed);
			pWriter->WriteBool2(2, attrCompatMode);
			pWriter->WriteLimit2(3, attrConformance);
			pWriter->WriteBool2(4, attrEmbedTrueTypeFonts);
			pWriter->WriteInt2(5, attrFirstSlideNum);
			pWriter->WriteBool2(6, attrRemovePersonalInfoOnSave);
			pWriter->WriteBool2(7, attrRtl);
			pWriter->WriteBool2(8, attrSaveSubsetFonts);
			pWriter->WriteString2(9, attrServerZoom);
			pWriter->WriteBool2(10, attrShowSpecialPlsOnTitleSld);
			pWriter->WriteBool2(11, attrStrictFirstAndLastChars);
			
			pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeEnd);

			pWriter->WriteRecord2(0, defaultTextStyle);
			pWriter->WriteRecordArray(1, 0, embeddedFontLst);
			pWriter->WriteRecord2(2, kinsoku);
			pWriter->WriteRecord2(3, notesSz);
			pWriter->WriteRecord2(4, photoAlbum);
			pWriter->WriteRecord2(5, sldSz);

			pWriter->WriteRecord2(6, commentAuthors);
			pWriter->WriteRecord2(7, sectionLst);

			if (m_pVbaProject.IsInit())
			{
				pWriter->StartRecord(8);
				{
					m_pVbaProject->toPPTY(pWriter);
				}
				pWriter->EndRecord();
			}
			pWriter->WriteRecord2(9, m_pJsaProject);
			pWriter->WriteRecord2(10, comments);

			pWriter->EndRecord();
		}
		virtual void fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader)
		{
			BYTE _type = pReader->GetUChar();
			LONG _len = pReader->GetULong();
			LONG _start_pos = pReader->GetPos();
			LONG _end_pos = _len + _start_pos;

			// attributes
			BYTE _sa = pReader->GetUChar();

			while (true)
			{
				BYTE _at = pReader->GetUChar_TypeNode();

				if (_at == NSBinPptxRW::g_nodeAttributeEnd)
					break;

				switch (_at)
				{
					case 0: { attrAutoCompressPictures		= pReader->GetBool(); break; }
					case 1: { attrBookmarkIdSeed			= pReader->GetLong(); break; }
					case 2: { attrCompatMode				= pReader->GetBool(); break; }
					case 3: { attrConformance				= pReader->GetUChar(); break; }
					case 4: { attrEmbedTrueTypeFonts		= pReader->GetBool(); break; }
					case 5: { attrFirstSlideNum				= pReader->GetLong(); break; }
					case 6: { attrRemovePersonalInfoOnSave	= pReader->GetBool(); break; }
					case 7: { attrRtl						= pReader->GetBool(); break; }
					case 8: { attrSaveSubsetFonts			= pReader->GetBool(); break; }
					case 9: { attrServerZoom				= pReader->GetString2(); break; }
					case 10: { attrShowSpecialPlsOnTitleSld = pReader->GetBool(); break; }
					case 11: { attrStrictFirstAndLastChars	= pReader->GetBool(); break; }
					default:
						return;
				}
			}

			while (pReader->GetPos() < _end_pos)
			{
				_type = pReader->GetUChar();
				
				switch (_type)
				{
					case 0:
					{
						defaultTextStyle = PPTX::Logic::TextListStyle();
						defaultTextStyle->m_name = _T("p:defaultTextStyle");
						defaultTextStyle->fromPPTY(pReader);
						break;
					}
					case 1: { pReader->SkipRecord(); break; }
					case 2: { pReader->SkipRecord(); break; }
					case 3: 
					{ 
						notesSz = new nsPresentation::NotesSz();
						pReader->Skip(5); // len + start attributes

						while (true)
						{
							BYTE _at = pReader->GetUChar_TypeNode();

							if (_at == NSBinPptxRW::g_nodeAttributeEnd)
								break;

							switch (_at)
							{
								case 0: { notesSz->cx = pReader->GetLong(); break; }
								case 1: { notesSz->cy = pReader->GetLong(); break; }
								default:
									return;
							}
						}
						break; 
					}
					case 4: { pReader->SkipRecord(); break; }
					case 5:
					{
						sldSz = new nsPresentation::SldSz();
						pReader->Skip(5); // len + start attributes

						while (true)
						{
							BYTE _at = pReader->GetUChar_TypeNode();

							if (_at == NSBinPptxRW::g_nodeAttributeEnd)
								break;

							switch (_at)
							{
								case 0: { sldSz->cx = pReader->GetLong(); break; }
								case 1: { sldSz->cy = pReader->GetLong(); break; }
								case 2: { sldSz->type = pReader->GetUChar(); break; }
								default:
									return;
							}
						}						
					}break;
					case 6:
					{
						commentAuthors = new PPTX::Authors(File::m_pMainDocument);
						commentAuthors->fromPPTY(pReader);						
					}break;
					case 7:
					{
						sectionLst = new nsPresentation::SectionLst();
						sectionLst->fromPPTY(pReader);						
					}break;
					case 8:
					{
						m_pVbaProject = new OOX::VbaProject(File::m_pMainDocument);
						m_pVbaProject->fromPPTY(pReader);
						
						smart_ptr<OOX::File> file = m_pVbaProject.smart_dynamic_cast<OOX::File>();
						FileContainer::Add(file);

						m_bMacroEnabled = true;
					}break;
					case 9:
					{
						m_pJsaProject = new OOX::JsaProject(File::m_pMainDocument);
						m_pJsaProject->fromPPTY(pReader);

						smart_ptr<OOX::File> file = m_pJsaProject.smart_dynamic_cast<OOX::File>();
						FileContainer::Add(file);
					}break;
					case 10:
					{
						comments = new PPTX::Comments(OOX::File::m_pMainDocument);
						comments->fromPPTY(pReader);
					}break;
					default:
					{
						pReader->SkipRecord();
						return;
					}
				}
			}

			pReader->Seek(_end_pos);
		}

		virtual void toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
		{
			pWriter->StartNode(_T("p:presentation"));

			pWriter->StartAttributes();

			pWriter->WriteAttribute(_T("xmlns:a"), PPTX::g_Namespaces.a.m_strLink);
			pWriter->WriteAttribute(_T("xmlns:r"), PPTX::g_Namespaces.r.m_strLink);
			pWriter->WriteAttribute(_T("xmlns:p"), PPTX::g_Namespaces.p.m_strLink);
			pWriter->WriteAttribute(_T("xmlns:m"), PPTX::g_Namespaces.m.m_strLink);
			pWriter->WriteAttribute(_T("xmlns:w"), PPTX::g_Namespaces.w.m_strLink);

			pWriter->WriteAttribute(_T("autoCompressPictures"), attrAutoCompressPictures);
			pWriter->WriteAttribute(_T("bookmarkIdSeed"), attrBookmarkIdSeed);
			pWriter->WriteAttribute(_T("compatMode"), attrCompatMode);
			pWriter->WriteAttribute(_T("conformance"), attrConformance);
			pWriter->WriteAttribute(_T("embedTrueTypeFonts"), attrEmbedTrueTypeFonts);
			pWriter->WriteAttribute(_T("firstSlideNum"), attrFirstSlideNum);
			pWriter->WriteAttribute(_T("removePersonalInfoOnSave"), attrRemovePersonalInfoOnSave);
			pWriter->WriteAttribute(_T("rtl"), attrRtl);
			pWriter->WriteAttribute(_T("saveSubsetFonts"), attrSaveSubsetFonts);
			pWriter->WriteAttribute(_T("serverZoom"), attrServerZoom);
			pWriter->WriteAttribute(_T("showSpecialPlsOnTitleSld"), attrShowSpecialPlsOnTitleSld);
			pWriter->WriteAttribute(_T("strictFirstAndLastChars"), attrStrictFirstAndLastChars);

			pWriter->EndAttributes();

			pWriter->WriteArray(L"p:sldMasterIdLst", sldMasterIdLst);
			pWriter->WriteArray(L"p:notesMasterIdLst", notesMasterIdLst);
			pWriter->WriteArray(L"p:handoutMasterIdLst", handoutMasterIdLst);
			pWriter->WriteArray(L"p:embeddedFontLst", embeddedFontLst);
			pWriter->WriteArray(L"p:sldIdLst", sldIdLst);
			
			pWriter->Write(sldSz);
			pWriter->Write(notesSz);
			pWriter->Write(photoAlbum);
			pWriter->Write(kinsoku);
			pWriter->Write(defaultTextStyle);

			std::vector<Logic::Ext> extLst;

			if (sectionLst.IsInit())
			{
				Logic::Ext exp;
				exp.sectionLst = sectionLst;
				extLst.push_back(exp);
			}
			pWriter->WriteArray(L"p:extLst", extLst);	

			pWriter->EndNode(L"p:presentation");
		}

		virtual const OOX::FileType type() const
		{
			if (m_bMacroEnabled)	return OOX::Presentation::FileTypes::PresentationMacro;
			else					return OOX::Presentation::FileTypes::Presentation;
		}
		virtual const OOX::CPath DefaultDirectory() const
		{
			return type().DefaultDirectory();
		}
		virtual const OOX::CPath DefaultFileName() const
		{
			return type().DefaultFileName();
		}

	//Childs
		//custDataLst (Customer Data List)
		//property<std::list<Presentation::CustShow> > custShowLst (List of Custom Shows)
		nullable<Logic::TextListStyle>				defaultTextStyle;
		std::vector<nsPresentation::EmbeddedFont>	embeddedFontLst;
		std::vector<Logic::XmlId>					handoutMasterIdLst;
		nullable<nsPresentation::Kinsoku>			kinsoku;
		//modifyVerifier (Modification Verifier)
		std::vector<Logic::XmlId>					notesMasterIdLst;
		nullable<nsPresentation::NotesSz>			notesSz;
		nullable<nsPresentation::PhotoAlbum>		photoAlbum;
		std::vector<Logic::XmlId>					sldIdLst;
		std::vector<Logic::XmlId>					sldMasterIdLst;
		nullable<nsPresentation::SldSz>				sldSz;
		nullable<nsPresentation::SectionLst>		sectionLst;
		//smartTags (Smart Tags)

	// Attrs
		nullable_bool							attrAutoCompressPictures;
		nullable_int							attrBookmarkIdSeed;
		nullable_bool							attrCompatMode;
		nullable_limit<Limit::Conformance>		attrConformance;
		nullable_bool							attrEmbedTrueTypeFonts;
		nullable_int							attrFirstSlideNum;
		nullable_bool							attrRemovePersonalInfoOnSave;
		nullable_bool							attrRtl;
		nullable_bool							attrSaveSubsetFonts;
		nullable_string							attrServerZoom;
		nullable_bool							attrShowSpecialPlsOnTitleSld;
		nullable_bool							attrStrictFirstAndLastChars;

		smart_ptr<PPTX::Authors>				commentAuthors;

	private:
		Logic::ClrMap				m_clrMap;
		nsTheme::ClrScheme			m_clrScheme;
	public:
		bool						m_bMacroEnabled;
		smart_ptr<OOX::VbaProject>	m_pVbaProject;
		smart_ptr<OOX::JsaProject>	m_pJsaProject;
		smart_ptr<PPTX::Comments>	comments;
		
        void SetClrMap(Logic::ClrMap map)				{m_clrMap = map;}
        void SetClrScheme(nsTheme::ClrScheme scheme)	{m_clrScheme = scheme;}

		DWORD GetRGBAFromMap(const std::wstring& str)const
		{
			return m_clrScheme.GetRGBAFromScheme(m_clrMap.GetColorSchemeIndex(str));
		}
		DWORD GetARGBFromMap(const std::wstring& str)const
		{
			return m_clrScheme.GetARGBFromScheme(m_clrMap.GetColorSchemeIndex(str));
		}
		DWORD GetBGRAFromMap(const std::wstring& str)const
		{
			return m_clrScheme.GetBGRAFromScheme(m_clrMap.GetColorSchemeIndex(str));
		}
		DWORD GetABGRFromMap(const std::wstring& str)const
		{
			return m_clrScheme.GetABGRFromScheme(m_clrMap.GetColorSchemeIndex(str));
		}

	private:
		AVSINLINE void Normalize()
		{
			attrBookmarkIdSeed.normalize(1, 2147483647);
			attrFirstSlideNum.normalize_positive();
		}
	};
} // namespace PPTX

#endif // PPTX_PRESENTATION_FILE_INCLUDE_H_
