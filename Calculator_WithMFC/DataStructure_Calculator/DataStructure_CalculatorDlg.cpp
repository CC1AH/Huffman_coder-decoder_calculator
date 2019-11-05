
// DataStructure_CalculatorDlg.cpp: 实现文件
#include "pch.h"
#include "framework.h"
#include "DataStructure_Calculator.h"
#include "DataStructure_CalculatorDlg.h"
#include "afxdialogex.h"

#include "basic.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CFont font;
CFont font2;
CFont font3;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()
CDataStructureCalculatorDlg::CDataStructureCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATASTRUCTURE_CALCULATOR_DIALOG, pParent)
	, expression(_T(""))
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CDataStructureCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, expression);
	DDX_Text(pDX, IDC_EDIT2, result);
}
BEGIN_MESSAGE_MAP(CDataStructureCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(NUM0, &CDataStructureCalculatorDlg::OnBnClickedNum0)
	ON_BN_CLICKED(NUM3, &CDataStructureCalculatorDlg::OnBnClickedNum3)
	ON_BN_CLICKED(NUM1, &CDataStructureCalculatorDlg::OnBnClickedNum1)
	ON_BN_CLICKED(NUM2, &CDataStructureCalculatorDlg::OnBnClickedNum2)
	ON_BN_CLICKED(NUM4, &CDataStructureCalculatorDlg::OnBnClickedNum4)
	ON_BN_CLICKED(NUM5, &CDataStructureCalculatorDlg::OnBnClickedNum5)
	ON_BN_CLICKED(NUM6, &CDataStructureCalculatorDlg::OnBnClickedNum6)
	ON_BN_CLICKED(NUM7, &CDataStructureCalculatorDlg::OnBnClickedNum7)
	ON_BN_CLICKED(NUM8, &CDataStructureCalculatorDlg::OnBnClickedNum8)
	ON_BN_CLICKED(NUM9, &CDataStructureCalculatorDlg::OnBnClickedNum9)
	ON_BN_CLICKED(DOC, &CDataStructureCalculatorDlg::OnBnClickedDoc)
	ON_BN_CLICKED(MINUS, &CDataStructureCalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(DIV, &CDataStructureCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(LBR, &CDataStructureCalculatorDlg::OnBnClickedLbr)
	ON_BN_CLICKED(RBR, &CDataStructureCalculatorDlg::OnBnClickedRbr)
	ON_BN_CLICKED(PLUS, &CDataStructureCalculatorDlg::OnBnClickedPlus)
	ON_BN_CLICKED(MULTI, &CDataStructureCalculatorDlg::OnBnClickedMulti)
	ON_BN_CLICKED(SQARE, &CDataStructureCalculatorDlg::OnBnClickedSqare)
	ON_BN_CLICKED(MOD, &CDataStructureCalculatorDlg::OnBnClickedMod)
	ON_BN_CLICKED(SQRT, &CDataStructureCalculatorDlg::OnBnClickedSqrt)
	ON_BN_CLICKED(EQS, &CDataStructureCalculatorDlg::OnBnClickedEqs)
	ON_BN_CLICKED(CLE, &CDataStructureCalculatorDlg::OnBnClickedCle)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/**
* 此函数中初始化了字体相关的代码
*/
BOOL CDataStructureCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//初始化字体
	font.CreatePointFont(300, _T("楷体"));
	font2.CreatePointFont(100, _T("黑体"));
	font3.CreatePointFont(100, _T("楷体"));
	//初始化帮助字
	char* helpInfo = "* Help: This is a calculator and the instrucions are as followed. * \n"
		"* Expressions include : *\n"
		"* 1. add(+)、subtract(-)、multiply(*)、divide(/ )、modulo(%) 、 involution(^) and extraction(&).\n"
		"* 2. brackets(()). * \n"
		"* USE \"=\" to calculate an expression at once*\n"
		"* *********************************************** *";
	//char* 转换为LPCTSTR
	CString   m(helpInfo);
	LPCTSTR   lp = (LPCTSTR)m;
	 GetDlgItem(HELP)->SetWindowText(lp);
	 //设置字体
	 GetDlgItem(TOP)->SetFont(&font);
	 GetDlgItem(HELP)->SetFont(&font3);
	 GetDlgItem(INP)->SetFont(&font2);
	 GetDlgItem(OUTPU)->SetFont(&font2);
	 
	 GetDlgItem(PLUS)->SetFont(&font3);
	 GetDlgItem(MINUS)->SetFont(&font3);
	 GetDlgItem(MULTI)->SetFont(&font3);
	 GetDlgItem(DIV)->SetFont(&font3);
	 GetDlgItem(LBR)->SetFont(&font3);
	 GetDlgItem(RBR)->SetFont(&font3);
	 GetDlgItem(SQARE)->SetFont(&font3);
	 GetDlgItem(SQRT)->SetFont(&font3);
	 GetDlgItem(EQS)->SetFont(&font3);
	 GetDlgItem(NUM1)->SetFont(&font3);
	 GetDlgItem(NUM2)->SetFont(&font3);
	 GetDlgItem(NUM3)->SetFont(&font3);
	 GetDlgItem(NUM4)->SetFont(&font3);
	 GetDlgItem(NUM5)->SetFont(&font3);
	 GetDlgItem(NUM6)->SetFont(&font3);
	 GetDlgItem(NUM7)->SetFont(&font3);
	 GetDlgItem(NUM8)->SetFont(&font3);
	 GetDlgItem(NUM9)->SetFont(&font3);
	 GetDlgItem(NUM0)->SetFont(&font3);
	 GetDlgItem(DOC)->SetFont(&font3);
	return TRUE; 
}

void CDataStructureCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
void CDataStructureCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
HCURSOR CDataStructureCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*颜色控制*/
HBRUSH CDataStructureCalculatorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == TOP)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置字体颜色
		pDC->SetBkColor(RGB(50, 200, 50));//设置背景颜色
	}
	if (pWnd->GetDlgCtrlID() == HELP)// IDC_Display为所选文本框ID
	{
		pDC->SetTextColor(RGB(255, 0, 255));//设置字体颜色
	}
	return hbr;
}
/** \brief
 * 这个函数将Expression的内容加以计算，存储到result里面
 * \param CString Expression -存储表达式
 * \param CString& result    -表达结果
 * \return none
 *
 */
void produceResultFromExpression(CString Expression, CString& result) {
	double res = 0;
	expression = CW2A(Expression) + "=";
	EvaluateExpression(expression, res);
	CString str(expression.c_str());
	result = str;
	CString Result;
	Result.Format(_T("\n%.2lf"), res);
	result += Result;
}

//监听函数：22个
/*11个数字组*/
void CDataStructureCalculatorDlg::OnBnClickedNum0()
{
	UpdateData(TRUE);
	expression.Append(_T("0"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum1()
{
	UpdateData(TRUE);
	expression.Append(_T("1"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum2()
{
	UpdateData(TRUE);
	expression.Append(_T("2"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum3()
{
	UpdateData(TRUE);
	expression.Append(_T("3"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum4()
{
	UpdateData(TRUE);
	expression.Append(_T("4"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum5()
{
	UpdateData(TRUE);
	expression.Append(_T("5"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum6()
{
	UpdateData(TRUE);
	expression.Append(_T("6"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum7()
{
	UpdateData(TRUE);
	expression.Append(_T("7"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum8()
{
	UpdateData(TRUE);
	expression.Append(_T("8"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedNum9()
{
	UpdateData(TRUE);
	expression.Append(_T("9"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedDoc()
{
	UpdateData(TRUE);
	expression.Append(_T("."));
	UpdateData(FALSE);
}

/*10个运算符组*/
void CDataStructureCalculatorDlg::OnBnClickedPlus()
{
	UpdateData(TRUE);
	expression.Append(_T("+"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedMinus()
{
	UpdateData(TRUE);
	expression.Append(_T("-"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedMulti()
{
	UpdateData(TRUE);
	expression.Append(_T("*"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedDiv()
{
	UpdateData(TRUE);
	expression.Append(_T("/"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedLbr()
{
	UpdateData(TRUE);
	expression.Append(_T("("));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedRbr()
{
	UpdateData(TRUE);
	expression.Append(_T(")"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedSqare()
{
	UpdateData(TRUE);
	expression.Append(_T("^"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedMod()
{
	UpdateData(TRUE);
	expression.Append(_T("%"));
	UpdateData(FALSE);
}
void CDataStructureCalculatorDlg::OnBnClickedSqrt()
{
	UpdateData(TRUE);
	expression.Append(_T("&"));
	UpdateData(FALSE);
}
//产生结果
void CDataStructureCalculatorDlg::OnBnClickedEqs()
{
	UpdateData(TRUE);
	result = "";
	produceResultFromExpression(expression, result);
	UpdateData(FALSE);
}

/*清空*/
void CDataStructureCalculatorDlg::OnBnClickedCle()
{
	UpdateData(TRUE);
	expression = "";
	result = "";
	UpdateData(FALSE);
}