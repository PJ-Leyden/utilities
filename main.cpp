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

	Integer_Ring my_ring(4969);
	vector<int> ring = my_ring.get_ring();
	cout << "Cardinality: " << my_ring.cardinality() << endl;
	cout << "Numbers: ";
	print_vector<int>(ring);
	
	vector<int> gen = my_ring.find_generators();
	cout << "Generators: ";
	print_vector<int>(gen);
	
	return 0;

}