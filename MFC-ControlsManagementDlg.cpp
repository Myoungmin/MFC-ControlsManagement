
// MFC-ControlsManagementDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC-ControlsManagement.h"
#include "MFC-ControlsManagementDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCControlsManagementDlg dialog



CMFCControlsManagementDlg::CMFCControlsManagementDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCONTROLSMANAGEMENT_DIALOG, pParent)
	, m_enableDisableVal(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCControlsManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_myEditControl);
	DDX_Check(pDX, IDC_CHECK1, m_enableDisableVal);
}

BEGIN_MESSAGE_MAP(CMFCControlsManagementDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CMFCControlsManagementDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CMFCControlsManagementDlg message handlers

BOOL CMFCControlsManagementDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCControlsManagementDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCControlsManagementDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCControlsManagementDlg::OnBnClickedCheck1()
{
	UpdateData(TRUE);
	if (m_enableDisableVal)
		m_myEditControl.EnableWindow(TRUE);
	else
		m_myEditControl.EnableWindow(FALSE);
}
