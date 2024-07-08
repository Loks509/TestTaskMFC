#include "CMainWnd.h"
BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_LOAD, OnFileLoad)
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


	return 0;
}

void CMainWnd::OnFileExit() {
	DestroyWindow();
}

void CMainWnd::OnFileLoad()
{
	CFileDialog fileDialog(TRUE, NULL, "*.txt");
	if (fileDialog.DoModal() == IDOK) {
		fillTreeFromFile(fileDialog.GetPathName());
	}
}

void CMainWnd::fillTreeFromFile(CString path)
{
	
}

CMainWnd::~CMainWnd()
{
}
