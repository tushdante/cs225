#ifndef apartment_h
#define apartment_h
#include <string>
using std::string;
class Apartment{
	public:
		Apartment();
		Apartment(string const & paramTenant, int paramNumber);
		string const & getTenant() const;
		void setTenant(string const & newTenant);
		string evictTenant();
		int getNumber() const;
		void setNumber(int newNumber);
		void printInfo() const;	
	private:
		string tenant;
		int number;
};
#endif
