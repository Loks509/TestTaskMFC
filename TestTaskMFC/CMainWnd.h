#pragma once
#include <afxwin.h>
#include <afxext.h>

class CMainWnd :
    public CFrameWnd
{
public:
    CMainWnd();
    int OnCreate(LPCREATESTRUCT lpCreateStruct);
    ~CMainWnd();
private:
    CStatusBar m_wndStatusBar;
    DECLARE_MESSAGE_MAP();
};



