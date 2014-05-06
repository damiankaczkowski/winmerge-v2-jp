/** 
 * @file  PropTextColors.h
 *
 * @brief Declaration file for PropTextColors propertyheet
 *
 */
// ID line follows -- this is updated by SVN
// $Id$

#if !defined(PropTextColors_h_included)
#define PropTextColors_h_included

#include "ColorButton.h"
#include "OptionsPanel.h"

class COptionsMgr;
class SyntaxColors;

/** @brief Property page for colors options; used in options property sheet */
class PropTextColors : public OptionsPanel
{

// Construction
public:

	PropTextColors(COptionsMgr *optionsMgr, SyntaxColors *pColors);

// Implement IOptionsPanel
	virtual void ReadOptions();
	virtual void WriteOptions();

// Dialog Data
private:

	SyntaxColors *m_pTempColors;
	COLORREF m_cCustColors[16];

	//{{AFX_DATA(PropTextColors)
	enum { IDD = IDD_PROPPAGE_COLORS_TEXT };
	CColorButton    m_btnDefaultStandardColors;
	CColorButton    m_btnWhitespaceBackground;
	CColorButton    m_btnRegularBackground;
	CColorButton    m_btnRegularText;
	CColorButton    m_btnSelectionBackground;
	CColorButton    m_btnSelectionText;
	bool            m_bCustomColors;
	//}}AFX_DATA

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PropTextColors)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	typedef enum { SET_DEFAULTS, READ_OPTIONS, LOAD_COLORS } OPERATION;

	virtual BOOL OnInitDialog();
	void BrowseColorAndSave(CColorButton & colorButton, int colorIndex);
	void SerializeColorsToFromScreen(OPERATION op);
	void SerializeColorToFromScreen(OPERATION op, CColorButton & btn, int colorIndex);
	void EnableColorButtons(BOOL bEnable);

	// Generated message map functions
	//{{AFX_MSG(PropTextColors)
	afx_msg void OnWhitespaceBackgroundColor();
	afx_msg void OnRegularBackgroundColor();
	afx_msg void OnRegularTextColor();
	afx_msg void OnSelectionBackgroundColor();
	afx_msg void OnSelectionTextColor();
	afx_msg void OnDefaultsStandardColors();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // PropTextColors_h_included
