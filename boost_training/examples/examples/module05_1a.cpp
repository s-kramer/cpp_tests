	...
	Wyprowadzona wypr;
	Bazowa * bazowa = &wypr;
	std::cout << "wypr    to: " << typeid(wypr).name() << std::endl;
	std::cout << "*bazowa to: " << typeid(*bazowa).name() << std::endl;
	std::cout << "Czy s± takiego samego typu? " << std::boolalpha;
	std::cout << (typeid(wypr) == typeid(*bazowa)) << std::endl;
	PolWyprowadzona polWypr;
	PolBazowa * polBazowa = &polWypr;
	std::cout << "polWypr to: " << typeid(polWypr).name() << std::endl;
	std::cout << "*polBazowa to: " << typeid(*polBazowa).name() << std::endl;
	std::cout << "Czy s± takiego samego typu? " << std::boolalpha;
	std::cout << (typeid(polWypr) == typeid(*polBazowa)) << std::endl;
}

