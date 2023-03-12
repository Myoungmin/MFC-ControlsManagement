#pragma once
#include "afxdialogex.h"


// CRadioButtonDialog dialog

class CRadioButtonDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CRadioButtonDialog)

public:
	CRadioButtonDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRadioButtonDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RADIO_BUTTON_DIALOG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
