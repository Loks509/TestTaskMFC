#include "CMainWnd.h"

BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_LOAD, OnFileLoad)
	ON_BN_CLICKED(IDC_BUTTON_SORT, OnBtnSortClick)
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

	m_wndTreeCtrl = new CSortTreeCtrl();

	if (m_wndTreeCtrl == NULL) {
		return -1;
	}

	if (m_wndTreeCtrl->Create(TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, CRect(0, 0, 200, 500), this, IDC_TREE_CTRL) == -1) {
		return -1;
	}
	m_wndTreeCtrl->ShowWindow(SW_SHOW);

	m_wndButton = new CButton();

	if (m_wndButton == NULL) {
		return -1;
	}

	if (m_wndButton->Create("SORT ASC", WS_CHILD | WS_VISIBLE | SS_CENTER,
		CRect(200, 10, 300, 50), this, IDC_BUTTON_SORT));

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


void CMainWnd::OnBtnSortClick()
{
	m_wndButton->SetWindowTextA(CURR_SORT == CSortTreeCtrl::SORT_ASC ? "SORT DESC" : "SORT_ASC");

	m_wndTreeCtrl->SortChildren(TVI_ROOT, CURR_SORT);

	CURR_SORT = CURR_SORT == CSortTreeCtrl::SORT_ASC ? CSortTreeCtrl::SORT_DESC : CSortTreeCtrl::SORT_ASC;
}

void CMainWnd::fillTreeFromFile(CString path)
{
	m_wndTreeCtrl->DeleteAllItems();

	CStdioFile file(path, CFile::modeRead);
	std::map<CString, std::vector<CString>> headTree;

	CString fullname;

	while (file.ReadString(fullname)) {
		int pos = fullname.FindOneOf(" ");
		CString firstname = pos > 0 ? fullname.Left(pos) : fullname;

		HTREEITEM head;
		headTree[firstname].push_back(fullname);
	}
	file.Close();

	for (auto [nameHead, vItems] : headTree) {
		if (vItems.size() == 1) {
			HTREEITEM head = m_wndTreeCtrl->InsertItem(vItems[0]);
			m_wndTreeCtrl->SetItemData(head, (DWORD)head);
		}
		else {
			HTREEITEM head = m_wndTreeCtrl->InsertItem(nameHead);
			m_wndTreeCtrl->SetItemData(head, (DWORD)head);
			for (auto item : vItems) {
				HTREEITEM head2 = m_wndTreeCtrl->InsertItem(item, head);
				
				m_wndTreeCtrl->SetItemData(head2, (DWORD)head2);
			}
		}
		
	}
}

CMainWnd::~CMainWnd()
{
	delete m_wndTreeCtrl;
	delete m_wndButton;
}
