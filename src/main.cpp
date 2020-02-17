#include <iostream>
#include <assert.h>
#include "trie.hpp"
#include "numeral_manager.hpp"

void trie_test()
{
	Trie t = Trie();

	assert(t.insert("hello") == true);
	assert(t.search("hello") == true);
	assert(t.insert("helloworld") == true);
	assert(t.search("helloworld") == true);
	assert(t.search("helll") == false);
	assert(t.insert("hell") == true);
	assert(t.insert("h") == true);
	assert(t.search("h") == true);

	assert(t.insert("hell") == false);

	assert(t.remove("hello") == true);
	assert(t.search("hello") == false);
	assert(t.search("helloworld") == true);
	assert(t.search("hell") == true);

	assert(t.remove("h") == true);
	assert(t.search("h") == false);
	assert(t.search("hell") == true);
	assert(t.search("helloworld") == true);

	assert(t.remove("hells") == false);
	assert(t.remove("tomatoes") == false);

	assert(t.remove("helloworld") == true);
	assert(t.search("helloworld") == false);
	assert(t.search("hell") == true);

	assert(t.remove("hell") == true);
	assert(t.empty() == true);
}

void num_mgr_test(NumeralManager &mgr)
{
	std::string str = "one hundred and eight";
	NumeralWord *nw = mgr.analyze(str);
	//std::cout << nw->to_string() << " = " << nw->evaluate() << std::endl;
	assert(nw->evaluate() == 108);
	delete nw;

	str = "two hundred thousand, four hundred forty";
	nw = mgr.analyze(str);
	assert(nw != nullptr);
	//std::cout << nw->to_string() << " = " << nw->evaluate() << std::endl;
	assert(nw->evaluate() == 200440);
}

int main(int argc, char *argv[])
{
	trie_test();

	NumeralManager mgr = NumeralManager();
	mgr.language_setup();

	num_mgr_test(mgr);

	if (argc > 1)
	{
		std::string str(argv[1]);
		int num = mgr.analyze(str)->evaluate();
		std::cout << std::to_string(num) << std::endl;
	}

	return 0;
}
