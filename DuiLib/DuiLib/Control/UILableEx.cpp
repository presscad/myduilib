#include "stdafx.h"
#include "UILableEx.h"

namespace DuiLib
{
	void CLabelUIEx::PaintBkImage(HDC hDC)
	{
		if (m_sBkImage.IsEmpty())
			return;
		if (!DrawImageEx(hDC, m_pManager, m_rcItem, m_rcPaint, (LPCTSTR)m_sBkImage))
			m_sBkImage.Empty();
	}

	void CLabelUIEx::OnFrame()
	{
		Invalidate();
	}

	void CLabelUIEx::PaintText(HDC hDC)
	{
		if (m_dwTextColor == 0) m_dwTextColor = m_pManager->GetDefaultFontColor();
		if (m_dwDisabledTextColor == 0) m_dwDisabledTextColor = m_pManager->GetDefaultDisabledColor();

		if (m_sText.IsEmpty()) return;
		int nLinks = 0;
		RECT rc = m_rcItem;
		rc.left += m_rcTextPadding.left;
		rc.right -= m_rcTextPadding.right;
		rc.top += m_rcTextPadding.top;
		rc.bottom -= m_rcTextPadding.bottom;
		if (IsEnabled()) {
			if (m_bShowHtml){
				CRenderEngine::DrawHtmlText(hDC, m_pManager, rc, m_sText, m_dwTextColor, \
					NULL, NULL, nLinks, m_uTextStyle);
			}
			else{
				CRenderEngine::DrawText(hDC, m_pManager, rc, m_sText, m_dwTextColor, \
					m_iFont, m_uTextStyle);
			}
		}
		else {
			if (m_bShowHtml){
				CRenderEngine::DrawHtmlText(hDC, m_pManager, rc, m_sText, m_dwDisabledTextColor, \
					NULL, NULL, nLinks, m_uTextStyle);
			}
			else {
				CRenderEngine::DrawText(hDC, m_pManager, rc, m_sText, m_dwDisabledTextColor, \
					m_iFont, m_uTextStyle);
			}
		}
	}
	
	CLabelIconUI::CLabelIconUI()
	{
		m_hIcon = NULL;
	}

	CLabelIconUI::~CLabelIconUI(void)
	{
		if (m_hIcon != NULL)
			::DestroyIcon(m_hIcon);
	}

	void CLabelIconUI::PaintStatusImage(HDC hDC)
	{
		CLabelUI::PaintStatusImage(hDC);
		if (m_hIcon != NULL)
		{
			ICONINFO ii;
			if (::GetIconInfo(m_hIcon, &ii))
			{
				BITMAP bmp;
				if (::GetObject(ii.hbmColor, sizeof(bmp), &bmp))
					::DrawIcon(hDC, m_rcItem.left + (m_rcItem.right - m_rcItem.left - bmp.bmWidth) / 2, m_rcItem.top + 4, m_hIcon);
				::DeleteObject(ii.hbmColor);
				::DeleteObject(ii.hbmMask);
			}
		}
	}
	
	void CLabelIconUI::SetIcon(HICON hIcon)
	{
		m_hIcon = hIcon;
	}

	void CLabelMutilineUI::PaintText(HDC hDC)
	{
		if (m_dwTextColor == 0) m_dwTextColor = m_pManager->GetDefaultFontColor();
		if (m_dwDisabledTextColor == 0) m_dwDisabledTextColor = m_pManager->GetDefaultDisabledColor();

		if (m_sText.IsEmpty()) return;
		int nLinks = 0;
		RECT rc = m_rcItem;
		rc.left += m_rcTextPadding.left;
		rc.right -= m_rcTextPadding.right;
		rc.top += m_rcTextPadding.top;
		rc.bottom -= m_rcTextPadding.bottom;
		if (IsEnabled()) {
			if (m_bShowHtml){
				CRenderEngine::DrawHtmlText(hDC, m_pManager, rc, m_sText, m_dwTextColor, \
					NULL, NULL, nLinks, m_uTextStyle);
			}
			else{
				CRenderEngine::DrawText(hDC, m_pManager, rc, m_sText, m_dwTextColor, \
					m_iFont, m_uTextStyle);
			}
		}
		else {
			if (m_bShowHtml){
				CRenderEngine::DrawHtmlText(hDC, m_pManager, rc, m_sText, m_dwDisabledTextColor, \
					NULL, NULL, nLinks, m_uTextStyle);
			}
			else{
				CRenderEngine::DrawText(hDC, m_pManager, rc, m_sText, m_dwDisabledTextColor, \
					m_iFont, m_uTextStyle);
			}
		}
	}
}