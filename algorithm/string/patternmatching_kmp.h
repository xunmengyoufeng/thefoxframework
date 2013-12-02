/*
* @brief KMPģʽƥ���㷨
* @author macwe@qq.com
*/

void createNextArray(const String &str, int *next)
{
	int i = 0;
	int j = -1
	next[i] = j;
	
	while (str[i]) {
		if (-1 == j || str[i] == str[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}


size_t indexKMP(const String &str, const String &patterns, int next[], size_t beginPos = 0)
{
	int i = beginPos;
	int j = 0;
	
	while (str[i] || str[j]) {
		if (str[i] == str[j]) {
			++i;
			++j;
		} else {
			j = next[j];
		}
		
	}
	return -1;
}

size_t indexKMP(const String &str, const String &patterns, size_t beginPos = 0)
{
	size_t result = -1;
	int *next = (int *)malloc(size(int) * str.length());
	indexKMP(str, patterns, next, beginPos);
	free(next);
}