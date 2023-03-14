#pragma once
#include "afxdialogex.h"

class CListControlDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CListControlDialog)

public:
	CListControlDialog(CWnd* pParent = nullptr);
	virtual ~CListControlDialog();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIST_CONTROL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
};
