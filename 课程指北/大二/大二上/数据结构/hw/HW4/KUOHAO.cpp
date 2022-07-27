#pragma warning(disable:4996)
#include"stdio.h"
#include <stack> 
#include "string"
#include "iostream"
bool paren( std::string exp, int lo, int hi) {
	//表达式括号匹配检查，可兼顾三种括号
	std::stack<char> S; //使用栈记录已发现但尚未匹配的左括号
	for (int i = lo; i <= hi; i++) { /* 逐一检查当前字符 */
		switch (exp[i]) {
			//左括号直接进栈；右括号若与栈顶失配，则表达式必不匹配
		case '(': case '[': case '{': S.push(exp[i]); break;
		case ')': 
		{
			if ((S.empty()) || ('(' != S.top())) {
				S.pop();
				return false;
			}
			else S.pop();
			break;
		}
		case ']': 
		{
			if ((S.empty()) || ('[' != S.top())) {
				S.pop();
				return false;
			}
			else S.pop();
			break;
		}
		case '}': 
		{
			if ((S.empty()) || ('{' != S.top())) {
				S.pop();
				return false;
			}
			else S.pop(); 
			break; 
		}
		default: break; //非括号字符一律忽略
		}

		//整个表达式扫描过后，栈中若仍残留（左）括号，则不匹配；否则（栈空）匹配
	}
	return S.empty();
}

int main() {
	int n;
	scanf("%d", &n);
	std::string str;
	for (int i = 0; i < n; i++) {
		std::cin >> str;
		printf("%d\n", paren(str, 0, str.size()-1));
	}
	return 0;
}