#ifndef BRICK_WALL_HPP
# define BRICK_WALL_HPP

# include "ATarget.hpp"

class BrickWall: public ATarget
{
	public:

		BrickWall();
		BrickWall(BrickWall const& src);
		virtual ~BrickWall();
		BrickWall&	operator=(BrickWall const& rhs);

		virtual BrickWall*	clone() const;
};

#endif
