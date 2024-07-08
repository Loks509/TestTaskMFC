#pragma once
#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

class CMainWnd :
    public CFrameWnd
{
public:
    CMainWnd();
    int OnCreate(LPCREATESTRUCT lpCreateStruct);
    void OnFileExit();
    ~CMainWnd();
private:
    CStatusBar m_wndStatusBar;
    CMenu m_wndMenu;
    DECLARE_MESSAGE_MAP();
};



