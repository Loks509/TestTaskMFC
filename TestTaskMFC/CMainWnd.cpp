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

	m_wndTreeCtrl = new CTreeCtrl();

	if (m_wndTreeCtrl == NULL) {
		return -1;
	}

	if (m_wndTreeCtrl->Create(TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, CRect(0, 0, 200, 500), this, IDC_TREE_CTRL) == -1) {
		return -1;
	}
	m_wndTreeCtrl->ShowWindow(SW_SHOW);
	fillTree();


	return 0;
}

void CMainWnd::OnFileExit() {
	DestroyWindow();
}

void CMainWnd::OnFileOpen()
{
}

void CMainWnd::fillTree()
{
	HTREEITEM otdel = m_wndTreeCtrl->InsertItem("otdel");
	m_wndTreeCtrl->InsertItem("1", otdel);
	m_wndTreeCtrl->InsertItem("2", otdel);
	m_wndTreeCtrl->InsertItem("3", otdel);
	m_wndTreeCtrl->InsertItem("4", otdel);
	HTREEITEM otdel2 = m_wndTreeCtrl->InsertItem("otdel2");
	m_wndTreeCtrl->InsertItem("1", otdel2);
	m_wndTreeCtrl->InsertItem("2", otdel2);
	m_wndTreeCtrl->InsertItem("3", otdel2);
	m_wndTreeCtrl->InsertItem("4", otdel2);
}

CMainWnd::~CMainWnd()
{
}
