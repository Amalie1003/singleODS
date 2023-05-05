#include "include/OMAP.h"
using namespace std;

int N = 1000;

// Bid createBid(string keyword, int number)
// {
// 	Bid bid(keyword);
// 	auto arr = to_bytes(number);
// 	std::copy(arr.begin(), arr.end(), bid.id.end()-4);
// 	return bid;
// }

int main()
{
	bytes<Key> key1{0};
	OMAP* my_map = new OMAP(N, key1);

	ifstream inFile("../key_value_dataset/new_key_value.csv", ios::in);
	if(!inFile)
	{
		std::cout << "打开文件失败!" << std::endl;
		exit(1);
	}
	int i = 0;
	string line;
	while(getline(inFile, line))
	{
		string key, value;
		istringstream sin(line);
		getline(sin, key, ',');
		getline(sin, value, '\r');
		if(i > 0)
		{
			Bid mapkey1(key);
			std::cout << "begin insert "<< i << ":(" << key << ", " << value << ")" << std::endl;
			my_map->insert(mapkey1, value);
		}
		i++;
		if(i == N) break;
	}
	string find_key = "ilovebruno";
	Bid mapkey2(find_key);
	string ret = my_map->find(mapkey2);
	std::cout << "find " << find_key << " and the value is:" << ret << std::endl;

	// Bid mapkey1 = createBid("test1", 1);
	// my_map->insert(mapkey1, "hello1");

	// Bid mapkey2 = createBid("test2", 2);
	// my_map->insert(mapkey2, "hello2");

	// Bid mapkey3 = createBid("test3", 3);
	// my_map->insert(mapkey3, "hello3");
	// my_map->printTree();

	// Bid mapkey4 = createBid("test2", 2);
	// my_map->insert(mapkey4, "hello2");
	// my_map->printTree();
	return 0;
}