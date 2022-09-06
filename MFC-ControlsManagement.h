
// MFC-ControlsManagement.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCControlsManagementApp:
// See MFC-ControlsManagement.cpp for the implementation of this class
//

class CMFCControlsManagementApp : public CWinApp
{
public:
	CMFCControlsManagementApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCControlsManagementApp theApp;
