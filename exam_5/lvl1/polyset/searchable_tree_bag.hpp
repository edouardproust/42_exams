#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag: public tree_bag, public searchable_bag
{
	public:

		searchable_tree_bag();
		searchable_tree_bag(searchable_tree_bag const&);
		searchable_tree_bag&	operator=(searchable_tree_bag const&);
		~searchable_tree_bag();

		bool has(int) const;
};

#endif
