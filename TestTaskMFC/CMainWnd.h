#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
#include "resource.h"
#include "CSortTreeCtrl.h"
#include <map>
#include <vector>

#define IDC_TREE_CTRL 1001
#define IDC_BUTTON_SORT 1002

class CMainWnd :
    public CFrameWnd
{
public:
    CMainWnd();
    int OnCreate(LPCREATESTRUCT lpCreateStruct);
    void OnFileExit();
    void OnFileLoad();
    void OnBtnSortClick();
    void fillTreeFromFile(CString path);
    ~CMainWnd();
private:
    CStatusBar m_wndStatusBar;
    CSortTreeCtrl* m_wndTreeCtrl = nullptr;
    CButton* m_wndButton = nullptr;
    CMenu m_wndMenu;

    int CURR_SORT = CSortTreeCtrl::SORT_ASC;


    DECLARE_MESSAGE_MAP();
};



