#include "CMainWnd.h"
BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
END_MESSAGE_MAP()

CMainWnd::CMainWnd()
{
	Create(NULL, "Hello world!", WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, NULL);
}

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1) {
		return -1;
	}
	m_wndStatusBar.Create(this);
	if (m_wndMenu.LoadMenu(IDR_MENU1) == -1) {
		return -1;
	}
	SetMenu(&m_wndMenu);
	return 0;
}

void CMainWnd::OnFileExit() {
	DestroyWindow();
}

CMainWnd::~CMainWnd()
{
}
