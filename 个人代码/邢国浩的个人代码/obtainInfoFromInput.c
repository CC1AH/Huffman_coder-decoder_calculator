/** \author CC1AH
*   \since 2019/29/10
*/
#include "basic.h"
#include <vector>
#include <cctype>
#include <iterator>

/** \brief
 * 这个函数提示用户输入一串表达式，并将表达式中的正数和操作符分别依次放在Nums和Ops两个vector变量数组里面
 * \param vector<double>& Nums -存储数字
 * \param vector<char>& Ops    -存储操作符
 * \return bool                -是否成功存储
 * 
 */
bool Input_DivideOpeAndNums(std::vector<double>& Nums,std::vector<char>& Ops) {
	char judge;
	double tmpNum;
	
	std::cout << "请输入一个表达式:";
	while ((judge = std::cin.get()) != '\n') {
		//读取数字
		if (isdigit(judge)) {
			std::cin.putback(judge);
			std::cin >> tmpNum;
			Nums.push_back(tmpNum);
		}
		//读取操作符
		else if (IsOperator(judge))
			Ops.push_back(judge);
		//忽略空白
		else if (isblank(judge))
			continue;
		//无效字符处理
		else {
			std::cout << "表达式中出现了以下未识别的标识符:" << std::endl;
			std::cerr << judge;
			return false;
		}
	}
		return true;
}



/** \brief 
 * 单元测试台 main 在该函数中进行关于输入和分开存储的测试
 * 测试文件将提取输入表达式的第三个操作数并依次打印出vector容器中
 * 存储的所有操作符和操作数,使用输入出无效字符的方式来退出
 * \param None
 * \return int    -abort signal
 * \testCase:
input:
     (-35.6 + 78.4*3 -6%2)^4/2.12 + 49.578&2 =		
output:
	从表达式中提取第三个操作数的结果是:
	3
	输入表达式的操作数有：
	35.6 78.4 3 6 2 4 2.12 49.578 2
	操作符有
	( - + * - % ) ^ / + & =
 * \pazzle 如何处理-4,-5之类的负的数字
 *
 */
int main()
{
	std::vector<double> Nums;
	std::vector<char> Ops;
	while (true) {
		if (Input_DivideOpeAndNums(Nums, Ops)) {
			std::cout << "\n从表达式中提取第三个操作数的结果是:" << std::endl;
			if (Nums.size() > 2)
				std::cout << Nums[2] << std::endl;
			else
				std::cout << "没有第三个操作数" << std::endl;

			std::cout << "输入表达式的操作数有：" << std::endl;
			std::copy(std::begin(Nums), std::end(Nums), std::ostream_iterator<double>(std::cout, "  "));
			std::cout << "\n操作符有 " << std::endl;
			std::copy(std::begin(Ops), std::end(Ops), std::ostream_iterator<char>(std::cout, "  "));
			std::cout << std::endl;
			
			Nums.clear();
			Ops.clear();
		}
		else {
			std::cerr << "\n没有成功存储\n";
			return 0;
		}
	}
}