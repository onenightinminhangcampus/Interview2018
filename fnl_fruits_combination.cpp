#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
using namespace std;

class fruit;
void branch_and_bound(int previous_total_price,int curr_index, vector<int> previous_fruit_combination,vector<int> fruits_factor, int cash,vector<fruit> all_fruits);
template<typename T>
void print_combinations(vector<T> avector,vector<fruit> all_fruits);

class fruit
{
public:
	int price;
	string name;
	fruit(int a, string b) { price = a; name = b; }
};

int main() {
	vector<fruit> all_fruits = {};
	fruit apple(59, "apple");
	fruit banana(32, "banana");
	fruit coconut(155, "coconut");
	fruit grapefruit(128, "grapefruit");
	fruit jackfruit(1100, "jackfruit");
	fruit kiwi(41, "kiwi");
	fruit lemon(70, "lemon");
	fruit mango(97, "mango");
	fruit orange(73, "orange");
	fruit papaya(254, "papaya");
	fruit pear(37, "pear");
	fruit pineapple(399, "pineapple");
	fruit watermelon(500, "watermelon");

	all_fruits.push_back(apple);
	all_fruits.push_back(banana);
	all_fruits.push_back(coconut);
	all_fruits.push_back(grapefruit);
	all_fruits.push_back(jackfruit);
	all_fruits.push_back(kiwi);
	all_fruits.push_back(lemon);
	all_fruits.push_back(mango);
	all_fruits.push_back(orange);
	all_fruits.push_back(papaya);
	all_fruits.push_back(pear);
	all_fruits.push_back(pineapple);
	all_fruits.push_back(watermelon);

	//Perform a bubble sort by price
	for(int i=0;i<all_fruits.size();i++)
	{
		for(int j=0;j<all_fruits.size()-i-1;j++)
		{
			if(all_fruits[j].price>all_fruits[j+1].price)
			{
				fruit temp = all_fruits[j + 1];
				all_fruits[j+1] = all_fruits[j];
				all_fruits[j] = temp;
			}
		}
	}

	//Factor of the total cash available
	vector<int> fruits_factor;
	//Combination of fruit
	vector<int> previous_fruit_combination;

	//Input the total cash
	cout << "Input the total cash:" << endl;
	int cash;
	cin >> cash;

	for (int i = 0; i < all_fruits.size(); i++) {
		if (cash / all_fruits[i].price == 0) {
			break;
		}
		fruits_factor.push_back(cash / all_fruits[i].price);
		previous_fruit_combination.push_back(0);
	}

	//Conduct a branch and bound search starting from the most expensive fruit, 
	int previous_total_price = 0;
	if (fruits_factor.size() > 0) {
		//Branch on this fruit
		branch_and_bound(previous_total_price, fruits_factor.size() - 1, previous_fruit_combination, fruits_factor, cash, all_fruits);
	}

	int a;
	cin >> a;
	cin.get();
	return 0;
}

void branch_and_bound(int previous_total_price, int curr_index, vector<int> previous_fruit_combination, vector<int> fruits_factor,int cash,vector<fruit> all_fruits)
{
	if (curr_index < 0) return;
	for(int i=0;i<=fruits_factor[curr_index];i++)
	{
		int new_total_price = previous_total_price + i*all_fruits[curr_index].price;
		vector<int> new_fruit_combination = previous_fruit_combination;
		new_fruit_combination[curr_index] = i;

		if(new_total_price==cash)
		{
			print_combinations(new_fruit_combination,all_fruits);
			return;
		} else if(new_total_price>cash) {
			//Bound, do not continue, it has no branch
			break;
		} else {
			branch_and_bound(new_total_price, curr_index - 1, new_fruit_combination, fruits_factor, cash, all_fruits);
		}
	}
}

template<typename T>
void print_combinations(vector<T> avector,vector<fruit> all_fruits)
{
	for(int i=0;i<avector.size();i++)
	{
		cout << all_fruits[i].name<< ": "<<avector[i] << " ";
	}
	cout << endl;
}