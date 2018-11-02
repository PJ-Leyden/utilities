#include "integer_ring_math.hpp"
#include <cassert>

using namespace std;

template <class T>
void print_vector(vector<T> v){
	cout << "{ ";
	for(T a : v){
		cout << a << " ";
	}
	cout << "}\n";
}

int main(){

	Integer_Ring my_ring(17);
	ab_mod_c(12, 16, 17);
	ab_mod_c(3, 16, 17);

	
	return 0;

}