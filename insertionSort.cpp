//###################################
//## www.mindwareLab.org Copyright ##
//###################################
#include "iostream"
#include <chrono>


using namespace std;
typedef std::chrono::high_resolution_clock Clock;


void printing(int ArrayToBeSorted[]) {
	for (int i = 0; i < 8; i++)
		printf("%d ", ArrayToBeSorted[i]);
	printf("\n");
}


int main()
{
	int ArrayToBeSorted[] = { 4, 9, 7, 5, 6, 8, 3, 1 };
	
	printing(ArrayToBeSorted);

	auto t1 = Clock::now();
	for (int j = 2; j <8; j++)
	{
		int key = ArrayToBeSorted[j];
		int i = j - 1;
		
		while (i >= 0 && ArrayToBeSorted[i] > key)
		{
			ArrayToBeSorted[i + 1] = ArrayToBeSorted[i];
			i = i - 1;
			//cout <<"Number moved: " << ArrayToBeSorted[i] << endl;
		}
		ArrayToBeSorted[i + 1] = key;

	}
	auto t2 = Clock::now();

	printing(ArrayToBeSorted);
	cout << "Delta t2-t1: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
		<< " nanoseconds" << std::endl;


	return 0;
}



© 2018 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
API
Training
Shop
Blog
