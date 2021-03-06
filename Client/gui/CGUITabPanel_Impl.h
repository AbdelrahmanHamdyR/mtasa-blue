/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        gui/CGUITabPanel_Impl.h
 *  PURPOSE:     Tab panel widget class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#ifndef __CGUITABPANEL_IMPL_H
#define __CGUITABPANEL_IMPL_H

#include <gui/CGUITabPanel.h>
#include "CGUIElement_Impl.h"
#include "CGUITab_Impl.h"

#define MAX_TABS 64

class CGUITabPanel_Impl : public CGUITabPanel, public CGUIElement_Impl
{
    friend class CGUITab_Impl;

public:
    CGUITabPanel_Impl(class CGUI_Impl* pGUI, CGUIElement* pParent = NULL);
    ~CGUITabPanel_Impl(void);

    CGUITab* CreateTab(const char* szCaption);
    void     DeleteTab(CGUITab* pTab);

    CGUITab* GetSelectedTab(void);
    void     SetSelectedTab(CGUITab* pTab);

    void         SetSelectedIndex(unsigned int uiIndex);
    unsigned int GetSelectedIndex(void);

    unsigned int GetTabCount(void);

    bool IsTabSelected(CGUITab* pTab);

    eCGUIType GetType(void) { return CGUI_TABPANEL; };

    void SetSelectionHandler(GUI_CALLBACK Callback);

    #include "CGUIElement_Inc.h"

private:
    class CGUI_Impl* m_pGUI;

    GUI_CALLBACK m_OnSelectionChanged;

    bool Event_OnSelectionChanged(const CEGUI::EventArgs& e);
};

#endif
