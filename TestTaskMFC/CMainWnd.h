#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
#include "resource.h"

#define IDC_TREE_CTRL 1001

class CMainWnd :
    public CFrameWnd
{
public:
    CMainWnd();
    int OnCreate(LPCREATESTRUCT lpCreateStruct);
    void OnFileExit();
    void fillTree();
    ~CMainWnd();
private:
    CStatusBar m_wndStatusBar;
    CTreeCtrl* m_wndTreeCtrl = nullptr;
    CMenu m_wndMenu;
    DECLARE_MESSAGE_MAP();
};



