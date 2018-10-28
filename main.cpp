#include "integer_ring_math.hpp"
#include <cassert>

using namespace std;

int main(){

	Integer_Ring my_ring(11);
	cout << "Cardinality: " << cardinality(my_ring.get_ring()) << endl;
	cout << "Numbers: { ";
	for(int a : my_ring.get_ring()){
		cout << a << " ";
	}
	cout << "}\n";

	vector<int> gen = find_generators(my_ring.get_ring(), my_ring.get_base());
	cout << "Generators: { ";
	for(int a : gen){
		cout << a << " ";
	}
	cout << "}\n";

}