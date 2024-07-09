#pragma once
#include <afxcmn.h>
class CSortTreeCtrl :
    public CTreeCtrl
{
public:
    static inline int SORT_ASC = 1;
    static inline int SORT_DESC = 2;
    void SortChildren(HTREEITEM HTreeItem, int order);

private:
    static int CALLBACK SortFunctionASC(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
    static int CALLBACK SortFunctionDESC(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
};

