#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {

	searchable_bag&	bag;
 	set::set(set const& s) : bag(s.bag);
	set& set::operator=(set const& rhs);

	public:

		set(searchable_bag&);
		
		void	insert (int);
		void	insert (int *, int);
		void	print() const;
		void	clear();

		bool	has(int);
		searchable_bag&	get_bag() const;
};

#endif

