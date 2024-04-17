#include<string>
#include<iostream>
#include<algorithm>
#include<clocale>

#pragma once

class Catcafe
{
private:
	std::string name;
	float rayting;
	float priceForHour;
public:
	std::string GetName();
	void SetName(const std::string n);

	float GetRayting();
	void SetRayting(const float r);

	float GetPrice();
	void SetPrice(const float p);

friend std::ostream &operator <<(std::ostream& out, Catcafe& r);
friend std::istream &operator >>(std::istream& in, Catcafe& r);
};
