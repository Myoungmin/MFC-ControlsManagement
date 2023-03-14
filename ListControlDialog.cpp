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
	ON_BN_CLICKED(IDC_LOAD_BUTTON, &CListControlDialog::OnBnClickedLoadButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CListControlDialog::OnBnClickedSaveButton)
END_MESSAGE_MAP()

void CListControlDialog::OnBnClickedLoadButton()
{
	// TODO: Add your control notification handler code here
}


void CListControlDialog::OnBnClickedSaveButton()
{
	// TODO: Add your control notification handler code here
}


BOOL CListControlDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_CONTROL);

	// Set the LVS_REPORT style for the List Control
	DWORD dwStyle = pListCtrl->GetStyle();
	pListCtrl->ModifyStyle(LVS_TYPEMASK, LVS_REPORT | dwStyle);

	// Insert the first column into the List Control
	pListCtrl->InsertColumn(0, _T("Column 1"), LVCFMT_LEFT, 100);

	// Insert the second column into the List Control
	pListCtrl->InsertColumn(1, _T("Column 2"), LVCFMT_LEFT, 100);

	// Set the column headers
	LVITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iSubItem = 0;
	lvItem.pszText = _T("Column 1");
	pListCtrl->SetItem(&lvItem);
	lvItem.iSubItem = 1;
	lvItem.pszText = _T("Column 2");
	pListCtrl->SetItem(&lvItem);

	for (int i = 0; i < 10; i++)
	{
		CString str1;
		str1.Format(_T("%d-1"), i);
		CString str2;
		str2.Format(_T("%d-2"), i);
		// Add a new row to the List Control
		int nIndex = pListCtrl->InsertItem(pListCtrl->GetItemCount(), _T(""));

		// Set the data in the first column of the new row
		pListCtrl->SetItemText(nIndex, 0, str1);

		// Set the data in the second column of the new row
		pListCtrl->SetItemText(nIndex, 1, str2);
	}

	return TRUE;
}
