#include "CSortTreeCtrl.h"

void CSortTreeCtrl::SortChildren(HTREEITEM HTreeItem, int order)
{
	if (HTreeItem == TVI_ROOT) {
		TVSORTCB tvs;
		tvs.hParent = HTreeItem;
		tvs.lParam = (LPARAM)this;
		tvs.lpfnCompare = order == SORT_DESC ? SortFunctionDESC : SortFunctionASC;
		SortChildrenCB(&tvs);
	}
	HTREEITEM itemUser = GetChildItem(HTreeItem);

	while (itemUser != NULL) {
		TVSORTCB tvs;
		tvs.hParent = itemUser;
		tvs.lParam = (LPARAM)this;
		tvs.lpfnCompare = order == SORT_DESC ? SortFunctionDESC : SortFunctionASC;
		SortChildrenCB(&tvs);

		itemUser = GetNextSiblingItem(itemUser);
	}
	
}

int CALLBACK CSortTreeCtrl::SortFunctionASC(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CSortTreeCtrl* pSortTreeCtrl = (CSortTreeCtrl*)lParamSort;
	CString strItem1 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam1);
	CString strItem2 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam2);
	return strItem1.Compare(strItem2);
}

int CALLBACK CSortTreeCtrl::SortFunctionDESC(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CSortTreeCtrl* pSortTreeCtrl = (CSortTreeCtrl*)lParamSort;
	CString strItem1 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam1);
	CString strItem2 = pSortTreeCtrl->GetItemText((HTREEITEM)lParam2);
	return strItem2.Compare(strItem1);
}
