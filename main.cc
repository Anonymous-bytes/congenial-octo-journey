# include <iostream>
# include <string.h>
# include <thread>


struct node {
	public:
		node(int d,struct node* n) {
		int data = d;
		struct node *next = *n;
		}
};


int main() {
	std::cout<<"ok"<<std::endl;
	return 0;
}
