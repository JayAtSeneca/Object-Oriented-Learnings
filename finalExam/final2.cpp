/*
	Requirements for template to work:
	operator!= is required
	operator<< is required
*/
template <typename type>
void printNotMatch(const type arr[], const type& v, int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] != v)
		{
			// this will call the display function of the type through "operator<<" because each type has it's own displaying format and member variables
			std::cout << arr[i];
		}
	}
}

//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello" << endl;
//	return 0;
//}