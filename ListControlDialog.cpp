#include "pch.h"
#include "MFC-ControlsManagement.h"
#include "afxdialogex.h"
#include "ListControlDialog.h"


IMPLEMENT_DYNAMIC(CListControlDialog, CDialogEx)

CListControlDialog::CListControlDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIST_CONTROL_DIALOG, pParent)
{

}

CListControlDialog::~CListControlDialog()
{
}

void CListControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CListControlDialog, CDialogEx)
END_MESSAGE_MAP()