/* mine_point.cpp
	Implementation of Point class

	Written by Matt Sachtler for CS225 MP6
	Spring 2009
	Revision history:
		3/21/2009        Created
*/

extern bool enable_mines;

/* Point constructor. Initializes everything to 0.
 */
template<int Dim>
Point<Dim>::Point()
{
	am_mine = false;
	for(int i = 0; i < Dim; ++i){
		vals[i] = 0;
	}
}

/* Point constructor
	Copy the array of points in
*/
template<int Dim>
Point<Dim>::Point(double arr[Dim])
{
	am_mine = false;
	for(int i = 0; i < Dim; ++i){
		vals[i] = arr[i];
	}
}

template<int Dim>
Point<Dim>::Point(double arr[Dim], bool mine)
{
	am_mine = mine;
	for(int i = 0; i < Dim; ++i){
		vals[i] = arr[i];
	}
}

template<int Dim>
void Point<Dim>::set_mine(bool en)
{
	am_mine = en;
}

template<int Dim>
double Point<Dim>::operator[](int index) const
{
	if(enable_mines && am_mine){
		cout << "FAIL" << endl;
	}
	if(index >= Dim){
		out_of_range e("Point index out of range");
		throw e;
	}
	return vals[index];
}

template<int Dim>
void Point<Dim>::set(int index, double val)
{
	if(index >= Dim){
		out_of_range e("Point index out of range");
		throw e;
	}
	vals[index] = val;

}

template<int Dim>
void Point<Dim>::print() const
{
	cout << "(";
	for(int i = 0; i < Dim - 1; ++i){
		cout << vals[i] << ", ";
	}
	cout << vals[Dim - 1] << ")";
	cout << endl;
}

template<int Dim>
bool Point<Dim>::operator==(const Point<Dim> p) const
{
	return ! (*this != p);
}

template<int Dim>
bool Point<Dim>::operator!=(const Point<Dim> p) const
{
	bool eq = true;
	for(int i = 0; i < Dim; ++i){
		eq &= (vals[i] == p.vals[i]);
	}

	return !eq;
}

template<int Dim>
bool Point<Dim>::operator<(const Point<Dim> p) const
{
	bool less;
	for(int i = 0; i < Dim; ++i){
		less = vals[i] < p[i];
		if(vals[i] != p[i]){
			break;
		}
	}
	return less;
}
