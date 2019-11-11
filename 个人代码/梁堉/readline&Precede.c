void readLine() {
	char myString[50];  //定义myString存储用户输进来的式子
	std::cin.getline(myString, 50, '\n');    //读取用户输入的一行式子
	char noSpaceStr[50];     //目标式子（即把用户输入的式子的空格部分去掉）
	int j = 0;
	for (int i = 0;myString[i] != '\0';i++) {
		if (myString[i] != ' ') {
			noSpaceStr[j] = myString[i];
			j++;
		}
	}
	noSpaceStr[j] = '\0';               //以'\0'结尾
	expression = noSpaceStr;         //让expression等于用户输入的一行式子（去掉空格的）
}
char Precede(int a, int b) {
	/*返回操作符的优先关系，例如 + < *  */
	if (a > b)
		return '>';
	else if (a < b)
		return '<';
	else
		return '=';

}
