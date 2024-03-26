#include "Technic.h"
#include "Categories.h"


bool Technic::canFix(const Technic& th,const BrokenAppliance& br) const
{
	for (size_t i = 0; i < categories::NUM_CATEGORIES; i++)
	{
		if (th.categories[i] == br.category) {
			return true;
		}
	}
	return false;
}
double Technic::averageEarnings(Technic& technic)
{
	double money = technic.getMoney();
	return money / technic.getTimesHired();

}
