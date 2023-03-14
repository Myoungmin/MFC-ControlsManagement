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
public:
	afx_msg void OnBnClickedLoadButton();
	afx_msg void OnBnClickedSaveButton();
	virtual BOOL OnInitDialog();

private:
	void ReadFileToListControlData(LPCTSTR lpszFileName, CListCtrl* pListCtrl);
	void WriteListControlDataToFile(CListCtrl* pListCtrl, LPCTSTR lpszFileName);
};
