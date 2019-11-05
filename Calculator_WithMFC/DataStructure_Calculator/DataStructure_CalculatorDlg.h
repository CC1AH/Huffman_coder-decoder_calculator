
// DataStructure_CalculatorDlg.h: 头文件
//

#pragma once


// CDataStructureCalculatorDlg 对话框
class CDataStructureCalculatorDlg : public CDialogEx
{
// 构造
public:
	CDataStructureCalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATASTRUCTURE_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CString expression;

	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum2();
	CString result;
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum9();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedLbr();
	afx_msg void OnBnClickedRbr();
	afx_msg void OnBnClickedDoc();
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMulti();
	afx_msg void OnBnClickedSqare();
	afx_msg void OnBnClickedMod();
	afx_msg void OnBnClickedSqrt();
	afx_msg void OnBnClickedEqs();
	afx_msg void OnBnClickedCle();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
