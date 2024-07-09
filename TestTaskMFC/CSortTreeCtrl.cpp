#include "CSortTreeCtrl.h"

void CSortTreeCtrl::SortChildren(HTREEITEM HTreeItem, int order)
{
	ASSERT(HTreeItem);
	TVSORTCB tvs;
	tvs.lParam = (LPARAM)this;
	tvs.lpfnCompare = order == SORT_DESC ? SortFunctionDESC : SortFunctionASC;
	if (HTreeItem == TVI_ROOT) {
		tvs.hParent = HTreeItem;
		SortChildrenCB(&tvs);
	}
	HTREEITEM itemUser = GetChildItem(HTreeItem);

	while (itemUser != NULL) {
		tvs.hParent = itemUser;
		SortChildrenCB(&tvs);
		itemUser = GetNextSiblingItem(itemUser);
	}
	
}

int CALLBACK CSortTreeCtrl::SortFunctionASC(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CSortTreeCtrl* pSortTreeCtrl = (CSortTreeCtrl*)lParamSort;
	CString strItem1 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam1);
	CString strItem2 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam2);
	int tmp = strItem1.Compare(strItem2);
	return tmp;
}

int CALLBACK CSortTreeCtrl::SortFunctionDESC(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CSortTreeCtrl* pSortTreeCtrl = (CSortTreeCtrl*)lParamSort;
	CString strItem1 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam1);
	CString strItem2 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam2);
	return strItem2.Compare(strItem1);
}
