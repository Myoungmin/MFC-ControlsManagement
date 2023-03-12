// RadioButtonDialog.cpp : implementation file
//

#include "pch.h"
#include "MFC-ControlsManagement.h"
#include "afxdialogex.h"
#include "RadioButtonDialog.h"


// CRadioButtonDialog dialog

IMPLEMENT_DYNAMIC(CRadioButtonDialog, CDialogEx)

CRadioButtonDialog::CRadioButtonDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RADIO_BUTTON_DIALOG, pParent)
{

}

CRadioButtonDialog::~CRadioButtonDialog()
{
}

void CRadioButtonDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRadioButtonDialog, CDialogEx)
END_MESSAGE_MAP()


// CRadioButtonDialog message handlers
