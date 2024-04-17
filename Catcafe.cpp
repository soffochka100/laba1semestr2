#include "Catcafe.h"

using namespace std;


string Catcafe::GetName() { return name; }
void Catcafe::SetName(const std::string n) { name = n; }

float Catcafe::GetRayting() { return rayting; }
void Catcafe::SetRayting(const float r) {rayting = r; }

float Catcafe::GetPrice() { return priceForHour; }
void Catcafe::SetPrice(const float p) { priceForHour = p; }

ostream& operator <<(ostream& out, Catcafe& r)
{
	out << "Имя: " + r.GetName() << endl;
	out << "Рейтинг: " << r.GetRayting() << endl;
	out << "Цена за час: " << r.GetPrice() << endl;
	return out;
}
istream& operator >>(istream& in, Catcafe& r)
{

	string n;
	cout << "Имя: ";
	cin >> n;

	float rayting;
	cout << "Рейтинг: ";
	cin >> rayting;

	float p;
	cout << "Цена за час: ";
	cin >> p;

	r.SetName(n);
	r.SetRayting(rayting);
	r.SetPrice(p);

	return in;
}
