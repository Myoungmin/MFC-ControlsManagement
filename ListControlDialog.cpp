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
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_CONTROL);
	ReadFileToListControlData(_T("myfile.data"), pListCtrl);
}


void CListControlDialog::OnBnClickedSaveButton()
{
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST_CONTROL);
	WriteListControlDataToFile(pListCtrl, _T("myfile.data"));
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

void CListControlDialog::ReadFileToListControlData(LPCTSTR lpszFileName, CListCtrl* pListCtrl)
{
	// Open the file for reading
	CStdioFile file;
	if (file.Open(lpszFileName, CFile::modeRead))
	{
		CString strLine;
		int nItemIndex = 0;

		// Read each line from the file
		while (file.ReadString(strLine))
		{
			TRACE(_T("Read line: %s\n"), strLine);

			// Split the line into columns using the tab delimiter
			CStringArray arrColumns;
			int nTokenIndex = 0;
			int nTokenCount = 0;
			CString strDelimiter = _T("\t");
			CString strToken = strLine.Tokenize(strDelimiter, nTokenIndex);
			while (!strToken.IsEmpty())
			{
				arrColumns.Add(strToken);
				strToken = strLine.Tokenize(strDelimiter, nTokenIndex);
				nTokenCount++;
			}

			// Add a new item to the List Control and populate the columns with data
			pListCtrl->InsertItem(nItemIndex, arrColumns[0]);
			for (int i = 1; i < nTokenCount; i++)
			{
				pListCtrl->SetItemText(nItemIndex, i, arrColumns[i]);
			}

			nItemIndex++;
		}

		file.Close();
	}
}

void CListControlDialog::WriteListControlDataToFile(CListCtrl* pListCtrl, LPCTSTR lpszFileName)
{
	/* 아래와 같은 코드로 하니까 위에 함수랑 안맞는듯? */
	/* 위 함수에서 자꾸 0만 읽었다. */

	//int nItemCount = pListCtrl->GetItemCount();

	//CFile file;
	//if (file.Open(lpszFileName, CFile::modeCreate | CFile::modeWrite))
	//{
	//	for (int i = 0; i < nItemCount; i++)
	//	{
	//		CString strItemData1 = pListCtrl->GetItemText(i, 0); // Get the data from column 0
	//		CString strItemData2 = pListCtrl->GetItemText(i, 1); // Get the data from column 1
	//		CString strDataToWrite = strItemData1 + _T("\t") + strItemData2; // Concatenate the two strings with a tab delimiter
	//		file.Write(strDataToWrite, strDataToWrite.GetLength() * sizeof(TCHAR));
	//		file.Write(_T("\r\n"), 2 * sizeof(TCHAR)); // Add a newline after each item
	//	}

	//	file.Close();
	//}

	int nItemCount = pListCtrl->GetItemCount();

	CStdioFile file;
	if (file.Open(lpszFileName, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
	{
		for (int i = 0; i < nItemCount; i++)
		{
			CString strDataToWrite;
			for (int j = 0; j < pListCtrl->GetHeaderCtrl()->GetItemCount(); j++)
			{
				strDataToWrite += pListCtrl->GetItemText(i, j);
				if (j < pListCtrl->GetHeaderCtrl()->GetItemCount() - 1)
				{
					strDataToWrite += _T("\t");
				}
			}
			file.WriteString(strDataToWrite + _T("\n"));
		}

		file.Close();
	}
}
